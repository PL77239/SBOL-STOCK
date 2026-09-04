Read PR's for latest changes and updates. Check readme.md. Act accordingly;

--------

There currently is a bug, where when a player wins a certain amount of races against NPCs from various teams, the rival arrows no longer change to green (status:won), and the wins may/may not save. When pressing the DATA button (which displays data, like wins, rivals, teams) the client crashes, only showing Error for Socket 10053 (client-server packets)
This happens irregularly. On top of that, some cars appear blank and only the NPC tag is visible above the "invisible" vehicle. You may need to compare team/rival id's from /data. 
  - IMPORTANT REMARK: Packets can only be 64K. Higher values may cause crashing. It's possible that this happens because of hard-coded valeus instead of readable (0x0xxx).
--------
All of this has dependencies between SERVER and DB SERVER. 
