#include "Observer.h"

CObserver::CObserver(void)
{
}

CObserver::~CObserver(void)
{
	m_ObList.clear();
}

bool CObserver::OnEvent(const SEvent& event)
{
	for(OBITER iter = m_ObList.begin(); iter != m_ObList.end()  ; iter++)
	{
		(*iter)->OnEvent(event);
	}
	return false;
}

void	CObserver::Register(CObserverEvent	*pt)
{
	m_ObList.push_back(pt);
}
void	CObserver::UnRegister(CObserverEvent	*pt)
{
	for(OBITER iter = m_ObList.begin(); iter != m_ObList.end();)
	{
		iter = m_ObList.erase(iter);
		
	}
}
