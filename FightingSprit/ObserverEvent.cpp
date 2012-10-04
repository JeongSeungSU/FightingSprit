#include "ObserverEvent.h"
#include "Irrdevice.h"

CObserverEvent::CObserverEvent(void)
{
	Irrdevice::GetInstance()->GetInputManager()->Register(this);
}

CObserverEvent::~CObserverEvent(void)
{
	Irrdevice::GetInstance()->GetInputManager()->UnRegister(this);
}
