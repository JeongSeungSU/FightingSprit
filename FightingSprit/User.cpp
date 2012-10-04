#include "User.h"

User::User(sockaddr_in Addr,int ID,char* Name,bool IsServer)
:m_Addr(Addr),m_iID(ID),m_Server(IsServer)
{
	strcpy(m_pUserName,Name);
}

User::~User(void)
{
}
