#pragma once
#include "Glober.h"
#include "Network.h"

/*!
 * @class     User
 * @brief     접속한 유져의 정보를 가진다.
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-02-23 
 * @warning   
 */
class User
{
public:
	/*!
	 * @brief		이것은 접속하는 클라이언트들의 IP와 포트 정보를 담고 있는 객체
	 */
	sockaddr_in				m_Addr;

	/*!
	 * @brief		서버에서 내려주는 기본 아이디..
	 */
	int						m_iID;

	/*!
	 * @brief		유져를 구분 하는 이름...이것은 클라이언트가 지어서 서버에 보냄...
	 */
	char					m_pUserName[255];

	/*!
	 * @brief		이 유져가 서버냐 아니냐 판단...
	 */
	bool					m_Server;



public:
	User(){}
	User(sockaddr_in Addr,int ID,char* Name,bool IsServer);
	~User(void);
};

