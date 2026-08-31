"""SBOL account registration service.

A dependency-free HTTP service that lets players create their own accounts
instead of the operator running
``"SBOL DB Server.exe" /createaccount <user> <pass> <email> <priv>`` by hand.

It writes directly into the same sbol.db that SBOL DB Server.exe uses, in the
byte-compatible format implemented in :mod:`sbol_db`.

Standard library only, so there is nothing to pip install on the server. It is
NOT a hardened edge server: bind it to localhost and put Caddy / nginx / IIS in
front for TLS. See README.md.

    python3 app.py                 # uses config.json beside this file
    python3 app.py --config x.json
    python3 app.py --init-db       # create an empty sbol.db for local testing
"""

import argparse
import base64
import hmac
import html
import json
import logging
import os
import secrets
import sqlite3
import sys
import threading
import time
from hashlib import sha256
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

import ratelimit
import sbol_db
import validation

HERE = os.path.dirname(os.path.abspath(__file__))

DEFAULT_CONFIG = {
    "database": "../sbol.db",
    "host": "127.0.0.1",
    "port": 8080,
    "wal": True,
    "busy_timeout_ms": 5000,
    # Only trust X-Forwarded-For when a reverse proxy you control sets it.
    # Left on with no proxy, any client could spoof its way past rate limits.
    "trusted_proxy": False,
    "registrations_per_hour": 5,
    "lookups_per_minute": 30,
    "global_registrations_per_hour": 200,
    "min_form_seconds": 2,
    "max_form_seconds": 3600,
    "secret_key": "",
    "log_path": "./log",
}

MAX_BODY_BYTES = 8192
CSRF_COOKIE = "sbol_csrf"

log = logging.getLogger("sbol.web")


# --------------------------------------------------------------------------
# Config
# --------------------------------------------------------------------------

def load_config(path):
    cfg = dict(DEFAULT_CONFIG)
    if path and os.path.exists(path):
        with open(path, "r", encoding="utf-8") as fh:
            cfg.update(json.load(fh))
    elif path:
        log.warning("Config %s not found; using defaults.", path)

    if not cfg["secret_key"]:
        # Ephemeral key: CSRF tokens stop validating across restarts, which is
        # merely inconvenient. Set secret_key in config.json in production.
        cfg["secret_key"] = secrets.token_hex(32)
        log.warning("No secret_key configured; generated a temporary one. "
                    "Set secret_key in config.json to keep sessions stable.")

    if not os.path.isabs(cfg["database"]):
        cfg["database"] = os.path.normpath(os.path.join(HERE, cfg["database"]))
    if not os.path.isabs(cfg["log_path"]):
        cfg["log_path"] = os.path.normpath(os.path.join(HERE, cfg["log_path"]))
    return cfg


# --------------------------------------------------------------------------
# Templating: substitute {{name}} placeholders, escaping by default.
# --------------------------------------------------------------------------

_template_cache = {}


def render(name, values=None, raw=None):
    """Render templates/<name>.

    ``values`` are HTML-escaped. ``raw`` is inserted verbatim and must only ever
    contain markup this module built itself.
    """
    if name not in _template_cache:
        with open(os.path.join(HERE, "templates", name), "r", encoding="utf-8") as fh:
            _template_cache[name] = fh.read()
    out = _template_cache[name]
    for key, value in (values or {}).items():
        out = out.replace("{{%s}}" % key, html.escape(str(value), quote=True))
    for key, value in (raw or {}).items():
        out = out.replace("{{%s}}" % key, value)
    return out


def page(title, tagline, body_html):
    return render("base.html", values={"title": title, "tagline": tagline},
                  raw={"content": body_html})


def error_block(messages):
    if not messages:
        return ""
    items = "".join("<li>%s</li>" % html.escape(m) for m in messages)
    return ('<div class="errors" role="alert"><strong>'
            'Your account could not be created.</strong>'
            '<ul>%s</ul></div>' % items)


def flatten_errors(errors):
    """Field->messages dict into a flat list, in a stable field order."""
    order = ["username", "email", "password", "confirm", "form"]
    out = []
    for field in order:
        out.extend(errors.get(field, []))
    for field, messages in errors.items():
        if field not in order:
            out.extend(messages)
    return out


# --------------------------------------------------------------------------
# CSRF (double-submit cookie) and the timing honeypot
# --------------------------------------------------------------------------

def sign(secret, message):
    return hmac.new(secret.encode("utf-8"), message.encode("utf-8"), sha256).hexdigest()


def make_csrf_token(secret):
    nonce = base64.urlsafe_b64encode(secrets.token_bytes(18)).decode("ascii")
    return "%s.%s" % (nonce, sign(secret, nonce))


def csrf_valid(secret, form_token, cookie_token):
    """Token must be well-formed, correctly signed, and match the cookie."""
    if not form_token or not cookie_token:
        return False
    if not hmac.compare_digest(form_token, cookie_token):
        return False
    nonce, _, mac = form_token.partition(".")
    if not nonce or not mac:
        return False
    return hmac.compare_digest(mac, sign(secret, nonce))


def make_timestamp(secret, now=None):
    stamp = str(int(now if now is not None else time.time()))
    return "%s.%s" % (stamp, sign(secret, stamp))


def timestamp_age(secret, value, now=None):
    """Seconds since the signed timestamp was issued, or None if it is invalid."""
    stamp, _, mac = (value or "").partition(".")
    if not stamp.isdigit() or not mac:
        return None
    if not hmac.compare_digest(mac, sign(secret, stamp)):
        return None
    return (now if now is not None else time.time()) - int(stamp)


# --------------------------------------------------------------------------
# Application
# --------------------------------------------------------------------------

class Application:
    def __init__(self, config):
        self.config = config
        self.secret = config["secret_key"]
        self.register_bucket = ratelimit.TokenBucket(
            config["registrations_per_hour"], 3600.0 / max(1, config["registrations_per_hour"]))
        self.lookup_bucket = ratelimit.TokenBucket(
            config["lookups_per_minute"], 60.0 / max(1, config["lookups_per_minute"]))
        self.global_bucket = ratelimit.TokenBucket(
            config["global_registrations_per_hour"],
            3600.0 / max(1, config["global_registrations_per_hour"]))
        self._db_lock = threading.Lock()

    def connect(self):
        return sbol_db.connect(self.config["database"],
                               wal=self.config["wal"],
                               busy_timeout_ms=self.config["busy_timeout_ms"])

    def create_account(self, username, password, email, client_ip):
        """Validate then insert. Returns (license_no, errors_dict)."""
        errors = validation.validate_registration(username, password, None, email)
        if errors:
            return None, errors
        try:
            with self._db_lock:
                conn = self.connect()
                try:
                    license_no = sbol_db.register_account(conn, username, password, email)
                finally:
                    conn.close()
        except sbol_db.AccountExists:
            return None, {"username": ["That username is already taken."]}
        except sbol_db.DatabaseBusy:
            log.error("Database busy while registering from %s", client_ip)
            return None, {"form": ["The server is busy. Please try again in a moment."]}
        except (sqlite3.Error, ValueError) as exc:
            log.exception("Registration failed from %s: %s", client_ip, exc)
            return None, {"form": ["Something went wrong creating the account."]}

        log.info("Created account '%s' (license %s) from %s",
                 username, license_no, client_ip)
        return license_no, {}


# --------------------------------------------------------------------------
# HTTP layer
# --------------------------------------------------------------------------

class Handler(BaseHTTPRequestHandler):
    server_version = "SBOLWeb/1.0"
    sys_version = ""
    protocol_version = "HTTP/1.1"

    # -- helpers ----------------------------------------------------------

    @property
    def app(self):
        return self.server.app

    def client_ip(self):
        if self.app.config["trusted_proxy"]:
            forwarded = self.headers.get("X-Forwarded-For", "")
            if forwarded:
                # Right-most entry is the one our own proxy appended.
                return forwarded.split(",")[-1].strip()
        return self.client_address[0]

    def cookies(self):
        jar = {}
        for chunk in (self.headers.get("Cookie") or "").split(";"):
            name, _, value = chunk.strip().partition("=")
            if name:
                jar[name] = value
        return jar

    def respond(self, status, body, content_type="text/html; charset=utf-8",
                extra_headers=None):
        payload = body.encode("utf-8") if isinstance(body, str) else body
        self.send_response(status)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(payload)))
        self.send_header("X-Content-Type-Options", "nosniff")
        self.send_header("X-Frame-Options", "DENY")
        self.send_header("Referrer-Policy", "same-origin")
        self.send_header(
            "Content-Security-Policy",
            "default-src 'none'; style-src 'self'; form-action 'self'; base-uri 'none'")
        for key, value in (extra_headers or {}):
            self.send_header(key, value)
        self.end_headers()
        if self.command != "HEAD":
            self.wfile.write(payload)

    def respond_json(self, status, payload, extra_headers=None):
        self.respond(status, json.dumps(payload),
                     content_type="application/json; charset=utf-8",
                     extra_headers=extra_headers)

    def redirect(self, location):
        self.send_response(HTTPStatus.SEE_OTHER)
        self.send_header("Location", location)
        self.send_header("Content-Length", "0")
        self.end_headers()

    def read_body(self):
        try:
            length = int(self.headers.get("Content-Length") or 0)
        except ValueError:
            return None
        if length <= 0:
            return b""
        if length > MAX_BODY_BYTES:
            return None
        return self.rfile.read(length)

    def log_message(self, fmt, *args):
        log.info("%s %s", self.client_ip(), fmt % args)

    # -- routing ----------------------------------------------------------

    def do_GET(self):
        route = urlparse(self.path)
        path = route.path.rstrip("/") or "/"
        if path == "/":
            return self.redirect("/register")
        if path == "/register":
            return self.get_register()
        if path == "/registered":
            return self.get_registered(parse_qs(route.query))
        if path == "/healthz":
            return self.get_healthz()
        if path == "/api/username-available":
            return self.get_username_available(parse_qs(route.query))
        if path == "/static/style.css":
            return self.get_static()
        self.respond(HTTPStatus.NOT_FOUND, page("Not found", "", "<h2>Not found</h2>"))

    do_HEAD = do_GET

    def do_POST(self):
        path = urlparse(self.path).path.rstrip("/") or "/"
        if path == "/register":
            return self.post_register()
        if path == "/api/register":
            return self.post_api_register()
        self.respond(HTTPStatus.NOT_FOUND, page("Not found", "", "<h2>Not found</h2>"))

    # -- handlers ---------------------------------------------------------

    def get_static(self):
        # Single known file; nothing is derived from the request path, so there
        # is no traversal surface here.
        with open(os.path.join(HERE, "static", "style.css"), "rb") as fh:
            body = fh.read()
        self.respond(HTTPStatus.OK, body, content_type="text/css; charset=utf-8")

    def render_register(self, status=HTTPStatus.OK, messages=(), username="", email=""):
        token = make_csrf_token(self.app.secret)
        body = render("register.html",
                      values={"csrf": token,
                              "ts": make_timestamp(self.app.secret),
                              "username": username,
                              "email": email},
                      raw={"errors": error_block(list(messages))})
        cookie = ("%s=%s; Path=/; HttpOnly; SameSite=Strict" % (CSRF_COOKIE, token))
        self.respond(status,
                     page("Register", "Create your driver's license", body),
                     extra_headers=[("Set-Cookie", cookie)])

    def get_register(self):
        self.render_register()

    def get_registered(self, query):
        license_no = (query.get("license") or ["?"])[0]
        # Displayed only; never trusted, and escaped by render().
        if not str(license_no).isdigit():
            license_no = "?"
        body = render("registered.html", values={"license": license_no})
        self.respond(HTTPStatus.OK, page("Account created", "Welcome to the highway", body))

    def get_healthz(self):
        try:
            conn = self.app.connect()
            try:
                ok = sbol_db.has_account_table(conn)
            finally:
                conn.close()
        except sqlite3.Error as exc:
            return self.respond_json(HTTPStatus.SERVICE_UNAVAILABLE,
                                     {"ok": False, "error": str(exc)})
        if not ok:
            return self.respond_json(HTTPStatus.SERVICE_UNAVAILABLE,
                                     {"ok": False, "error": "account_data table missing"})
        return self.respond_json(HTTPStatus.OK, {"ok": True})

    def get_username_available(self, query):
        ip = self.client_ip()
        if not self.app.lookup_bucket.allow(ip):
            return self.respond_json(
                HTTPStatus.TOO_MANY_REQUESTS, {"error": "rate limited"},
                extra_headers=[("Retry-After", str(self.app.lookup_bucket.retry_after(ip)))])

        username = (query.get("u") or [""])[0]
        errors = validation.validate_username(username)
        if errors:
            return self.respond_json(HTTPStatus.OK,
                                     {"available": False, "reason": errors[0]})
        try:
            conn = self.app.connect()
            try:
                taken = sbol_db.username_taken(conn, username)
            finally:
                conn.close()
        except (sqlite3.Error, ValueError):
            return self.respond_json(HTTPStatus.SERVICE_UNAVAILABLE,
                                     {"error": "database unavailable"})
        return self.respond_json(HTTPStatus.OK, {"available": not taken})

    def _rate_limit_register(self, ip):
        """Returns an error message when this request should be refused."""
        if not self.app.register_bucket.allow(ip):
            return "Too many registrations from your address. Please try again later."
        if not self.app.global_bucket.allow("global"):
            return "The server is accepting too many signups right now. Please try again later."
        return None

    def post_register(self):
        ip = self.client_ip()
        raw = self.read_body()
        if raw is None:
            return self.render_register(HTTPStatus.BAD_REQUEST,
                                        ["The submitted form was too large."])
        form = {k: v[0] for k, v in
                parse_qs(raw.decode("utf-8", "replace"), keep_blank_values=True).items()}

        username = form.get("username", "").strip()
        email = form.get("email", "").strip()
        password = form.get("password", "")
        confirm = form.get("confirm", "")

        if not csrf_valid(self.app.secret, form.get("csrf"), self.cookies().get(CSRF_COOKIE)):
            return self.render_register(
                HTTPStatus.BAD_REQUEST,
                ["Your session expired. Please submit the form again."],
                username, email)

        # Bots fill in every field they can see, including the hidden one.
        if form.get("website"):
            log.warning("Honeypot triggered from %s", ip)
            return self.render_register(HTTPStatus.BAD_REQUEST,
                                        ["Your submission looked automated."],
                                        username, email)

        age = timestamp_age(self.app.secret, form.get("ts"))
        if age is None or age < self.app.config["min_form_seconds"] \
                or age > self.app.config["max_form_seconds"]:
            return self.render_register(
                HTTPStatus.BAD_REQUEST,
                ["Your submission looked automated, or the form was left open too long. "
                 "Please try again."],
                username, email)

        limited = self._rate_limit_register(ip)
        if limited:
            return self.render_register(HTTPStatus.TOO_MANY_REQUESTS, [limited],
                                        username, email)

        errors = validation.validate_registration(username, password, confirm, email)
        if errors:
            return self.render_register(HTTPStatus.BAD_REQUEST,
                                        flatten_errors(errors), username, email)

        license_no, errors = self.app.create_account(username, password, email, ip)
        if errors:
            return self.render_register(HTTPStatus.BAD_REQUEST,
                                        flatten_errors(errors), username, email)
        self.redirect("/registered?license=%d" % license_no)

    def post_api_register(self):
        ip = self.client_ip()
        raw = self.read_body()
        if raw is None:
            return self.respond_json(HTTPStatus.BAD_REQUEST,
                                     {"ok": False, "errors": ["Request body too large."]})
        try:
            payload = json.loads(raw.decode("utf-8") or "{}")
            if not isinstance(payload, dict):
                raise ValueError("expected an object")
        except (ValueError, UnicodeDecodeError):
            return self.respond_json(HTTPStatus.BAD_REQUEST,
                                     {"ok": False, "errors": ["Invalid JSON body."]})

        limited = self._rate_limit_register(ip)
        if limited:
            return self.respond_json(
                HTTPStatus.TOO_MANY_REQUESTS, {"ok": False, "errors": [limited]},
                extra_headers=[("Retry-After", str(self.app.register_bucket.retry_after(ip)))])

        username = str(payload.get("username", "")).strip()
        email = str(payload.get("email", "")).strip()
        password = str(payload.get("password", ""))

        license_no, errors = self.app.create_account(username, password, email, ip)
        if errors:
            return self.respond_json(HTTPStatus.BAD_REQUEST,
                                     {"ok": False, "errors": flatten_errors(errors)})
        return self.respond_json(HTTPStatus.CREATED, {"ok": True, "license": license_no})


class Server(ThreadingHTTPServer):
    daemon_threads = True
    allow_reuse_address = True

    def __init__(self, address, app):
        self.app = app
        super().__init__(address, Handler)


# --------------------------------------------------------------------------
# Entry point
# --------------------------------------------------------------------------

def setup_logging(log_path):
    os.makedirs(log_path, exist_ok=True)
    handler = logging.FileHandler(os.path.join(log_path, "web.log"), encoding="utf-8")
    handler.setFormatter(logging.Formatter("%(asctime)s [%(levelname)s] %(message)s"))
    stream = logging.StreamHandler(sys.stdout)
    stream.setFormatter(logging.Formatter("%(asctime)s [%(levelname)s] %(message)s"))
    logging.basicConfig(level=logging.INFO, handlers=[handler, stream])


def init_db(path):
    """Create an empty database with just account_data, for local testing.

    On a real server the DB server creates the schema itself; this only exists so
    the site can be exercised without running the Windows binaries.
    """
    conn = sqlite3.connect(path)
    try:
        if conn.execute("SELECT name FROM sqlite_master WHERE name='account_data'").fetchone():
            print("account_data already exists in %s" % path)
            return
        conn.execute(sbol_db.SCHEMA_ACCOUNT_DATA)
        conn.commit()
        print("Created account_data in %s" % path)
    finally:
        conn.close()


def main(argv=None):
    parser = argparse.ArgumentParser(description="SBOL account registration service")
    parser.add_argument("--config", default=os.path.join(HERE, "config.json"))
    parser.add_argument("--host", default=None)
    parser.add_argument("--port", type=int, default=None)
    parser.add_argument("--init-db", action="store_true",
                        help="create an empty sbol.db for local testing and exit")
    args = parser.parse_args(argv)

    config = load_config(args.config)
    if args.host:
        config["host"] = args.host
    if args.port:
        config["port"] = args.port
    setup_logging(config["log_path"])

    if args.init_db:
        return init_db(config["database"])

    if not os.path.exists(config["database"]):
        log.error("Database not found: %s. Start SBOL DB Server.exe once to create "
                  "it, or run with --init-db for local testing.", config["database"])
        return 1

    app = Application(config)
    server = Server((config["host"], config["port"]), app)
    log.info("Serving on http://%s:%d/ (database: %s)",
             config["host"], config["port"], config["database"])
    if config["host"] not in ("127.0.0.1", "localhost", "::1"):
        log.warning("Bound to a non-loopback address. This server is not hardened "
                    "for direct internet exposure; put a reverse proxy in front.")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        log.info("Shutting down.")
    finally:
        server.server_close()
    return 0


if __name__ == "__main__":
    sys.exit(main() or 0)
