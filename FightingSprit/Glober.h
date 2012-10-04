#pragma once
//std
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <cstring>

//window
//#include <windows.h>

//irrlicht
#include <irrlicht.h>

using namespace irr;
using namespace io;
using namespace gui;
using namespace core;
using namespace video;
using namespace scene;


#include "Exception.h"
#include "NetworkException.h"

#define NULLEXCEPTION(p)		if(p == NULL) throw Exception("NULL POINT EXCEPTION");
#define SAFE_DELETE(p)			if(p != NULL) {delete p;		p = NULL;}
#define SAFE_DELETE_ARRAY(p)	if(p != NULL) {delete[] p;		p = NULL;}


//Network
//#include "Network.h"

typedef unsigned char BYTE;
typedef unsigned long DWORD;

//패킷 주고 받는데 필요한 자료구조들???
enum UNIT_ACTION_STATE	{STAND,SIT};
enum UNIT_STATE			{LIVE,DIE};