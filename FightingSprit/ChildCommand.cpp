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
// 	if( m_pPacket->m_SocketAddr.sin_addr.s_addr == ::inet_addr( "127.0.0.1" ) )	//�������...
// 	{
// 		m_pNetworkControl->AddUser(m_pPacket,true);
// 		//���ʿ��� Ŭ���̾�Ʈ �ҽ� �ʿ�...
// 		IAnimatedMeshSceneNode* pMyNode = m_pNetworkControl->GetInfo()->GetUserInfo(m_pNetworkControl->getUser()-1)->m_pMyMesh = smgr->addAnimatedMeshSceneNode(ninja);
// 		pMyNode->setPosition(vector3df(10,-30,50));
// 
// 		//���̵� ���� �ڱ� �ڽ��� ���̵� ���� ����...
// 		m_pstate->SetMyID(m_pNetworkControl->getUser()-1);
// 	}
// 	else
// 	{
// 		pOther	= smgr->addAnimatedMeshSceneNode(ninja);
// 		pOther->setPosition(vector3df(-10,-30,50));
// 		m_pNetworkControl->AddUser(m_pPacket);	
// 
// 		//�ٽ� ����..
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
// 	if( m_pPacket->m_SocketAddr.sin_addr.s_addr == ::inet_addr( "127.0.0.1" ) )	//�������...
// 	{
// 		m_pNetworkControl->AddUser(m_pPacket,true);
// 		//���ʿ��� Ŭ���̾�Ʈ �ҽ� �ʿ�...
// 		IAnimatedMeshSceneNode* pMyNode = m_pNetworkControl->GetInfo()->GetUserInfo(m_pNetworkControl->getUser()-1)->m_pMyMesh = smgr->addAnimatedMeshSceneNode(ninja);
// 		pMyNode->setPosition(vector3df(10,-30,50));
// 
// 		//���̵� ���� �ڱ� �ڽ��� ���̵� ���� ����...
// 		m_pstate->SetMyID(m_pNetworkControl->getUser()-1);
// 	}
// 	else
// 	{
// 		pOther	= smgr->addAnimatedMeshSceneNode(ninja);
// 		pOther->setPosition(vector3df(-10,-30,50));
// 		m_pNetworkControl->AddUser(m_pPacket);	
// 
// 		//�ٽ� ����..
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
