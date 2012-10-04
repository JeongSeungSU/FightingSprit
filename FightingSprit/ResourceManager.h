#pragma once
#include "Glober.h"
#include "ObjectFactory.h"

/*!
 * @class     ResourceManager
 * @brief     리소스 관리 매니져임...
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-07 
 * @warning   빨리제작하기 위한 여러가지 기능을 일단 뺀다.
			  1. 폴더에서 모든 리소스를 검색하여 불러들여 텍스트에 저장해 놓는 것..
			  2. 모든 리소스들의 이름을 부여하는 것..(알아서 ㅋㅋ)
			  3. 일단 위의 두개 더 생각나면 적지뭐
 */

typedef std::list<IMesh*>		MeshList;
typedef MeshList::iterator		MeshIter;

class ResourceManager
{
private:
	MeshList				m_MeshList;

	ObjectFactory*			m_pObjectFactory;
public:
	ResourceManager(void);
	~ResourceManager(void);

public:
	UnitObject*			AddUnitObject();
	SkyBoxObject*		AddSkyBoxObject();
	TerrainObject*		AddTerrainObject();

};