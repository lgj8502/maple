#include "stdafx.h"
#include "cErebMap.h"

cErebMap::~cErebMap()
{
	Destroy();
}

void cErebMap::Init()
{
	IMG_MGR->FileFindDir_Take(L".\\Img\\map\\Ereb\\", m_MapImgList);

	MAP_MGR->AddBackGround1_Back1();

	m_LayOut2_Size = { 1400, 800 };

	MAP_MGR->AddBackGround2(L"back.9",	{ 200.0f,  200.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 600.0f,  200.0f });
	MAP_MGR->AddBackGround2(L"back.9",	{ 1000.0f, 200.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 1400.0f, 200.0f });

	m_LayOut3_Size = { 1600, 800 };

	MAP_MGR->AddBackGround3(L"back.11", { 400.0f, 626.0f });
	MAP_MGR->AddBackGround3(L"back.12", { 1200.0f, 626.0f });
	MAP_MGR->AddBackGround3(L"back.13", { 2000.0f, 626.0f });

	m_LayOut4_Size = { 1600, 800 };

	MAP_MGR->AddBackGround4(L"back.14", { 400.0f, 598.0f });
	MAP_MGR->AddBackGround4(L"back.15", { 1200.0f, 598.0f });
	MAP_MGR->AddBackGround4(L"back.16", { 2000.0f, 598.0f });

	m_LayOut5_Size = { 1800, 800 };

	MAP_MGR->AddBackGround5(L"back.18", { 400.0f, 688.0f });
	MAP_MGR->AddBackGround5(L"back.19", { 1200.0f, 688.0f });
	MAP_MGR->AddBackGround5(L"back.20", { 2000.0f, 688.0f });

	MAP_MGR->AddBackGround6(L"nature.11.0", { 150.0f, 595.0f });
	MAP_MGR->AddBackGround6(L"nature.0.0", { 0.0f, 595.0f });
	MAP_MGR->AddBackGround6(L"nature.10.0", { 50.0f, 595.0f });

	// Holybird
	MAP_MGR->AddBackGround6(L"holybird.0.0", { 1300.0f, 595.0f });
	MAP_MGR->AddBackGround6(L"holybird.1.0", { 1393.0f, 600.0f });
	MAP_MGR->AddBackGround6(L"holybird.4.0", { 1513.0f, 596.0f });

	m_LayOut6_Size = { 2000, 800 };

	MAP_MGR->AddFlatTileH({ 0, 600 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 648 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 708 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 768 }, 30);
	MAP_MGR->AddFlatTileL({ 0, 812 }, 30);

	vector<wstring> m_wstrList;

	m_wstrList.push_back(L"holybird.17.0");
	m_wstrList.push_back(L"holybird.17.1");
	m_wstrList.push_back(L"holybird.17.2");

	MAP_MGR->AddAnimation({ 650.0f, 595.0f }, MAP_BACKGROUND6, 0.2f, m_wstrList);



}


