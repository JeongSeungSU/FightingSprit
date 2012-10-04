#pragma once
#include "Player.h"
#include "Protocol.h"
#include "SmartPointer.h"
#include "NetworkControler.h"
#include "PacketMaker.h"


class PacketFactory
{
public:
	PacketFactory(void);
	~PacketFactory(void);

public:
	//Send Client To Server
	Packet*	MovePacket(int id, vector3df Position, vector3df Direction, UNIT_ACTION_STATE state);
	Packet* ShotPacket(int id, vector3df Position, vector3df Direction);
	Packet* ResurrectionPacket(int id, vector3df Position);
	Packet* ConnectPacket();
	
	
	//Send Server To Client
	Packet* EventPacket();		//요기에다 다넣자... 케릭 디지고 살고 아니면 게임 넘어가고 안넘어가고...
	Packet* InformationPacket();
	Packet* ConnectPacketREQ(int id,NetworkControler* pControler);


};
