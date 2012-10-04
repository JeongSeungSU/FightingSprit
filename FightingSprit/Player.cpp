#include "Player.h"
#include "Irrdevice.h"

Player::Player(void)
{
	//�ӽ�
	m_UnitAction	 = STAND;
	m_UnitState		 = LIVE;

}

Player::~Player(void)
{
}
void Player::Init(UnitObject* pUnit,ITriangleSelector* pTerrain)
{
	Irrdevice* pDevice 	= Irrdevice::GetInstance();
	m_pUnitObject		= pUnit;

	ISceneManager* pSmgr = pDevice->GetSceneManager();

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

	//�� ���ָ��� ī�޶� ����
	m_pCamera = pSmgr->addCameraSceneNodeFPS(0,100.0f,0.5f,-1,aKeyMap,9,false,0,false,false);
	m_pCollisionAnimator = static_cast<ISceneNodeAnimatorCameraFPS*>(*(m_pCamera->getAnimators().begin()));	//ī�޶� ������ �ִ� FPS ī�޶� �ִϸ��̼� �� �����´�. �̰��� �� Ȯ�� ��� ��!!
	
	
	//ī�޶� ������� ���� ������Ʈ... ���⿡ ���Ѱ͵� �����������... �̰��� �ϴ� ���߿� �׽�Ʈ�� ���Ͽ�
	m_pUnitObject->GetAnimatedNode()->setParent(m_pCamera);

	
	IMeshSceneNode* pNode = pSmgr->addCubeSceneNode(10,m_pCamera);
	m_pCamera->addChild(pUnit->GetAnimatedNode());

	pNode->setVisible(true);

	m_pMyTriangle = pSmgr->createTriangleSelector(pNode->getMesh(),pNode);
	
	m_pMetaTriangle = pSmgr->createMetaTriangleSelector();
	m_pMetaTriangle->addTriangleSelector(pTerrain);
	
	//���� ��ũ��Ʈ ���� ���� ���� ����... ������ �о�ͼ� �����ϴ���.... �ƿ�
	ISceneNodeAnimatorCollisionResponse * pani = pSmgr->createCollisionResponseAnimator(m_pMetaTriangle,m_pCamera);
	m_pCamera->addAnimator(pani);
	pani->drop();
	
}
void Player::AddPlayerTriangleSelecter(Player* pPlayer)
{
	m_pMetaTriangle->addTriangleSelector(pPlayer->m_pMyTriangle);
}

void Player::RemovePlayerTriangleSelecter(Player* pPlayer)
{
	m_pMetaTriangle->removeTriangleSelector(pPlayer->m_pMyTriangle);
}

void Player::Update(DWORD time)
{
	
}

void Player::Shooting()
{
	
}
void Player::Die()
{

}
void Player::Respawn()
{

}
void Player::SetActiveCamera()
{
	Irrdevice* pDevice = Irrdevice::GetInstance();

	pDevice->GetSceneManager()->setActiveCamera(m_pCamera);
	m_pCamera->setInputReceiverEnabled(true);
}
void Player::SetPosition(vector3df vec)
{
	m_pCamera->setPosition(vec);
}