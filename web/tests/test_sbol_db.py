"""The compatibility tests. If these fail, accounts created here cannot log in."""

import os
import sqlite3
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import sbol_db


class TempDB(unittest.TestCase):
    def setUp(self):
        fd, self.path = tempfile.mkstemp(suffix=".db")
        os.close(fd)
        conn = sqlite3.connect(self.path)
        conn.execute(sbol_db.SCHEMA_ACCOUNT_DATA)
        conn.commit()
        conn.close()
        self.conn = sbol_db.connect(self.path)

    def tearDown(self):
        self.conn.close()
        for suffix in ("", "-wal", "-shm"):
            try:
                os.unlink(self.path + suffix)
            except OSError:
                pass


class TestHashFormat(unittest.TestCase):
    def test_known_vector(self):
        # Independently computed: SHA256("GENKIWHYYOUDOTHIS?.test"), uppercased.
        # This is the exact string Server::CreateAccount builds in the C++.
        self.assertEqual(
            sbol_db.hash_password("test"),
            "EE97E8ECE098CC280F3FAB0AFAE14555838E89D3F6F72024B17AAF5DAF077F83")

    def test_hash_is_uppercase_hex(self):
        # HexString() uses sprintf("%02X"), so lowercase would never match.
        digest = sbol_db.hash_password("another-password")
        self.assertEqual(digest, digest.upper())
        self.assertEqual(len(digest), 64)

    def test_username_key_matches_hex_lower(self):
        self.assertEqual(sbol_db.username_key("Bob"), "626F62")


class TestStorageFormat(TempDB):
    def test_username_and_email_are_blobs(self):
        # The C++ writes X'<hex>' literals, so the storage class must be BLOB.
        sbol_db.register_account(self.conn, "racer", "hunter2hunter2", "a@b.com")
        row = self.conn.execute(
            "SELECT typeof(username), typeof(email), typeof(password) FROM account_data"
        ).fetchone()
        self.assertEqual(tuple(row), ("blob", "blob", "text"))

    def test_privileges_default_to_zero(self):
        # 255 is full admin; registration must never grant anything.
        sbol_db.register_account(self.conn, "racer", "hunter2hunter2", "a@b.com")
        row = self.conn.execute("SELECT privileges FROM account_data").fetchone()
        self.assertEqual(row["privileges"], 0)

    def test_license_is_assigned(self):
        first = sbol_db.register_account(self.conn, "one", "hunter2hunter2", "a@b.com")
        second = sbol_db.register_account(self.conn, "two", "hunter2hunter2", "c@d.com")
        self.assertIsInstance(first, int)
        self.assertGreater(second, first)


class TestLoginCompatibility(TempDB):
    """Replays the game's own login query against rows we wrote."""

    def test_registered_account_can_log_in(self):
        sbol_db.register_account(self.conn, "racer", "hunter2hunter2", "a@b.com")
        # The DB server requires exactly one match (results.size() == 1).
        self.assertEqual(
            sbol_db.count_login_matches(self.conn, "racer", "hunter2hunter2"), 1)

    def test_login_is_case_insensitive_on_username(self):
        sbol_db.register_account(self.conn, "RaCeR", "hunter2hunter2", "a@b.com")
        self.assertEqual(
            sbol_db.count_login_matches(self.conn, "racer", "hunter2hunter2"), 1)

    def test_wrong_password_does_not_match(self):
        sbol_db.register_account(self.conn, "racer", "hunter2hunter2", "a@b.com")
        self.assertEqual(
            sbol_db.count_login_matches(self.conn, "racer", "wrongpassword"), 0)

    def test_raw_login_sql_from_the_cpp(self):
        """Use the literal SQL shape from Packets/ClientAuthPackets.cpp."""
        sbol_db.register_account(self.conn, "Driver_9", "hunter2hunter2", "a@b.com")
        username_hex = sbol_db.username_key("driver_9")
        password_hex = sbol_db.hash_password("hunter2hunter2")
        sql = ("SELECT * FROM account_data WHERE HEX(LOWER(username)) = '%s' "
               "AND password = '%s'" % (username_hex, password_hex))
        self.assertEqual(len(self.conn.execute(sql).fetchall()), 1)


class TestDuplicatePrevention(TempDB):
    """Guards against the account-bricking bug present in the CLI path."""

    def test_exact_duplicate_rejected(self):
        sbol_db.register_account(self.conn, "racer", "hunter2hunter2", "a@b.com")
        with self.assertRaises(sbol_db.AccountExists):
            sbol_db.register_account(self.conn, "racer", "otherpassword", "c@d.com")

    def test_case_variant_duplicate_rejected(self):
        """Server::CreateAccount allows this; it must never happen here.

        If both "Bob" and "bob" existed, the login query would match two rows,
        the DB server's results.size() == 1 check would fail, and both accounts
        would be permanently locked out.
        """
        sbol_db.register_account(self.conn, "Bob", "hunter2hunter2", "a@b.com")
        with self.assertRaises(sbol_db.AccountExists):
            sbol_db.register_account(self.conn, "bob", "hunter2hunter2", "c@d.com")

    def test_username_taken_is_case_insensitive(self):
        sbol_db.register_account(self.conn, "Bob", "hunter2hunter2", "a@b.com")
        self.assertTrue(sbol_db.username_taken(self.conn, "bob"))
        self.assertTrue(sbol_db.username_taken(self.conn, "BOB"))
        self.assertFalse(sbol_db.username_taken(self.conn, "bobby"))

    def test_the_two_row_state_would_break_login(self):
        """Demonstrates why the case-insensitive check matters.

        Insert the collision directly, the way the CLI would, and show that
        login then matches two rows and is therefore refused.
        """
        for name in ("Bob", "bob"):
            self.conn.execute(
                "INSERT INTO account_data (username, password, email, privileges) "
                "VALUES (?, ?, ?, 0)",
                (name.encode("latin-1"), sbol_db.hash_password("hunter2hunter2"),
                 b"a@b.com"))
        self.assertEqual(
            sbol_db.count_login_matches(self.conn, "bob", "hunter2hunter2"), 2)


class TestRollback(TempDB):
    def test_failed_registration_leaves_no_row(self):
        sbol_db.register_account(self.conn, "racer", "hunter2hunter2", "a@b.com")
        with self.assertRaises(sbol_db.AccountExists):
            sbol_db.register_account(self.conn, "RACER", "hunter2hunter2", "c@d.com")
        count = self.conn.execute("SELECT COUNT(*) AS n FROM account_data").fetchone()
        self.assertEqual(count["n"], 1)
        # The failed attempt must not have left a transaction open.
        self.assertFalse(self.conn.in_transaction)


if __name__ == "__main__":
    unittest.main()
