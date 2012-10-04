#include "StateWaitingRoom.h"
#include "Irrdevice.h"

StateWaitingRoom::StateWaitingRoom(void)
{
}

StateWaitingRoom::~StateWaitingRoom(void)
{
}

void StateWaitingRoom::Init()
{
	m_pNetworkControler = NetworkManager::getInstance()->GetNetworkControler();
	Irrdevice* pDevice = Irrdevice::GetInstance();

	IGUIEnvironment* pGuiEnviron = pDevice->GetGUIEnvironment();
	IVideoDriver* pVideoDriver	 = pDevice->GetVideoDriver();
	ISceneManager* pSceneManager = pDevice->GetSceneManager();
		

	IAnimatedMesh* mesh = pSceneManager->getMesh("media/ninja.b3d");
	IAnimatedMesh* mesh2 = pSceneManager->getMesh("media/dd.X");
	SMaterial material;

	ITexture* tex = pVideoDriver->getTexture("media/nskinbl.jpg");
	material.setTexture(0,tex);
	material.Lighting = false;
	material.NormalizeNormals = true;

	IAnimatedMeshSceneNode* node = pSceneManager->addAnimatedMeshSceneNode(mesh);
	IAnimatedMeshSceneNode* node2 = pSceneManager->addAnimatedMeshSceneNode(mesh2);
	node->setMaterialFlag(EMF_LIGHTING, false);
	node2->setMaterialFlag(EMF_LIGHTING, false);
	node->getMaterial(0) = material;
	node->setPosition(vector3df(0,10,0));

	pSceneManager->addCameraSceneNode(0, vector3df(0,0,-30));

	node2->setAnimationSpeed(1000);
	node->setAnimationSpeed(10);
	mesh->drop();
	mesh2->drop();


}
STATE StateWaitingRoom::Update()
{
	SmartPointer<PacketAddr> pAddr;
	if( (pAddr = m_pNetworkControler->GetPacket()) != NULL)
	{
		switch(pAddr->m_Packet.Protocolid())
		{
		case CONNECT_ACK:
			int id = m_pNetworkControler->GetNewID();
			m_pNetworkControler->AddUser(pAddr->m_SocketAddr,"zksdlfakj",id);
			SmartPointer<Packet> pt = m_PacketFactory.ConnectPacketREQ(id,m_pNetworkControler);
			m_pNetworkControler->SendServerToClientPacket(*pt);
			break;
		}
	}

	return STATE_NONE;
}
void StateWaitingRoom::Draw()
{

}

bool StateWaitingRoom::OnEvent(const SEvent& event)
{
	return true;
}