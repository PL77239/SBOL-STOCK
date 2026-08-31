The current version (2.0.3.1b) is the 'SpeedMaster' update. The version before that had PA's (Parking Areas, like Daikoku, Shibaura) that the players could access.
Inside, it was a social hub with chat - players could trade, chat, or go from the PA to desired shops. 
This entire system was replaced in the SpeedMaster update, main change being getting rid of PAs as a "garage"/instance, and instead introducing ramps/exits to car/parts shop courses. They also switched to gameswf.
However, the textures are still in the game's directory: .../data/TEX -> BUIL.MIA contains textures of PAs (and objects like vending machines, trees).
3D models can also be found in .../data/COURSE/PACK -> here, since BUIL.MIA has an id of 8 (iirc) the pack should be 0800.
Parking Areas were "static" spaces, not driveable maps. There are no photos of them, though this is the only logical explanation considering these textures. 
Create one PA (where there's a "free" exit/ramp slot, like Daikoku, Tatsumi or Heiwajima (heiwa were the names of textures for Heiwajima PA) as a garage-like instance, where players can join to see each others cars (from front-view perspective like in Garage), use the chat.
Unless you find the actual way they worked, this seems optimal. 
There are overall 22 Courses - 1-8 are taken, 8 being EVENT and 9-21 UNKNOWN. 22 is Beginner Course (a fallback i assume). Event only works when toggled. But, since the server and db are written from ashes, all of this needs to be implemented.
The repo also contains the client's .exe.c which should help creating packets for that.
