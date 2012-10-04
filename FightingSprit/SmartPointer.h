#pragma once

/*!
 * @class     SmartPointer
 * @brief     ±ÍÂú¾Æ....
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-04-05 
 * @warning   
 */
template<typename T>
class SmartPointer
{
private:
	T*		m_pPointer;

public:

	SmartPointer(void)
	{
		m_pPointer = NULL;
	}
	SmartPointer(T* pt)
	{
		m_pPointer = pt;
	}
	virtual ~SmartPointer(void)
	{
		delete m_pPointer;
	}
public:
	T* operator->()
	{
		return m_pPointer;
	}
	T operator*()
	{
		return *m_pPointer;	
	}
	T* operator&()
	{
		return &m_pPointer;
	}
	SmartPointer<T>& operator= (T* rhs)
	{
		m_pPointer = rhs;
		return *this;
	}
	bool operator ==(T* rhs)
	{
		if(m_pPointer == rhs)
			return true;
		else
			return false;
	}
	bool operator !=(T* rhs)
	{
		if(m_pPointer != rhs)
			return true;
		else
			return false;
	}
	T* getPoint()
	{
		return m_pPointer;
	}

};
