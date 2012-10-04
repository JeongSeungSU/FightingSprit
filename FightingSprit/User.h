#pragma once
#include "Glober.h"
#include "Network.h"

/*!
 * @class     User
 * @brief     ������ ������ ������ ������.
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-02-23 
 * @warning   
 */
class User
{
public:
	/*!
	 * @brief		�̰��� �����ϴ� Ŭ���̾�Ʈ���� IP�� ��Ʈ ������ ��� �ִ� ��ü
	 */
	sockaddr_in				m_Addr;

	/*!
	 * @brief		�������� �����ִ� �⺻ ���̵�..
	 */
	int						m_iID;

	/*!
	 * @brief		������ ���� �ϴ� �̸�...�̰��� Ŭ���̾�Ʈ�� ��� ������ ����...
	 */
	char					m_pUserName[255];

	/*!
	 * @brief		�� ������ ������ �ƴϳ� �Ǵ�...
	 */
	bool					m_Server;



public:
	User(){}
	User(sockaddr_in Addr,int ID,char* Name,bool IsServer);
	~User(void);
};

