import os
import sys
import unittest

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import ratelimit


class FakeClock:
    def __init__(self):
        self.now = 1000.0

    def __call__(self):
        return self.now

    def advance(self, seconds):
        self.now += seconds


class TestTokenBucket(unittest.TestCase):
    def setUp(self):
        self.clock = FakeClock()
        self.bucket = ratelimit.TokenBucket(3, 10.0, clock=self.clock)

    def test_allows_up_to_capacity_then_blocks(self):
        self.assertEqual([self.bucket.allow("ip") for _ in range(4)],
                         [True, True, True, False])

    def test_refills_over_time(self):
        for _ in range(3):
            self.bucket.allow("ip")
        self.assertFalse(self.bucket.allow("ip"))
        self.clock.advance(10.0)
        self.assertTrue(self.bucket.allow("ip"))

    def test_does_not_refill_beyond_capacity(self):
        self.bucket.allow("ip")
        self.clock.advance(10_000)
        self.assertEqual([self.bucket.allow("ip") for _ in range(4)],
                         [True, True, True, False])

    def test_keys_are_independent(self):
        for _ in range(3):
            self.bucket.allow("a")
        self.assertFalse(self.bucket.allow("a"))
        self.assertTrue(self.bucket.allow("b"))

    def test_retry_after_is_positive_when_blocked(self):
        for _ in range(3):
            self.bucket.allow("ip")
        self.assertFalse(self.bucket.allow("ip"))
        self.assertGreater(self.bucket.retry_after("ip"), 0)
        self.assertLessEqual(self.bucket.retry_after("ip"), 11)

    def test_retry_after_zero_when_allowed(self):
        self.assertEqual(self.bucket.retry_after("fresh"), 0)

    def test_prunes_stale_keys(self):
        for i in range(5000):
            self.bucket.allow("ip-%d" % i)
        self.clock.advance(10_000)
        self.bucket.allow("trigger")
        self.assertLess(len(self.bucket._buckets), 5000)


if __name__ == "__main__":
    unittest.main()
