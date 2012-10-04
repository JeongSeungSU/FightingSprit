#pragma once
#include "WorkThread.h"

#define  WorkerThreadCount		1

class CCompletionHandler
{
public:
	static	CCompletionHandler*		getInstance();
	static	void					releaseInstance();

	bool							initialize();

	HANDLE							getWorkerIOCPHandle();
	bool							addHandleToIOCP( HANDLE handle, DWORD keyValue );

private:
	CCompletionHandler();
	virtual	~CCompletionHandler();

	static	CCompletionHandler*		m_pSelfInstance;

	HANDLE					m_HandleWorkerIOCP;
	CWorkThread*			m_pWorkerThread[WorkerThreadCount];
};
