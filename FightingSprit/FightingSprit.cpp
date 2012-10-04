#include "FightingSprit.h"

FightingSprit::FightingSprit(void)
{
	Irrdevice::GetInstance()->Init(EDT_DIRECT3D9, 800, 600, 32, false, TRUE);
	Irrdevice::GetInstance()->GetDevice()->setWindowCaption(L"ÅõÈ¥");	

	m_pState = NULL;
	ModifyState(STATE_NETWORK);
}
FightingSprit::~FightingSprit(void)
{
}
void FightingSprit::Run()
{
	Irrdevice* pIrrlicht = Irrdevice::GetInstance();

	while(pIrrlicht->GetDevice()->run())
	{

		STATE State = m_pState->Update();
		if(State != STATE_NONE)
		{
			ModifyState(State);
		}

		pIrrlicht->GetVideoDriver()->beginScene(true, true,video::SColor(255,255,255,255));
		{
			m_pState->Draw();
			pIrrlicht->GetSceneManager()->drawAll();
			pIrrlicht->GetGUIEnvironment()->drawAll();

		}
		pIrrlicht->GetVideoDriver()->endScene();
	}

}
void FightingSprit::ModifyState(STATE TargetState)
{
	if(m_pState) delete m_pState;

	m_pState = m_StateFactory(TargetState);
}

