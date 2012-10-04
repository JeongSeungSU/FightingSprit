#pragma once
#include "NetworkManager.h"


/*!
 * @class     NetworkControler
 * @brief     ��Ʈ��ũ �Ŵ����� �������̽���� ���� �� ������ ������...
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
	void			SendClientToServerPacket(Packet& packet);				//Ŭ���̾�Ʈ���� ������ ������ ��Ŷ��...
	void			SendServerToClientPacket(Packet& packet);				//�������� �� Ŭ���̾�Ʈ�� ������ ��Ŷ��...
	PacketAddr*		GetPacket();											//�̰��� Ŭ���̾�Ʈ���� ��Ŷ�� ��� ����..

	void			ReceivePacket();										//�̰��� Ŭ���̾�Ʈ���� ��Ŷ�� �ޱ� ����
	
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
