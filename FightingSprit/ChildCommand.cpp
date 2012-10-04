#include "ChildCommand.h"
#include "Irrdevice.h"
#include "NetworkControler.h"

UserConnect::UserConnect(Irrdevice* device, NetworkControler* NetworkControl,PacketAddr* pPacket,StateTemp* state)
:m_pDevice(device),m_pNetworkControl(NetworkControl),m_pPacket(pPacket),m_pstate(state)
{
	ninja  = m_pDevice->GetSceneManager()->getMesh("media/ninja.b3d");
}

UserConnect::~UserConnect(void)
{
}
void  UserConnect::Excute()
{

// 	ISceneManager* smgr	  = m_pDevice->GetSceneManager();
// 	IAnimatedMeshSceneNode * pOther;
// 	if( m_pPacket->m_SocketAddr.sin_addr.s_addr == ::inet_addr( "127.0.0.1" ) )	//서버라면...
// 	{
// 		m_pNetworkControl->AddUser(m_pPacket,true);
// 		//이쪽에서 클라이언트 소스 필요...
// 		IAnimatedMeshSceneNode* pMyNode = m_pNetworkControl->GetInfo()->GetUserInfo(m_pNetworkControl->getUser()-1)->m_pMyMesh = smgr->addAnimatedMeshSceneNode(ninja);
// 		pMyNode->setPosition(vector3df(10,-30,50));
// 
// 		//아이디 설정 자기 자신의 아이디를 설정 해줌...
// 		m_pstate->SetMyID(m_pNetworkControl->getUser()-1);
// 	}
// 	else
// 	{
// 		pOther	= smgr->addAnimatedMeshSceneNode(ninja);
// 		pOther->setPosition(vector3df(-10,-30,50));
// 		m_pNetworkControl->AddUser(m_pPacket);	
// 
// 		//다시 보냄..
// 		Packet p;
// 		p.Protocolid(WELCOME_REQ);
// 		p.ID(m_pNetworkControl->getUser()-1);
// 		p<<m_pNetworkControl->getUser()-1;
// 
// 		m_pNetworkControl->SendServerToPacket(p);
// 	}

}

void UserConnect::SetPacket(PacketAddr* packet)
{
	m_pPacket = packet;
}

//UserConnectReceive
UserConnectReceive::UserConnectReceive(Irrdevice* device, NetworkControler* NetworkControl,PacketAddr* pPacket,StateTemp* state)
:m_pDevice(device),m_pNetworkControl(NetworkControl),m_pPacket(pPacket),m_pstate(state)
{
}

UserConnectReceive::~UserConnectReceive(void)
{
}
void  UserConnectReceive::Excute()
{
// 	IAnimatedMesh* ninja  = m_pDevice->GetSceneManager()->getMesh("media/ninja.b3d");
// 	ISceneManager* smgr	  = m_pDevice->GetSceneManager();
// 	IAnimatedMeshSceneNode * pOther;
// 	if( m_pPacket->m_SocketAddr.sin_addr.s_addr == ::inet_addr( "127.0.0.1" ) )	//서버라면...
// 	{
// 		m_pNetworkControl->AddUser(m_pPacket,true);
// 		//이쪽에서 클라이언트 소스 필요...
// 		IAnimatedMeshSceneNode* pMyNode = m_pNetworkControl->GetInfo()->GetUserInfo(m_pNetworkControl->getUser()-1)->m_pMyMesh = smgr->addAnimatedMeshSceneNode(ninja);
// 		pMyNode->setPosition(vector3df(10,-30,50));
// 
// 		//아이디 설정 자기 자신의 아이디를 설정 해줌...
// 		m_pstate->SetMyID(m_pNetworkControl->getUser()-1);
// 	}
// 	else
// 	{
// 		pOther	= smgr->addAnimatedMeshSceneNode(ninja);
// 		pOther->setPosition(vector3df(-10,-30,50));
// 		m_pNetworkControl->AddUser(m_pPacket);	
// 
// 		//다시 보냄..
// 		Packet p;
// 		p.Protocolid(WELCOME_REQ);
// 		p.ID(m_pNetworkControl->getUser()-1);
// 		p<<m_pNetworkControl->getUser()-1;
// 
// 		m_pNetworkControl->SendServerToPacket(p);
// 	}

}

void UserConnectReceive::SetPacket(PacketAddr* packet)
{
	m_pPacket = packet;
}
