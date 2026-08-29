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
URGENT TO CHECK/FIX; 
---------------
OVERALL: CHECK // TODO [...] MARKS. ACT ACCORDINGLY
---------------
1) PVP/PVE Battles - randomize the rewards. CP/EXP are based on rival's level with a multiplier applied - but after beating 11 rivals the EXP rewards are identical. Since it's based on NPC level, check if there's a ladder for their levels or are they all the same? Random tickets (items) can drop, but so far they seem to be repetitive - anytime a player wins the reward is a car ticket for a Toyota Trueno.
2) Teams creation and their functionality - This also needs a webpage for user registration and teams creation/management. So far it can be done by commands in cmd/powershell ("SBOL Battle Server.exe" /createaccount). Database is set on SQLite. When entering TEAM CENTER, there's a message "Agree to TA Terms to continue". Presumably, these were also available on genki's webpage but there's no traces of that. 
3) Packets (some are unassigned)
     - On the online version when you leave beginner it connects to the server again without a password so fails to authenticate. But if you close game and login again it'll enter the main course. There's 2 calls to the 0x100 packets one for initial connect and another for reconnect. So some reason it doesn't send the packet with the password the 2nd time
4) Sound (BGM is too loud, and car sounds are inaudible regardless of ini settings). Check for compatibility if imported from games like Tokyo Xtreme Racer 0.
5) When in SAFEMODE, after switching tabs to other than the game it tends to still catch the keypresses causing the car to constantly hit/spin
6) Create a short functionality documentation based on packets (what is responsible for what action)
7) EXP Rewards for completing time attacks based on times(for times under 4:10min)
8) Beaten rivals (NPC) should appear in different color on the map, iirc blue arrow - not yet beaten, green - battle won, yellow - battle lost.
9) NPC AI - current NPC's are very weak when it comes to their driving - there's no difficulty at all. TXR games get their fame from being difficult in battles. This needs to be changed, either by rewriting their algorythm or by importing AI's from a game like TXR0
10) NPC ruleset/requirements/spawns: NPC's should spawn on routes according to the ones in gangs JSON file (battle server -> rivals). routeTable could be the course, like C1, and courseID could be inner/outer. NPCs have their requirements that the player has to meet in order to battle them; for gang leaders, it's (ex.) to beat all previous gang members. Wanderers (rare rivals) have their own rulesets, that should be set individually as per wanderer - ex. player has to be driving said car, or desired drivetrain, tires etc.
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
