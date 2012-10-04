#pragma once
#include "Glober.h"
#include "ObjectFactory.h"

/*!
 * @class     ResourceManager
 * @brief     ���ҽ� ���� �Ŵ�����...
 * @author    JSS(E-Mail : sjdmldi@naver.com)
 * @date      2012-03-07 
 * @warning   ���������ϱ� ���� �������� ����� �ϴ� ����.
			  1. �������� ��� ���ҽ��� �˻��Ͽ� �ҷ��鿩 �ؽ�Ʈ�� ������ ���� ��..
			  2. ��� ���ҽ����� �̸��� �ο��ϴ� ��..(�˾Ƽ� ����)
			  3. �ϴ� ���� �ΰ� �� �������� ������
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