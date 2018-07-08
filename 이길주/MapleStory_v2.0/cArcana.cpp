#include "stdafx.h"
#include "cArcana.h"



cArcana::~cArcana()
{
}

void cArcana::Init()
{
	IMG_MGR->FileFindDir_Take(L".\\Img\\map\\Arcana\\", m_MapImgList);

	MAP_MGR->AddBackGround1_Back1();

	MAP_MGR->AddBackGround1(L"back.14", { 300, 50 });


	// 배경 6

	m_LayOut6_Size = { 2000, 800 };
	// 타일 _ 베이스

	MAP_MGR->AddFlatTileH({ 0, 618 }, 30, true);
	MAP_MGR->AddFlatTileM({ 0, 648 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 708 }, 30);
	MAP_MGR->AddFlatTileM({ 0, 768 }, 30);
	MAP_MGR->AddFlatTileL({ 0, 800 }, 30);


	vector<wstring> portalImgList;
	portalImgList.push_back(L"pv.default.1");
	portalImgList.push_back(L"pv.default.2");
	portalImgList.push_back(L"pv.default.3");
	portalImgList.push_back(L"pv.default.4");
	portalImgList.push_back(L"pv.default.5");
	portalImgList.push_back(L"pv.default.6");
	portalImgList.push_back(L"pv.default.7");

	MAP_MGR->AddPortal(1, { 100, 585 }, portalImgList, MNAME_EREB, 1);
	MAP_MGR->AddPortal(2, { 1800, 585 }, portalImgList, MNAME_EREB, 2);
	MAP_MGR->AddPortal(3, { 1000, 585 }, portalImgList, MNAME_EREB, 3);


	vector<wstring> lighitForestList;

	lighitForestList.push_back(L"lightForest.reed.1.0");
	lighitForestList.push_back(L"lightForest.reed.1.1");
	lighitForestList.push_back(L"lightForest.reed.1.2");
	lighitForestList.push_back(L"lightForest.reed.1.3");
	lighitForestList.push_back(L"lightForest.reed.1.4");
	lighitForestList.push_back(L"lightForest.reed.1.5");
	lighitForestList.push_back(L"lightForest.reed.1.6");
	lighitForestList.push_back(L"lightForest.reed.1.7");
	lighitForestList.push_back(L"lightForest.reed.1.8");
	lighitForestList.push_back(L"lightForest.reed.1.9");


	MAP_MGR->AddAnimation({ 400, 585 }, MAP_BACKGROUND6, 0.1f, lighitForestList);
}
