#pragma once
#include "Glober.h"
#include "Command.h"

typedef std::list<Command*>		CommandList;
typedef CommandList::iterator	CommandIter;


class MacroCommand : public Command
{
private:
	CommandList			m_CommandList;
public:
	MacroCommand(void);
	~MacroCommand(void);

	void addCommand(Command* pCommand);		//������Ʈ �߰�...
	
	void Excute();
};
