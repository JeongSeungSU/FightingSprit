#pragma once
#include "Network.h"

class CSynchronized;

	class CriticalSection
	{
		friend class Synchronized;

	private:
		bool			 m_bpcs;
		CRITICAL_SECTION cs;
		CRITICAL_SECTION *pcs;
	public:
		CriticalSection(void);
		void operator () (CRITICAL_SECTION &css);
		virtual ~CriticalSection(void);

		bool equals(CriticalSection * obj);
	};

