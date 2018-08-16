#include "stdafx.h"
#include "cCokeTown.h"

cCokeTown::~cCokeTown()
{
	Destroy();
}

void cCokeTown::Init()
{
	m_MapName = "코크타운";

	//SOUND_MGR->SoundStop(L"Sound_Login");
	//SOUND_MGR->SoundStop(L"QueensGarden");
	//SOUND_MGR->SoundBGM(L"CokeTown");

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


	//UI_MGR->AddImage("미니맵0", L"minimap_0", { 50,50 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("미니맵1", L"minimap_1", { 130, 50 }, { 1.5f, 1.0f });
	//UI_MGR->AddImage("미니맵2", L"minimap_2", { 210, 50 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("미니맵3", L"minimap_3", { 50, 123 }, { 1.0f, 3.0f });
	//UI_MGR->AddImage("미니맵4", L"minimap_4", { 210, 123 }, { 1.0f, 3.0f });
	//UI_MGR->AddImage("미니맵5", L"minimap_5", { 50, 175 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("미니맵6", L"minimap_6", { 130, 175 }, { 1.5f, 1.0f });
	//UI_MGR->AddImage("미니맵7", L"minimap_7", { 210, 175 }, { 1.0f, 1.0f });
	//
	//UI_MGR->AddImage("미니맵베이스", L"minimap_base", { 27, 78, 232, 180 });

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
	//MAP_MGR->AddBackGround2(L"back.17", { 170.0f,  640.0f });
	//MAP_MGR->AddBackGround2(L"back.17", { 510.5f,   630.0f });
	//MAP_MGR->AddBackGround2(L"back.17", { 850.0f,   636.0f });
	//MAP_MGR->AddBackGround2(L"back.17", { 1190.0f,  368.0f });
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

	MAP_MGR->AddBackGround5(L"back.17", { 170.0f,					970.0f });
	MAP_MGR->AddBackGround5(L"back.17", { 170.0f + 339.5f,			970.0f });
	MAP_MGR->AddBackGround5(L"back.17", { 170.0f + 339.5f * 2,		970.0f });
	MAP_MGR->AddBackGround5(L"back.17", { 170.0f + 339.5f * 3,		970.0f });
	MAP_MGR->AddBackGround5(L"back.17", { 170.0f + 339.5f * 4,		970.0f });
	MAP_MGR->AddBackGround5(L"back.17", { 170.0f + 339.5f * 5,		970.0f });
	MAP_MGR->AddBackGround5(L"back.17", { 170.0f + 339.5f * 6,		970.0f });

	// 배경 5

	m_LayOut5_Size = { 1800, 1100 };


	// 배경 6 , addTile과 y축 y축 픽셀의 중간점 // 

	m_LayOut6_Size = { 2000, 1200 };
	MAP_MGR->AddBackGround6(L"cokeTown.acc1.0.0", { 150.0f,    998.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.acc1.10.0", { 1500.0f,    998.0f });

	MAP_MGR->AddBackGround6(L"cokeTown.foot.12.0", { 150.0f,    798.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.foot.13.0", { 166.0f,    830.0f });
	MAP_MGR->AddTile(L"cokeTown.foot.13.0", { 166.0f, 749.5f }, L"CokeTown");
	MAP_MGR->AddBackGround6(L"cokeTown.foot.10.0", { 350.0f,    580.0f }); // 108, 38
	MAP_MGR->AddBackGround6(L"cokeTown.foot.10.0", { 450.0f,    558.0f });

	MAP_MGR->AddBackGround6(L"cokeTown.nature.5.0", { 700.0f,    998.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.nature.6.0", { 500.0f,    998.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.foot.2.0", { 900.0f, 990.0f });


	// 조형물 타일
	//MAP_MGR->AddTile(L"cokeTown.foot.15.0", { 400.0f, 798.0f}, L"CokeTown");
	MAP_MGR->AddTile(L"cokeTown.foot.2.0", { 900.0f, 860.0f }, L"CokeTown");



	// 타일 _ 베이스  // 바닥
	MAP_MGR->AddFlatTileH({ 0, 1018 }, 22, true);
	MAP_MGR->AddFlatTileM({ 0, 1048 }, 22);
	MAP_MGR->AddFlatTileM({ 0, 1108 }, 22);
	MAP_MGR->AddFlatTileM({ 0, 1168 }, 22);
	//

	
	// 로프용 타일

	MAP_MGR->AddFlatTileH({ 300, 518 }, 3);
	MAP_MGR->AddFlatTileL({ 300, 518 }, 3);

	MAP_MGR->AddFlatTileH({ 700, 718 }, 5);
	MAP_MGR->AddFlatTileL({ 700, 718 }, 5);

	// 지형 애니메이션 만들기

	// 비트맵 이름 리스트
	//vector<wstring> holybirdImgList;
	//vector<wstring> cokeAniImgList;
	//vector<wstring> cokeAniImgList2;

	//cokeAniImgList.push_back(L"ani.0.0");
	//cokeAniImgList.push_back(L"ani.1.0");
	//cokeAniImgList.push_back(L"ani.2.0");
	//cokeAniImgList.push_back(L"ani.3.0");
	//cokeAniImgList.push_back(L"ani.4.0");
	//cokeAniImgList.push_back(L"ani.5.0");
	//cokeAniImgList.push_back(L"ani.6.0");
	//cokeAniImgList.push_back(L"ani.7.0");
	//cokeAniImgList.push_back(L"ani.8.0");
	//cokeAniImgList.push_back(L"ani.9.0");
	//cokeAniImgList.push_back(L"ani.10.0");
	//cokeAniImgList.push_back(L"ani.11.0");

	//cokeAniImgList2.push_back(L"5.0");
	//cokeAniImgList2.push_back(L"5.1");
	//cokeAniImgList2.push_back(L"5.2");
	//cokeAniImgList2.push_back(L"5.3");
	//cokeAniImgList2.push_back(L"5.4");
	//cokeAniImgList2.push_back(L"5.5");
	//cokeAniImgList2.push_back(L"5.6");
	//cokeAniImgList2.push_back(L"5.7");
	//cokeAniImgList2.push_back(L"5.8");

	//holybirdImgList.push_back(L"holybird.17.0");
	//holybirdImgList.push_back(L"holybird.17.1");
	//holybirdImgList.push_back(L"holybird.17.2");


	// 위치, 맵 타입, 애니메이션 시간 간격, 비트맵 리스트(벡터)
	//MAP_MGR->AddAnimation({ 650.0f, 985.0f }, MAP_BACKGROUND6, 0.2f, holybirdImgList);
	//MAP_MGR->AddAnimation({ 650.0f, 985.0f }, MAP_BACKGROUND6, 0.2f, cokeAniImgList);
	//MAP_MGR->AddAnimation({ 850.0f, 685.0f }, MAP_BACKGROUND6, 0.2f, cokeAniImgList2);
	// 로프

	MAP_MGR->AddLadder(L"0.0.0", { 400, 515 }, true);
	MAP_MGR->AddLadder(L"0.3.0", { 396, 635 }, false);
	MAP_MGR->AddLadder(L"0.3.0", { 396, 755 }, false);
	MAP_MGR->AddLadder(L"0.3.0", { 396, 875 }, false);



	// 포탈

	vector<wstring> portalImgList;
	portalImgList.push_back(L"pv.default.1");
	portalImgList.push_back(L"pv.default.2");
	portalImgList.push_back(L"pv.default.3");
	portalImgList.push_back(L"pv.default.4");
	portalImgList.push_back(L"pv.default.5");
	portalImgList.push_back(L"pv.default.6");
	portalImgList.push_back(L"pv.default.7");

	//vector<wstring> bossPortalImgList;
	//bossPortalImgList.push_back(L"bossPotal1.0");
	//bossPortalImgList.push_back(L"bossPotal1.1");
	//bossPortalImgList.push_back(L"bossPotal1.2");
	//bossPortalImgList.push_back(L"bossPotal1.3");
	//bossPortalImgList.push_back(L"bossPotal1.4");
	//bossPortalImgList.push_back(L"bossPotal1.5");


	MAP_MGR->AddPortal(1, { 320, 495 }, portalImgList, MNAME_EREB, 1);

	MAP_MGR->AddPortal(2, { 150, 1000 }, portalImgList, MNAME_COKETOWNNORMAL, 6);
	//MAP_MGR->AddPortal(0, { 1500, 991 }, bossPortalImgList, MNAME_COKETOWNBOSS, 4);

	MAP_MGR->AddPortal(3, { 500, 495 }, portalImgList, MNAME_ARCANA, 3);


	//MAP_MGR->AddMinimapWindow(L"minimap.portal", { 67.0f, 104.5f }, { 1.0f, 1.0f });
	//MAP_MGR->AddMinimapWindow(L"minimap.portal", { 50.0f, 155.0f }, { 1.0f, 1.0f });
	//MAP_MGR->AddMinimapWindow(L"minimap.portal", { 85.0f, 104.5f }, { 1.0f, 1.0f });

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
