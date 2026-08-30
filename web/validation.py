"""Input rules for registration.

Every limit here traces back to something in the game or server code rather than
being a taste decision:

* Username max 20 -- the battle server truncates with
  ``username = in.substr(0, 20)`` (client.cpp), and the credential field is 0x14
  bytes wide in ``ManagementServer::SendCheckCredentials``. A longer name would
  silently become a different name at login.
* Username charset and reserved names -- the client creates a folder per account
  under ``user/<username>/`` (see the existing user/adm, user/janko), so the name
  must be a legal Windows directory name.
* ASCII only -- ``Server::ToNarrow`` truncates wide chars to their low byte, so
  anything outside ASCII round-trips unpredictably between the CLI and here.
"""

import re

USERNAME_MIN = 3
USERNAME_MAX = 20
PASSWORD_MIN = 8
PASSWORD_MAX = 32
EMAIL_MAX = 254

USERNAME_RE = re.compile(r"^[A-Za-z0-9_-]+$")
EMAIL_RE = re.compile(r"^[^@\s]+@[^@\s.]+(\.[^@\s.]+)+$")

# Names Windows refuses to use as a directory, which would break user/<username>/.
WINDOWS_RESERVED = {
    "con", "prn", "aux", "nul",
    *("com%d" % i for i in range(1, 10)),
    *("lpt%d" % i for i in range(1, 10)),
}

# Seeded by the DB server's checkDB() as the default admin row.
RESERVED_USERNAMES = {"sboladmin"}


def validate_username(username):
    errors = []
    if not username:
        return ["Username is required."]
    if len(username) < USERNAME_MIN or len(username) > USERNAME_MAX:
        errors.append(
            "Username must be between %d and %d characters."
            % (USERNAME_MIN, USERNAME_MAX)
        )
    if not USERNAME_RE.match(username):
        errors.append(
            "Username may only contain letters, numbers, underscores and hyphens."
        )
    lowered = username.lower()
    if lowered in WINDOWS_RESERVED:
        errors.append("That username is reserved by the operating system.")
    if lowered in RESERVED_USERNAMES:
        errors.append("That username is reserved.")
    return errors


def validate_password(password):
    errors = []
    if not password:
        return ["Password is required."]
    if len(password) < PASSWORD_MIN or len(password) > PASSWORD_MAX:
        errors.append(
            "Password must be between %d and %d characters."
            % (PASSWORD_MIN, PASSWORD_MAX)
        )
    if any(ord(c) < 0x20 or ord(c) > 0x7E for c in password):
        errors.append("Password may only contain printable ASCII characters.")
    return errors


def validate_email(email):
    errors = []
    if not email:
        return ["Email is required."]
    if len(email) > EMAIL_MAX:
        errors.append("Email address is too long.")
    if not EMAIL_RE.match(email):
        errors.append("Enter a valid email address.")
    try:
        email.encode("ascii")
    except UnicodeEncodeError:
        errors.append("Email address must be ASCII.")
    return errors


def validate_registration(username, password, confirm, email):
    """Return a dict of field -> list of error messages (empty dict when valid)."""
    errors = {}
    if u := validate_username(username):
        errors["username"] = u
    if p := validate_password(password):
        errors["password"] = p
    elif confirm is not None and password != confirm:
        errors["confirm"] = ["Passwords do not match."]
    if e := validate_email(email):
        errors["email"] = e
    return errors
