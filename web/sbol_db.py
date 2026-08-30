"""Compatibility layer for the SBOL account database.

Everything here exists to write rows that ``SBOL DB Server.exe`` and the game
client will accept without modification. The formats are not our choice -- they
are dictated by the existing C++ code, and each rule below is traceable to it:

* Passwords are ``SHA256(HASH_SECRET + "." + password)`` stored as UPPERCASE hex.
  See ``Server::GetHash`` (server.cpp) and ``HexString`` (which uses "%02X").
* ``username`` and ``email`` are written by the C++ as ``X'<hex>'`` literals, so
  the stored values are BLOBs even though the columns are declared TEXT.
  Binding Python ``bytes`` produces exactly the same storage class.
* The game's login query is ``WHERE HEX(LOWER(username)) = ? AND password = ?``
  and requires EXACTLY ONE row (Packets/ClientAuthPackets.cpp). Login is
  therefore case-insensitive on the username.

That last point matters a great deal. ``Server::CreateAccount`` checks for
duplicates with a case-SENSITIVE comparison, so the CLI will happily create both
"Bob" and "bob" -- after which the login query matches two rows, the
``results.size() == 1`` check fails, and BOTH accounts are permanently unable to
log in. We deliberately use the same case-insensitive predicate that login uses,
inside a single ``BEGIN IMMEDIATE`` transaction, so we can never create that state.
"""

import hashlib
import sqlite3

# SBOL DB Server.h -- must match the C++ byte for byte or every password breaks.
HASH_SECRET = "GENKIWHYYOUDOTHIS?"

# Reproduced verbatim from SQLITE_STATEMENT_ACCOUNT_DATA in SBOL DB Server.h.
# Only used to build throwaway databases in tests and by --init-db; the real
# schema is created by the DB server itself.
SCHEMA_ACCOUNT_DATA = '''CREATE TABLE "account_data" (
\t`license`\tINTEGER NOT NULL,
\t`username`\tTEXT NOT NULL UNIQUE,
\t`password`\tTEXT NOT NULL,
\t`email`\tTEXT NOT NULL,
\t`joindate`\tTEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
\t`handle`\tTEXT,
\t`cp`\tINTEGER DEFAULT 0,
\t`level`\tINTEGER DEFAULT 1,
\t`points`\tINTEGER NOT NULL DEFAULT 0,
\t`playerwin`\tINTEGER NOT NULL DEFAULT 0,
\t`playerlose`\tINTEGER NOT NULL DEFAULT 0,
\t`rivalwin`\tINTEGER NOT NULL DEFAULT 0,
\t`rivallose`\tINTEGER NOT NULL DEFAULT 0,
\t`activecar`\tINTEGER,
\t`rank`\tINTEGER DEFAULT 0,
\t`privileges`\tINTEGER NOT NULL DEFAULT 0,
\t`teamid`\tINTEGER,
\t`teamarea`\tINTEGER DEFAULT 0,
\t`state`\tINTEGER NOT NULL DEFAULT 0,
\t`beginner`\tINTEGER DEFAULT 0,
\t`garagecount`\tINTEGER DEFAULT 0,
\t`garagedata`\tINTEGER,
\tPRIMARY KEY(`license`)
)'''


class AccountExists(Exception):
    """Raised when the username is already taken (case-insensitively)."""


class DatabaseBusy(Exception):
    """Raised when SQLite stayed locked past the busy timeout."""


def encode_text(value):
    """Encode a Python str the way the C++ ``Server::ToNarrow`` does.

    ToNarrow copies each wchar_t into a char, i.e. it keeps only the low byte.
    That is precisely latin-1. Validation restricts input to ASCII, so this is
    only ever exercised on the ASCII subset, but matching the C++ exactly means
    accounts made by the CLI and by this service are indistinguishable.
    """
    try:
        return value.encode("latin-1")
    except UnicodeEncodeError as exc:
        raise ValueError("value contains characters the game cannot store") from exc


def hash_password(plain):
    """SHA256(HASH_SECRET + "." + password) as uppercase hex, as the C++ stores it."""
    payload = encode_text(HASH_SECRET + "." + plain)
    return hashlib.sha256(payload).hexdigest().upper()


def username_key(username):
    """The value the game's login query compares against: HEX(LOWER(username))."""
    return encode_text(username.lower()).hex().upper()


def connect(path, wal=True, busy_timeout_ms=5000):
    """Open sbol.db for concurrent use alongside the running DB server.

    ``isolation_level=None`` puts us in autocommit mode so that we control
    transactions explicitly -- required for the BEGIN IMMEDIATE in
    :func:`register_account`.

    WAL is a persistent property of the database file, so enabling it here also
    affects SBOL DB Server.exe. That is the correct mode for two processes on one
    machine, but it does NOT work when the database lives on a network share,
    which is why it is configurable.
    """
    conn = sqlite3.connect(path, timeout=busy_timeout_ms / 1000.0, isolation_level=None)
    conn.row_factory = sqlite3.Row
    conn.execute("PRAGMA busy_timeout = %d" % int(busy_timeout_ms))
    if wal:
        conn.execute("PRAGMA journal_mode = WAL")
    return conn


def has_account_table(conn):
    row = conn.execute(
        "SELECT name FROM sqlite_master WHERE type = 'table' AND name = 'account_data'"
    ).fetchone()
    return row is not None


def username_taken(conn, username):
    """Case-insensitive existence check using the game's own login predicate."""
    row = conn.execute(
        "SELECT license FROM account_data WHERE HEX(LOWER(username)) = ?",
        (username_key(username),),
    ).fetchone()
    return row is not None


def count_login_matches(conn, username, password):
    """Replay the game's login query verbatim (ClientAuthPackets.cpp).

    Returns the number of matching rows. The DB server only accepts a login when
    this is exactly 1, so this is the ground truth for "can this account log in".
    """
    rows = conn.execute(
        "SELECT license FROM account_data "
        "WHERE HEX(LOWER(username)) = ? AND password = ?",
        (username_key(username), hash_password(password)),
    ).fetchall()
    return len(rows)


def register_account(conn, username, password, email):
    """Create an account and return its license number.

    The duplicate check and the INSERT run inside one BEGIN IMMEDIATE
    transaction. Without that, two simultaneous signups for the same name could
    both pass the check and both insert, producing the two-row state that locks
    players out permanently.

    ``privileges`` is hardcoded to 0 and is never taken from user input -- 255 is
    full admin in this schema.
    """
    try:
        conn.execute("BEGIN IMMEDIATE")
    except sqlite3.OperationalError as exc:
        raise DatabaseBusy(str(exc)) from exc

    try:
        if username_taken(conn, username):
            raise AccountExists(username)
        cur = conn.execute(
            "INSERT INTO account_data (username, password, email, privileges) "
            "VALUES (?, ?, ?, 0)",
            (encode_text(username), hash_password(password), encode_text(email)),
        )
        license_no = cur.lastrowid
        conn.execute("COMMIT")
        return license_no
    except sqlite3.OperationalError as exc:
        conn.execute("ROLLBACK")
        raise DatabaseBusy(str(exc)) from exc
    except Exception:
        conn.execute("ROLLBACK")
        raise
