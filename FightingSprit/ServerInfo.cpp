#include "ServerInfo.h"


ServerInfo::~ServerInfo()
{
	UserIter iter;

	for(iter = m_UserMap.begin(); iter != m_UserMap.end(); iter++)
	{
		SAFE_DELETE(iter->second);
	}
	m_UserMap.clear();
}

/*!
 * @brief     유져 추가
 * @return    void
 * @param     User * user	추가할 유져
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-06 
 * @warning   
 */
void ServerInfo::AddUser(User* user)
{
	m_UserMap.insert(std::pair<int,User*>(user->m_iID,user));
	m_iUserNumber++;
}
/*!
 * @brief     유져꺼져...
 * @return    void
 * @param     int id	꺼질 유져 아이디
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-06 
 * @warning   
 */
void ServerInfo::SubtractionUser(int id)
{
	UserIter iter = m_UserMap.find(id);
	if(iter == m_UserMap.end())
		return;
	SAFE_DELETE(iter->second);
	m_UserMap.erase(id);
	m_iUserNumber--;
}

User*	ServerInfo::GetUserInfo(int id)
{
	UserIter iter = m_UserMap.find(id);
	if(iter == m_UserMap.end())
		return NULL;
	return (User*)iter->second;
}