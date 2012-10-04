#include "ServerSocket.h"

ServerSocket::ServerSocket()
: m_SocketListen( INVALID_SOCKET )
{
}

ServerSocket::~ServerSocket()
{
	if( m_SocketListen != INVALID_SOCKET )
		closesocket( m_SocketListen );
}

bool ServerSocket::initialize( int portNo)
{
	WSADATA wsaData;

	//소켓 버젼 초기화
	if( ::WSAStartup( MAKEWORD( 2, 2 ), &wsaData ) != 0 )
		return false;

	if( wsaData.wVersion != MAKEWORD( 2, 2 ) )
	{
		::WSACleanup();

		return false;
	}

	struct sockaddr_in sockAddr;
	int reuse = 1;

	//소켓 주소 설정 및 포트 설정
	::ZeroMemory( &sockAddr, sizeof( sockAddr ) );
	sockAddr.sin_family			= AF_INET;
	sockAddr.sin_addr.s_addr	=  ::htonl( INADDR_ANY );//::htonl(INADDR_ANY);
	sockAddr.sin_port			= ::htons( portNo );

	//SOCK_DGRAM = UDP
	m_SocketListen = ::socket( AF_INET, SOCK_DGRAM, 0);
	if( m_SocketListen == INVALID_SOCKET )
	{
		::WSACleanup();

		return false;
	}

	//바인드 시킴 UDP라 바인드만 하면 됨...
	if( ::bind( m_SocketListen, ( struct sockaddr * )&sockAddr, sizeof( sockAddr ) ) == SOCKET_ERROR)
	{
		::WSACleanup();

		return false;
	}

	return true;
}

void ServerSocket::close()
{
	if( m_SocketListen != INVALID_SOCKET )
		::closesocket( m_SocketListen );

	::WSACleanup();
}

