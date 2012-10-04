#pragma once
#include "state.h"
#include "ObserverEvent.h"
#include "ChildCommand.h"
#include "Player.h"
#include "TerrainObject.h"
#include "PacketFactory.h"

struct PacketAddr;
class  NetworkControler;

class StateTemp : public IState, CObserverEvent
{
private:
	int							m_MyId;
	int							m_OhterId;
	NetworkControler*			m_pNetworkControl;
	ICameraSceneNode*			m_pCamera;
//	IAnimatedMeshSceneNode*		m_pMe;
//	IAnimatedMeshSceneNode*		m_pOther;


	Player*						m_pMe;
	Player*						m_pYou;

	UnitObject*					m_pNinja;
	UnitObject*					m_pNinja2;
	TerrainObject*				m_pTerrain;
	

	PacketFactory				m_PacketFactory;

	IAnimatedMesh * ninja ;
	IAnimatedMesh * faerie ;

	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}

	UserConnect*				m_pUserConnect;
public:
	StateTemp(void);
	~StateTemp(void);
public:
	void Init();
	STATE Update();
	void Draw();
	bool OnEvent(const SEvent& event);

	void ServerPacketParsing(PacketAddr* packet);
	void ClientPacketParsing(PacketAddr* packet);

	
	void MoveNode(int move,int ID);


	void SetMyID(int ID);
};
