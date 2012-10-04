#pragma once
#include "State.h"
#include "StateNetwork.h"
#include "StateTemp.h"
#include "StateFighting.h"
#include "StateWaitingRoom.h"



class StateFactyory
{
public:
	StateFactyory(void);
	~StateFactyory(void);
	IState* operator()(STATE State);
};
