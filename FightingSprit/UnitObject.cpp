#include "UnitObject.h"

UnitObject::UnitObject(void)
{
}

UnitObject::~UnitObject(void)
{
}

void UnitObject::init(ISceneManager* Manager,IAnimatedMesh* pMesh,ISceneNode * Parent,
					  int ID)
{
	m_pParent = Parent;
	m_pAnimatedMeshNode = Manager->addAnimatedMeshSceneNode(pMesh,Parent,ID);
	m_pAnimatedMeshNode->setMaterialFlag(EMF_LIGHTING,false);
	
}