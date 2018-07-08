#include "stdafx.h"
#include "cErebMap.h"

cErebMap::~cErebMap()
{
	Destroy();
}

void cErebMap::Init()
{
	IMG_MGR->FileFindDir_Take(L".\\Img\\map\\Ereb\\", m_MapImgList);

	// 제일 뒷 배경 1

	MAP_MGR->AddBackGround1_Back1();

	// 구름처럼 스크롤 되는 맵

	MAP_MGR->AddScroll(L"back.2", { 200.0f,150.0f });
	MAP_MGR->AddScroll(L"back.3", { 200.0f, 100.0f });
	MAP_MGR->AddScroll(L"back.4", { 350.0f, 70.0f });
	MAP_MGR->AddScroll(L"back.6", { 400.0f, 80.0f });
	MAP_MGR->AddScroll(L"back.7", { 600.0f, 90.0f });
	MAP_MGR->AddScroll(L"back.8", { 750.0f, 40.0f });
	MAP_MGR->AddScroll(L"back.4", { 850.0f, 110.0f });
	MAP_MGR->AddScroll(L"back.7", { 900.0f, 30.0f });
	MAP_MGR->AddScroll(L"back.2", { 1050.0f, 50.0f });
	MAP_MGR->AddScroll(L"back.6", { 1000.0f, 120.0f });

	// 배경 2

	m_LayOut2_Size = { 1400, 800 };

	MAP_MGR->AddBackGround2(L"back.9",	{ 200.0f,  200.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 600.0f,  200.0f });
	MAP_MGR->AddBackGround2(L"back.9",	{ 1000.0f, 200.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 1400.0f, 200.0f });

	// 배경 3

	m_LayOut3_Size = { 1600, 800 };

	MAP_MGR->AddBackGround3(L"back.11", { 400.0f, 626.0f });
	MAP_MGR->AddBackGround3(L"back.12", { 1200.0f, 626.0f });
	MAP_MGR->AddBackGround3(L"back.13", { 2000.0f, 626.0f });

	// 배경 4

	m_LayOut4_Size = { 1600, 800 };

	MAP_MGR->AddBackGround4(L"back.14", { 400.0f, 598.0f });
	MAP_MGR->AddBackGround4(L"back.15", { 1200.0f, 598.0f });
	MAP_MGR->AddBackGround4(L"back.16", { 2000.0f, 598.0f });

	// 배경 5

	m_LayOut5_Size = { 1800, 800 };

	MAP_MGR->AddBackGround5(L"back.18", { 400.0f, 688.0f });
	MAP_MGR->AddBackGround5(L"back.19", { 1200.0f, 688.0f });
	MAP_MGR->AddBackGround5(L"back.20", { 2000.0f, 688.0f });

	// 배경 6

	m_LayOut6_Size = { 2000, 800 };

	MAP_MGR->AddBackGround6(L"nature.11.0", { 150.0f, 595.0f });
	MAP_MGR->AddBackGround6(L"nature.0.0", { 0.0f, 595.0f });
	MAP_MGR->AddBackGround6(L"nature.10.0", { 50.0f, 595.0f });

	// Holybird
	MAP_MGR->AddBackGround6(L"holybird.0.0", { 1300.0f, 595.0f });
	MAP_MGR->AddBackGround6(L"holybird.1.0", { 1393.0f, 600.0f });
	MAP_MGR->AddBackGround6(L"holybird.4.0", { 1513.0f, 596.0f });

	// 타일 _ 베이스

	MAP_MGR->AddFlatTileH({ 0, 618 }, 30, true);
	MAP_MGR->AddFlatTileM({ 0, 648 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 708 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 768 }, 30);
	MAP_MGR->AddFlatTileL({ 0, 800 }, 30);

	// 로프용 타일

	MAP_MGR->AddFlatTileH({ 300, 418 }, 3);
	MAP_MGR->AddFlatTileL({ 300, 418 }, 3);


	// 지형 애니메이션 만들기

	// 비트맵 이름 리스트
	vector<wstring> holybirdImgList;

	holybirdImgList.push_back(L"holybird.17.0");
	holybirdImgList.push_back(L"holybird.17.1");
	holybirdImgList.push_back(L"holybird.17.2");


	// 위치, 맵 타입, 애니메이션 시간 간격, 비트맵 리스트(벡터)
	MAP_MGR->AddAnimation({ 650.0f, 585.0f }, MAP_BACKGROUND6, 0.2f, holybirdImgList);

	// 로프

	MAP_MGR->AddLadder(L"0.0.0", { 400, 420 }, true);
	MAP_MGR->AddLadder(L"0.3.0", { 396, 540 }, false);

	// 포탈

	vector<wstring> portalImgList;
	portalImgList.push_back(L"pv.default.1");
	portalImgList.push_back(L"pv.default.2");
	portalImgList.push_back(L"pv.default.3");
	portalImgList.push_back(L"pv.default.4");
	portalImgList.push_back(L"pv.default.5");
	portalImgList.push_back(L"pv.default.6");
	portalImgList.push_back(L"pv.default.7");


	MAP_MGR->AddPortal(1, { 320, 393 }, portalImgList, MNAME_ARCANA, 1);

	MAP_MGR->AddPortal(2, { 320, 591 }, portalImgList, MNAME_ARCANA, 2);


	MAP_MGR->AddPortal(3, { 500, 393 }, portalImgList, MNAME_ARCANA, 3);
}


