#include "MacroCommand.h"

MacroCommand::MacroCommand(void)
{
}

MacroCommand::~MacroCommand(void)
{
	CommandIter iter;
	for(iter = m_CommandList.begin(); iter != m_CommandList.end(); iter++)
		SAFE_DELETE((*iter));
}

void MacroCommand::addCommand(Command* pCommand)
{
	m_CommandList.push_back(pCommand);
}

void MacroCommand::Excute()
{
	CommandIter iter;

	for(iter = m_CommandList.begin(); iter != m_CommandList.end(); iter++)
		(*iter)->Excute();
}