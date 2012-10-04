#pragma once
#include "Glober.h"

class Time
{
public:
	Time(void);
	virtual ~Time(void);

	virtual	DWORD GetNowTime() = 0;
};
