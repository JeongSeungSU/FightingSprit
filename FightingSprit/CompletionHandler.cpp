#include "CompletionHandler.h"

CCompletionHandler*	CCompletionHandler::m_pSelfInstance = 0;

CCompletionHandler::CCompletionHandler()
: m_HandleWorkerIOCP( 0 )
{
}

CCompletionHandler::~CCompletionHandler()
{
	int i;

	for( i = 0 ; i < WorkerThreadCount ; i++ )
		delete m_pWorkerThread[i];
}

CCompletionHandler* CCompletionHandler::getInstance()
{
	if( m_pSelfInstance == 0 )
		m_pSelfInstance = new CCompletionHandler();

	return m_pSelfInstance;
}

void CCompletionHandler::releaseInstance()
{
	if( m_pSelfInstance != 0 )
	{
		delete m_pSelfInstance;
		m_pSelfInstance = 0;
	}
}

bool CCompletionHandler::initialize()
{
	m_HandleWorkerIOCP = ::CreateIoCompletionPort( INVALID_HANDLE_VALUE, 0, 0, WorkerThreadCount );
	if( m_HandleWorkerIOCP == 0 )
		return false;

	int i;

	for( i = 0 ; i < WorkerThreadCount ; i++ )
	{
		m_pWorkerThread[i] = new CWorkThread();
		m_pWorkerThread[i]->begin();
	}

	return true;
}

HANDLE CCompletionHandler::getWorkerIOCPHandle()
{
	return m_HandleWorkerIOCP;
}

bool CCompletionHandler::addHandleToIOCP( HANDLE handle, DWORD keyValue )
{
	::CreateIoCompletionPort( handle, m_HandleWorkerIOCP, keyValue, 0 );

	return true;
}
