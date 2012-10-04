#include "Thread.h"
#include "ThreadManager.h"

CThread::CThread()
: m_bIsStarted( false ), m_dwThreadID( 0 )
{
}

CThread::~CThread()
{
}

DWORD CThread::getThreadID()
{
	return m_dwThreadID;
}

void CThread::begin()
{
	if( m_bIsStarted == true )
		return;

	m_HandleThread = CThreadManager::getInstance()->spawn( handleRunner, this, &m_dwThreadID );

	m_bIsStarted = true;
}

DWORD WINAPI CThread::handleRunner( LPVOID parameter )
{
	CThread* thread = ( CThread* )parameter;

	thread->run();

	return 0;
}
