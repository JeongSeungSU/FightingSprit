#pragma once
#include "Glober.h"
#include "CompletionHandler.h"
#include "ServerSocket.h"
#include "ClientSocket.h"
#include "ServerInfo.h"
#include "Session.h"
#include "CriticalSection.h"
#include "ThreadManager.h"
#include "Synchronized.h"

const int MAX_CONNECT_NUM = 8;

enum NETWORKSTATE {CLIENT, SERVER, NONE};

struct PacketAddr
{
public:
	Packet			m_Packet;
	sockaddr_in		m_SocketAddr;
public:
	PacketAddr(Packet packet ,sockaddr_in socketaddr);
};

typedef std::queue<PacketAddr*>		 PacketQueue;

class NetworkControler;



class NetworkManager
{
private:

	friend	class NetworkControler;

	static	NetworkManager*		m_pInstance;
	////////////////����////////////////////

	/*!
	 * @brief	���� Ŭ���̾�Ʈ ���� ť..
	 */
	PacketQueue					m_PacketQueue;

	/*!
	 * @brief	������ Ŭ���̾�Ʈ��
	 */
	NETWORKSTATE				m_NetworkState;

	/*!
	 * @brief	���� ������...
	 */
	ServerInfo					m_ServerInfo;

	/*!
	 * @brief	ť������ ũ��Ƽ�� ����
	 */
	CriticalSection				m_CriticalQueue;

	/*!
	 * @brief	���� ������ �ִ� ��Ʈ��ũ ��Ʈ�ѷ�...
	 */
	NetworkControler*			m_pNetworkControl;


	///////////////������////////////////////
	CCompletionHandler*			m_pCompletionHandler;
	Session*					m_pSession;
	CThreadManager*				m_pThreadManager;
	ServerSocket				m_ServerSocket;

	bool						m_SetID[MAX_CONNECT_NUM];


	///////////////Ŭ����////////////////////
	ClientSocket				m_ClientSocket;

	
private:
	void		InitClient(const char* ServerIP);
	void		InitServer();
	
	
public:
	NetworkManager(void);
	~NetworkManager(void);

	static	NetworkManager* getInstance()
	{
		if(m_pInstance == NULL)
			m_pInstance = new NetworkManager();

		return m_pInstance;
	}

	static	void	DeleteNetworkManager()
	{
		if(!m_pInstance)
			delete m_pInstance;

		m_pInstance = NULL;
	}
public:
	NetworkControler*	InitNetwork(NETWORKSTATE state,const char* ServerIp);
	void				DestoryNetwork();
	NETWORKSTATE		GetNetwork()	{return m_NetworkState;}
	NetworkControler*	GetNetworkControler();
	
	void				SendPacketQueue(PacketAddr* pac);
	PacketAddr*			ReceivePacketQueue();
};
