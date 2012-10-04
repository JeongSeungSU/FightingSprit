#include "StateFactyory.h"

StateFactyory::StateFactyory(void)
{
}

StateFactyory::~StateFactyory(void)
{
}



IState* StateFactyory::operator()(STATE State)
{
	IState* pState = NULL;
	switch (State)
	{
	case STATE_MAIN:
		return NULL;
	case STATE_FIGHTING:
		return NULL;
	case STATE_NETWORK:
		pState = new StateNetwork();
		pState->Init();
		return pState;
	case STATE_TEMP:
		pState = new StateTemp();
		pState->Init();
		return pState;
	case  STATE_WAITINGROOM:
		pState = new StateWaitingRoom();
		pState->Init();
		return pState;
	default:
		throw JsException("STATEFACTORY::OPERATOR() : YOU SATATE IS NOTHING Select\n");
	}
}