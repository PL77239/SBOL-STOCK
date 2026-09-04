#include "parkingarea.h"
#include "client.h"

ParkingArea::ParkingArea()
{
	areaClient.clear();
	areaClient.resize(PARKINGAREA_PLAYER_LIMIT);
	for (auto& client : areaClient)
	{
		client = nullptr;
	}
	index = -1;
	entry.placeID = 0;
	entry.name = "";
	logger = nullptr;
}
ParkingArea::~ParkingArea()
{
}
uint32_t ParkingArea::getClientCount()
{
	uint32_t count = 0;
	for (auto& client : areaClient)
	{
		if (client != nullptr) count++;
	}
	return count;
}
int32_t ParkingArea::getFree()
{
	for (uint32_t i = 0; i < areaClient.size(); i++)
	{
		if (areaClient[i] == nullptr) return i;
	}
	return -1;
}
int32_t ParkingArea::findClient(Client* in)
{
	for (uint32_t i = 0; i < areaClient.size(); i++)
	{
		if (areaClient[i] != nullptr && areaClient[i] == in) return i;
	}
	return -1;
}
Client* ParkingArea::findClient(int32_t driverslicense)
{
	for (auto& client : areaClient)
	{
		if (client != nullptr && client->driverslicense == driverslicense) return client;
	}
	return nullptr;
}
int32_t ParkingArea::addClient(Client* in)
{
	int32_t freeClient = -1;
	if (findClient(in) == -1)
	{
		freeClient = getFree();
		if (freeClient != -1)
		{
			areaClient[freeClient] = in;
			in->parkingArea = this;
		}
	}
	return freeClient;
}
void ParkingArea::removeClient(Client* in)
{
	int32_t clientIndex = findClient(in);
	if (clientIndex != -1)
	{
		areaClient[clientIndex]->parkingArea = nullptr;
		areaClient[clientIndex] = nullptr;
	}
}
void ParkingArea::getMemberHandles(std::vector<std::string>& out)
{
	out.clear();
	for (auto& client : areaClient)
	{
		if (client != nullptr) out.push_back(client->handle);
	}
}
void ParkingArea::sendToArea(PACKET* src, int32_t exclude)
{
	// Unlike Course::sendToCourse this does not test hasPlayers. Nobody in a Parking Area
	// is on a course, so that flag is never set here and testing it would mute the room.
	for (auto& client : areaClient)
	{
		if (client != nullptr && client->driverslicense != exclude)
		{
			if (src->getSize() == 0) return;
			client->addToSendQueue(src);
		}
	}
}
void ParkingArea::sendToClient(PACKET* src, int32_t driverslicense)
{
	for (auto& client : areaClient)
	{
		if (client != nullptr && client->driverslicense == driverslicense)
		{
			if (src->getSize() == 0) return;
			client->addToSendQueue(src);
			return;
		}
	}
}
