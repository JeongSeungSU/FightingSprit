#include "NetworkControler.h"

NetworkControler::NetworkControler(void)
:m_pNetworkManager(NetworkManager::getInstance()),m_iUser(-1)
{
	
}

NetworkControler::~NetworkControler(void)
{
}

void NetworkControler::SendClientToServerPacket(Packet& packet)
{
	m_pNetworkManager->m_ClientSocket.sendPacket(packet);
}
void NetworkControler::SendServerToClientPacket(Packet& packet)
{
	//맨처음은 무조건 서버 이므로 무시하여도 된다...
	UserIter iter = m_pNetworkManager->m_ServerInfo.m_UserMap.begin();
	iter++;

	//서버이외의 놈들한테 몽땅 패킷을 보냄...
	for( ;iter !=m_pNetworkManager->m_ServerInfo.m_UserMap.end(); 	iter++)
	{
		if(!(iter->second->m_Server))
			m_pNetworkManager->m_pSession->sendMessage(packet,iter->second->m_Addr);
	}
}
PacketAddr* NetworkControler::GetPacket()
{
	return m_pNetworkManager->ReceivePacketQueue();
}
void NetworkControler::ReceivePacket()
{
	m_pNetworkManager->m_ClientSocket.selectEvent();
}
NETWORKSTATE	NetworkControler::GetNetworkState()
{
	return m_pNetworkManager->GetNetwork();
}
void NetworkControler::AddUser(User* user)
{
	bool server = false;
	if(user->m_iID == 0)
		server = true;

	m_pNetworkManager->m_SetID[user->m_iID] = true;
	m_pNetworkManager->m_ServerInfo.AddUser(new User(user->m_Addr,user->m_iID,user->m_pUserName,server));
}
void NetworkControler::AddUser(sockaddr_in Addr,char* UserName,int ID)
{
	bool server = false;
	if(ID == 0)
		server = true;
	
	m_pNetworkManager->m_SetID[ID] = true;
	m_pNetworkManager->m_ServerInfo.AddUser(new User(Addr,ID,UserName,server));
}

void	NetworkControler::SubtractionUser(int id)
{
	m_pNetworkManager->m_ServerInfo.SubtractionUser(id);
	m_pNetworkManager->m_SetID[id] = false;
}
User*	NetworkControler::GetUserInfo(int id)
{
	return m_pNetworkManager->m_ServerInfo.GetUserInfo(id);
}
int		NetworkControler::GetUserNum()
{
	return m_pNetworkManager->m_ServerInfo.GetUserNum();
}
int		NetworkControler::GetNewID()
{
	for(int i =0; i< MAX_CONNECT_NUM; i++)
	{
		if(m_pNetworkManager->m_SetID[i] == false)
			return i;
	}

}