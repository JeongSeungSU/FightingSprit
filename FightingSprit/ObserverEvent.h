#pragma once
#include "Glober.h"

class CObserverEvent
{
private:
	

public:
	CObserverEvent(void);
	virtual ~CObserverEvent(void);

	virtual bool OnEvent(const SEvent& event) = 0;

};
