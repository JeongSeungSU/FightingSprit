#pragma once
#include "NetworkManager.h"


/*!
 * @class     NetworkControler
 * @brief     네트워크 매니져의 인터페이스라고 보면 됨 프랜드 사이임...
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-04-05 
 * @warning   
 */
class NetworkControler
{
private:
	int					m_iUser;

	NetworkManager*		m_pNetworkManager;
public:
	NetworkControler(void);
	~NetworkControler(void);
public:
	void			SendClientToServerPacket(Packet& packet);				//클라이언트에서 서버로 보내는 패킷임...
	void			SendServerToClientPacket(Packet& packet);				//서버에서 각 클라이언트에 보내는 패킷임...
	PacketAddr*		GetPacket();											//이것은 클라이언트에서 패킷을 얻기 위함..

	void			ReceivePacket();										//이것은 클라이언트에서 패킷을 받기 위함
	
	NETWORKSTATE	GetNetworkState();

	void		AddUser(sockaddr_in Addr,char* UserName,int ID);
	void		AddUser(User* user);

	int			getMyUserID(){return m_iUser;}
	void		SetMyUserID(int ID){m_iUser = ID;}


	int			GetNewID();

	
	
	void		SubtractionUser(int id);		
	User*		GetUserInfo(int id);

	int			GetUserNum();
};
