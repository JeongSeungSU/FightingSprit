#pragma once
#include "Glober.h"

enum STATE { STATE_NONE, STATE_MAIN, STATE_TITLE, STATE_FIGHTING, STATE_NETWORK ,STATE_TEMP, STATE_WAITINGROOM};

class IState
{
public:
	IState() { }
	virtual ~IState() { }
	virtual void Init() = 0;
	virtual STATE Update() = 0;
	virtual void Draw()	= 0;
	
};