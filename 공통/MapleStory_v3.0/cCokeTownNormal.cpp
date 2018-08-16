#include "stdafx.h"
#include "cCokeTownNormal.h"

cCokeTownNormal::~cCokeTownNormal()
{
	Destroy();
}

void cCokeTownNormal::Init()
{
	m_MapName = "코크타운 사냥터";

	m_RevivalPos = { 1800,800 };

	MAP_MGR->AddMinimapWindow(L"minimap_0", { 50,50 }, { 1.0f, 1.0f });
	MAP_MGR->AddMinimapWindow(L"minimap_1", { 130,50 }, { 1.5f, 1.0f });
	MAP_MGR->AddMinimapWindow(L"minimap_2", { 210,50 }, { 1.0f, 1.0f });
	MAP_MGR->AddMinimapWindow(L"minimap_3", { 50,123 }, { 1.0f, 3.0f });
	MAP_MGR->AddMinimapWindow(L"minimap_4", { 210,123 }, { 1.0f, 3.0f });
	MAP_MGR->AddMinimapWindow(L"minimap_5", { 50,175 }, { 1.0f, 1.0f });
	MAP_MGR->AddMinimapWindow(L"minimap_6", { 130,175 }, { 1.5f, 1.0f });
	MAP_MGR->AddMinimapWindow(L"minimap_7", { 210,175 }, { 1.0f, 1.0f });
	MAP_MGR->AddMinimapWindow_Rect(L"minimap_base", { 27, 78, 232, 180 });

	MAP_MGR->AddMinimapWindow(L"MiniMap.BtNpc.normal.0", { 215,28 }, { 1.0f, 1.0f });
	MAP_MGR->AddMinimapWindow(L"MiniMap.BtMap.normal.0", { 175,28 }, { 1.0f, 1.0f });
	MAP_MGR->AddMinimapWindow(L"MiniMap.BtSmall.normal.0", { 148,28 }, { 1.0f, 1.0f });

	MAP_MGR->AddMinimapWindow(L"CokeTown", { 50, 52 }, { 1.0f, 1.0f });

	IMG_MGR->FileFindDir_Take(L".\\Img\\map\\CokeTown\\", m_MapImgList);
	//IMG_MGR->FileFindDir(L".\\Img\\CokeTown\\");
	// 제일 뒷 배경 1

	MAP_MGR->AddBackGround1_Back1();

	// 구름처럼 스크롤 되는 맵

	//MAP_MGR->AddScroll(L"back.2", { 200.0f,150.0f });
	MAP_MGR->AddScroll(L"back.3", { 200.0f, 100.0f });
	MAP_MGR->AddScroll(L"back.4", { 350.0f, 70.0f });
	MAP_MGR->AddScroll(L"back.6", { 400.0f, 80.0f });
	MAP_MGR->AddScroll(L"back.7", { 600.0f, 90.0f });
	MAP_MGR->AddScroll(L"back.8", { 750.0f, 40.0f });
	MAP_MGR->AddScroll(L"back.4", { 850.0f, 110.0f });
	MAP_MGR->AddScroll(L"back.7", { 900.0f, 30.0f });
	//MAP_MGR->AddScroll(L"back.2", { 1050.0f, 50.0f });
	MAP_MGR->AddScroll(L"back.6", { 1000.0f, 120.0f });

	// 배경 2

	m_LayOut2_Size = { 1400, 850 };

	MAP_MGR->AddBackGround2(L"back.2", { 700.0f, 150.0f });
	MAP_MGR->AddBackGround3(L"back.11", { 401.0f,  326.0f });
	MAP_MGR->AddBackGround3(L"back.12", { 1200.5f, 326.0f });
	MAP_MGR->AddBackGround3(L"back.13", { 2000.0f, 326.0f });
	// 배경 3

	m_LayOut3_Size = { 1600, 900 };
	MAP_MGR->AddBackGround4(L"back.16", { 195.5f, 910.0f });
	MAP_MGR->AddBackGround4(L"back.15", { 760.0f,  910.0f });
	MAP_MGR->AddBackGround4(L"back.16", { 1324.5f, 910.0f });
	MAP_MGR->AddBackGround4(L"back.15", { 1889.0f, 910.0f });


	// 배경 4

	m_LayOut4_Size = { 1600, 1000 };


	// 배경 5

	m_LayOut5_Size = { 1800, 1100 };


	// 배경 6 , addTile과 ㅛ축 변취 차이는 +45

	m_LayOut6_Size = { 2000, 1200 };
	//MAP_MGR->AddBackGround6(L"cokeTown.acc1.0.0", { 1800.0f,    998.0f });
	vector<wstring> cokebottle;

	cokebottle.push_back(L"cokeTown.acc1.1.0");
	cokebottle.push_back(L"cokeTown.acc1.1.1");
	cokebottle.push_back(L"cokeTown.acc1.1.2");
	cokebottle.push_back(L"cokeTown.acc1.1.3");
	cokebottle.push_back(L"cokeTown.acc1.1.4");

	MAP_MGR->AddAnimation({ 1500.0f, 998.0f }, MAP_BACKGROUND6, 0.2f, cokebottle);

	//MAP_MGR->AddBackGround6(L"cokeTown.nature.5.0", { 1500.0f,    998.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.nature.6.0", { 1200.0f,    998.0f });

	MAP_MGR->AddBackGround6(L"cokeTown.nature.5.0", { 700.0f,    998.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.nature.6.0", { 300.0f,    998.0f });


	// 조형물 타일
	//MAP_MGR->AddTile(L"cokeTown.foot.15.0", { 400.0f, 798.0f}, L"CokeTown");

	//// BossAcc
	MAP_MGR->AddBackGround6(L"cokeTown.acc1.13.0", { 1133.5f, 1000.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.acc1.14.0", { 920.0f, 995.0f }); // 1301

	MAP_MGR->AddBackGround6(L"cokeTown.acc1.15.0", { 1113.0f, 996.0f });

	// 타일 _ 베이스  // 바닥
	MAP_MGR->AddFlatTileH({ 0, 1018 }, 22, true);
	MAP_MGR->AddFlatTileM({ 0, 1048 }, 22);
	MAP_MGR->AddFlatTileM({ 0, 1108 }, 22);
	MAP_MGR->AddFlatTileM({ 0, 1168 }, 22);
	//


	// 로프용 타일

	MAP_MGR->AddFlatTileH({ 300, 518 }, 3);
	MAP_MGR->AddFlatTileL({ 300, 518 }, 3);

	MAP_MGR->AddFlatTileH({ 260, 718 }, 5);
	MAP_MGR->AddFlatTileL({ 260, 718 }, 5);


	//MAP_MGR->AddFlatTileH({ 1500, 518 }, 3);
	//MAP_MGR->AddFlatTileL({ 1500, 518 }, 3);
	//
	//MAP_MGR->AddFlatTileH({ 1400, 718 }, 5);
	//MAP_MGR->AddFlatTileL({ 1400, 718 }, 5);

	//MAP_MGR->AddFlatTileH({ 700, 718 }, 20);
	//MAP_MGR->AddFlatTileL({ 700, 718 }, 20);

	// 지형 애니메이션 만들기

	// 비트맵 이름 리스트



	// 위치, 맵 타입, 애니메이션 시간 간격, 비트맵 리스트(벡터)
	// 로프

	MAP_MGR->AddLadder(L"0.0.0", { 400, 520 }, true);
	MAP_MGR->AddLadder(L"0.1.0", { 396, 550 }, false);
	MAP_MGR->AddLadder(L"0.1.0", { 396, 580 }, false);
	MAP_MGR->AddLadder(L"0.1.0", { 396, 610 }, false);
	MAP_MGR->AddLadder(L"0.2.0", { 396, 640 }, false);

	MAP_MGR->AddLadder(L"0.0.0", { 600, 720 }, true);
	MAP_MGR->AddLadder(L"0.3.0", { 596, 840 }, false);
	MAP_MGR->AddLadder(L"0.1.0", { 596, 870 }, false);
	MAP_MGR->AddLadder(L"0.2.0", { 596, 900 }, false);

	//MAP_MGR->AddLadder(L"0.0.0", { 1500, 520 }, true);
	//MAP_MGR->AddLadder(L"0.1.0", { 1496, 550 }, false);
	//MAP_MGR->AddLadder(L"0.1.0", { 1496, 580 }, false);
	//MAP_MGR->AddLadder(L"0.1.0", { 1496, 610 }, false);
	//MAP_MGR->AddLadder(L"0.2.0", { 1496, 640 }, false);
	//
	//MAP_MGR->AddLadder(L"0.0.0", { 1650, 720 }, true);
	//MAP_MGR->AddLadder(L"0.3.0", { 1646, 840 }, false);
	//MAP_MGR->AddLadder(L"0.1.0", { 1646, 870 }, false);
	//MAP_MGR->AddLadder(L"0.2.0", { 1646, 900 }, false);




	// 포탈

	vector<wstring> portalImgList;
	portalImgList.push_back(L"pv.default.1");
	portalImgList.push_back(L"pv.default.2");
	portalImgList.push_back(L"pv.default.3");
	portalImgList.push_back(L"pv.default.4");
	portalImgList.push_back(L"pv.default.5");
	portalImgList.push_back(L"pv.default.6");
	portalImgList.push_back(L"pv.default.7");

	vector<wstring> bossPortalImgList;
	bossPortalImgList.push_back(L"bossPotal1.0");
	bossPortalImgList.push_back(L"bossPotal1.1");
	bossPortalImgList.push_back(L"bossPotal1.2");
	bossPortalImgList.push_back(L"bossPotal1.3");
	bossPortalImgList.push_back(L"bossPotal1.4");
	bossPortalImgList.push_back(L"bossPotal1.5");


	MAP_MGR->AddPortal(6, { 1800, 1000 }, portalImgList, MNAME_COKETOWN, 2);
	MAP_MGR->AddPortal(0, { 1000, 1000 }, bossPortalImgList, MNAME_COKETOWNBOSS, 4, true);


	MOB_MGR->MobSetting(MOB_JUNIERYETTI, 5, { 450, 991 }, 470);
	MOB_MGR->MobSetting(MOB_MURUCOON, 5, { 300 , 691 }, 400);


	///// 레이아웃 카메라 비율 설정

	m_LayOut2.m_Transform.m_isCamera = true;
	m_LayOut3.m_Transform.m_isCamera = true;
	m_LayOut4.m_Transform.m_isCamera = true;
	m_LayOut5.m_Transform.m_isCamera = true;
	m_LayOut6.m_Transform.m_isCamera = true;

	m_LayOut2.m_Transform.m_CameraRate.x = (m_LayOut2_Size.x - WIN_WIDTH) / (m_LayOut6_Size.x - WIN_WIDTH);
	m_LayOut3.m_Transform.m_CameraRate.x = (m_LayOut3_Size.x - WIN_WIDTH) / (m_LayOut6_Size.x - WIN_WIDTH);
	m_LayOut4.m_Transform.m_CameraRate.x = (m_LayOut4_Size.x - WIN_WIDTH) / (m_LayOut6_Size.x - WIN_WIDTH);
	m_LayOut5.m_Transform.m_CameraRate.x = (m_LayOut5_Size.x - WIN_WIDTH) / (m_LayOut6_Size.x - WIN_WIDTH);
	m_LayOut6.m_Transform.m_CameraRate.x = (m_LayOut6_Size.x - WIN_WIDTH) / (m_LayOut6_Size.x - WIN_WIDTH);

	m_LayOut2.m_Transform.m_CameraRate.y = (m_LayOut2_Size.y - WIN_HEIGHT) / (m_LayOut6_Size.y - WIN_HEIGHT);
	m_LayOut3.m_Transform.m_CameraRate.y = (m_LayOut3_Size.y - WIN_HEIGHT) / (m_LayOut6_Size.y - WIN_HEIGHT);
	m_LayOut4.m_Transform.m_CameraRate.y = (m_LayOut4_Size.y - WIN_HEIGHT) / (m_LayOut6_Size.y - WIN_HEIGHT);
	m_LayOut5.m_Transform.m_CameraRate.y = (m_LayOut5_Size.y - WIN_HEIGHT) / (m_LayOut6_Size.y - WIN_HEIGHT);
	m_LayOut6.m_Transform.m_CameraRate.y = (m_LayOut6_Size.y - WIN_HEIGHT) / (m_LayOut6_Size.y - WIN_HEIGHT);


	m_MiniMap.m_Transform.SetPos({ 35,60 });
	m_MiniMap.m_Transform.SetScale(0.1f, 0.1f);
}
