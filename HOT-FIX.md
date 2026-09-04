Read PR's for latest changes and updates. Check readme.md. Act accordingly;

--------

There currently is a bug, where when a player wins a certain amount of races against NPCs from various teams, the rival arrows no longer change to green (status:won), and the wins may/may not save. When pressing the DATA button (which displays data, like wins, rivals, teams) the client crashes, only showing Error for Socket 10053 (client-server packets).

This happens irregularly. On top of that, some cars appear blank and only the NPC tag is visible above the "invisible" vehicle. When flashing lights at the invisible car, the client crashes. You may need to compare team/rival id's from /data. 
  - IMPORTANT REMARK: Packets can only be 64K. Higher values may cause crashing. It's possible that this happens because of hard-coded valeus instead of readable (0x0xxx).
--------
All of this has dependencies between SERVER and DB SERVER. 

================================================================================
FIXED. Rebuild BOTH "SBOL Battle Server" and "SBOL DB Server". SBOL_Dll is unchanged.
================================================================================

It was three separate faults, not one. Two of them ride on the same packet, 0x0480.

--------------------------------------------------------------------------------
1) THE ARROWS, AND THE DATA BUTTON KILLING THE CONNECTION
--------------------------------------------------------------------------------

Root cause: `Server::LoadRivalFile` put the member's *global* id into
`TEAMDATA::memberID`, which is the field the client reads out of the 0x0480 join
packet.

The ids in `SBOL Battle Server/data/rivals/*.json` are unique across the whole set -
ROLLING GUY is 0 - 7, ROWING GUY 8 - 15, ROLLING KIDS 16 - 23, on up to TEAM DOREMI at
232 - 239. The client wants the slot *within* the team, 0 - 7. It ships `teamnames`
with 42 teams and `teamhandles` with 336 = 42 x 8 rival names (data/lang-en.json), and
its own copy of the rival records is 100 rows of 24 bytes: 4 bytes of team id, 4
spare, then 16 status bytes.

What the client does with the number, from the decompile:

  0x0042e8f0   arrow colour lookup. Refuses memberID >= 0x10 and returns null, so no
               colour gets applied. Teams 0 and 1 were the only ones under 16 - which
               is exactly "the arrows stop turning green once you start beating other
               teams".
  0x0042e980   battle result. Writes the status at row + 8 + memberID with NO range
               check, so memberID 16 and up runs off the end of the row and into the
               NEXT row's team id. Beat ROLLING KIDS and the team id of the row after
               it gets overwritten with a 1 or a 2.

The DATA screen then asks the server for the records of the team ids in those rows.
The corrupted ones come back as nonsense, `Client::SendRivalRecords` found an id past
the 100 the records hold, and called `Disconnect()` - and that is the socket 10053 the
client reports. Nothing was wrong with the account; the server hung up on it.

Fixed in two places:

  - `Server::LoadRivalFile` stores `id % 8` in `TEAMDATA::memberID`, which is the slot
    the client wants and the value the server's own `setRivalStatus` was already
    reducing to. `rivalID` is still `teamID * 8 + slot`, unchanged.
  - `Client::SendRivalRecords` no longer disconnects. An id it has no row for - a
    player team, or a client that corrupted its own table before the update - is
    answered with an empty record and one line in the log. It also stops trusting the
    request blindly: a short packet is dropped rather than read past its end.

A client that got corrupted before the fix repairs itself. Those rival records are RAM
only, never saved, and are rebuilt from the server's reply the next time DATA is
opened. Nothing to reset in the database.

--------------------------------------------------------------------------------
2) THE INVISIBLE CARS WITH AN NPC TAG, AND THE CRASH ON FLASHING LIGHTS
--------------------------------------------------------------------------------

Root cause: NPC and player course IDs overlapped.

The client keeps ONE entity table per course and indexes it directly with the id in
the 0x0480 packet - 0x00440d00 for an NPC, 0x00445e30 for a player, both write to
`table[id]` and neither range checks. The table is sized from the three limits the
server declares in the 0x0380 course info packet, summed at 0x0043a2f0:
rival + liveview + player.

`Course::addClient` handed players `slot + 0x10`. That was safe while `getRivals()`
spawned 15 NPCs, which is what it did originally. It was raised to 40, so NPC ids
0 - 39 started landing on top of players 0x10 - 0x27. Whichever arrived second
overwrote the other in the client's table: the tag off one entity, no car off the
other. Flashing your lights at it sends 0x0500 or 0x0504 depending on what the client
thinks it is, against a half replaced entity, and the client goes down.

`COURSE_NPC_LIMIT` was 100 at the same time, so `ClientPacketBattle`'s 0x0504 handler
("is this ID an NPC?") would happily accept a player's ID as a rival.

Fixed: the split is now one constant in globals.h.

    COURSE_NPC_LIMIT        40   rival IDs 0x00 .. 0x27
    COURSE_PLAYER_ID_BASE        first player ID, = COURSE_NPC_LIMIT
    COURSE_PLAYER_LIMIT     200  player IDs 0x28 .. 0xEF

`getRivals()` caps its spawn count at COURSE_NPC_LIMIT, `Course::addClient` bases
players on COURSE_PLAYER_ID_BASE, and the 0x0380 packet keeps declaring both, so the
client allocates 40 + 40 + 200 = 280 slots for a highest id of 239. Still 40 NPCs on
the road, they just no longer collide. If you raise the NPC count, raise
COURSE_NPC_LIMIT with it and nothing else needs touching.

--------------------------------------------------------------------------------
3) "THE WINS MAY/MAY NOT SAVE"
--------------------------------------------------------------------------------

`battle.isNPC` was set true when you challenged a rival and only ever cleared by the
60 second battle timeout. `clearBattle()` did not reset it and the PvP challenge path
did not set it false, so after your first race against an NPC the flag stayed on for
the rest of the session. Every PvP result after that went down the NPC arm of
`processBattleWin` / `processBattleLose`, where `currentRival` is null, and fell out
the bottom: no win counted, no EXP, nothing to save.

Fixed: `clearBattle()` clears `isNPC`, and both PvP challenge paths set it false.

Also fixed while in there: `clearRivals()` now clears `currentRival`. The rival list
is dropped whenever the player leaves the course - shop, parking area, anything -
which left the battle holding a pointer into a freed vector for the next 0x0505 to
dereference.

--------------------------------------------------------------------------------
4) THE TEAM/RIVAL ID COMPARISON YOU ASKED FOR
--------------------------------------------------------------------------------

There is a second way into the same corruption, and it is what "compare team/rival
id's from /data" points at.

The client decides whether a battle was against a rival or against a player by the
opponent's team id: below 10000 it is a rival team, at or above it is a player
(0x0042e980). `team_data` autoincremented from 1, straight through the game's own
rival teams 0 - 41. A player in team 3 would have every PvP battle against them filed
into the LITTLE GANG row of everyone else's RIVAL LIST.

Fixed for new databases: `team_data`'s autoincrement is seeded to PLAYER_TEAMID_BASE
(10000) when the DB server creates the table. The battle server logs an error at login
for any account already in a team below that.

If you already have teams in sbol.db, renumber them once:

    UPDATE team_data       SET teamid = teamid + 10000;
    UPDATE account_data    SET teamid = teamid + 10000 WHERE teamid IS NOT NULL;
    UPDATE teamgarage_data SET teamid = teamid + 10000;
    UPDATE sqlite_sequence SET seq = (SELECT MAX(teamid) FROM team_data)
        WHERE name = 'team_data';

--------------------------------------------------------------------------------
ON THE 64K REMARK
--------------------------------------------------------------------------------

Worth being precise about, because it is not what was happening here.

`CLIENT_BUFFER_SIZE` is 8192, not 64000 - see globals.h, the 64000 line is commented
out. The largest packet any of this touches is the 0x0C81 reply, 7 + 100 x 17 = 1707
bytes at its absolute worst, so nothing on this path was ever near a size limit. The
DATA button's 10053 was the server calling `Disconnect()`, not an oversized packet.

The hazard the remark describes is real and is still open as known issue 3:
`Server::Send` disconnects the client outright when an outgoing packet exceeds the
buffer, and `PACKET::append` silently drops the tail rather than failing, so an
oversized packet turns into a truncated one whose size field lies. The biggest thing
on the wire is the auth record from the DB server at roughly 3.9 KB, and it grows by
26 bytes per team member - a team of about 160 would overflow it. Worth a bound before
teams go live.

One genuine hard-coded-offset bug did turn up next door: `PACKET::set` and
`SERVERPACKET::set` ignored their `offset` argument and wrote at the cursor instead.
The only caller is `Course::sendRacerPositions`, patching up the racer count in the
0x0780 course broadcast, so that count sat permanently at 0 and other players' map
blips were never updated from it. Fixed in both packet classes - worth watching on the
first run, since it turns a broadcast back on that has been inert.

--------------------------------------------------------------------------------
NOT COMPILED
--------------------------------------------------------------------------------

These are MSVC/Windows sources and no compiler was available where the fix was
written. Build both server projects before deploying, and check the two things that
are cheapest to verify in game:

  - beat a ROLLING KIDS or LITTLE GANG member, then press DATA. The connection should
    hold and the arrow should be green.
  - put two accounts on the main course at once and look for blank cars.
