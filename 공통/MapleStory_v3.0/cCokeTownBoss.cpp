#include "stdafx.h"
#include "cCokeTownBoss.h"

cCokeTownBoss::~cCokeTownBoss()
{
	Destroy();
}

void cCokeTownBoss::Init()
{
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

	//MAP_MGR->AddBackGround5(L"back.17", { 170.0f,    970.0f });
	//MAP_MGR->AddBackGround5(L"back.17", { 510.5f,    970.0f });
	//MAP_MGR->AddBackGround5(L"back.17", { 850.0f,    970.0f });
	//MAP_MGR->AddBackGround5(L"back.17", { 1190.5f,  970.0f });
	//MAP_MGR->AddBackGround5(L"back.17", { 1530.0f,  970.0f });
	//MAP_MGR->AddBackGround5(L"back.17", { 1870.5f,  970.0f });
	//MAP_MGR->AddBackGround5(L"back.17", { 2210.0f,  970.0f });

	// 배경 5

	m_LayOut5_Size = { 1800, 1100 };


	// 배경 6 , addTile과 y축 변취 차이는 +45

	m_LayOut6_Size = { 2000, 1200 };
	//MAP_MGR->AddBackGround6(L"cokeTown.acc1.10.0", { 1500.0f,    998.0f });
	//// BossAcc
	MAP_MGR->AddBackGround6(L"cokeTown.acc1.13.0", { 1133.5f, 1000.0f });
	MAP_MGR->AddBackGround6(L"cokeTown.acc1.14.0", { 920.0f, 995.0f }); // 1301

	MAP_MGR->AddBackGround6(L"cokeTown.acc1.15.0", { 1113.0f, 996.0f });
	// 조형물 타일


	//// Holybird


	// 타일 _ 베이스  // 바닥
	MAP_MGR->AddFlatTileH({ 0, 1018 }, 30, true);
	MAP_MGR->AddFlatTileM({ 0, 1048 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 1108 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 1168 }, 30);
	//


	// 로프용 타일


	// 지형 애니메이션 만들기

	// 비트맵 이름 리스트
	//vector<wstring> holybirdImgList;



	// 포탈

	vector<wstring> portalImgList;
	portalImgList.push_back(L"pv.default.1");
	portalImgList.push_back(L"pv.default.2");
	portalImgList.push_back(L"pv.default.3");
	portalImgList.push_back(L"pv.default.4");
	portalImgList.push_back(L"pv.default.5");
	portalImgList.push_back(L"pv.default.6");
	portalImgList.push_back(L"pv.default.7");


	MAP_MGR->AddPortal(4, { 1000, 995 }, portalImgList, MNAME_COKETOWNNORMAL, 0);



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


	m_MiniMap.m_Transform.SetPos({ 50,0 });
	m_MiniMap.m_Transform.SetScale(0.1f, 0.1f);

}
