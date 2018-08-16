#include "stdafx.h"
#include "cErebMap.h"

cErebMap::~cErebMap()
{
	Destroy();
}

void cErebMap::Init()
{
	m_MapName = "에레브";

	m_RevivalPos = { 320,950 };
	//SOUND_MGR->SoundStop(L"Sound_Login");
	//SOUND_MGR->SoundStop(L"CokeTown");
	//
	//SOUND_MGR->SoundBGM(L"QueensGarden");

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

	MAP_MGR->AddMinimapWindow(L"Ereb", { 50, 52 }, { 1.0f, 1.0f });

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

	m_LayOut2_Size = { 1400, 850 };

	MAP_MGR->AddBackGround2(L"back.9", { 201.0f,  468.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 600.5f,   468.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 1000.0f, 468.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 1400.0f,  468.0f });

	MAP_MGR->AddBackGround2(L"back.9", { 201.0f,  368.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 600.5f,   368.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 1000.0f, 368.0f });
	MAP_MGR->AddBackGround2(L"back.9", { 1400.0f,  368.0f });
	// 배경 3

	m_LayOut3_Size = { 1600, 900 };

	MAP_MGR->AddBackGround3(L"back.11", { 401.0f,  726.0f });
	MAP_MGR->AddBackGround3(L"back.12", { 1200.5f, 726.0f });
	MAP_MGR->AddBackGround3(L"back.13", { 2000.0f, 726.0f });

	// 배경 4

	m_LayOut4_Size = { 1600, 1000 };

	MAP_MGR->AddBackGround4(L"back.14", { 401.0f,  798.0f });
	MAP_MGR->AddBackGround4(L"back.15", { 1200.5f, 798.0f });
	MAP_MGR->AddBackGround4(L"back.16", { 2000.0f, 798.0f });

	// 배경 5

	m_LayOut5_Size = { 1800, 1100 };

	MAP_MGR->AddBackGround5(L"back.18", { 401.0f,  988.0f });
	MAP_MGR->AddBackGround5(L"back.19", { 1200.5f, 988.0f });
	MAP_MGR->AddBackGround5(L"back.20", { 2000.0f, 988.0f });

	// 배경 6

	m_LayOut6_Size = { 2000, 1200 };

	auto CarlClick = [](void) { MK_LOG("칼 테스트"); };


	//MAP_MGR->AddNPC_Carl({ 500.0f, 985.0f }, CarlClick);

	MAP_MGR->AddBackGround6(L"nature.11.0", { 300.0f, 995.0f });
	MAP_MGR->AddBackGround6(L"nature.0.0", { 150.0f,    995.0f });
	MAP_MGR->AddBackGround6(L"nature.10.0", { 200.0f,  995.0f });

	// Holybird
	MAP_MGR->AddBackGround6(L"holybird.0.0", { 1301.0f, 995.0f });
	MAP_MGR->AddBackGround6(L"holybird.1.0", { 1393.5f, 1000.0f });
	MAP_MGR->AddBackGround6(L"holybird.4.0", { 1513.0f, 996.0f });

	// 타일 _ 베이스

	MAP_MGR->AddFlatTileH({ 0, 1018 }, 22, true);
	MAP_MGR->AddFlatTileM({ 0, 1048 }, 22);
	MAP_MGR->AddFlatTileM({ 0, 1108 }, 22);
	MAP_MGR->AddFlatTileM({ 0, 1168 }, 22);


	// 로프용 타일

	MAP_MGR->AddFlatTileH({ 300, 518 }, 3);
	MAP_MGR->AddFlatTileL({ 300, 518 }, 3);

	// 몬스터용 타일
	MAP_MGR->AddFlatTileH({ 500, 700 }, 5);
	MAP_MGR->AddFlatTileL({ 500, 700 }, 5);


	// 지형 애니메이션 만들기

	// 비트맵 이름 리스트
	vector<wstring> holybirdImgList;

	holybirdImgList.push_back(L"holybird.17.0");
	holybirdImgList.push_back(L"holybird.17.1");
	holybirdImgList.push_back(L"holybird.17.2");


	// 위치, 맵 타입, 애니메이션 시간 간격, 비트맵 리스트(벡터)
	MAP_MGR->AddAnimation({ 650.0f, 985.0f }, MAP_BACKGROUND6, 0.2f, holybirdImgList);

	// 로프

	MAP_MGR->AddLadder(L"0.0.0", { 400, 520 }, true);
	MAP_MGR->AddLadder(L"0.3.0", { 396, 640 }, false);
	MAP_MGR->AddLadder(L"0.3.0", { 396, 760 }, false);
	MAP_MGR->AddLadder(L"0.3.0", { 396, 880 }, false);



	// 포탈

	vector<wstring> portalImgList;
	portalImgList.push_back(L"pv.default.1");
	portalImgList.push_back(L"pv.default.2");
	portalImgList.push_back(L"pv.default.3");
	portalImgList.push_back(L"pv.default.4");
	portalImgList.push_back(L"pv.default.5");
	portalImgList.push_back(L"pv.default.6");
	portalImgList.push_back(L"pv.default.7");


	MAP_MGR->AddPortal(1, { 320, 493 }, portalImgList, MNAME_COKETOWN, 1);

	MAP_MGR->AddPortal(2, { 320, 991 }, portalImgList, MNAME_ARCANA, 1);

	MAP_MGR->AddPortal(3, { 500, 493 }, portalImgList, MNAME_ARCANA, 3);


	//MOB_MGR->Init();
	MOB_MGR->MobSetting(MOB_MUSHROOM, 3, { 450, 670 }, 470);


	
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


