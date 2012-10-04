#include "ConsolLog.h"

ConsolLog::ConsolLog(Time* Timer)
:CLog(Timer)
{
	m_bFileMode = false;
}

ConsolLog::~ConsolLog(void)
{
	m_File.close();
}

void ConsolLog::PrintStringLog(char* string)
{
	std::cout<<string<<std::endl;
	if(m_bFileMode)
		m_File<<string<<std::endl;
}
void ConsolLog::IsFileWriteMode(bool file)
{
	if(file)
	{
		m_bFileMode = file;
		m_File.open("Log\\TotalLog.txt",std::ios::out);
	}
}