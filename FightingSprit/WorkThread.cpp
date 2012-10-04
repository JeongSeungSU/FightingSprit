#include "WorkThread.h"
#include "CompletionHandler.h"
#include "Session.h"

CWorkThread::CWorkThread()
{
	m_HandleKillEvent = ::CreateEvent( 0, 0, 0, 0 );
}

CWorkThread::~CWorkThread()
{
	::SetEvent( m_HandleKillEvent );

	::WaitForSingleObject( m_HandleThread, 1000 );

	::CloseHandle( m_HandleKillEvent );
}

void CWorkThread::run()
{
	DWORD bytesTransfer, keyValue;
	LPOVERLAPPED overlapped;
	bool retVal;
	HANDLE handleIOCP = CCompletionHandler::getInstance()->getWorkerIOCPHandle();

	while( 1 )
	{
		if( WaitForSingleObject( m_HandleKillEvent, 1 ) == WAIT_OBJECT_0 )
			break;

		keyValue = 0;
		overlapped = 0;

		retVal = GetQueuedCompletionStatus( handleIOCP, &bytesTransfer, &keyValue, &overlapped, INFINITE );

		if( retVal == TRUE && keyValue != 0 && bytesTransfer != 0 && overlapped != 0 )
		{
			Session* session = ( Session* )keyValue;

			session->dispatch( bytesTransfer, overlapped );
		}
		else
		{
			//if( keyValue != 0 && GetLastError() != ERROR_OPERATION_ABORTED )
				//세션 삭제CSessionManager::getInstance()->removeSession( ( CSessionFuck* )keyValue );
		}
	}
}
