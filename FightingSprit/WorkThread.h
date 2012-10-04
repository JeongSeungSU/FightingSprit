#pragma once
#include "thread.h"

class CWorkThread :
	public CThread
{

public:
	CWorkThread();
	virtual	~CWorkThread();

	virtual	void	run();

private:
	HANDLE	m_HandleKillEvent;
};
