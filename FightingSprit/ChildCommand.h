#pragma once
#include "command.h"
#include "NetworkManager.h"
//사용하는 클래스 목록들 이것은 CPP파일에 인클루드 할 것 임 오키? 쑤ㅢ빨 아주 죳되는 거야

class	NetworkControler;
class	Irrdevice;
class	StateTemp;			//얘는 나중에 바꿔주면 되고 ㅋㅋ

/*!
 * @class     UserConnect
 * @brief     유져 접속시 서버에서 처리
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
 * @brief     유져 접속시 클라이언트 처리..
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
