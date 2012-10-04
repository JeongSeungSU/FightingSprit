#pragma once
#include "object.h"

class TerrainObject :
	public Object
{
private:
	IAnimatedMesh*		m_pTerrainMesh;
	ISceneNode*			m_pTerrainNode;
	ITriangleSelector*	m_pTerrainTriangeSelecter;

	char*				m_pTerrainFileName;
public:
	TerrainObject(void);
	~TerrainObject(void);


	bool Init(ISceneManager* Manager,IAnimatedMesh* pMesh);
	void Update(DWORD Time);

	ITriangleSelector* GetTriangleSelecter() {return m_pTerrainTriangeSelecter;}
};
