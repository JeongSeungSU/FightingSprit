#pragma once
#include "Glober.h"
#include "packet.h"
#include "User.h"
#include "NetworkControler.h"



/*!
 * Struct comment 이 구조체는 한케릭터의 모든 이동정보들이 포함되어있다..
 * 실시간으로 뿌려주기 위해 꼭 필요한 정보들만 모아놓은것임...
 */
struct CharacterInformation
{
	int			m_id;
	vector3df	m_Position;
	vector3df	m_Direction;
	UNIT_ACTION_STATE m_State;
};

/*!
 * @class     InformationPacket
 * @brief     모든 캐릭터의 이동정보 및 방향 정보에 대해서 패킷을 만들어서 편리하게 사용...
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-30 
 * @warning   
 */
typedef std::list<CharacterInformation>				CharacterList;
typedef std::list<CharacterInformation>::iterator	CharacterIter;

class InformationPacketMaker
{
private:
	/*!
	 * @brief 한꺼번에 보낼 플레이어의 수...
	 */
	int				m_iPlayerNumber;
	CharacterList	m_CharList;

	Packet*			m_pPacket;

	void			Clear();
public:
	InformationPacketMaker(void);
	~InformationPacketMaker(void);

	void	SetPacket(Packet* pPacket);
	
	void InputInformation(int id, vector3df Position, vector3df Direction, UNIT_ACTION_STATE state);
	void InputInformation(CharacterInformation& info);
	void Build();
	CharacterList OutPutInformation();
};

typedef std::list<User*>				UserList;

class UserInfomationPacketMaker
{
private:
	UserList	m_UserList;

	Packet*		m_pPacket;
public:
	UserInfomationPacketMaker();
	~UserInfomationPacketMaker();

	void SetPacket(Packet* pPacket);

	void InputUserInformation(int id, NetworkControler* pControler);
	void Build();

	UserList OutPutUserInformation();
};