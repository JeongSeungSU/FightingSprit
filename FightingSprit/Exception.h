#pragma once

#include <iostream>

/*!
 * @class     JsException
 * @brief     예외처리 클래스..
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
