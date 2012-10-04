#include "NetworkException.h"

NetworkException::NetworkException(void)
{
}
NetworkException::NetworkException(char* ErrorString)
{
	m_pErrorString = ErrorString;
}
NetworkException::~NetworkException(void)
{
}
