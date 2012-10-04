#pragma once
#include "Glober.h"
#include "Observer.h"	//인풋받기 위해서 임시로 넣었음.. 인풋 알아서 처리하셈


class Irrdevice
{
private:
	static Irrdevice*		m_pIrrlicht;
private:
	IrrlichtDevice*			m_pDevice;
	IVideoDriver*			m_pVideoDriver;
	ISceneManager*			m_pSceneManager;
	IGUIEnvironment*		m_pGUIEnvironment;
	E_DRIVER_TYPE			m_DriverType;
	CObserver*				m_pInputObserve;		//인풋받기 위해서 임시로 넣었음.. 인풋 알아서 처리하셈


	int				m_nWidth;
	int				m_nHeight;
	unsigned int	m_nColorBit;
	bool			m_bFullScreen;
	bool			m_bStencil;
	bool			m_bVSync;

public:
	static Irrdevice* GetInstance();
	static void Release();
private:
	Irrdevice();
	~Irrdevice();
public:
	IrrlichtDevice*		GetDevice()				{ return m_pDevice;			}
	IVideoDriver*		GetVideoDriver()		{ return m_pVideoDriver;	}
	ISceneManager*		GetSceneManager()		{ return m_pSceneManager;	}
	IGUIEnvironment*	GetGUIEnvironment()		{ return m_pGUIEnvironment; }
	CObserver*			GetInputManager()		{ return m_pInputObserve;	}

	int		GetWidth()		{ return m_nWidth;		}
	int		GetHeight()		{ return m_nHeight;		}
	bool	IsFullScreen()	{ return m_bFullScreen; }

	void Init(E_DRIVER_TYPE DriverType, int nWidth, int nHeight, unsigned int nColorBit, bool bFullScreen, bool bStencil, bool bVSync = false);
};