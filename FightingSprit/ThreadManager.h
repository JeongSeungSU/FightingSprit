#pragma once
#include "Glober.h"
#include "Network.h"

class CThreadManager
{
private:
	CThreadManager();
	virtual ~CThreadManager();

	static	CThreadManager*						m_pInstance;

	std::list	< HANDLE >						ListThreadHandle;
	typedef	std::list< HANDLE >::iterator		ListPosition;

public:
	static	CThreadManager*	getInstance();
	static	void			releaseInstance();

	void			join();
	HANDLE			spawn( LPTHREAD_START_ROUTINE startAddress, LPVOID parameter, DWORD* identifier );
};
