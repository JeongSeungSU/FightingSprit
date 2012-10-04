#pragma once
#include "Irrdevice.h"
#include "StateFactyory.h"


class FightingSprit
{
private:
	IState*			m_pState;
	StateFactyory	m_StateFactory;

public:
	FightingSprit(void);
	~FightingSprit(void);
	void Run();
	void ModifyState(STATE TargetState);
};
