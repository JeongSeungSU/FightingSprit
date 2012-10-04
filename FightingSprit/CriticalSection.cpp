#include "CriticalSection.h"



CriticalSection::CriticalSection(void)
{
	m_bpcs = false;
	pcs = &cs;
	::InitializeCriticalSection(&cs);
}
void CriticalSection::operator() (CRITICAL_SECTION &css)
{
	m_bpcs = true;
	pcs = &css;
	::InitializeCriticalSection(pcs);
}
CriticalSection::~CriticalSection(void)
{
	::DeleteCriticalSection(&cs);
	::DeleteCriticalSection(pcs);
	pcs = NULL;
}

bool CriticalSection::equals(CriticalSection * obj)
{
	return (this == obj);
}

