#pragma once
#include "Glober.h"
#include "packet.h"
#include "User.h"
#include "NetworkControler.h"



/*!
 * Struct comment �� ����ü�� ���ɸ����� ��� �̵��������� ���ԵǾ��ִ�..
 * �ǽð����� �ѷ��ֱ� ���� �� �ʿ��� �����鸸 ��Ƴ�������...
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
 * @brief     ��� ĳ������ �̵����� �� ���� ������ ���ؼ� ��Ŷ�� ���� ���ϰ� ���...
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
	 * @brief �Ѳ����� ���� �÷��̾��� ��...
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