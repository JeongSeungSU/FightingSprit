#pragma once
#include "UnitObject.h"


/*!
 * @class     Player
 * @brief     유닛오브젝트에 대한 인터페이스
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-08 
 * @warning   
 */



class Player
{
private:
	unsigned int						m_HitPoint;
	
	UnitObject*							m_pUnitObject;

	ICameraSceneNode*					m_pCamera;
	ISceneNodeAnimatorCameraFPS*		m_pCollisionAnimator;

	ITriangleSelector*					m_pMyTriangle;
	IMetaTriangleSelector*				m_pMetaTriangle;

	UNIT_ACTION_STATE					m_UnitAction;
	UNIT_STATE							m_UnitState;
public:
	Player(void);
	~Player(void);

public:
	void Init(UnitObject* pUnit,ITriangleSelector* pTerrain);
	void Update(DWORD time);

	void AddPlayerTriangleSelecter(Player* pPlayer);
	void RemovePlayerTriangleSelecter(Player* pPlayer);

	void SetPosition(vector3df vec);

	void Shooting();
	void Die();
	void Respawn();

	void SetActiveCamera();

};
