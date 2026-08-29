#include "rival.h"
#include "TicketTables.h"
#include "RouteTables.h"
#include "RivalTables.h"
#include <iostream>
#include <random>

#define ARRAYCOUNT(x) (uint32_t)(sizeof(x) / sizeof((x)[0]))

namespace {
	// A ticket table is a struct of fixed size arrays, one per part category, padded with -1.
	struct TICKETCATEGORY {
		const int16_t* entries;
		uint32_t count;
	};
	const uint32_t TICKET_CATEGORY_COUNT = 17;
	const uint32_t TICKET_CATEGORY_MAX_ENTRIES = 16;

	// rand() / srand() keep per thread state under MSVC, so worker threads would all replay
	// the same sequence from the default seed. Give every thread its own seeded generator.
	std::mt19937& RewardRNG()
	{
		static thread_local std::mt19937 rng((uint32_t)std::random_device{}() ^ (uint32_t)timeGetTime());
		return rng;
	}
	// 0.0 .. 100.0
	float RandomPercent()
	{
		std::uniform_real_distribution<float> distribution(0.0f, 100.0f);
		return distribution(RewardRNG());
	}
	// 0 .. count - 1
	uint32_t RandomIndex(uint32_t count)
	{
		if (count < 2) return 0;
		std::uniform_int_distribution<uint32_t> distribution(0, count - 1);
		return distribution(RewardRNG());
	}
	// Applies a +/- variance to a reward so repeat battles never pay out exactly the same
	uint32_t Vary(uint32_t value, float variance)
	{
		if (value == 0) return 0;
		std::uniform_real_distribution<float> distribution(1.0f - variance, 1.0f + variance);
		uint32_t varied = (uint32_t)((float)value * distribution(RewardRNG()));
		return (varied < 1) ? 1 : varied;
	}
	uint32_t GetTicketCategories(const PARTTICKETTABLE* table, TICKETCATEGORY* categories)
	{
		uint32_t count = 0;
		categories[count].entries = table->engine;			categories[count++].count = ARRAYCOUNT(table->engine);
		categories[count].entries = table->muffler;			categories[count++].count = ARRAYCOUNT(table->muffler);
		categories[count].entries = table->transmission;	categories[count++].count = ARRAYCOUNT(table->transmission);
		categories[count].entries = table->differential;	categories[count++].count = ARRAYCOUNT(table->differential);
		categories[count].entries = table->suspension;		categories[count++].count = ARRAYCOUNT(table->suspension);
		categories[count].entries = table->body;			categories[count++].count = ARRAYCOUNT(table->body);
		categories[count].entries = table->frontBumper;		categories[count++].count = ARRAYCOUNT(table->frontBumper);
		categories[count].entries = table->bonnet;			categories[count++].count = ARRAYCOUNT(table->bonnet);
		categories[count].entries = table->overFender;		categories[count++].count = ARRAYCOUNT(table->overFender);
		categories[count].entries = table->mirror;			categories[count++].count = ARRAYCOUNT(table->mirror);
		categories[count].entries = table->sideSkirt;		categories[count++].count = ARRAYCOUNT(table->sideSkirt);
		categories[count].entries = table->rearBumper;		categories[count++].count = ARRAYCOUNT(table->rearBumper);
		categories[count].entries = table->rearSpoiler;		categories[count++].count = ARRAYCOUNT(table->rearSpoiler);
		categories[count].entries = table->grill;			categories[count++].count = ARRAYCOUNT(table->grill);
		categories[count].entries = table->lights;			categories[count++].count = ARRAYCOUNT(table->lights);
		categories[count].entries = table->tireBrakes;		categories[count++].count = ARRAYCOUNT(table->tireBrakes);
		categories[count].entries = table->bodyColour;		categories[count++].count = ARRAYCOUNT(table->bodyColour);
		return count;
	}
}

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
	uint32_t maxRandomRivals = ARRAYCOUNT(RandomRivals);

	if (maxRandomRivals > 0)
	{
		// randomly select a rival from the RandomRivals table (0 to maxRandomRivals - 1)
		uint32_t randomIndex = RandomIndex(maxRandomRivals);

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
	return Vary(CP, REWARD_VARIANCE);
}

uint32_t Rival::LoseCP(float distance, bool firsttime, float boost)
{
	uint32_t CP = 0;
	CP += (uint32_t)(distance / 1000.0f) * 10;
	CP = (uint32_t)((float)CP * (boost + 1.0f));
	return Vary(CP, REWARD_VARIANCE);
}

int16_t Rival::WinReward(float boost)
{
	// 1) Roll for the rival's own car ticket. rewardChance comes from the rival JSON files:
	//    gang leaders are set to 100%, ordinary members to roughly 9 - 15%.
	if (RandomPercent() < (settings.rewardChance * (boost + 1.0f)))
	{
		int16_t ticket = CarTicket();

		// if rivals car has a ticket that can be obtained, return it
		if (ticket != -1)
		{
			return ticket;
		}
	}

	// 2) Otherwise roll for a part ticket out of this rival's ticket table
	if (RandomPercent() < (PARTTICKET_CHANCE * (boost + 1.0f)))
	{
		return PartTicket();
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

	if (settings.carID >= 0 && settings.carID < (int16_t)ARRAYCOUNT(CARTICKET_LOOKUP))
	{
		return CARTICKET_LOOKUP[settings.carID];
	}

	// No requirments met
	return -1;
}

int16_t Rival::PartTicket()
{
	// rewardTable selects the ticket class, commonTable the manufacturer sub table.
	// Class C only has the one generic table so commonTable is unused for it.
	// Manufacturer order matches ITEM.DAT: 0 Generic, 1 Toyota, 2 Nissan, 3 Mitsubishi, 4 Mazda.
	const PARTTICKETTABLE* table = nullptr;

	switch (settings.rewardTable)
	{
	case 0:
		table = &Class_C_TicketTable;
		break;
	case 1:
		if (settings.commonTable >= 0 && settings.commonTable < (int32_t)ARRAYCOUNT(Class_B_TicketTable))
			table = &Class_B_TicketTable[settings.commonTable];
		else
			table = &Class_B_TicketTable[0];
		break;
	default:
		// TODO: no class A ticket table exists yet (ITEM.DAT items 323+)
		return -1;
	}

	TICKETCATEGORY categories[TICKET_CATEGORY_COUNT];
	uint32_t categoryCount = GetTicketCategories(table, categories);

	// Pick a random part category, then a random ticket within it. -1 entries are padding.
	// Categories that are entirely padding (the manufacturer tables have several) are re-rolled.
	for (uint32_t attempt = 0; attempt < categoryCount; attempt++)
	{
		const TICKETCATEGORY& category = categories[RandomIndex(categoryCount)];
		int16_t valid[TICKET_CATEGORY_MAX_ENTRIES];
		uint32_t validCount = 0;

		for (uint32_t i = 0; i < category.count && validCount < TICKET_CATEGORY_MAX_ENTRIES; i++)
		{
			if (category.entries[i] >= 0) valid[validCount++] = category.entries[i];
		}

		if (validCount > 0) return valid[RandomIndex(validCount)];
	}

	// No ticket available in this table
	return -1;
}

uint32_t Rival::WinXP(float distance, uint32_t remainingSP)
{
	// 8 points per rival level. Levels come from the "level" field in the data/rivals JSON files,
	// which ladder from 2 (ROLLING GUY members) up to 50 (TEAM DOREMI leader).
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

	return Vary(XP, REWARD_VARIANCE);
}

uint32_t Rival::LoseXP(float distance)
{
	// lose exp values 
	// npc level (ex. 20 EXP for 20lv npc) + 1 EXP per km
	uint32_t XP = settings.level;
	XP += (uint32_t)(distance / 1000.0f) * 1;

	return Vary(XP, REWARD_VARIANCE);
}