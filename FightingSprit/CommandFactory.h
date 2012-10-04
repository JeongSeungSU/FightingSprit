#pragma once
#include "ChildCommand.h"



class CommandFactory
{
public:
	CommandFactory(void);
	~CommandFactory(void);

	static Command* CreateUserConnectCommand(Irrdevice* device, NetworkControler* NetworkControl,PacketAddr* pPacket);
};
