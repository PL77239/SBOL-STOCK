This repo represents the game "Shutokou Battle Online" made by Genki and ran throughout 2002-2005. Heavily server-sided.
It was primarly a MMO game based on MPS (MassPlayerSystem). There is also Blowfish for decyphering MPS in this repo.

It is currently set to localhost - to set it up on a server, change the IP and settings in the SERVERS.INI for the server's sided ones. There was also one line with "localhost" in the csproj, which when left unchanged disabled entering shops and other courses for other players. Might have to be changed to the server's IP too. 

Since the server was never publicly documented, a lot of functionality is trimmed from the game as of now. The freeroam works, along with car-shops, parts-shops, Time attack A/B and all the other "spots".
Team Area/Center is half-baked in the vsproj, but setting teams up required doing so in a webpage. Player also had to be lvl 10 or higher to create a team. Registration was also webpage-sided, therefore apart from the game itself, a webpage (even local for now) has to be set up to make it possible to create teams and register users. 
---------------

- SBOL-Battle-Server: This is the server. It contains majority of the packets, scripts and dependencies
- SBOL-DB-Server:     This is the DataBase for items, accounts, garage etc.
- Game (main folder): This is the game .exe. There is also an .exe.c (decompiled) to find dependencies and connections for packets. 
- SBOL-Dll:           Contains patches and improvements for graphics and sound mainly. 
- MPS-Blowfish:       This deciphers the MPS.
- Offline.dll:        This file has to be deleted in order to play online. Has a lot of fixes (like only 2 cars to choose from when starting as a new player, survival arena as an endurance race etc.) 
---------------
FIXED - the CP balance sticking at 999,999,999. Reported as: CP turns to -1, the game shows a 999,999,999 balance at each login, after one win it reads "win: 35CP, total: 34CP", it rises again on the next win, then jumps back to 999,999,999 on returning to the garage or entering a new course. Cause: `Client::giveCP` treated a reward of 0 as an overflow and set the balance to `_I64_MAX`, and `Rival::LoseCP` returns 0 for any battle shorter than a kilometre, so a single short loss broke the account for good. The number was never actually -1: the client renders anything from 1,000,000,000 up as the 999,999,999 cap, and the battle result screen adds the reward to the low 32 bits only, which is where the 34 came from. `giveCP` now ignores non-positive rewards and clamps to `CP_LIMIT` (999,999,999), and `setCP` clamps on load so accounts already broken in the database come back into a displayable range. Reset a wrecked balance with `!set cp <amount>` in game, or `UPDATE account_data SET cp = 0 WHERE license = <id>;`.
The rival half of the same report - ROLLING GUY showing as defeated with green arrows, wins against other teams not registering in the RIVAL LIST, the arrow staying blue after a win - is fixed too, see known issue 8 below.
---------------
FIXED - the HOT-FIX.md report: rival arrows stuck blue past ROWING GUY, the DATA button dropping the connection with socket error 10053, blank cars carrying an NPC tag, and PvP wins not being recorded. Three separate causes - the member id sent to the client in the 0x0480 join packet was the global one instead of the 0 - 7 in-team slot, NPC course IDs (0 - 39) overlapped player course IDs (0x10 and up) after the NPC spawn count was raised to 40, and `battle.isNPC` was never cleared so every PvP result after your first NPC race was silently dropped. Full write-up, including the client addresses it was traced through and the SQL to renumber existing teams, is in HOT-FIX.md. Both the battle server and the DB server have to be rebuilt.
---------------
OVERALL: CHECK // TODO [...] MARKS. ACT ACCORDINGLY
---------------
PARKING AREAS (PA)

Restored as static social rooms. Not a driveable course - the original never was one either.

What the client still has: game mode 0x1F (PARKINGAREA) in the scene factory at 0x004272F0,
12 backdrops (pa_bg001..012 in data/TEX/pa_bg.MIA), 11 place thumbnails (pa_wmp01..11 in
data/TEX/pa_new.MIA), 7 hub icons, data/BGM/parking.ogg, the help strings (table at
0x0064da00, entry 26 is the PA place picker) and the English lines for all of it in
data/lang-en.json. What the SpeedMaster update deleted was the PA hub *movie* out of
data/interface/KFD.SSS, along with the main menu's "Go to PA" button - `BID_MM_MOVE_PA`
appears in the client's button enum but in none of the archive's 30 movies.

So players are warped into mode 0x1B (MAINMENU_PA) instead, the in-PA menu variant whose
movie does still ship. Everything the hub used to link to is still reachable from there:
the ranking screen, Team Center, the Tuned Car Exchange and the shops.

Usage, in game chat:

    !pa                 list the areas and how many people are in each
    !pa <number|name>   travel to one
    !pa who             who else is in this one
    !pa leave           back to the main menu

Entering an area takes you off whatever course you were on, and scopes your chat to the
room - the people in it see what you type, the drivers outside do not. Battles block travel.

Names and place ids live in `SBOL Battle Server/data/parkingareas.json`, which is optional;
without it eleven generic names are used. The place ids default to 0x09..0x13 because that
is what the client's own junction table at 0x00444a1a assigns to these eleven places. The
real-world names (Daikoku, Tatsumi, Heiwajima and so on) are not stored anywhere in the
client, so they ship generic - enter each area, look at the backdrop, and rename it in the
JSON.

The warp rides on server -> client packet 0x0482, which SBOL_Dll already implemented for
shop entry. Its handler now reads a target game mode out of the high 16 bits of the place
field, so the same packet can reach either the shops (0x1A, the old behaviour when those
bits are zero) or a PA (0x1B). Rebuild both the battle server and SBOL_Dll.

NOT DONE, in full, with the addresses and the experiments worth running first:
docs/PARKING-AREAS.md. The short version is that warping to 0x1B rather than 0x1F means the
12 backdrops are never drawn - you get the room and the chat, over the ordinary main menu
background - and that fixing it needs the hub movie rebuilt as a SWF6 and appended to
KFD.SSS. Other players' cars are not drawn either; the original did not draw them.

---------------
KNOWN ISSUES:

1) PVP/PVE Battles - randomize the rewards. CP/EXP are based on rival's level with a multiplier applied - but after beating 11 rivals the EXP rewards are identical. Since it's based on NPC level, check if there's a ladder for their levels or are they all the same? Random tickets (items) can drop, but so far they seem to be repetitive - anytime a player wins the reward is a car ticket for a Toyota Trueno.
2) Teams creation and their functionality - This also needs a webpage for user registration and teams creation/management. Registration is now DONE - see the `web` folder for a self-service signup site and JSON API; accounts it creates are byte-identical to the CLI ones. The CLI is still there as a fallback, and note it is the DB server, not the battle server, that owns it: ("SBOL DB Server.exe" /createaccount username password email privileges). Database is set on SQLite. Teams are still open: in-game team creation actually works already (0x1201 in ClientPacketTeam.cpp), what's missing is the team list, join requests and accept-join (0x120D / 0x120F / 0x1205 are stubbed). When entering TEAM CENTER, there's a message "Agree to TA Terms to continue". Presumably, these were also available on genki's webpage but there's no traces of that. One thing to know before teams go live: the client reads a battle opponent's team id and treats anything below 10000 as one of the game's own rival teams (0x0042e980), so a player team numbered from 1 has its PvP results filed into the RIVAL LIST rows of teams 0 - 41. `team_data`'s autoincrement is now seeded to `PLAYER_TEAMID_BASE` (10000) on creation; any team already below that has to be renumbered, SQL in HOT-FIX.md.
3) Packets (some are unassigned)
     - On the online version when you leave beginner it connects to the server again without a password so fails to authenticate. But if you close game and login again it'll enter the main course. There's 2 calls to the 0x100 packets one for initial connect and another for reconnect. So some reason it doesn't send the packet with the password the 2nd time. Single packet send has a max size of 64k. Sometimes the client crashes with a socket error 10054, potentially due to a oversize? When compiling, there are several errors for sizing, ex. "Invalid data read from careerdata.rivalStatus: the read size is 1200, but the number of bytes read is: TeamID.". This is caused by setting hard number limits - it was implemented for debugging, but all this needs to be adressed. Note the buffer is 8192 (`CLIENT_BUFFER_SIZE`), not 64000 - the 64000 line in globals.h is commented out - and nothing on the rival or DATA path comes close to it; the 10053 reported against the DATA button was the server calling `Disconnect()`, not an oversized packet. What is still open here is that `Server::Send` disconnects on an oversized packet and `PACKET::append` silently drops the tail instead of failing, so an oversized packet becomes a truncated one whose size field lies. The auth record from the DB server is the biggest thing on the wire at roughly 3.9 KB and grows by 26 bytes per team member, so a team of around 160 would overflow it - bound it before teams go live.
4) Sound (BGM is too loud, and car sounds are inaudible regardless of ini settings). Check for compatibility if imported from games like Tokyo Xtreme Racer 0.
5) When in SAFEMODE, after switching tabs to other than the game it tends to still catch the keypresses causing the car to constantly hit/spin
6) Create a short functionality documentation based on packets (what is responsible for what action)
7) EXP Rewards for completing time attacks based on times(for times under 4:10min)
8) Beaten rivals (NPC) should appear in different color on the map, iirc blue arrow - not yet beaten, green - battle won, yellow - battle lost. DONE - the 0x480 join packet's flag byte was hardcoded to 0, so every NPC stayed blue; it is now derived from the stored rival status (bit 6 green for a win, bit 7 red for a loss - the client only documents green and red, not yellow). The arrow is also refreshed at the end of an NPC battle by re-issuing the rival, since the colour is fixed at join time. Related: `Client::SendRivalRecords` read the requested team IDs with `addOffset` on a stale packet offset, so the RIVAL LIST was built from whatever bytes happened to be at that position - usually zeros, which reported every entry as team 0 (ROLLING GUY) and hid wins against every other team. It now uses `setOffset(0x05)`. Second pass, see HOT-FIX.md: the arrows still refused to go green for anything past ROWING GUY because `Server::LoadRivalFile` put the member's global id (ROLLING KIDS is 16 - 23, TEAM DOREMI 232 - 239) into `TEAMDATA::memberID`, and the client uses that as the slot index into its own 24 byte rival record row - the colour lookup at 0x0042e8f0 rejects anything from 16 up, and the battle result writer at 0x0042e980 does not range check it at all, so 24 and up wrote over the next row's team id. It now stores `id % 8`. `SendRivalRecords` also no longer disconnects a client that asks about a team it has no row for, which is what the DATA button dying with socket 10053 actually was.
9) NPC AI - current NPC's are very weak when it comes to their driving - there's no difficulty at all. TXR games get their fame from being difficult in battles. This needs to be changed, either by rewriting their algorythm or by importing AI's from a game like TXR0
10) NPC ruleset/requirements/spawns: NPC's should spawn on routes according to the ones in gangs JSON file (battle server -> rivals). routeTable could be the course, like C1, and courseID could be inner/outer. NPCs have their requirements that the player has to meet in order to battle them; for gang leaders, it's (ex.) to beat all previous gang members. Wanderers (rare rivals) have their own rulesets, that should be set individually as per wanderer - ex. player has to be driving said car, or desired drivetrain, tires etc. The online version only has NPC's on C1, as their "line" was no yet recorded on other routes. They are recorded (with coordinates) in the offline.dll, which would have to be decompiled to take that data out; To create a route you need to log the junction, distance and marker values from the 0x700 packets.
---------------
PvE/PvP (note from the private server creator):

0x0400 is the packets that tell other players of status changes
But I use them also to mark the player as in course and leaving
Rival and player battle code is working in those repos
However I'm not handling packets right in that release
The client has a send and receive buffer of 64k and it wraps. So you need to ensure when the client requests a smaller packet size you need to only send that and add it to the next packet
This is the same for sending and receiving
It's common in games but I overlooked it and it causes a lot of issues
So fairly easy to fix
You need to leave from the last junction in the c1 to get out of the "Beginner" rank. Battles are disabled for beginners and admins.

--------------

There's also a decompiled file of the game itself - match the packets, check for missmatches. 


--------------

How are objects placed onto the maps (instances)?


--------------

The time attack routes A/B are similiar, but only one displays sections, time, start and finish. For time attack A it's safe to set the reward time at 4:10 for now, as it rewards the player with CP and EXP which are necessary. Check why B isn't loading. For A - if user reaches time under 3:30, grant a random item. 

--------------

Check the actual game engine limit for NPCs on track. NPCs are user-based and invisible to others, vice-versa. 

--------------
RUNNING THE REGISTRATION WEBSITE (web/)

The `web` folder is a self-service signup site + JSON API, so players can make their own accounts instead of you running "SBOL DB Server.exe" /createaccount for every single person. It writes straight into the same sbol.db the DB server uses, in the exact same format, so an account made on the site works in the game immediately.

Needs Python 3.8 or newer and NOTHING else. No pip install, no virtualenv, no node. It's standard library only, on purpose - one less thing to break on the server box.

1) FIRST TIME SETUP

Start "SBOL DB Server.exe" once and let it create sbol.db with all its tables. The website does not create the schema, it only inserts accounts into an existing database.

Then, in the web folder:

    copy config.example.json config.json          (cp on Linux)

Open config.json and set two things:

    "database"    path to sbol.db. Relative paths are resolved from the web folder,
                  so the default "../sbol.db" already points at the repo root where
                  the DB server puts it. Use a full path if yours lives elsewhere.

    "secret_key"  generate one and paste it in:
                      python -c "import secrets;print(secrets.token_hex(32))"
                  If you leave it empty the server makes a temporary one at startup,
                  which works, but every restart invalidates forms people currently
                  have open and they get "your session expired".

Everything else in the file has sane defaults, see below.

2) RUNNING IT

    cd web
    python app.py

Then open http://127.0.0.1:8080/ - that's the signup page. Logs go to web/log/web.log and to the console.

To stop it, Ctrl+C.

If you just want to poke at the site without running any of the Windows binaries, you can make an empty database with only the accounts table:

    python app.py --init-db

Other flags: --config <file> to point at a different config, --host and --port to override the address for a one-off run.

3) CHECKING IT WORKS

    curl http://127.0.0.1:8080/healthz

Should give {"ok": true}. If it doesn't, it can't reach the database - check the path in config.json.

Make a test account from the command line:

    curl -X POST http://127.0.0.1:8080/api/register -H "Content-Type: application/json" -d "{\"username\":\"testguy\",\"password\":\"hunter2hunter2\",\"email\":\"a@b.com\"}"

You get back {"ok": true, "license": N}. Now log into the game with testguy / hunter2hunter2. If that works, you're done - that's the only test that proves the whole chain.

Run the test suite any time with:

    cd web
    python -m unittest discover -s tests -t .

68 tests, takes about 15 seconds. They check the password hashing matches the C++, that the rows come out identical to CLI-made ones, and the whole HTTP surface.

4) PUTTING IT ONLINE

Important: this uses Python's built-in http.server. It is fine behind a proxy but it is NOT meant to sit directly on the open internet. Leave "host" as 127.0.0.1 and put a real web server in front of it for HTTPS. Caddy is the least effort, the whole config is:

    sbol.example.com {
        reverse_proxy 127.0.0.1:8080
    }

nginx or IIS work the same way. Once you do that, set "trusted_proxy": true in config.json so the rate limiter can see the real visitor IP from the X-Forwarded-For header.

Do NOT set trusted_proxy to true if the service is reachable directly - anyone can fake that header and walk straight past the rate limits. That's why it's off by default.

To keep it running on the Windows box, wrap it with NSSM or a Task Scheduler task set to "run whether user is logged on or not". On Linux, a small systemd unit.

5) SPAM CONTROL

Out of the box each IP gets 5 registrations per hour and 30 username checks per minute, with a server-wide ceiling of 200 signups per hour. All three are in config.json (registrations_per_hour, lookups_per_minute, global_registrations_per_hour). There's also a hidden honeypot field and a minimum form fill time, which stops the lazy bots without dragging in a captcha service.

If you get hammered, drop registrations_per_hour to 1 or 2 and lower the global ceiling.

Note the limits are counted in memory, so restarting the service resets them, and running more than one copy of it would multiply the effective limit.

6) SHARING sbol.db WITH THE RUNNING SERVER

Two programs writing one SQLite file. The website turns on WAL mode and waits up to 5 seconds if the file is locked, and it only holds the lock for a single INSERT. Tested against a simulation of the DB server's access pattern at 20 writes a second while registering non-stop: no failures on either side.

Two things to know:

- WAL does not work if sbol.db is on a network share. If yours is, set "wal": false in config.json.
- The C++ side (Database::ExecSqlite) throws away SQLite's return code, so in the unlikely event the DB server ever does lose a write to a lock, it won't tell you. Adding sqlite3_busy_timeout(sqliteDb, 5000); after the open in Database::OpenSqlite() is cheap insurance. Not urgent based on the measurements, but worth doing eventually.

7) WHAT PLAYERS SEE

They pick a username (3-20 chars, letters/numbers/underscore/hyphen), an email and a password. That's it. The driver name is NOT chosen on the website - that still happens in-game on first login, same as always. The confirmation page tells them to rename offline.dll and where to go from the Beginner course.

Usernames are restricted to that character set because the client makes a folder per account under user/<username>/, so anything Windows won't accept as a folder name would break the client. Reserved names like CON, NUL, COM1 are blocked for the same reason.

8) IF SOMETHING GOES WRONG

"Database not found" on startup - the path in config.json is wrong, or the DB server hasn't been run yet to create sbol.db.

"Your session expired" when submitting the form - the service restarted between loading the page and submitting it, or secret_key is empty. Set a permanent secret_key.

"Your submission looked automated" - the form was submitted faster than min_form_seconds (default 2). If you're testing with curl, set min_form_seconds to 0 in config.json.

Account created but the game won't accept the login - check the account exists with the right case, and remember the game truncates usernames at 20 characters. See web/README.md for the full breakdown of the storage format.

Full documentation, including exactly how the password hashing and blob storage match the C++, is in web/README.md.
