#include "ObjectFactory.h"

ObjectFactory::ObjectFactory(Irrdevice* pIrrdevice)
:m_pIrrdevice(pIrrdevice)
{
}

ObjectFactory::~ObjectFactory(void)
{
}

UnitObject*	ObjectFactory::CreateUnitObject(IAnimatedMesh* pMesh,ISceneNode * Parent,int ID)
{
	ISceneManager* pSceneManager = m_pIrrdevice->GetSceneManager();
//	UnitObject* pObject = new UnitObject();
//	pObject->init(pSceneManager,pMesh,Parent,ID);

//	return pObject;
	return NULL;
}