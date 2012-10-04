#pragma once
#include "object.h"

/*!
 * @class     UnitObject
 * @brief     �ʻ󿡼� ���ƴٴϴ� ���... �̳�� ���� ī�޶� ������ ����...
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-08 
 * @warning   
 */
class UnitObject :public Object
{
private:
	IAnimatedMeshSceneNode*				m_pAnimatedMeshNode;
	ISceneNode*							m_pParent;

public:
	UnitObject(void);
	~UnitObject(void);
	
	void init(ISceneManager* Manager,IAnimatedMesh* pMesh,ISceneNode * Parent,int ID);
	void Update(DWORD Time) {};

	IAnimatedMeshSceneNode* GetAnimatedNode() {return m_pAnimatedMeshNode;}

	ITriangleSelector* GetTriangleSelecter() {return m_pAnimatedMeshNode->getTriangleSelector();}
};
