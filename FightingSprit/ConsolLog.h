#pragma once
#include <fstream>
#include "log.h"


class ConsolLog : public CLog
{
private:
	bool				m_bFileMode;
	std::ofstream		m_File;
public:
	ConsolLog(Time* Timer);
	~ConsolLog(void);

	void PrintStringLog(char* string);
	void IsFileWriteMode(bool file);
};
