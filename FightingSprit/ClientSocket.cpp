#include "ClientSocket.h"
#include "Protocol.h"
#include "NetworkException.h"
#include "NetworkManager.h"

ClientSocket::ClientSocket()
: m_iReceivedPacketSize( 0 ), m_SocketValue( INVALID_SOCKET ), m_RecvEvent( INVALID_HANDLE_VALUE )
{
}

ClientSocket::~ClientSocket()
{
	close();
}

DWORD ClientSocket::getHostByName( char* name, char* host )
{
	HOSTENT* hostent;
	char* ip;

	hostent = ::gethostbyname( name );

	if( ::WSAGetLastError() == WSANOTINITIALISED )
		return WSANOTINITIALISED;

	ip = ::inet_ntoa( *( struct in_addr* )*hostent->h_addr_list );
	::strcpy( host, ip );

	return 0;
}

void ClientSocket::create( const char* address, int portNo )
{
	WSADATA wsaData;

	//  ws2_32.dll을 사용하기 위해 초기화한다.
	if( ::WSAStartup( 0x202, &wsaData ) != 0 )
		throw NetworkException("ws2_32소켓 초기화 안됨....이 떵컴아");

	if( LOBYTE( wsaData.wVersion ) != 2 || HIBYTE( wsaData.wVersion ) != 2 )
	{
		::WSACleanup();

		throw NetworkException("ws2_32소켓 초기화 안됨....이 떵컴아");
	}

	m_RecvEvent			= ::WSACreateEvent();

	m_SocketValue = ::socket( AF_INET,SOCK_DGRAM, 0 );
	if( m_SocketValue == INVALID_SOCKET ) 
	{
		throw NetworkException("ClientSocket::Create : Client Socket Create Fail");
		return;
	}
	
	::ZeroMemory( &m_Serveraddr, sizeof( m_Serveraddr ) );
	m_Serveraddr.sin_family      = AF_INET;
	m_Serveraddr.sin_addr.s_addr = inet_addr( address );
	m_Serveraddr.sin_port        = ::htons( portNo );
}

void ClientSocket::close()
{
	if( m_RecvEvent != INVALID_HANDLE_VALUE )
	{
		::WSACloseEvent( m_RecvEvent );
		m_RecvEvent = INVALID_HANDLE_VALUE;
	}

	::shutdown( m_SocketValue, SD_BOTH );
	::closesocket( m_SocketValue );
}

int	ClientSocket::sendPacket( Packet& packet )
{
	OVERLAPPED overlapped;

	::ZeroMemory( &overlapped, sizeof( OVERLAPPED ) );

	return ::sendto( m_SocketValue, (char*)packet.getPacketBuffer(), packet.getPacketSize(), 0,(sockaddr*)&m_Serveraddr, sizeof(m_Serveraddr) );
}

void ClientSocket::onReceive() 
{
	Packet receivedPacket;
	DWORD bufSize = PACKETBUFFERSIZE - m_iReceivedPacketSize;
	DWORD	dwRecvBytes = 0;
	DWORD	dwFlags = 0;
	OVERLAPPED recvOverlap;

	ZeroMemory(&recvOverlap,sizeof(OVERLAPPED));

	int retval;
	//char buf[PACKETBUFFERSIZE];
	sockaddr_in peeraddr;
	int addrlen = sizeof(peeraddr);

	retval = recvfrom( m_SocketValue, m_cReceiveBuffer, PACKETBUFFERSIZE, 0, (SOCKADDR*)&peeraddr, &addrlen );

	if( retval > 0 )
		m_iReceivedPacketSize += retval;

	while( m_cReceiveBuffer > 0 )
	{
		receivedPacket.copyToBuffer( m_cReceiveBuffer, m_iReceivedPacketSize );

		if( receivedPacket.isValidPacket() == true && m_iReceivedPacketSize >= ( int )receivedPacket.getPacketSize() )
		{
			NetworkManager::getInstance()->SendPacketQueue(new PacketAddr(receivedPacket,peeraddr));

			char buffer[PACKETBUFFERSIZE];

			m_iReceivedPacketSize -= receivedPacket.getPacketSize();
			CopyMemory( buffer, ( m_cReceiveBuffer + receivedPacket.getPacketSize() ), m_iReceivedPacketSize );
			CopyMemory( m_cReceiveBuffer, buffer, m_iReceivedPacketSize );
		}
		else
			break;
	}
}

void ClientSocket::selectEvent()
{
	WSANETWORKEVENTS netEvent;

	::ZeroMemory( &netEvent, sizeof( netEvent ) );
	::WSAEventSelect( m_SocketValue, m_RecvEvent, FD_READ | FD_CLOSE );
	::WSAEnumNetworkEvents( m_SocketValue, m_RecvEvent, &netEvent );

	if( ( netEvent.lNetworkEvents & FD_READ ) == FD_READ )
		onReceive();
 	else if( ( netEvent.lNetworkEvents & FD_CLOSE ) == FD_CLOSE )
		throw NetworkException("ClientSocket::SelectEvent() : 패킷이 닫혔다네");
}
