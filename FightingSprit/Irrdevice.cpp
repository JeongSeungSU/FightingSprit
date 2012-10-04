#include "Irrdevice.h"


Irrdevice* Irrdevice::m_pIrrlicht = NULL;

Irrdevice* Irrdevice::GetInstance()
{
	if(m_pIrrlicht == NULL) m_pIrrlicht = new Irrdevice();
	return m_pIrrlicht;
}

void Irrdevice::Release()
{
	if(m_pIrrlicht)
	{
		delete m_pIrrlicht;
		m_pIrrlicht = NULL;
	}
}

Irrdevice::Irrdevice()
{
	m_pDevice = NULL;
	m_pVideoDriver = NULL;
	m_pSceneManager = NULL;
	m_pGUIEnvironment = NULL;
	m_pInputObserve	  = new CObserver();
}

Irrdevice::~Irrdevice()
{
	m_pDevice->drop();
	delete m_pInputObserve;
}

void Irrdevice::Init(E_DRIVER_TYPE DriverType, int nWidth, int nHeight, unsigned int nColorBit, bool bFullScreen, bool bStencil, bool bVSync)
{
	m_DriverType = DriverType;
	m_nWidth = nWidth;
	m_nHeight = nHeight;
	m_nColorBit = nColorBit;
	m_bFullScreen = bFullScreen;
	m_bStencil = bStencil;
	m_bVSync = bVSync;

	m_pDevice = createDevice(m_DriverType, dimension2d<u32>(m_nWidth, m_nHeight), m_nColorBit, m_bFullScreen, m_bStencil, m_bVSync, m_pInputObserve);
	m_pVideoDriver = m_pDevice->getVideoDriver();
	m_pSceneManager = m_pDevice->getSceneManager();
	m_pGUIEnvironment = m_pDevice->getGUIEnvironment();
}