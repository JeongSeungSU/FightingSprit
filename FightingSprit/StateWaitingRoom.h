#pragma once
#include "Glober.h"
#include "state.h"
#include "ObserverEvent.h"
#include "NetworkControler.h"
#include "PacketFactory.h"

class StateWaitingRoom : public IState, CObserverEvent
{
private:

	NetworkControler*			m_pNetworkControler;
	PacketFactory				m_PacketFactory;
public:
	StateWaitingRoom(void);
	~StateWaitingRoom(void);
public:
	void Init();
	STATE Update();
	void Draw();

	bool OnEvent(const SEvent& event);
};
