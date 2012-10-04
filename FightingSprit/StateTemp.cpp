#include "StateTemp.h"
#include "NetworkControler.h"
#include "Irrdevice.h"
#include "Protocol.h"
#include "CommandFactory.h"

StateTemp::StateTemp(void)
{
}

StateTemp::~StateTemp(void)
{
	SAFE_DELETE(m_pUserConnect);
	SAFE_DELETE(m_pMe);
	SAFE_DELETE(m_pYou);

	SAFE_DELETE(m_pNinja);
	SAFE_DELETE(m_pNinja2);
	SAFE_DELETE(m_pTerrain);
}
void StateTemp::Init()
{
	SKeyMap aKeyMap[5];
	aKeyMap[0].Action = EKA_MOVE_FORWARD;
	aKeyMap[0].KeyCode = KEY_KEY_W;
	aKeyMap[1].Action = EKA_MOVE_BACKWARD;
	aKeyMap[1].KeyCode = KEY_KEY_S;
	aKeyMap[2].Action = EKA_STRAFE_LEFT;
	aKeyMap[2].KeyCode = KEY_KEY_A;
	aKeyMap[3].Action = EKA_STRAFE_RIGHT;
	aKeyMap[3].KeyCode = KEY_KEY_D;
	aKeyMap[4].Action = EKA_JUMP_UP;
	aKeyMap[4].KeyCode = KEY_SPACE;
	m_pCamera = Irrdevice::GetInstance()->GetSceneManager()->addCameraSceneNodeFPS(NULL, 50.f, 0.1f, -1, aKeyMap, 9, FALSE, 2.f);
	m_pNetworkControl = NetworkManager::getInstance()->GetNetworkControler();
	m_pCamera->setPosition(vector3df(20,2000,20));

	ISceneManager * smgr = Irrdevice::GetInstance()->GetSceneManager();
	IVideoDriver * driver = Irrdevice::GetInstance()->GetVideoDriver();

	m_MyId = -1;
	m_OhterId = -1;

	
	///////////////////////////여기서 부터 테스트
	IAnimatedMesh * Terrain = smgr->getMesh("media/test.X");
	m_pTerrain = new TerrainObject();
	m_pTerrain->Init(smgr,Terrain);


	m_pNinja = new UnitObject();
	IAnimatedMesh* mesh = smgr->getMesh("media/ninja.b3d");
	m_pNinja->init(smgr,mesh,NULL,1);
	m_pMe = new Player();
	m_pMe->Init(m_pNinja,m_pTerrain->GetTriangleSelecter());


	m_pNinja2 = new UnitObject();
	m_pNinja2->init(smgr,mesh,NULL,2);
	m_pYou = new Player();
	m_pYou->Init(m_pNinja2,m_pTerrain->GetTriangleSelecter());


	m_pMe->AddPlayerTriangleSelecter(m_pYou);
	m_pYou->AddPlayerTriangleSelecter(m_pMe);

	m_pMe->SetPosition(vector3df(50,2100,50));
	m_pYou->SetPosition(vector3df(-50,2100,-50));


	//m_pMe->SetActiveCamera();

	

	//커맨드패턴.. -_-;
	//m_pUserConnect = CommandFactory::CreateUserConnectCommand(Irrdevice::GetInstance(),m_pNetworkControl,NULL);

	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;

	//Packet p(WELCOME_ACK,0);
	//m_pNetworkControl->SendClientToPacket(p);

}
STATE StateTemp::Update()
{
	SmartPointer<PacketAddr> pAddr;

 	m_pNetworkControl->ReceivePacket();
	ISceneManager * smgr = Irrdevice::GetInstance()->GetSceneManager();
 	if((pAddr= m_pNetworkControl->GetPacket()) != NULL)
 	{
 		ServerPacketParsing(pAddr.getPoint());
 	}

	if(IsKeyDown(irr::KEY_KEY_T))
	{
		smgr->setActiveCamera(m_pCamera);
	}
	if(IsKeyDown(irr::KEY_KEY_H))
	{
		m_pMe->SetActiveCamera();
	}
	if(IsKeyDown(irr::KEY_KEY_N))
	{
		m_pYou->SetActiveCamera();
	}
	


// 	if(IsKeyDown(irr::KEY_KEY_T))
// 	{
// 		Packet p(BASE_ACK,m_MyId);	
// 		p<<1;
// 		m_pNetworkControl->SendClientToPacket(p);
// 	}
// 	if(IsKeyDown(irr::KEY_KEY_F))
// 	{
// 		Packet p(BASE_ACK,m_MyId);	
// 		p<<2;
// 		m_pNetworkControl->SendClientToPacket(p);
// 	}
// 	if(IsKeyDown(irr::KEY_KEY_G))
// 	{
// 		Packet p(BASE_ACK,m_MyId);	
// 		p<<3;
// 		m_pNetworkControl->SendClientToPacket(p);
// 	}
// 	if(IsKeyDown(irr::KEY_KEY_H))
// 	{
// 		Packet p(BASE_ACK,m_MyId);	
// 		p<<4;
// 		m_pNetworkControl->SendClientToPacket(p);
// 	}

	return STATE_NONE;
}
void StateTemp::Draw()
{
	
}
bool StateTemp::OnEvent(const SEvent& event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	return false;
}


void StateTemp::ServerPacketParsing(PacketAddr* packet)
{
	ISceneManager * smgr = Irrdevice::GetInstance()->GetSceneManager();
	IVideoDriver * driver = Irrdevice::GetInstance()->GetVideoDriver();
	int i =0;
	int Move;
	Packet p;

// 	switch (packet->m_Packet.Protocolid())
// 	{
// 	case WELCOME_ACK:
// 		m_pUserConnect->SetPacket(packet);
// 		m_pUserConnect->Excute();
// 		break;
// 	case WELCOME_REQ:
// 		m_pNetworkControl->AddUser(packet);
// 
// 		(packet->m_Packet)>>i;
// 		if( i== 2)
// 		{
// 			m_MyId	  = 2;
// 			m_OhterId = 1;
// 			m_pMe = smgr->addAnimatedMeshSceneNode(faerie);
// 			m_pMe->setPosition(vector3df(-10,-30,50));
// 
// 			m_pOther	= smgr->addAnimatedMeshSceneNode(ninja);
// 			m_pOther->setPosition(vector3df(10,-30,50));
// 		}
// 		break;
// 	case BASE_ACK:
// 		packet->m_Packet>>Move;
// 		
// 		MoveNode(Move,packet->m_Packet.ID());
// 		
// 		p.Protocolid(BASE_REQ);
// 		p.ID(packet->m_Packet.ID());
// 		p<<Move;
// 		m_pNetworkControl->SendServerToPacket(p);
// 		break;
// 	case BASE_REQ:
// 		packet->m_Packet>>Move;
// 
// 		MoveNode(Move,packet->m_Packet.ID());
// 		break;
// 	}
// 	


}
void StateTemp::MoveNode(int move,int ID)
{
// 	ISceneNode * pNode;
// 	vector3df vc;
// 
// 	if(ID == m_MyId)
// 		pNode = m_pMe;
// 	else
// 		pNode = m_pOther;
// 	
// 	switch(move)
// 	{
// 	case 1:
// 		vc = pNode->getPosition();
// 		vc.X+=0.1f;
// 		pNode->setPosition(vc);
// 		break;
// 	case 2:
// 		vc = pNode->getPosition();
// 		vc.X-=0.1f;
// 		pNode->setPosition(vc);
// 		break;
// 	case 3:
// 		vc = pNode->getPosition();
// 		vc.Y+=0.1f;
// 		pNode->setPosition(vc);
// 		break;
// 	case 4:
// 		vc = pNode->getPosition();
// 		vc.Y-=0.1f;
// 		pNode->setPosition(vc);
// 		break;
// 	}
}