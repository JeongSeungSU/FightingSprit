#pragma once
#include "Glober.h"
#include "ObserverEvent.h"
//��� ������ Ŭ���� �̺�Ʈ ���ù��� ���� �̺�Ʈ���� �ѷ��ִ� �ߴ� ������?
//���������� �ϵ� �����Ǽ� ���Ύ� ��������� ����??

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
