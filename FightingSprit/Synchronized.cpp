#include "Synchronized.h"

Synchronized::Synchronized( CriticalSection* cs )
: m_pCriticalSection( cs )
{
	::EnterCriticalSection( &m_pCriticalSection->cs );
}

Synchronized::~Synchronized()
{
	::LeaveCriticalSection( &m_pCriticalSection->cs );
}
