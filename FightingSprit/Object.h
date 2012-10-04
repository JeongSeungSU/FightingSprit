#pragma once
#include "Glober.h"

class Object
{
public:
	Object(void);
	virtual ~Object(void);

public:
	virtual void Update(DWORD Time) = 0;
};
