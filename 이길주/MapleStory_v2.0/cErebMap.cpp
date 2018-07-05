#include "stdafx.h"
#include "cErebMap.h"

cErebMap::~cErebMap()
{
	Destroy();
}

void cErebMap::Init()
{
	IMG_MGR->FileFindDir_Take(L".\\Img\\map\\Ereb\\", m_MapImgList);

	m_LayOut1.m_Transform.SetPos(0, 0);
	m_LayOut1_Size = { 2000, 800 };

	MAP_MGR->AddFlatTileH({ 200, 500 }, 10);
	MAP_MGR->AddFlatTileM({ 200, 548 }, 10);
	MAP_MGR->AddFlatTileL({ 200, 592 }, 10);


	MAP_MGR->AddFlatTileH({ 0, 700 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 748 }, 30);
	MAP_MGR->AddFlatTileL({ 0, 792 }, 30);

	//MAP_MGR->AddFlatTileH({ 200, 500 }, 10);
}


