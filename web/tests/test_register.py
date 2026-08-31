"""End-to-end tests: a real server on a real socket, driven over HTTP."""

import http.client
import json
import os
import re
import sqlite3
import sys
import tempfile
import threading
import unittest
from urllib.parse import urlencode

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import app as webapp
import sbol_db

GOOD_PW = "hunter2hunter2"


class ServerCase(unittest.TestCase):
    """Boots the real application against a throwaway database."""

    config_overrides = {}

    def setUp(self):
        fd, self.db_path = tempfile.mkstemp(suffix=".db")
        os.close(fd)
        conn = sqlite3.connect(self.db_path)
        conn.execute(sbol_db.SCHEMA_ACCOUNT_DATA)
        conn.commit()
        conn.close()

        config = dict(webapp.DEFAULT_CONFIG)
        config.update({
            "database": self.db_path,
            "secret_key": "test-secret-key",
            "min_form_seconds": 0,   # no need to make the suite wait
            "log_path": tempfile.mkdtemp(),
        })
        config.update(self.config_overrides)
        self.config = config

        self.server = webapp.Server(("127.0.0.1", 0), webapp.Application(config))
        self.port = self.server.server_address[1]
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.thread.start()

    def tearDown(self):
        self.server.shutdown()
        self.server.server_close()
        self.thread.join(timeout=5)
        for suffix in ("", "-wal", "-shm"):
            try:
                os.unlink(self.db_path + suffix)
            except OSError:
                pass

    # -- helpers ----------------------------------------------------------

    def request(self, method, path, body=None, headers=None):
        conn = http.client.HTTPConnection("127.0.0.1", self.port, timeout=10)
        try:
            conn.request(method, path, body=body, headers=headers or {})
            response = conn.getresponse()
            return response.status, dict(response.getheaders()), response.read().decode("utf-8")
        finally:
            conn.close()

    def get_form(self):
        """Fetch /register and pull out the CSRF cookie and hidden fields."""
        status, headers, body = self.request("GET", "/register")
        self.assertEqual(status, 200)
        cookie = headers["Set-Cookie"].split(";")[0]
        csrf = re.search(r'name="csrf" value="([^"]+)"', body).group(1)
        ts = re.search(r'name="ts" value="([^"]+)"', body).group(1)
        return cookie, csrf, ts

    def submit(self, username, password, confirm=None, email="driver@example.com",
               overrides=None):
        cookie, csrf, ts = self.get_form()
        fields = {
            "csrf": csrf, "ts": ts, "website": "",
            "username": username, "email": email,
            "password": password,
            "confirm": password if confirm is None else confirm,
        }
        fields.update(overrides or {})
        return self.request(
            "POST", "/register", body=urlencode(fields),
            headers={"Content-Type": "application/x-www-form-urlencoded",
                     "Cookie": cookie})

    def api_register(self, payload):
        status, _, body = self.request(
            "POST", "/api/register", body=json.dumps(payload),
            headers={"Content-Type": "application/json"})
        return status, json.loads(body)

    def db(self):
        return sbol_db.connect(self.db_path)


class TestPages(ServerCase):
    def test_root_redirects_to_register(self):
        status, headers, _ = self.request("GET", "/")
        self.assertEqual(status, 303)
        self.assertEqual(headers["Location"], "/register")

    def test_register_page_renders(self):
        status, _, body = self.request("GET", "/register")
        self.assertEqual(status, 200)
        self.assertIn("Create an account", body)
        self.assertIn('name="csrf"', body)

    def test_security_headers_present(self):
        _, headers, _ = self.request("GET", "/register")
        self.assertEqual(headers["X-Content-Type-Options"], "nosniff")
        self.assertEqual(headers["X-Frame-Options"], "DENY")
        self.assertIn("default-src 'none'", headers["Content-Security-Policy"])

    def test_csrf_cookie_is_httponly_and_samesite(self):
        _, headers, _ = self.request("GET", "/register")
        self.assertIn("HttpOnly", headers["Set-Cookie"])
        self.assertIn("SameSite=Strict", headers["Set-Cookie"])

    def test_stylesheet_served(self):
        status, headers, _ = self.request("GET", "/static/style.css")
        self.assertEqual(status, 200)
        self.assertTrue(headers["Content-Type"].startswith("text/css"))

    def test_unknown_path_is_404(self):
        status, _, _ = self.request("GET", "/nope")
        self.assertEqual(status, 404)

    def test_healthz_reports_ok(self):
        status, _, body = self.request("GET", "/healthz")
        self.assertEqual(status, 200)
        self.assertTrue(json.loads(body)["ok"])


class TestFormRegistration(ServerCase):
    def test_successful_registration_redirects_and_creates_a_usable_account(self):
        status, headers, _ = self.submit("racer_01", GOOD_PW)
        self.assertEqual(status, 303)
        self.assertRegex(headers["Location"], r"^/registered\?license=\d+$")

        conn = self.db()
        try:
            # The real proof: the game's login query finds exactly one row.
            self.assertEqual(
                sbol_db.count_login_matches(conn, "racer_01", GOOD_PW), 1)
        finally:
            conn.close()

    def test_confirmation_page_shows_the_license(self):
        _, headers, _ = self.submit("racer_01", GOOD_PW)
        status, _, body = self.request("GET", headers["Location"])
        self.assertEqual(status, 200)
        self.assertIn("Account created", body)

    def test_duplicate_username_is_refused_case_insensitively(self):
        self.submit("racer_01", GOOD_PW)
        status, _, body = self.submit("RACER_01", GOOD_PW)
        self.assertEqual(status, 400)
        self.assertIn("already taken", body)
        conn = self.db()
        try:
            count = conn.execute("SELECT COUNT(*) AS n FROM account_data").fetchone()
            self.assertEqual(count["n"], 1)
        finally:
            conn.close()

    def test_invalid_input_is_reported_and_stores_nothing(self):
        status, _, body = self.submit("x", "short", email="nope")
        self.assertEqual(status, 400)
        self.assertIn("could not be created", body)
        conn = self.db()
        try:
            count = conn.execute("SELECT COUNT(*) AS n FROM account_data").fetchone()
            self.assertEqual(count["n"], 0)
        finally:
            conn.close()

    def test_mismatched_confirmation_refused(self):
        status, _, body = self.submit("racer_01", GOOD_PW, confirm="somethingelse1")
        self.assertEqual(status, 400)
        self.assertIn("do not match", body)

    def test_entered_values_survive_an_error(self):
        status, _, body = self.submit("racer_01", "short", email="keep@me.com")
        self.assertEqual(status, 400)
        self.assertIn('value="racer_01"', body)
        self.assertIn('value="keep@me.com"', body)

    def test_missing_csrf_token_refused(self):
        status, _, body = self.request(
            "POST", "/register",
            body=urlencode({"username": "racer_01", "password": GOOD_PW,
                            "confirm": GOOD_PW, "email": "a@b.com"}),
            headers={"Content-Type": "application/x-www-form-urlencoded"})
        self.assertEqual(status, 400)
        self.assertIn("session expired", body)

    def test_forged_csrf_token_refused(self):
        status, _, body = self.submit("racer_01", GOOD_PW,
                                      overrides={"csrf": "forged.deadbeef"})
        self.assertEqual(status, 400)
        self.assertIn("session expired", body)

    def test_honeypot_field_blocks_submission(self):
        status, _, body = self.submit("racer_01", GOOD_PW,
                                      overrides={"website": "http://spam.example"})
        self.assertEqual(status, 400)
        self.assertIn("automated", body)

    def test_unsigned_timestamp_refused(self):
        status, _, body = self.submit("racer_01", GOOD_PW,
                                      overrides={"ts": "1700000000.notasignature"})
        self.assertEqual(status, 400)
        self.assertIn("automated", body)

    def test_oversized_body_refused(self):
        status, _, _ = self.request(
            "POST", "/register", body="x" * (webapp.MAX_BODY_BYTES + 1),
            headers={"Content-Type": "application/x-www-form-urlencoded"})
        self.assertEqual(status, 400)

    def test_html_in_input_is_escaped(self):
        status, _, body = self.submit("<script>alert(1)</script>", GOOD_PW)
        self.assertEqual(status, 400)
        self.assertNotIn("<script>alert(1)</script>", body)
        self.assertIn("&lt;script&gt;", body)


class TestApiRegistration(ServerCase):
    def test_creates_an_account(self):
        status, payload = self.api_register(
            {"username": "api_user", "password": GOOD_PW, "email": "a@b.com"})
        self.assertEqual(status, 201)
        self.assertTrue(payload["ok"])
        self.assertIsInstance(payload["license"], int)

        conn = self.db()
        try:
            self.assertEqual(sbol_db.count_login_matches(conn, "api_user", GOOD_PW), 1)
        finally:
            conn.close()

    def test_reports_validation_errors(self):
        status, payload = self.api_register(
            {"username": "x", "password": "short", "email": "nope"})
        self.assertEqual(status, 400)
        self.assertFalse(payload["ok"])
        self.assertGreaterEqual(len(payload["errors"]), 3)

    def test_rejects_invalid_json(self):
        status, _, body = self.request(
            "POST", "/api/register", body="{not json",
            headers={"Content-Type": "application/json"})
        self.assertEqual(status, 400)
        self.assertFalse(json.loads(body)["ok"])

    def test_privileges_cannot_be_injected(self):
        """255 is full admin; a client must not be able to ask for it."""
        status, payload = self.api_register(
            {"username": "sneaky", "password": GOOD_PW,
             "email": "a@b.com", "privileges": 255})
        self.assertEqual(status, 201)
        conn = self.db()
        try:
            row = conn.execute(
                "SELECT privileges FROM account_data WHERE license = ?",
                (payload["license"],)).fetchone()
            self.assertEqual(row["privileges"], 0)
        finally:
            conn.close()

    def test_sql_injection_in_username_is_inert(self):
        self.api_register({"username": "a'; DROP TABLE account_data; --",
                           "password": GOOD_PW, "email": "a@b.com"})
        conn = self.db()
        try:
            self.assertTrue(sbol_db.has_account_table(conn))
        finally:
            conn.close()


class TestUsernameLookup(ServerCase):
    def test_reports_available_then_taken(self):
        status, _, body = self.request("GET", "/api/username-available?u=racer_01")
        self.assertEqual(status, 200)
        self.assertTrue(json.loads(body)["available"])

        self.submit("racer_01", GOOD_PW)
        _, _, body = self.request("GET", "/api/username-available?u=RACER_01")
        self.assertFalse(json.loads(body)["available"])

    def test_invalid_username_is_unavailable_with_a_reason(self):
        _, _, body = self.request("GET", "/api/username-available?u=CON")
        payload = json.loads(body)
        self.assertFalse(payload["available"])
        self.assertIn("reason", payload)


class TestRateLimiting(ServerCase):
    config_overrides = {"registrations_per_hour": 2}

    def test_registration_is_rate_limited_per_address(self):
        self.assertEqual(self.submit("racer_01", GOOD_PW)[0], 303)
        self.assertEqual(self.submit("racer_02", GOOD_PW)[0], 303)
        status, _, body = self.submit("racer_03", GOOD_PW)
        self.assertEqual(status, 429)
        self.assertIn("Too many registrations", body)

    def test_api_rate_limit_sets_retry_after(self):
        for name in ("api_01", "api_02"):
            self.api_register({"username": name, "password": GOOD_PW,
                               "email": "a@b.com"})
        status, headers, _ = self.request(
            "POST", "/api/register",
            body=json.dumps({"username": "api_03", "password": GOOD_PW,
                             "email": "a@b.com"}),
            headers={"Content-Type": "application/json"})
        self.assertEqual(status, 429)
        self.assertIn("Retry-After", headers)


class TestProxyHandling(ServerCase):
    def test_forwarded_header_ignored_without_trusted_proxy(self):
        """Otherwise anyone could rotate the header to bypass rate limits."""
        self.assertEqual(self.submit("racer_01", GOOD_PW)[0], 303)
        self.assertEqual(self.submit("racer_02", GOOD_PW)[0], 303)
        # Default config allows 5/hour; spoofing must not reset the bucket.
        for i in range(3, 6):
            self.submit("racer_%02d" % i, GOOD_PW)
        cookie, csrf, ts = self.get_form()
        status, _, _ = self.request(
            "POST", "/register",
            body=urlencode({"csrf": csrf, "ts": ts, "website": "",
                            "username": "racer_09", "email": "a@b.com",
                            "password": GOOD_PW, "confirm": GOOD_PW}),
            headers={"Content-Type": "application/x-www-form-urlencoded",
                     "Cookie": cookie, "X-Forwarded-For": "10.9.9.9"})
        self.assertEqual(status, 429)


if __name__ == "__main__":
    unittest.main()
