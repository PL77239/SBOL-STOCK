#include "rival.h"
#include "TicketTables.h"
#include "RouteTables.h"
#include "RivalTables.h"
#include <iostream>

Rival::Rival()
{
	Initialize();
	m_Client = nullptr;
}

Rival::Rival(Client* Client, int32_t RivalID)
{
	// TODO: To load Rival table and set data from table
	Initialize();
	m_Client = Client;
	SetRivalID(RivalID);
}

Rival::~Rival()
{
}

void Rival::Random(int32_t Difficulty)
{
	// total rival count in RandomRivals table
	int maxRandomRivals = sizeof(RandomRivals) / sizeof(RIVALDATA);

	if (maxRandomRivals > 0)
	{
		// randomly select a rival from the RandomRivals table (0 to maxRandomRivals - 1)
		int randomIndex = rand() % maxRandomRivals;

		// TODO: optionally, filter by Difficulty level if needed

		// copy the selected rival's data into this Rival instance
		memcpy(&settings, &RandomRivals[randomIndex], sizeof(RIVALDATA));
	}
}

void Rival::SetName(std::string& Name)
{
	// Rival name must not match a players handle so add a hidden character to start and the end
	size_t nameLength = min(16, Name.length());
	settings.name[0] = '\t';
	memcpy(&settings.name[1], Name.c_str(), nameLength);
	settings.name[nameLength + 1] = '\t';
}

bool Rival::SetRivalID(int32_t RivalID)
{
	if (!m_Client || !m_Client->server)
		return false;

	settings.rivalID = RivalID;

	RIVALDATA* rd = m_Client->server->GetRivalData(RivalID);
	if (rd == nullptr)
		return false;

	memcpy(&settings, rd, sizeof(settings));
	return true;
}

void Rival::SpaceTick(uint32_t part, uint32_t total)
{
	uint32_t routeTableSize = 0;
	switch (settings.routeTable)
	{
	case 0:
		routeTableSize = sizeof(NPC_Position_C1_Outer) / 6;
		break;
	case 1:
		routeTableSize = sizeof(NPC_Position_C1_Inner) / 6;
		break;
	case 2:
		routeTableSize = sizeof(NPC_Position_Loop1_Outer) / 6;
		break;
	case 3:
		routeTableSize = sizeof(NPC_Position_Loop1_Inner) / 6;
		break;
	case 4:
		routeTableSize = sizeof(NPC_Position_Loop2_Outer) / 6;
		break;
	case 5:
		routeTableSize = sizeof(NPC_Position_Loop2_Inner) / 6;
		break;
	case 6:
		routeTableSize = sizeof(NPC_Position_Loop3_Outer) / 6;
		break;
	case 7:
		routeTableSize = sizeof(NPC_Position_Loop3_Inner) / 6;
		break;
	default:
		routeTableSize = 0;
		break;
	}

	tick = (routeTableSize / total) * part;
}

void Rival::Tick()
{
	uint32_t routeTableSize = 0;
	int16_t* routeTablePtr = nullptr;
	switch (settings.routeTable)
	{
	case 0:
		routeTableSize = sizeof(NPC_Position_C1_Outer) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_C1_Outer;
		break;
	case 1:
		routeTableSize = sizeof(NPC_Position_C1_Inner) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_C1_Inner;
		break;
	case 2:
		routeTableSize = sizeof(NPC_Position_Loop1_Outer) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_Loop1_Outer;
		break;
	case 3:
		routeTableSize = sizeof(NPC_Position_Loop1_Inner) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_Loop1_Inner;
		break;
	case 4:
		routeTableSize = sizeof(NPC_Position_Loop2_Outer) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_Loop2_Outer;
		break;
	case 5:
		routeTableSize = sizeof(NPC_Position_Loop2_Inner) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_Loop2_Inner;
		break;
	case 6:
		routeTableSize = sizeof(NPC_Position_Loop3_Outer) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_Loop3_Outer;
		break;
	case 7:
		routeTableSize = sizeof(NPC_Position_Loop3_Inner) / 6;
		routeTablePtr = (int16_t*)&NPC_Position_Loop3_Inner;
		break;
	default:
		routeTableSize = 0;
		break;
	}
	if (routeTablePtr == nullptr) return;
	tick += Rival_AUTOPILOT_SPEED;
	tick %= routeTableSize;
	position.location1 = routeTablePtr[(tick * 3) + 0];
	position.location2 = routeTablePtr[(tick * 3) + 1];
	position.location3 = routeTablePtr[(tick * 3) + 2];
	position.time = timeGetTime();
}

uint32_t Rival::WinCP(float distance, bool firsttime, float boost)
{
	uint32_t CP = settings.cp * (firsttime ? 4 : 3);
	CP += (uint32_t)(distance / 1000.0f) * 10;
	CP = (uint32_t)((float)CP * (boost + 1.0f));
	return CP;
}

uint32_t Rival::LoseCP(float distance, bool firsttime, float boost)
{
	uint32_t CP = 0;
	CP += (uint32_t)(distance / 1000.0f) * 10;
	CP = (uint32_t)((float)CP * (boost + 1.0f));
	return CP;
}

int16_t Rival::WinReward(float boost)
{
	int16_t ticket = CarTicket();

	// if rivals car has a ticket that can be obtained, return it
	if (ticket != -1)
	{
		return ticket;
	}

	// no reward available
	return -1;
}

int16_t Rival::LoseReward(float boost)
{
	// No reward for losers
	return -1;
}

void Rival::Initialize()
{
	ready = false;
	ZeroMemory(&settings, sizeof(settings));
	settings.rivalID = -1;
	ZeroMemory(&position, sizeof(position));
	reward = 0;
	tick = 0;
}

int16_t Rival::CarTicket()
{
	// Does rivals car have a ticket that can be obtained?

	if (settings.carID < (sizeof(CARTICKET_LOOKUP) / sizeof(int16_t)))
	{
		return CARTICKET_LOOKUP[settings.carID];
	}

	// No requirments met
	return -1;
}

uint32_t Rival::WinXP(float distance, uint32_t remainingSP)
{
	// 5 points per level
	uint32_t baseXP = settings.level * 8;

	// if leader, double the base XP
	if (settings.leader)
	{
		baseXP *= 2;
	}

	uint32_t XP = baseXP;

	// bonus for remaining SP, scaled by base XP
	XP += (uint32_t)(((float)baseXP / 100000.0f) * (float)remainingSP);

	// bonus for distance, 2 XP per km
	XP += (uint32_t)(distance / 1000.0f) * 2;

	return XP;
}

uint32_t Rival::LoseXP(float distance)
{
	// lose exp values 
	// npc level (ex. 20 EXP for 20lv npc) + 1 EXP per km
	uint32_t XP = settings.level;
	XP += (uint32_t)(distance / 1000.0f) * 1;

	return XP;
}