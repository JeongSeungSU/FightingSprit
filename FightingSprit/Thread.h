#pragma once
#include "Network.h"

class CThread
{

private:
	static	DWORD	WINAPI	handleRunner( LPVOID parameter );

	bool		m_bIsStarted;
	DWORD		m_dwThreadID;

protected:
	HANDLE		m_HandleThread;

public:
	CThread();
	virtual ~CThread();

	virtual	void		run(){}

	DWORD		getThreadID();
	void		begin();




};
