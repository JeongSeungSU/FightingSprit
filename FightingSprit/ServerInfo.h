#pragma once
#include "Glober.h"
#include "User.h"

/*!
 * 각종 서버 정보를 담고 있다.
 * 클라이언트도 이 리스트를 가진다....
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
	 * @brief 현재 접속해 있는 유져수
	 */
	int			m_iUserNumber;

	/*!
	 * @brief 유져 리스트 각종 정보를 담고 있다. 클라이언트와 연계를 위한 정보도 포함할까?포함..
	 */
	UserMap		m_UserMap;


	void	AddUser(User* user);
	void	SubtractionUser(int id);		
	User*	GetUserInfo(int id);

	int		GetUserNum() {return m_iUserNumber;}
};