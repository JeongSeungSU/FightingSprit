#include "PacketMaker.h"

InformationPacketMaker::InformationPacketMaker(void)
:m_iPlayerNumber(0),m_pPacket(0)
{
}

InformationPacketMaker::~InformationPacketMaker(void)
{
}
void InformationPacketMaker::InputInformation(int id, vector3df Position, vector3df Direction,UNIT_ACTION_STATE state)
{
	m_iPlayerNumber++;
	CharacterInformation tmp;

	tmp.m_id		= id;
	tmp.m_Position  = Position;
	tmp.m_Direction = Direction;
	tmp.m_State		= state;


	m_CharList.push_back(tmp);
}
void InformationPacketMaker::InputInformation(CharacterInformation& info)
{
	m_iPlayerNumber++;
	
	m_CharList.push_back(info);
}
CharacterList InformationPacketMaker::OutPutInformation()
{
	CharacterList tmplist;

	(*m_pPacket)>>m_iPlayerNumber;


	CharacterInformation tmpchar;
	float x,y,z;
	int State;

	for(int i = 0; i< m_iPlayerNumber; i++)
	{
		(*m_pPacket)>>tmpchar.m_id;

		(*m_pPacket)>>x>>y>>z;
		vector3df position(x,y,z);
		tmpchar.m_Position = position;

		(*m_pPacket)>>x>>y>>z;
		vector3df Direction(x,y,z);
		tmpchar.m_Direction = Direction;

		(*m_pPacket)>>State;
		tmpchar.m_State = (UNIT_ACTION_STATE)State;

		tmplist.push_back(tmpchar);
	}

	Clear();
	return tmplist;
}
void InformationPacketMaker::Build()
{
	CharacterIter iter;

	

	(*m_pPacket)<<m_iPlayerNumber;

	for(iter = m_CharList.begin(); iter != m_CharList.end(); iter++)
	{
		(*m_pPacket)<<(*iter).m_id;

		(*m_pPacket)<<(float)(*iter).m_Position.X;
		(*m_pPacket)<<(float)(*iter).m_Position.Y;
		(*m_pPacket)<<(float)(*iter).m_Position.Z;

		(*m_pPacket)<<(float)(*iter).m_Direction.X;
		(*m_pPacket)<<(float)(*iter).m_Direction.Y;
		(*m_pPacket)<<(float)(*iter).m_Direction.Z;

		(*m_pPacket)<<(int)((*iter).m_State);
	}

	Clear();
}
void InformationPacketMaker::SetPacket(Packet* pPacket)
{
	m_pPacket = pPacket;
}

void InformationPacketMaker::Clear()
{
	m_pPacket = NULL;
	m_CharList.clear();
	m_iPlayerNumber = 0;
}


//////////////////////////////USERINFORMATIONPACKETMAKER//////////////////////////

UserInfomationPacketMaker::UserInfomationPacketMaker()
:m_pPacket(NULL)
{

}

UserInfomationPacketMaker::~UserInfomationPacketMaker()
{
	m_UserList.clear();
}

void UserInfomationPacketMaker::SetPacket(Packet* pPacket)
{
	m_pPacket = pPacket;	
}

void UserInfomationPacketMaker::InputUserInformation(int id,NetworkControler* pControler)
{
	int number = pControler->GetUserNum();
	(*m_pPacket)<< number;

	for(int i =0; i< MAX_CONNECT_NUM; i++)
	{
		User* pUser = pControler->GetUserInfo(i);
		if(!pUser)
			continue;

		m_pPacket->writeData((void*)&pUser->m_Addr,sizeof(pUser->m_Addr));
		*m_pPacket<<pUser->m_iID;
		*m_pPacket<<pUser->m_pUserName;
		*m_pPacket<<pUser->m_Server;
	}
}
void UserInfomationPacketMaker::Build()
{
	
}

UserList UserInfomationPacketMaker::OutPutUserInformation()
{
	int UserNumber = 0;
	*m_pPacket>>UserNumber;

	for(int i =0; i< UserNumber; i++)
	{
		User* pUser = new User();

		m_pPacket->readData((void*)&pUser->m_Addr,sizeof(pUser->m_Addr));
		*m_pPacket>>pUser->m_iID;
		*m_pPacket>>pUser->m_pUserName;
		*m_pPacket>>pUser->m_Server;

		m_UserList.push_back(pUser);
	}

	return m_UserList;
}