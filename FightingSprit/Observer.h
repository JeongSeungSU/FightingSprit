#pragma once
#include "Glober.h"
#include "ObserverEvent.h"
//당근 옵저버 클래스 이벤트 리시버로 받은 이벤트들은 뿌려주는 야는 옵저브?
//구현안한지 하도 오래되서 씨부뢀 어케헀드라 ㅋㅋ??

typedef std::vector<CObserverEvent*>				OBLIST;
typedef std::vector<CObserverEvent*>::iterator		OBITER;

class CObserver :public IEventReceiver
{
private:
	OBLIST		m_ObList;
public:
	CObserver(void);
	~CObserver(void);

public:
	bool OnEvent(const SEvent& event);

public:
	void	Register(CObserverEvent	*pt);
	void	UnRegister(CObserverEvent	*pt);

};
