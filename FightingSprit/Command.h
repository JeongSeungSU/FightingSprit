#pragma once

/*!
 * @class     Command
 * @brief     Ŀ�ǵ�����..
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-02-16 
 * @warning   
 */
class Command
{
public:
	virtual ~Command(void);

public:
	virtual void Excute() = 0;

protected:
	Command(void);
};
