#include "stdafx.h"
#include "cErebMap.h"

cErebMap::~cErebMap()
{
	Destroy();
}

void cErebMap::Init()
{
	IMG_MGR->FileFindDir_Take(L".\\Img\\map\\Ereb\\", m_MapImgList);

	MAP_MGR->AddFlatTileH({ 0, 500 }, 10);
	MAP_MGR->AddFlatTileM({ 0, 548 }, 10);
	MAP_MGR->AddFlatTileL({ 0, 592 }, 10);
}


