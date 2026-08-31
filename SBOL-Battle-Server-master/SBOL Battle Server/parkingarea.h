#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include "globals.h"
#include "packet.h"
#include "Logger.h"

class Client;

// A Parking Area is a static social instance, not a driveable course.
//
// The client still carries the whole thing: game mode 0x1F (PARKINGAREA) in the scene
// factory at 0x004272F0, the 12 backdrops in data/TEX/pa_bg.MIA, the 11 place thumbnails
// pa_wmp01..pa_wmp11 in data/TEX/pa_new.MIA, and data/BGM/parking.ogg. What the
// SpeedMaster update removed was the hub *movie* from data/interface/KFD.SSS, so we send
// players to mode 0x1B (MAINMENU_PA) instead - the in-PA menu variant, whose movie does
// still ship. Everything the hub used to link to (ranking, team centre, TCE, the shops)
// is reachable from there.
//
// The warp itself is server -> client packet 0x0482, which SBOL_Dll already implements in
// patch.cpp: it writes the place id to the client global at 0x006F64C0 and calls
// WarpToScreen(app, 0x14, mode). See Client::SendParkingAreaWarp for the encoding.
typedef struct st_parkingarea_entry {
	uint32_t placeID;		// Written to the client's place global (0x006F64C0)
	std::string name;		// Shown in chat and in !pa list
} PARKINGAREA_ENTRY;

class ParkingArea
{
private:
	int32_t index;						// 0-based slot, also the pa_wmp thumbnail number - 1
	PARKINGAREA_ENTRY entry;
	std::vector<Client*> areaClient;
public:
	ParkingArea();
	~ParkingArea();
	Logger* logger;

	void setIndex(int32_t in) { index = in; };
	int32_t getIndex() { return index; };
	void setEntry(PARKINGAREA_ENTRY& in) { entry = in; };
	uint32_t getPlaceID() { return entry.placeID; };
	std::string& getName() { return entry.name; };

	uint32_t getClientCount();
	int32_t addClient(Client* in);
	void removeClient(Client* in);
	int32_t findClient(Client* in);
	Client* findClient(int32_t driverslicense);
	int32_t getFree();
	void getMemberHandles(std::vector<std::string>& out);

	void sendToArea(PACKET* src, int32_t exclude = -1);
	void sendToClient(PACKET* src, int32_t driverslicense);
};
