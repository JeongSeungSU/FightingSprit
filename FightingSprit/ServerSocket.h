#pragma once
#include "Network.h"

class ServerSocket
{

protected:
	SOCKET		m_SocketListen;

public:
	ServerSocket();
	virtual	~ServerSocket();

	bool		initialize( int portNo);
	void		close();

	SOCKET		getListenSocket(){ return m_SocketListen; }



};
