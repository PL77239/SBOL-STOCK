# Parking Areas - what works, what is missing

Status of the PA feature added on `feature/pa`. Everything below was established by reading
the shipped client statically. Nothing in this document has been confirmed against a running
game, because the feature has not been built or run yet.

Addresses are client VAs in `SBClient.exe` (image base `0x400000`).

---

## What the client still has

The SpeedMaster update did not remove the Parking Area. It removed its user interface.

| Piece | Where | State |
|---|---|---|
| `PARKINGAREA` game mode `0x1F` | scene factory `0x004272F0`, ctor `FUN_004ad0c0`, 0xdf0 bytes | intact |
| 12 backdrops `pa_bg001`..`pa_bg012` | `data/TEX/pa_bg.MIA` | intact |
| 11 place thumbnails `pa_wmp01`..`pa_wmp11` | `data/TEX/pa_new.MIA` | intact |
| 7 hub icons `pa_icon1`..`pa_icon7` | `data/TEX/pa_new.MIA` | intact |
| Music | `data/BGM/parking.ogg`, playlist 7 in `SBOL_Dll/patch.cpp` | intact |
| Button enum incl. `BID_MM_MOVE_PA` | table at `0x005B6114`, 548 entries, 40-byte stride | intact |
| Help strings, incl. id 26 "select where to move to inside the PA" | table at `0x0064DA00`, 190 entries | intact |
| English translations for all of the above | `data/lang-en.json` | intact |
| Ranking / Team Center / TCE / shop screens | movies 23, 26, 27 and others in `data/interface/KFD.SSS` | intact |
| **The PA hub movie** | `data/interface/KFD.SSS` | **deleted** |
| **The main menu's "Go to PA" button** | `data/interface/KFD.SSS` | **deleted** |

`KFD.SSS` is a chain of 30 SWF6 movies with the `FWS` signature swapped for `SSS`. None of
them contains `BID_MM_MOVE_PA`, `BID_PA_COM_SELPLACE`, `BID_PA_TAB_MOVE`, `BID_PA_RANKING`,
`BID_PA_INFO` or `BID_PA_SHOP_ENTRANCE`, compressed or plain.

## What the branch adds

Server-side rooms. `ParkingArea` container, 11 rooms of 50, membership and presence,
chat scoped to the room, `!pa` / `!pa <number|name>` / `!pa who` / `!pa leave`, names and
place ids in `data/parkingareas.json`. The warp rides the existing `0x0482` packet, whose
`SBOL_Dll` handler now takes a target game mode from the high 16 bits of the place field.

---

## Missing, in order of how much it matters

### 1. There are no PA visuals

This is the big one, and it is a direct consequence of warping to `0x1B` (`MAINMENU_PA`)
instead of `0x1F` (`PARKINGAREA`).

The client keeps the room and the menu in separate scenes. The room scene draws the place;
the menu scene is the overlay you open while standing in it. Their texture sets say so
plainly:

- `PARKINGAREA` (`0x1F`) loads `Wheel, pa_bg, qo_all, pa_new, pa_tce, pa_team, gr_new,
  pa_shop, i_box, in_sml, in_big, i_icon, chat, all`
- `TEAM_SPACE` (`0x20`) loads the same set **plus** `ts`
- `MAINMENU` / `MAINMENU_PA` / `MAINMENU_TS` (`0x1A`/`0x1B`/`0x1C`) load only
  `lg_all, all, chat, mm_new`

`MAINMENU_PA` never loads `pa_bg`. So a player who travels to a Parking Area today gets a
working social room - correct occupants, scoped chat, the right shops reachable - while
looking at the ordinary main menu background. The twelve backdrops are never drawn.

`0x1B` was chosen because `0x1F` would construct the room scene and then ask for a hub movie
that is no longer in the archive. What that actually does - blank screen, or a crash - is
untested. See "Experiments worth running" below; this is the single highest-value unknown in
the whole feature.

### 2. The hub movie

The screen with the seven icons (Car Shop, Parts Shop, Item Shop, Tuned Car Exchange,
Ranking, Team, Info) and the `SELPLACE` picker built from `pa_wmp01`..`11`.

Rebuilding it means authoring a SWF6 movie that gameswf can parse, firing the `BID_PA_*`
FSCommands the exe still handles, and appending it to `KFD.SSS`. The container format is
understood - `SSS` + version byte + `uint32` body length, members concatenated - so appending
is mechanical. Authoring the movie is not.

Until this exists, `0x1F` stays unreachable and item 1 stands.

### 3. Other players' cars are not drawn

Requested during design, and worth being clear about: the original did not do this either.
The PA scene object is `0xdf0` bytes, smaller than the garage's `0xe88`, with no per-player
array anywhere in it. Its one 100-entry table is the ranking board. Social contact in the
original PA was the chat window and the rankings, not a car park full of other people's cars.

Adding it is new client-side rendering in a scene never built for it - an `SBOL_Dll` patch,
and the most likely thing in this list to destabilise the client.

### 4. The ranking board has no server behind it

Movie 23 still ships, with `BID_PA_RANK_PAGE_L/R`, `BID_PA_RANK_SCR_UP/DOWN`,
`BID_PA_TAB_TOPRANK` and the "Top 1000" string. The battle server has nothing that answers
it. `careerdata.ranking` is a single per-player number handed over by the DB server at auth;
there is no leaderboard query, and the packet that feeds the board has not been identified.

### 5. The Tuned Car Exchange returns an empty list

`Client::SendTunedCarPurchaseList` (`client.cpp`) replies to `0x20C` with car count `0`. The
screen opens and is empty. Selling into it (`BID_PA_TCE_SELL_CAR_CHOICE_ENTRY`) has no
server-side storage at all.

### 6. The place ids and the names are both guesses

The eleven default place ids `0x09`..`0x13` come from the junction table at `0x00444a1a`,
which maps highway junctions onto places. That block assigns exactly eleven consecutive ids,
and the client ships exactly eleven place thumbnails, which is strong but circumstantial.

Two things follow, and neither is verified:

- **Ordering.** That place `0x09` is thumbnail 1, `0x0A` is thumbnail 2 and so on is an
  assumption. The real order may be anything.
- **Names.** No PA name exists anywhere in the client. The only identifiers are texture names
  in `BUIL.MIA` - `heiwa_PA_00_m1_nog`, `n_tatu_wc`, `n_tatu_zihanki`, `daikoku`,
  `sibaura256` - and those are roadside scenery drawn as you drive past, not tied to a place
  id. The areas therefore ship numbered. Rename them in `data/parkingareas.json` once
  someone has entered each one and looked at it.

### 7. There is no in-game way in

Travel is a chat command. The original entry points - `BID_MM_MOVE_PA` on the main menu and
the highway junctions that map to PA place ids - are both unavailable: the first because the
button is not in the shipped movie, the second because it needs the room scene from item 1.

### 8. None of it has been compiled

Written in an environment with no C++ compiler at all. The diff was reviewed by hand and
brace-balance checked, nothing more. Both the battle server and `SBOL_Dll` need rebuilding,
and the whole feature needs a first run.

---

## Smaller gaps and rough edges

- **Packet-set drift.** The incoming packet mask is driven by the client's own requests:
  `0x208` (enter car shop) calls `enableShopPackets`, `0x210` (returning to highway) calls
  `enableCoursePackets`. A player who opens a shop from inside a PA and backs out can flip
  themselves to the course packet set while still in the room. Chat (`0x06`) is enabled in
  every set, so `!pa leave` always works, but other packets may be dropped in that state.
- **No beginner gating.** Beginners can travel. The original PA was a post-beginner feature.
- **No persistence.** PA membership is not saved. Reconnecting puts you nowhere, which is
  probably the behaviour you want, but it is untested and undecided rather than designed.
- **No admin tooling.** No way to kick someone from a room, broadcast into one room, or take
  a room out of service.
- **Travel mid-drive.** `!pa` can be typed at speed on the highway. The server ejects the
  client from the course and warps the scene. Whether the client's state machine copes with a
  scene change mid-drive is untested.
- **Leaving.** `!pa leave` warps to `0x1A` with the place set to the client's own "nowhere"
  value `0xFFFFFFFF`. From there the player uses the normal menu to get back onto C1, which
  goes through `joinCourse` and drops the PA membership cleanly.

---

## Experiments worth running

In rough order of information gained per minute, once the branch builds:

1. **Warp to `0x1F` instead of `0x1B`.** One constant in `Client::EnterParkingArea`
   (`GAMEMODE_MAINMENU_PA` -> `0x1F`). If the room scene comes up with a backdrop and merely
   lacks buttons, item 1 collapses to a much smaller problem and item 2 becomes optional
   rather than blocking. If it crashes, that is worth knowing cheaply and early.
2. **Vary the place id** across `0x00`..`0x14` and note which backdrop each one produces.
   That settles item 6's ordering question and may reveal which places are PAs at all.
3. **Check whether chat input is usable** in `MAINMENU_PA`. The scene loads `chat.MIA` and
   `BID_MM_CONFIG_OPENCHAT` exists, so it should be, but if it is not then `!pa leave` is
   unreachable from inside a room and players are stuck until they rejoin a course.
4. **Open a shop from inside a PA** and confirm the shop packets are accepted, then back out
   and confirm the room and its chat are still intact.

---

## Reference

Extracted while investigating, useful for any of the above:

- Game mode table, from the mode-name switch at `0x00427090`:
  `0x15` WARNING, `0x16` LOGIN, `0x17` LOGIN_OK, `0x18` FIRST_PLAY_MENU, `0x19` GARAGE,
  `0x1A` MAINMENU, `0x1B` MAINMENU_PA, `0x1C` MAINMENU_TS, `0x1E` NEWGARAGE (no factory
  case - dead), `0x1F` PARKINGAREA, `0x20` TEAM_SPACE, `0x21` RACE.
- Texture archive ids, table at `0x006949B8`, 34 entries: `8` Buil, `9` Exit, `10` Wheel,
  `13` all, `14` chat, `17` qo_all, `18` mm_new, `20` gr_new, `21` pa_bg, `22` pa_new,
  `25` pa_tce, `26` pa_team, `27` pa_shop, `32` ts.
- Button id enum: `0x005B6114`, 548 entries, 40-byte stride, terminated by `BID_NON`.
- Help string ids: `0x0064DA00`, 190 entries. Id 26 is the PA place picker.
- Place global: `0x006F64C0`. App object: `0x006EBDD0`. Scene switcher: `0x004272F0`,
  message `0x14` changes mode.
- Junction to place map: `0x00444A1A` onwards.
