#include "PacketFactory.h"

PacketFactory::PacketFactory(void)
{
}

PacketFactory::~PacketFactory(void)
{
}


Packet*	PacketFactory::MovePacket(int id,vector3df Position,vector3df Direction,UNIT_ACTION_STATE state)
{
	InformationPacketMaker mk;
	Packet* pTmp = new Packet(MOVE,id);

	mk.SetPacket(pTmp);
	mk.InputInformation(id,Position,Direction,state);
	mk.Build();

	//pTmp

	return pTmp;
}


Packet* PacketFactory::ConnectPacket()
{
	Packet* pTmp = new Packet(CONNECT_ACK,-1);

	return pTmp;
}
Packet* PacketFactory::ConnectPacketREQ(int id,NetworkControler* pControler)
{
 	Packet* pTmp = new Packet(CONNECT_REQ,id);

	UserInfomationPacketMaker pkmaker;

	pkmaker.SetPacket(pTmp);


	pkmaker.InputUserInformation(id,pControler);

	pkmaker.Build();

	return pTmp;
}