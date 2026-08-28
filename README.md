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

1) PVP/PVE Battles  (working in Offline, issues in Online - check the note below)
2) Teams creation and their functionality  
3) Packets (some are unassigned)
4) Sound (BGM is too loud, and car sounds are inaudible regardless of ini settings)
5) When in SAFEMODE, after switching tabs to other than the game it tends to still catch the keypresses causing the car to constantly hit/spin
6) Create a short functionality documentation based on packets (what is responsible for what action)
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
You need to leave from the last junction in the c1 to get out of the "Beginner" rank. Battles are disabled for beginners. 

--------------

There's also a decompiled file of the game itself - match the packets, check for missmatches. 


--------------

How are objects placed onto the maps (instances)?


--------------

The time attack routes A/B are similiar, but only one displays sections, time, start and finish. For time attack A it's safe to set the reward time at 4:10 for now, as it rewards the player with CP and EXP which are necessary. Check why B isn't loading.

--------------

As of now, if I was to set a number of NPC Rivals it's an amount that spawns when the player enters the course. Could it be possible to make them spawn in randomly or actively in a X drawing distance of the player? 
