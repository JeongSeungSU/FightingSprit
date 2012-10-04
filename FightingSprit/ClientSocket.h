#pragma once
#include "Glober.h"
#include "Network.h"
#include "Packet.h"


enum WindowMessage
{
	WM_CLIENTSOCKET_BASE = 1242,
	WM_CLIENTSOCKET_CONNECT,
	WM_CLIENTSOCKET_CLOSE
};

class ClientSocket
{

private:
	void				onConnect( DWORD error );
	

	SOCKET				m_SocketValue;
	char				m_cReceiveBuffer[PACKETBUFFERSIZE];
	int					m_iReceivedPacketSize;

	WSAEVENT			m_RecvEvent;

	sockaddr_in			m_Serveraddr;

public:
	ClientSocket();
	virtual ~ClientSocket();

	static	DWORD				getHostByName( char* name, char* host );

	void						create(const char* address, int portNo );
	void						close();

	int							sendPacket(Packet& packet );

	void						selectEvent();
	void						onReceive();	


};
