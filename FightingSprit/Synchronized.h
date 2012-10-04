#pragma once
#include "CriticalSection.h"


class Synchronized
{
private:
	CriticalSection*	m_pCriticalSection;

public:
	Synchronized( CriticalSection* cs );
	virtual ~Synchronized(void);
};
