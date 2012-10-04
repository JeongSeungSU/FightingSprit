#include "TerrainObject.h"

TerrainObject::TerrainObject(void)
{
}

TerrainObject::~TerrainObject(void)
{
}

bool TerrainObject::Init(ISceneManager* Manager,IAnimatedMesh* pMesh)
{
	if((m_pTerrainNode = Manager->addOctTreeSceneNode(pMesh->getMesh(0))) == NULL)
		return false;

	if((m_pTerrainTriangeSelecter = Manager->createOctTreeTriangleSelector(pMesh->getMesh(0),
		m_pTerrainNode,2048)) == NULL)
		return false;

	m_pTerrainNode->setTriangleSelector(m_pTerrainTriangeSelecter);

	m_pTerrainMesh = pMesh;

	m_pTerrainNode->setMaterialFlag(EMF_LIGHTING,false);


	return true;
}
void TerrainObject::Update(DWORD Time)
{
	
}