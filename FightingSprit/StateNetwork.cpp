#include "StateNetwork.h"
#include "NetworkManager.h"
#include "Irrdevice.h"


void WcharToChar(char* pstrDest, const wchar_t* pwstrSrc)
{
	int nLen=(int)wcslen(pwstrSrc);
	wcstombs(pstrDest,pwstrSrc, nLen+1);
}


StateNetwork::StateNetwork(void)
:m_pNetworkControler(0)
{
}

StateNetwork::~StateNetwork(void)
{
	Irrdevice::GetInstance()->GetGUIEnvironment()->clear();
}
void StateNetwork::Init()
{
	//일단 GUI부터 그리고 그다음에 초기화 하면서 넘어간다!!
	IVideoDriver* pDriver = Irrdevice::GetInstance()->GetVideoDriver();
	IGUIEnvironment* env  = Irrdevice::GetInstance()->GetGUIEnvironment();
	IGUISkin	   * skin = env->getSkin();

	IGUIFont* font = env->getFont("media/fonthaettenschweiler.bmp");
	if(font)
		skin->setFont(font);

	skin->setFont(env->getBuiltInFont(),EGDF_TOOLTIP);

	env->addButton(rect<s32>(10,240,110,240 + 32), 0, GUI_ID_SERVER_BUTTON,
		L"SERVER", L"HELL SERVER");
	env->addButton(rect<s32>(10,280,110,280 + 32), 0, GUI_ID_CLIENT_BUTTON,
		L"CLIENT", L"HELL CLIENT");

	m_pConnectButton = env->addButton(rect<s32>(500,280,610,280 + 32), 0, GUI_ID_CONNECT_BUTTON,
		L"CONNECT", NULL);
	m_pConnectButton ->setVisible(false);
	m_pServerIpBox = env->addEditBox(L"192.168.0.3",rect<s32>(200,280,480,280 + 32),true,0,GUI_ID_TEXT_BOX);
	m_pServerIpBox->setVisible(false);

	m_bSelectState = false;

	//배경화면

	m_pBackGround = pDriver->getTexture("media/network.jpg");

	

}
STATE StateNetwork::Update()
{
	if(m_pNetworkControler && (m_pNetworkControler->GetNetworkState() == CLIENT))
	{
		m_pNetworkControler->ReceivePacket();

		SmartPointer<PacketAddr> pAddr;
		if((pAddr = m_pNetworkControler->GetPacket()) != NULL)
		{
			if( pAddr->m_Packet.Protocolid() == CONNECT_REQ)
			{
				UserInfomationPacketMaker pkMaker;
				pkMaker.SetPacket(&pAddr->m_Packet);
				UserList lst = pkMaker.OutPutUserInformation();
				UserList::iterator iter;
				for(iter = lst.begin(); iter != lst.end(); iter++)
				{
					//여기에다가 이미 존재하는 유져가 있을경우 AddUser를 호출하지 않게 만들어야 함...
					m_pNetworkControler->AddUser((*iter));
					delete (*iter);
				}
				lst.clear();

				m_pNetworkControler->SetMyUserID(pAddr->m_Packet.ID());
				return STATE_WAITINGROOM;
			}
		}
	}

	if(m_bSelectState)
		return STATE_WAITINGROOM;
	else
		return STATE_NONE;
}
bool StateNetwork::OnEvent(const SEvent& event)
{
	if (!Irrdevice::GetInstance()->GetDevice())
		return false;


	char buf[255];
	if (event.EventType == EET_GUI_EVENT)
	{
		s32 id = event.GUIEvent.Caller->getID();
		SmartPointer<Packet> smt;

		switch(event.GUIEvent.EventType)
		{
		case EGET_BUTTON_CLICKED:
			switch(id)
			{
			case GUI_ID_SERVER_BUTTON:
				m_pNetworkControler = NetworkManager::getInstance()->InitNetwork(SERVER,NULL);
				smt = m_PacketFactory.ConnectPacket();
				m_pNetworkControler->SendClientToServerPacket(*smt);
				m_bSelectState = true;
				break;
			case GUI_ID_CLIENT_BUTTON:
				m_pServerIpBox->setVisible(true);
				m_pConnectButton->setVisible(true);
				break;
			case GUI_ID_CONNECT_BUTTON:
				NetworkManager::getInstance()->DestoryNetwork();
				
				WcharToChar(buf,m_pServerIpBox->getText());
				m_pNetworkControler = NetworkManager::getInstance()->InitNetwork(CLIENT,buf);
				smt = m_PacketFactory.ConnectPacket();
				m_pNetworkControler->SendClientToServerPacket(*smt);
				//m_bSelectState = true;
				break;
			}
			break;
		}

	}
	return true;
}
void StateNetwork::Draw()
{
	IVideoDriver* pDriver = Irrdevice::GetInstance()->GetVideoDriver();
	pDriver->draw2DImage(m_pBackGround,core::position2d<s32>(0,0),core::rect<s32>(0,0,800,600));
}