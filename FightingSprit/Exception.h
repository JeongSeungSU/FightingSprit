#pragma once

#include <iostream>

/*!
 * @class     JsException
 * @brief     ����ó�� Ŭ����..
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-02-16 
 * @warning   
 */
class JsException
{
protected:
	char*	m_pErrorString;
public:
	JsException(void);
	JsException(char*	ErrorString);
	virtual ~JsException(void);

	virtual void PrintErrorMessage();
};
