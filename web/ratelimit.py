"""A small in-process token bucket, keyed by client IP.

Correct for a single-process server, which is how this is meant to run. If it is
ever put behind multiple workers each worker gets its own buckets and the
effective limit multiplies -- the README says so, and the fix would be a shared
store.
"""

import threading
import time


class TokenBucket:
    def __init__(self, capacity, refill_seconds, clock=time.monotonic):
        """Allow ``capacity`` events, refilling one slot every ``refill_seconds``."""
        self.capacity = float(capacity)
        self.refill_seconds = float(refill_seconds)
        self.clock = clock
        self._buckets = {}
        self._lock = threading.Lock()

    def _prune(self, now):
        # Drop fully-refilled buckets so an attacker cycling IPs cannot grow this
        # dictionary without bound.
        stale = self.capacity * self.refill_seconds
        for key, (tokens, stamp) in list(self._buckets.items()):
            if now - stamp > stale:
                del self._buckets[key]

    def allow(self, key):
        """Consume one token for ``key``. Returns True if it was available."""
        now = self.clock()
        with self._lock:
            if len(self._buckets) > 4096:
                self._prune(now)
            tokens, stamp = self._buckets.get(key, (self.capacity, now))
            tokens = min(self.capacity, tokens + (now - stamp) / self.refill_seconds)
            if tokens < 1.0:
                self._buckets[key] = (tokens, now)
                return False
            self._buckets[key] = (tokens - 1.0, now)
            return True

    def retry_after(self, key):
        """Whole seconds until one token is available, for the Retry-After header."""
        now = self.clock()
        with self._lock:
            tokens, stamp = self._buckets.get(key, (self.capacity, now))
            tokens = min(self.capacity, tokens + (now - stamp) / self.refill_seconds)
        if tokens >= 1.0:
            return 0
        return int((1.0 - tokens) * self.refill_seconds) + 1
