#pragma once
#include "ObserverEvent.h"
#include "state.h"
#include "ChildCommand.h"
#include "Player.h"
#include "TerrainObject.h"
#include "PacketFactory.h"

class StateFighting : public IState, CObserverEvent
{
private:
	int							m_MyId;
	NetworkControler*			m_pNetworkControl;

	PacketFactory				m_PacketFactory;


public:
	StateFighting(void);
	~StateFighting(void);
public:

	void Init();
	STATE Update();
	void Draw();

	bool OnEvent(const SEvent& event);
};
