#pragma once
#include "exception.h"

class NetworkException :
	public JsException
{

public:
	NetworkException(char* ErrorString);
	NetworkException(void);
	~NetworkException(void);
};
