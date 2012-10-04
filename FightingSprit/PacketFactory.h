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
	Packet* EventPacket();		//��⿡�� �ٳ���... �ɸ� ������ ��� �ƴϸ� ���� �Ѿ�� �ȳѾ��...
	Packet* InformationPacket();
	Packet* ConnectPacketREQ(int id,NetworkControler* pControler);


};
