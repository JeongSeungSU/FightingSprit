#include "NetworkManager.h"
#include "NetworkControler.h"


NetworkManager* NetworkManager::m_pInstance = NULL;


PacketAddr::PacketAddr(Packet packet ,sockaddr_in socketaddr)
:m_Packet(packet), m_SocketAddr(socketaddr)
{}


NetworkManager::NetworkManager(void)
:m_NetworkState(NONE),m_pSession(NULL),m_pNetworkControl(NULL),m_pThreadManager(NULL),m_pCompletionHandler(NULL)
{
	memset(m_SetID,0,sizeof(m_SetID));
}

NetworkManager::~NetworkManager(void)
{
	DestoryNetwork();
}


NetworkControler* NetworkManager::InitNetwork(NETWORKSTATE state,const char* ServerIp)
{

	m_NetworkState = state;			//���� ��Ʈ��ũ�� Ŭ��� ������ ���� ����

	switch(state)
	{
	case SERVER:
		InitServer();
	case CLIENT:
		InitClient(ServerIp);
		break;
	case  NONE:
		return NULL;
	}

	m_pNetworkControl = new NetworkControler();		//��Ʈ��ũ ��Ʈ�ѷ� ����...
	return m_pNetworkControl;
}

NetworkControler*	NetworkManager::GetNetworkControler()
{
	return m_pNetworkControl;
}

void NetworkManager::InitClient(const char* ServerIP)
{
	if(m_NetworkState == SERVER)
	{
		m_ClientSocket.create("127.0.0.1",FIGHTING_SPRIT_PORT);
		return;
	}
	m_ClientSocket.create(ServerIP,FIGHTING_SPRIT_PORT);
	
}
void NetworkManager::InitServer()
{
	m_pCompletionHandler = CCompletionHandler::getInstance();		//IOCPť�� �����Ͽ� �����͸� ������...
	m_pThreadManager	 = CThreadManager::getInstance();			//������ �Ŵ���

	m_ServerSocket.initialize(FIGHTING_SPRIT_PORT);					//��� ���� �ʱ�ȭ

	m_pSession = new Session(m_ServerSocket.getListenSocket());		//���� ��Ŀ�����忡�� ���� ����� ����...

	m_pCompletionHandler->initialize();
	m_pCompletionHandler->addHandleToIOCP( (HANDLE)m_ServerSocket.getListenSocket(), (DWORD)m_pSession );
	m_pSession->onCreate();
}
void NetworkManager::DestoryNetwork()
{
	if(m_pThreadManager)
		m_pThreadManager->releaseInstance();
	if(m_pCompletionHandler)
		m_pCompletionHandler->releaseInstance();
	
	if(m_pSession)
		m_pSession->closeConnection();
	m_ServerSocket.close();
	m_ClientSocket.close();

	SAFE_DELETE(m_pSession);
	SAFE_DELETE(m_pNetworkControl);
	
	memset(m_SetID,0,sizeof(m_SetID));
}
PacketAddr*	NetworkManager::ReceivePacketQueue()
{
	Synchronized sync(&m_CriticalQueue);			//ũ��Ƽ�� ���� ����...
	
	if(!m_PacketQueue.empty())
	{
		PacketAddr* pPacket = m_PacketQueue.front();
		m_PacketQueue.pop();
		return pPacket;
	}
	return NULL;
}

void	NetworkManager::SendPacketQueue(PacketAddr* pac)
{
	Synchronized sync(&m_CriticalQueue);			//ũ��Ƽ�� ���� ����...

	m_PacketQueue.push(pac);
}
