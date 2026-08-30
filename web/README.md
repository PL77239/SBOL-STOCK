# SBOL account registration

A small web service that lets players create their own SBOL accounts, replacing
the manual

    "SBOL DB Server.exe" /createaccount <username> <password> <email> <privileges>

It writes directly into the same `sbol.db` that **SBOL DB Server.exe** uses, in a
format that is byte-for-byte identical to what that command produces, so an
account made on the website can be used to log into the game immediately.

**Standard library only** — no `pip install`, no virtualenv. Any Python 3.8+
will do.

---

## Quick start

```
copy config.example.json config.json      (cp on Linux)
```

Edit `config.json`:

* `database` — path to `sbol.db`. Relative paths resolve from this folder;
  the default `../sbol.db` assumes the repo layout.
* `secret_key` — generate one:
  `python -c "import secrets;print(secrets.token_hex(32))"`.
  Without it a temporary key is generated at startup and everyone's open forms
  break on restart.

Then:

```
python app.py
```

and open <http://127.0.0.1:8080/>.

The database must already exist — start `SBOL DB Server.exe` once and let it
create the schema. For local development without the Windows binaries,
`python app.py --init-db` creates an empty `sbol.db` containing just
`account_data`.

## Endpoints

| Method | Path | Purpose |
| --- | --- | --- |
| `GET` | `/register` | The signup form |
| `POST` | `/register` | Form submission |
| `POST` | `/api/register` | JSON `{username, password, email}` → `{ok, license}` |
| `GET` | `/api/username-available?u=NAME` | `{available: true\|false}` |
| `GET` | `/healthz` | Checks the database is reachable and `account_data` exists |

```
curl -X POST http://127.0.0.1:8080/api/register \
     -H 'Content-Type: application/json' \
     -d '{"username":"racer_01","password":"hunter2hunter2","email":"a@b.com"}'
```

## Deployment

`http.server` is not a hardened edge server. Keep `host` at `127.0.0.1` and put
a reverse proxy in front for TLS — Caddy is the least work:

```
sbol.example.com {
    reverse_proxy 127.0.0.1:8080
}
```

If you do, set `"trusted_proxy": true` so rate limiting reads `X-Forwarded-For`.
**Only enable it behind a proxy you control** — when the service is directly
reachable, any client can spoof that header and bypass the limits, which is why
it defaults to off.

Run it as a service with NSSM, Task Scheduler, or systemd. It logs to
`log/web.log` and stdout.

## Rate limiting

Per-IP token buckets, configurable: `registrations_per_hour` (5),
`lookups_per_minute` (30), and a server-wide `global_registrations_per_hour`
(200). Plus a hidden honeypot field and a minimum form-fill time
(`min_form_seconds`) to filter naive bots without a third-party captcha.

The buckets live in process memory, which is correct for the single-process
server this is. Running several workers would give each its own buckets and
multiply the effective limit; that would need a shared store.

## How compatibility is guaranteed

The formats are dictated by the existing C++ and the 2002 game client, not chosen
here. `sbol_db.py` documents each rule against the code it came from:

* **Password** — `SHA256("GENKIWHYYOUDOTHIS?" + "." + password)` as
  **uppercase** hex (`Server::GetHash` and `HexString`'s `%02X`).
  Unsalted, and it cannot be changed without breaking the game client.
* **Username / email** — stored as **BLOBs**, because the C++ writes them as
  `X'<hex>'` literals even though the columns are declared `TEXT`.
* **Username matching** — the game logs in with
  `WHERE HEX(LOWER(username)) = ? AND password = ?` and requires *exactly one*
  row, so matching is case-insensitive.
* **Privileges** — always `0`. 255 is full admin, and the value is never taken
  from user input.
* **Username rules** — 3–20 characters (the battle server truncates at
  `substr(0, 20)`), ASCII letters/digits/`_`/`-` only, no Windows reserved device
  names, because the client creates a folder per account at `user/<username>/`.

The driver name (`handle`) is **not** set here — players choose it in-game on
first login.

### Why registration rejects case-variant duplicates

`Server::CreateAccount` checks for duplicates case-*sensitively* while login
matches case-*insensitively*. The `UNIQUE` constraint stops exact repeats, but
not `Bob` versus `bob`. If both existed, the login query would match two rows,
the DB server's `results.size() == 1` check would fail, and **both accounts would
be permanently unable to log in**.

This service checks with the same case-insensitive predicate login uses, inside
one `BEGIN IMMEDIATE` transaction so two simultaneous signups cannot both pass.
`tests/test_sbol_db.py` covers this, including a test that demonstrates the
broken two-row state.

## Sharing sbol.db with the running server

Two processes write to one SQLite file. The service sets `journal_mode=WAL` and
a 5 second `busy_timeout`, and holds its write lock only for a single `INSERT`.

Measured against a simulation of the DB server's access pattern (open / exec /
close per packet, no busy timeout, ~20 writes/sec) while registering
continuously: **no failures on either side**. WAL only becomes significant under
synthetic hammering, where it cut the DB server's failure rate from 100% to 20%.

Two caveats:

* **WAL does not work on a network share.** If `sbol.db` lives on one, set
  `"wal": false`.
* `Database::ExecSqlite` in the C++ discards `sqlite3_exec`'s return code, so if
  the DB server *does* ever lose a write to a lock, it fails silently. Adding
  `sqlite3_busy_timeout(sqliteDb, 5000);` after the open in
  `Database::OpenSqlite()` is cheap insurance, though the measurements above
  suggest it is not urgent.

## Tests

```
python -m unittest discover -s tests -t .
```

68 tests, no dependencies. They cover the hash format against an independently
computed vector, storage classes, the duplicate-prevention logic, and the full
HTTP surface against a real server on a real socket. The key ones replay the
game's own login SQL against rows this service wrote.

## Not included

Web login, profile pages, and team management. In-game team creation already
works; what is missing there is team listing, join requests and accept-join
(`0x120D` / `0x120F` / `0x1205` in `ClientPacketTeam.cpp`, currently stubbed).
Email verification would need SMTP and a pending-accounts table, since
`account_data` has no `verified` column.
