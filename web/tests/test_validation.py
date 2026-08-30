import os
import sys
import unittest

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import validation

GOOD_PW = "hunter2hunter2"


class TestUsername(unittest.TestCase):
    def test_accepts_reasonable_names(self):
        for name in ("adm", "janko", "racer_01", "Wangan-Mid", "A" * 20):
            self.assertEqual(validation.validate_username(name), [], name)

    def test_length_bounds(self):
        # Max is 20 because the battle server truncates at substr(0, 20).
        self.assertTrue(validation.validate_username("ab"))
        self.assertTrue(validation.validate_username("A" * 21))

    def test_rejects_characters_illegal_in_a_windows_path(self):
        # The client creates user/<username>/, so these would break it.
        for name in ("bad name", "bad/name", "bad\\name", "bad:name", "bad*name",
                     "bad?name", 'bad"name', "bad<name", "bad>name", "bad|name",
                     "bad.name", "trailing."):
            self.assertTrue(validation.validate_username(name), name)

    def test_rejects_windows_reserved_device_names(self):
        for name in ("con", "CON", "nul", "com1", "LPT9", "aux", "prn"):
            self.assertTrue(validation.validate_username(name), name)

    def test_rejects_non_ascii(self):
        # ToNarrow truncates wide chars to their low byte, so these break login.
        for name in ("zażółć", "Ünter", "日本語"):
            self.assertTrue(validation.validate_username(name), name)

    def test_rejects_the_seeded_admin_account(self):
        self.assertTrue(validation.validate_username("sboladmin"))
        self.assertTrue(validation.validate_username("SBOLADMIN"))

    def test_rejects_empty(self):
        self.assertTrue(validation.validate_username(""))


class TestPassword(unittest.TestCase):
    def test_accepts_reasonable_passwords(self):
        for pw in ("hunter2hunter2", "a" * 32, "with spaces ok", "P@ssw0rd!"):
            self.assertEqual(validation.validate_password(pw), [], pw)

    def test_length_bounds(self):
        self.assertTrue(validation.validate_password("short"))
        self.assertTrue(validation.validate_password("a" * 33))

    def test_rejects_non_printable_and_non_ascii(self):
        for pw in ("has\ttab12345", "has\nnewline1", "zażółćgęśl1"):
            self.assertTrue(validation.validate_password(pw), repr(pw))


class TestEmail(unittest.TestCase):
    def test_accepts_ordinary_addresses(self):
        for addr in ("a@b.com", "first.last@example.co.uk", "x+tag@mail.example.org"):
            self.assertEqual(validation.validate_email(addr), [], addr)

    def test_rejects_malformed(self):
        for addr in ("", "nope", "no@domain", "two@@at.com", "spaces in@mail.com"):
            self.assertTrue(validation.validate_email(addr), repr(addr))

    def test_rejects_overlong(self):
        self.assertTrue(validation.validate_email("a" * 250 + "@example.com"))


class TestRegistrationForm(unittest.TestCase):
    def test_valid_input_produces_no_errors(self):
        self.assertEqual(
            validation.validate_registration("racer", GOOD_PW, GOOD_PW, "a@b.com"), {})

    def test_mismatched_confirmation(self):
        errors = validation.validate_registration("racer", GOOD_PW, "different1234", "a@b.com")
        self.assertIn("confirm", errors)

    def test_confirmation_skipped_when_none(self):
        # The JSON API has no confirm field.
        self.assertEqual(
            validation.validate_registration("racer", GOOD_PW, None, "a@b.com"), {})

    def test_reports_every_bad_field_at_once(self):
        errors = validation.validate_registration("x", "short", "short", "nope")
        self.assertEqual(set(errors), {"username", "password", "email"})


if __name__ == "__main__":
    unittest.main()
