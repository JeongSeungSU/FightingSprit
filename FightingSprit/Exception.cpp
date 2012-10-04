#include "Exception.h"

JsException::JsException(void)
{
}

JsException::JsException(char*	ErrorString)
{
	m_pErrorString = ErrorString;
}
JsException::~JsException(void)
{
}


void JsException::PrintErrorMessage()
{
	std::cout<<m_pErrorString<<std::endl;
}