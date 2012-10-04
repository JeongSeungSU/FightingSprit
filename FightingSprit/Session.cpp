#include "Session.h"
#include "Protocol.h"
#include "NetworkException.h"
#include "NetworkManager.h"



Session::Session( SOCKET s )
: m_SocketValue( s ), m_iReceivedPacketSize( 0 ), m_HandleRecvEvent( INVALID_HANDLE_VALUE )
{
	waitForPacketReceive();
}

Session::~Session()
{
	::WSACloseEvent( m_HandleRecvEvent );

	if( m_SocketValue != INVALID_SOCKET )
		::closesocket( m_SocketValue );
}

void Session::onCreate()
{
	if( m_SocketValue == INVALID_SOCKET )
		throw NetworkException("Session::OnCreate() : 잘못된 소켓이다.. 이떵컴아");
	
	return;
}

void Session::onDestroy()
{
	closeConnection();
}

void Session::closeConnection()
{
	::shutdown( m_SocketValue, SD_BOTH );
	::closesocket( m_SocketValue );
	m_SocketValue = INVALID_SOCKET;

	m_iReceivedPacketSize = 0;
}



bool Session::waitForPacketReceive()
{
	if( m_SocketValue == INVALID_SOCKET )
		return false;

	DWORD	readBytes = 0;
	DWORD	bufSize = PACKETBUFFERSIZE - m_iReceivedPacketSize;
	DWORD	dwRecvBytes = 0;
	DWORD	dwFlags = 0;
	OVERLAPPED recvOverlap;

	ZeroMemory(&recvOverlap,sizeof(OVERLAPPED));

	int size = sizeof(m_Clientaddr);

	WSABUF	wsaBuffer;

	wsaBuffer.buf = m_ReceiveBuffer;
	wsaBuffer.len = bufSize;

	if( !::WSARecvFrom( m_SocketValue, &wsaBuffer, 1,&dwRecvBytes,&dwFlags,
		(sockaddr*)&m_Clientaddr,&size,(OVERLAPPED*)&recvOverlap,NULL))
	{
		DWORD lastError = ::GetLastError();

		if( lastError != ERROR_IO_PENDING && lastError != ERROR_SUCCESS )
			return false;
	}

	return true;
}

void Session::dispatch( DWORD bytesTransferred, OVERLAPPED* ov )
{
	OVERLAPPED2* overlapped = ( OVERLAPPED2* )ov;

	if( bytesTransferred == 0 )
		return;

	//if( overlapped->flags == ASYNCFLAG_RECEIVE )			//요주의 코드...
		dispatchReceive( bytesTransferred );
}

void Session::dispatchReceive( DWORD bytesTransferred )
{
	Packet* receivedPacket = new Packet();

	m_iReceivedPacketSize += bytesTransferred;

	while( m_iReceivedPacketSize > 0 )
	{
		receivedPacket->copyToBuffer( m_ReceiveBuffer, m_iReceivedPacketSize );

		if( receivedPacket->isValidPacket() == true && m_iReceivedPacketSize >= ( int )receivedPacket->getPacketSize() )
		{
			//  Parsing
			packetParsing( *receivedPacket , m_Clientaddr);

			unsigned char buffer[PACKETBUFFERSIZE];

			m_iReceivedPacketSize -= receivedPacket->getPacketSize();
			if( m_iReceivedPacketSize > 0 )
			{
				CopyMemory( buffer, ( m_ReceiveBuffer + receivedPacket->getPacketSize() ), m_iReceivedPacketSize );
				CopyMemory( m_ReceiveBuffer, buffer, m_iReceivedPacketSize );
			}
		}
		else
			break;
	}

	waitForPacketReceive();
}

void	Session::packetParsing( Packet& packet, sockaddr_in sendtoclinet )
{
	NetworkManager::getInstance()->SendPacketQueue(new PacketAddr(packet,sendtoclinet));
}
bool Session::sendMessage( Packet& packet,sockaddr_in sendtoclinet  )
{
	DWORD writtenBytes = 0;

	sockaddr_in tmp = sendtoclinet;

	if( m_SocketValue == INVALID_SOCKET )
		return false;

	//::ZeroMemory( &m_OverlappedSend, sizeof( OVERLAPPED2 ) );

	if( !::sendto( m_SocketValue, (char*) packet.getPacketBuffer(), packet.getPacketSize(), 0,(sockaddr*)&tmp,sizeof(tmp)) )
	{
		DWORD lastError = ::GetLastError();
		if( lastError != ERROR_IO_PENDING && lastError != ERROR_SUCCESS )
			return false;
	}
	return true;
}