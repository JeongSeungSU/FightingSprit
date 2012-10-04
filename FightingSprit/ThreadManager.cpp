#include "ThreadManager.h"

CThreadManager*	CThreadManager::m_pInstance = 0;

CThreadManager::CThreadManager()
{
}

CThreadManager::~CThreadManager()
{
	ListPosition pos;

	while( ListThreadHandle.size() > 0 )
		ListThreadHandle.erase( ListThreadHandle.begin() );
}

CThreadManager* CThreadManager::getInstance()
{
	if( m_pInstance == 0)
		m_pInstance = new CThreadManager();

	return m_pInstance;
}

void CThreadManager::releaseInstance()
{
	if( m_pInstance != 0 )
	{
		delete m_pInstance;
		m_pInstance = 0;
	}
}


void CThreadManager::join()
{
	ListPosition pos, posPrev;

	pos = ListThreadHandle.begin();
	while( pos != ListThreadHandle.end() )
	{
		posPrev = pos++;

		::WaitForSingleObject( *posPrev, INFINITE );

		ListThreadHandle.erase( posPrev );
	}
}

HANDLE CThreadManager::spawn( LPTHREAD_START_ROUTINE startAddress, LPVOID parameter, DWORD* threadID )
{
	HANDLE threadHandle;

	threadHandle = ::CreateThread( 0, 0, startAddress, parameter, 0, threadID );

	ListThreadHandle.push_back( threadHandle );

	return threadHandle;
}
