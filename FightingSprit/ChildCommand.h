#pragma once
#include "command.h"
#include "NetworkManager.h"
//����ϴ� Ŭ���� ��ϵ� �̰��� CPP���Ͽ� ��Ŭ��� �� �� �� ��Ű? ���һ� ���� ���Ǵ� �ž�

class	NetworkControler;
class	Irrdevice;
class	StateTemp;			//��� ���߿� �ٲ��ָ� �ǰ� ����

/*!
 * @class     UserConnect
 * @brief     ���� ���ӽ� �������� ó��
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-06 
 * @warning   
 */
class UserConnect :	public Command			
{
private:
	Irrdevice*				m_pDevice;
	NetworkControler*		m_pNetworkControl;
	PacketAddr*				m_pPacket;
	StateTemp*				m_pstate;

	IAnimatedMesh*			ninja;
public:
	UserConnect(Irrdevice* device, NetworkControler* NetworkControl,PacketAddr*	pPacket,StateTemp* state);
	~UserConnect(void);
public:
	void Excute();

	void SetPacket(PacketAddr* packet);
};


/*!
 * @class     UserConnectReceive
 * @brief     ���� ���ӽ� Ŭ���̾�Ʈ ó��..
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-07 
 * @warning   
 */
class UserConnectReceive :	public Command			
{
private:
	Irrdevice*				m_pDevice;
	NetworkControler*		m_pNetworkControl;
	PacketAddr*				m_pPacket;
	StateTemp*				m_pstate;

	
public:
	UserConnectReceive(Irrdevice* device, NetworkControler* NetworkControl,PacketAddr*	pPacket,StateTemp* state);
	~UserConnectReceive(void);
public:
	void Excute();

	void SetPacket(PacketAddr* packet);
};
