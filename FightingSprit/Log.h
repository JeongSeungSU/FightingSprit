#pragma once

#include "Time.h"

class CLog
{
protected:
	Time* m_Timer;
public:
	CLog(Time* Timer);
	virtual ~CLog(void);

	virtual void PrintStringLog(char* string) = 0;
};
