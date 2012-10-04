#pragma once
#include "UnitObject.h"
#include "TerrainObject.h"
#include "SkyBoxObject.h"
#include "Irrdevice.h"

/*!
 * @class     ObjectFactory
 * @brief     ������Ʈ ���� ���...
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-08 
 * @warning   
 */

class ObjectFactory
{
private:
	Irrdevice*			m_pIrrdevice;
public:
	ObjectFactory(Irrdevice* pIrrdevice);
	~ObjectFactory(void);
public:
	UnitObject*			CreateUnitObject(IAnimatedMesh* pMesh,ISceneNode * Parent,int ID);
	TerrainObject*		CreateTerrainObject();
	SkyBoxObject*		CreateSkyBoxObject();
};
