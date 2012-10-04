#pragma once
#include "state.h"
#include "Observer.h"
#include "PacketFactory.h"
#include "NetworkControler.h"


enum
{
	GUI_ID_SERVER_BUTTON = 101,
	GUI_ID_CLIENT_BUTTON,
	GUI_ID_CONNECT_BUTTON,
	GUI_ID_TEXT_BOX
};



class StateNetwork : public IState , CObserverEvent
{
private:
	bool			m_bSelectState;
	IGUIButton*		m_pConnectButton;
	IGUIEditBox*	m_pServerIpBox;

	ITexture*		m_pBackGround;


	//네트워크 컨트롤러... 클라이언트는 신호를 쏘고 REQ를 받아야 넘어감 안그러면 안됨...
	NetworkControler*			m_pNetworkControler;
	PacketFactory				m_PacketFactory;
public:
	StateNetwork(void);
	~StateNetwork(void);
public:
	void Init();
	STATE Update();
	void Draw();

	bool OnEvent(const SEvent& event);
};
