#pragma once
#include "Glober.h"
#include "User.h"

/*!
 * ���� ���� ������ ��� �ִ�.
 * Ŭ���̾�Ʈ�� �� ����Ʈ�� ������....
 */
typedef std::map<int,User*>		UserMap;
typedef UserMap::iterator		UserIter;

struct ServerInfo
{
public:
	ServerInfo()
	:m_iUserNumber(0)
	{}
	~ServerInfo();
	
	/*!
	 * @brief ���� ������ �ִ� ������
	 */
	int			m_iUserNumber;

	/*!
	 * @brief ���� ����Ʈ ���� ������ ��� �ִ�. Ŭ���̾�Ʈ�� ���踦 ���� ������ �����ұ�?����..
	 */
	UserMap		m_UserMap;


	void	AddUser(User* user);
	void	SubtractionUser(int id);		
	User*	GetUserInfo(int id);

	int		GetUserNum() {return m_iUserNumber;}
};