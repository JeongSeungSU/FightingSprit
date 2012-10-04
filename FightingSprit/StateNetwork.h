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


	//��Ʈ��ũ ��Ʈ�ѷ�... Ŭ���̾�Ʈ�� ��ȣ�� ��� REQ�� �޾ƾ� �Ѿ �ȱ׷��� �ȵ�...
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
