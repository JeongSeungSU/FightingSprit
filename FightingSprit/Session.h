#pragma once

#include "Network.h"
#include "Packet.h"

#define  ASYNCFLAG_SEND				0x01
#define  ASYNCFLAG_RECEIVE			0x02

class Session
{
private:
	typedef struct OVERLAPPED2 : OVERLAPPED
	{
		DWORD		flags;
	} OVERLAPPED2;

	void				dispatchReceive( DWORD bytesTransferred );

	char				m_ReceiveBuffer[PACKETBUFFERSIZE];
	int					m_iReceivedPacketSize;

	HANDLE				m_HandleRecvEvent;

	sockaddr_in			m_Clientaddr;

public:

	Session( SOCKET s );
	~Session();

	void	onCreate();
	void	onDestroy();

	void	dispatch( DWORD bytesTransferred, OVERLAPPED* ov );			
	bool	sendMessage(Packet& packet,sockaddr_in sendtoclinet );

	void	closeConnection();

	SOCKET	getSocketValue(){ return m_SocketValue; }

	void	packetParsing( Packet& packet, sockaddr_in sendtoclinet );

	bool	waitForPacketReceive();

	SOCKET	m_SocketValue;
};
