#include "stdafx.h"
#include "LobbyScene.h"

#include <io.h>

//////추가 사항
static bool checkEvent = false;
static int aniCount = 0;
Object2D charBackground1;
//////////////////
LobbyScene::~LobbyScene()
{

}

void LobbyScene::Init(HWND hWnd)
{
	m_SceneName = "Lobby";

	IMG_MGR->FileFindDir(L".\\Img\\LobbyScene\\");

	DATA_MGR->m_CharacterName = "";
	//	mouse default image 
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseDefault"));	//0
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseClick"));		// 1

																	//mouse animation
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver0"));		// 2
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver1"));		// 3
	obj.m_Renderer.AddAnimation(0, 2, 3, 0.5, 0.5);
	obj.m_Renderer.m_State = -1;

	UI_MGR->AddImage("background", L"LobbyScene_background", { 0,0,1200,800 });

																							   //이전으로
	UI_MGR->AddButton("ChannelReturn_Default", L"LobbyScene_ChannelReturn_Default", { 59,694 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("ChannelReturn_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("ChannelReturn_Default", L"LobbyScene_ChannelReturn_Over");
	auto LobbyScene_Func10 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func11 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseOver, LobbyScene_Func10);
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseExit, LobbyScene_Func11);
	auto LobbyScene_Func16 = [](void) {SCENE_MGR->ChangeScene(SCENE_CHANNEL); };
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseClick, LobbyScene_Func16);

	//

	//leftArrow
	UI_MGR->AddButton("LeftArrow_Default", L"LobbyScene_LeftArrow_Default", { 177,686 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("LeftArrow_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("LeftArrow_Default", L"LobbyScene_LeftArrow_Over");
	auto LobbyScene_Func12 = [](void) { UI_MGR->FindUI("LeftArrow_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func13 = [](void) { UI_MGR->FindUI("LeftArrow_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("LeftArrow_Default", ADDEVENT_OnMouseOver, LobbyScene_Func12);
	UI_MGR->AddEvent("LeftArrow_Default", ADDEVENT_OnMouseExit, LobbyScene_Func13);


	//RightArrow
	UI_MGR->AddButton("RightArrow_Default", L"LobbyScene_RightArrow_Default", { 758,686 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("RightArrow_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("RightArrow_Default", L"LobbyScene_RightArrow_Over");
	auto LobbyScene_Func14 = [](void) { UI_MGR->FindUI("RightArrow_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func15 = [](void) { UI_MGR->FindUI("RightArrow_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("RightArrow_Default", ADDEVENT_OnMouseOver, LobbyScene_Func14);
	UI_MGR->AddEvent("RightArrow_Default", ADDEVENT_OnMouseExit, LobbyScene_Func15);


	// //  17
	///////////////////////////// 리소스 수정 필요
	//케릭터삭제
	UI_MGR->AddButton("CharDelete_Default", L"LobbyScene_charDelete_default0", { 556,683 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("CharDelete_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CharDelete_Default", L"LobbyScene_charDelete_Over0");
	auto LobbyScene_Func17 = [](void) { UI_MGR->FindUI("CharDelete_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func18 = [](void) { UI_MGR->FindUI("CharDelete_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("CharDelete_Default", ADDEVENT_OnMouseOver, LobbyScene_Func17);
	UI_MGR->AddEvent("CharDelete_Default", ADDEVENT_OnMouseExit, LobbyScene_Func18);

	//케릭터생성
	UI_MGR->AddButton("CharCreate_Default", L"LobbyScene_CharCreate_Default0", { 382,683 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("CharCreate_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CharCreate_Default", L"LobbyScene_CharCreate_Over0");
	auto LobbyScene_Func19 = [](void) { UI_MGR->FindUI("CharCreate_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func20 = [](void) { UI_MGR->FindUI("CharCreate_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("CharCreate_Default", ADDEVENT_OnMouseOver, LobbyScene_Func19);
	UI_MGR->AddEvent("CharCreate_Default", ADDEVENT_OnMouseExit, LobbyScene_Func20);
	auto LobbyScene_Func21 = [](void) {SCENE_MGR->ChangeScene(SCENE_CREATE0); };
	UI_MGR->AddEvent("CharCreate_Default", ADDEVENT_OnMouseClick, LobbyScene_Func21);


	//게임시작


	//ChannelScene_returnLogin_Default
	//처음으로
	UI_MGR->AddButton("returnLogin_Default", L"ChannelScene_returnLogin_Default", { 59,747 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("returnLogin_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnLogin_Default", L"ChannelScene_returnLogin_Over");
	auto LobbyScene_Func8 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func9 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseOver, LobbyScene_Func8);
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseExit, LobbyScene_Func9);


	UI_MGR->AddButton("returnPage", L"ChannelScene_returnPage", { 600,400 }, { 1.50f, 1.33333f });
	//644, 462 부모 설정 안했을 시 좌표
	UI_MGR->AddButton("returnPage_no_Default", L"ChannelScene_returnPage_no_Default", { 30,47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("returnPage_no_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_no_Default", L"ChannelScene_returnPage_no_Over");
	auto LobbyScene_Func1 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func2 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseOver, LobbyScene_Func1);
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseExit, LobbyScene_Func2);
	// 556, 462 부모 설정 안했을 시 좌표


	UI_MGR->AddButton("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Default", { -30,47 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("returnPage_ok_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Over");
	auto LobbyScene_Func3 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_Func4 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseOver, LobbyScene_Func3);
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseExit, LobbyScene_Func4);
	UI_MGR->SetParent("returnPage", "returnPage_no_Default");
	UI_MGR->SetParent("returnPage", "returnPage_ok_Default");
	UI_MGR->FindUI("returnPage")->m_isActive = false;
	auto LobbyScene_Func5 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = true; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseClick, LobbyScene_Func5);
	auto LobbyScene_Func6 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseClick, LobbyScene_Func6);
	auto LobbyScene_Func7 = [](void) {SCENE_MGR->ChangeScene(SCENE_LOGIN); };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseClick, LobbyScene_Func7);

	//게임시작 부분
	UI_MGR->AddButton("LobbyScene_Status_Default", L"LobbyScene_Status_Default", { 1005,448 }, { 1.5f, 1.33333f });
	UI_MGR->FindUI("LobbyScene_Status_Default")->m_RayCast = false;
	UI_MGR->AddButton("LobbyScene_GameStart_Default", L"LobbyScene_GameStart_Default", { -2,107 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("LobbyScene_GameStart_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("LobbyScene_GameStart_Default", L"LobbyScene_GameStart_Over");
	auto LobbyScene_start0 = [](void) { UI_MGR->FindUI("LobbyScene_GameStart_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto LobbyScene_start1 = [](void) { UI_MGR->FindUI("LobbyScene_GameStart_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto LobbyScene_click = [](void) {

		if (PLAYER_MGR->m_PlayerList.size() == 0 || PLAYER_MGR->m_PlayerIndex == -1) return;

		SCENE_MGR->ChangeScene(SCENE_INGAME);
	};
	UI_MGR->AddEvent("LobbyScene_GameStart_Default", ADDEVENT_OnMouseOver, LobbyScene_start0);
	UI_MGR->AddEvent("LobbyScene_GameStart_Default", ADDEVENT_OnMouseExit, LobbyScene_start1);
	UI_MGR->AddEvent("LobbyScene_GameStart_Default", ADDEVENT_OnMouseClick, LobbyScene_click);

	UI_MGR->SetParent("LobbyScene_Status_Default", "LobbyScene_GameStart_Default");

	UI_MGR->AddImage("LV", L"LV", { -15, -115 }, { 1.0f, 1.0f });
	auto LVu = [](void) {
		if (DATA_MGR->m_CharacterName == "")
		{
			UI_MGR->FindUI("LV")->m_Renderer.SetAlpha(0.0f);
		}
		else
		{
			UI_MGR->FindUI("LV")->m_Renderer.SetAlpha(1.0f);
		}
	};

	UI_MGR->AddEvent("LV", ADDEVENT_Update, LVu);
	UI_MGR->SetParent("LobbyScene_Status_Default", "LV");

	//============================================================================================
	//게임 종료 창
	UI_MGR->AddButton("gameEnd", L"Game_End", { 600,400 }, { 1.50f, 1.33333f });

	// 취소 버튼
	UI_MGR->AddButton("gameEnd_No", L"ChannelScene_returnPage_no_Default", { 30,47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("gameEnd_No")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameEnd_No", L"ChannelScene_returnPage_no_Over");
	auto End_Func0 = [](void) { UI_MGR->FindUI("gameEnd_No")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto End_Func1 = [](void) { UI_MGR->FindUI("gameEnd_No")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseOver, End_Func0);
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseExit, End_Func1);

	// 확인 버튼
	UI_MGR->AddButton("gameEnd_Ok", L"ChannelScene_returnPage_ok_Default", { -30,47 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("gameEnd_Ok")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameEnd_Ok", L"ChannelScene_returnPage_ok_Over");
	auto End_Func2 = [](void) { UI_MGR->FindUI("gameEnd_Ok")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto End_Func3 = [](void) { UI_MGR->FindUI("gameEnd_Ok")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseOver, End_Func2);
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseExit, End_Func3);

	// 부모 설정
	UI_MGR->SetParent("gameEnd", "gameEnd_No");
	UI_MGR->SetParent("gameEnd", "gameEnd_Ok");
	// 초기값 안보이게
	UI_MGR->FindUI("gameEnd")->m_isActive = false;

	//게임 종료 취소 이벤트
	auto End_Func5 = [](void) { UI_MGR->FindUI("gameEnd")->m_isActive = false; };
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseClick, End_Func5);
	//게임 종료 확인 이벤트
	auto End_Func6 = [](void) {
		DATA_MGR->AllMgrDestroy();
		PostQuitMessage(WM_DESTROY); };
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseClick, End_Func6);
	//=====

	// 캐릭터 표기

	vector<sCharacter> info;

	DATA_MGR->Load_CharacterList(info);

	PLAYER_MGR->Destroy();

	for (size_t i = 0; i < info.size(); i++)
	{
		PlayerTest * Charac = new PlayerTest;

		Charac->m_CharacInfo = info[i];

		Charac->Init();

		Charac->ChangeState(PLAYER_IDLE);

		if (i >= (int)2)
		{
			Charac->SetScale(1.3f, 1.3f);
		}
		else
		{
			Charac->SetScale(-1.3f, 1.3f);
		}

		Charac->SetPos({ 200.0f + (int)i * 184.0f , 295.0f });

		PLAYER_MGR->m_PlayerList.push_back(Charac);
	}



	UI_MGR->AddButton("Charac1", L"Hide", { 180, 250, 220, 340 }, 0.0f);
	auto Charac1 = [](void) { 

		if (PLAYER_MGR->m_PlayerList.size() == 0) return;

		UI_MGR->FindUI("캐릭클릭애니")->m_isActive = true;

		UI_MGR->FindUI("캐릭클릭애니")->m_Transform.SetPos({ 200.0f, 300.0f });

		for (auto &i : PLAYER_MGR->m_PlayerList)
		{
			i->ChangeState(PLAYER_IDLE);
		}
		
		PLAYER_MGR->m_PlayerList[0]->ChangeState(PLAYER_WALK);

		DATA_MGR->m_CharacterName = PLAYER_MGR->m_PlayerList[0]->m_CharacInfo.m_Name;

		PLAYER_MGR->m_PlayerIndex = 0;

		UI_MGR->LevelSetting(PLAYER_MGR->m_PlayerList[0]->m_CharacInfo.m_Level, {1015, 295}, {2.0f, 2.0f});
	};

	UI_MGR->AddEvent("Charac1", ADDEVENT_OnMouseClick, Charac1);

	UI_MGR->AddButton("Charac2", L"Hide", { 365, 250, 405, 340 }, 0.0f);
	auto Charac2 = [](void) {		
		if (PLAYER_MGR->m_PlayerList.size() <= 1) return;

		UI_MGR->FindUI("캐릭클릭애니")->m_isActive = true;
		UI_MGR->FindUI("캐릭클릭애니")->m_Transform.SetPos({ 383.0f, 300.0f });
		for (auto &i : PLAYER_MGR->m_PlayerList)
		{
			i->ChangeState(PLAYER_IDLE);
		}

		PLAYER_MGR->m_PlayerList[1]->ChangeState(PLAYER_WALK);

		DATA_MGR->m_CharacterName = PLAYER_MGR->m_PlayerList[1]->m_CharacInfo.m_Name;

		PLAYER_MGR->m_PlayerIndex = 1;

		UI_MGR->LevelSetting(PLAYER_MGR->m_PlayerList[1]->m_CharacInfo.m_Level, { 1015, 295 }, { 2.0f, 2.0f });
	};

	UI_MGR->AddEvent("Charac2", ADDEVENT_OnMouseClick, Charac2);

	UI_MGR->AddButton("Charac3", L"Hide", { 550, 250, 590, 340 }, 0.0f);
	auto Charac3 = [](void) {

		if (PLAYER_MGR->m_PlayerList.size() <= 2) return;

		UI_MGR->FindUI("캐릭클릭애니")->m_isActive = true;
		UI_MGR->FindUI("캐릭클릭애니")->m_Transform.SetPos({ 575.0f, 300.0f });


		for (auto &i : PLAYER_MGR->m_PlayerList)
		{
			i->ChangeState(PLAYER_IDLE);
		}

		PLAYER_MGR->m_PlayerList[2]->ChangeState(PLAYER_WALK);

		DATA_MGR->m_CharacterName = PLAYER_MGR->m_PlayerList[2]->m_CharacInfo.m_Name;

		PLAYER_MGR->m_PlayerIndex = 2;

		UI_MGR->LevelSetting(PLAYER_MGR->m_PlayerList[2]->m_CharacInfo.m_Level, { 1015, 295 }, { 2.0f, 2.0f });
	};

	UI_MGR->AddEvent("Charac3", ADDEVENT_OnMouseClick, Charac3);

	UI_MGR->AddButton("Charac4", L"Hide", { 735, 250, 775, 340 }, 0.0f);
	auto Charac4 = [](void) {

		if (PLAYER_MGR->m_PlayerList.size() <= 3) return;

		UI_MGR->FindUI("캐릭클릭애니")->m_isActive = true;
		UI_MGR->FindUI("캐릭클릭애니")->m_Transform.SetPos({ 760.0f, 300.0f });

		for (auto &i : PLAYER_MGR->m_PlayerList)
		{
			i->ChangeState(PLAYER_IDLE);
		}

		PLAYER_MGR->m_PlayerList[3]->ChangeState(PLAYER_WALK);

		DATA_MGR->m_CharacterName = PLAYER_MGR->m_PlayerList[3]->m_CharacInfo.m_Name;

		PLAYER_MGR->m_PlayerIndex = 3;

		UI_MGR->LevelSetting(PLAYER_MGR->m_PlayerList[3]->m_CharacInfo.m_Level, { 1015, 295 }, { 2.0f, 2.0f });
	};

	UI_MGR->AddEvent("Charac4", ADDEVENT_OnMouseClick, Charac4);

	vector<wstring> cca;

	cca.push_back(L"ZeroAura0.0");
	cca.push_back(L"ZeroAura0.1");
	cca.push_back(L"ZeroAura0.2");
	cca.push_back(L"ZeroAura0.3");
	cca.push_back(L"ZeroAura0.4");
	cca.push_back(L"ZeroAura0.5");
	cca.push_back(L"ZeroAura0.6");
	cca.push_back(L"ZeroAura0.7");
	cca.push_back(L"ZeroAura0.8");
	cca.push_back(L"ZeroAura0.9");
	cca.push_back(L"ZeroAura0.10");
	cca.push_back(L"ZeroAura0.11");
	cca.push_back(L"ZeroAura0.12");
	cca.push_back(L"ZeroAura0.13");
	cca.push_back(L"ZeroAura0.14");
	cca.push_back(L"ZeroAura0.15");
	cca.push_back(L"ZeroAura0.16");
	cca.push_back(L"ZeroAura0.17");
	cca.push_back(L"ZeroAura0.18");
	cca.push_back(L"ZeroAura0.19");
	cca.push_back(L"ZeroAura0.20");
	cca.push_back(L"ZeroAura0.21");
	cca.push_back(L"ZeroAura0.22");
	cca.push_back(L"ZeroAura0.23");

	UI_MGR->AddAnimation("캐릭클릭애니", { 0,0 }, 0.1f, cca);

	UI_MGR->FindUI("캐릭클릭애니")->m_isActive = false;

	// 캐릭 정보

	auto Cnick1 = [](void) { 

		if (DATA_MGR->m_CharacterName != "")
		{
			UI_MGR->FindUI("캐릭터닉넴")->m_Text = DATA_MGR->m_CharacterName;
		}
		
	};
	UI_MGR->AddText("캐릭터닉넴", "", { -905, -107 }, ColorF(ColorF::White), L"고딕", 20.0f);
	UI_MGR->FindUI("캐릭터닉넴")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_CENTER;
	UI_MGR->AddEvent("캐릭터닉넴", ADDEVENT_Update, Cnick1);
	UI_MGR->SetParent("LobbyScene_Status_Default", "캐릭터닉넴");

	auto Cjob = [](void) {

		if (DATA_MGR->m_CharacterName != "")
		{
			UI_MGR->FindUI("캐릭터직업")->m_Text = "모험가";			
		}


	};
	UI_MGR->AddText("캐릭터직업", "", { 30 , -65 }, ColorF(ColorF::White), L"고딕", 10.0f);
	UI_MGR->AddEvent("캐릭터직업", ADDEVENT_Update, Cjob);
	UI_MGR->SetParent("LobbyScene_Status_Default", "캐릭터직업");

	auto Cstr = [](void) {

		if (DATA_MGR->m_CharacterName != "")
		{
			ostringstream a;

			a << PLAYER_MGR->m_PlayerList[PLAYER_MGR->m_PlayerIndex]->m_CharacInfo.m_STR;

			UI_MGR->FindUI("캐릭터힘")->m_Text = a.str();
			
		}


	};
	UI_MGR->AddText("캐릭터힘", "", { -940 , 30 }, ColorF(ColorF::White), L"고딕", 10.0f);
	UI_MGR->FindUI("캐릭터힘")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_CENTER;
	UI_MGR->AddEvent("캐릭터힘", ADDEVENT_Update, Cstr);
	UI_MGR->SetParent("LobbyScene_Status_Default", "캐릭터힘");

	auto Cdex = [](void) {

		if (DATA_MGR->m_CharacterName != "")
		{
			ostringstream a;

			a << PLAYER_MGR->m_PlayerList[PLAYER_MGR->m_PlayerIndex]->m_CharacInfo.m_DEX;

			UI_MGR->FindUI("캐릭터민첩")->m_Text = a.str();

		}


	};
	UI_MGR->AddText("캐릭터민첩", "", { -940 , 60 }, ColorF(ColorF::White), L"고딕", 10.0f);
	UI_MGR->FindUI("캐릭터민첩")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_CENTER;
	UI_MGR->AddEvent("캐릭터민첩", ADDEVENT_Update, Cdex);
	UI_MGR->SetParent("LobbyScene_Status_Default", "캐릭터민첩");

	auto Cint = [](void) {

		if (DATA_MGR->m_CharacterName != "")
		{
			ostringstream a;

			a << PLAYER_MGR->m_PlayerList[PLAYER_MGR->m_PlayerIndex]->m_CharacInfo.m_INT;

			UI_MGR->FindUI("캐릭터지능")->m_Text = a.str();

		}


	};
	UI_MGR->AddText("캐릭터지능", "", { -830 , 30 }, ColorF(ColorF::White), L"고딕", 10.0f);
	UI_MGR->FindUI("캐릭터지능")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_CENTER;
	UI_MGR->AddEvent("캐릭터지능", ADDEVENT_Update, Cint);
	UI_MGR->SetParent("LobbyScene_Status_Default", "캐릭터지능");

	auto Cluk = [](void) {

		if (DATA_MGR->m_CharacterName != "")
		{
			ostringstream a;
			a << PLAYER_MGR->m_PlayerList[PLAYER_MGR->m_PlayerIndex]->m_CharacInfo.m_LUK;
			UI_MGR->FindUI("캐릭터운")->m_Text = a.str();
		}
	};

	UI_MGR->AddText("캐릭터운", "", { -830 , 60 }, ColorF(ColorF::White), L"고딕", 10.0f);
	UI_MGR->FindUI("캐릭터운")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_CENTER;
	UI_MGR->AddEvent("캐릭터운", ADDEVENT_Update, Cluk);
	UI_MGR->SetParent("LobbyScene_Status_Default", "캐릭터운");


}

void LobbyScene::Update(float _DelayTime)
{
	if (UI_MGR->m_ExitField == true)
	{
		m_szBuf = "";
		m_szMixingString[0] = NULL;

		UI_MGR->m_ExitField = false;

	}
	//LobbyScene_charBackground1.5.0

	////케릭터 주변 이펙트 보이기
	//aniCount++;
	//if (aniCount > 45)
	//	aniCount = 0;

	//UI_MGR->FindUI("LobbyScene_charBackground1.5.0")->m_Renderer.ChangeBitmap(aniCount);
	////케릭터 주변 이펙트 보이기

	UI_MGR->Update(_DelayTime);

	for (auto &i : PLAYER_MGR->m_PlayerList)
	{
		i->UpdateLobby(_DelayTime);
	}

	//m_player.Update(_DelayTime);
	obj.Update(_DelayTime);

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (UI_MGR->m_isChating == false)
		{
			UI_MGR->m_isChating = true;
		}
	}
}

void LobbyScene::Render()
{
	UI_MGR->Render();

	for (auto &i : PLAYER_MGR->m_PlayerList)
	{
		i->Render();
	}

	//m_player.Render();
	obj.Render();
}

void LobbyScene::SendText()
{
	if (UI_MGR->m_InputField->m_SonUI[0]->m_isTyping == false)
	{
		m_oldText = UI_MGR->m_InputField->m_SonUI[0]->m_Text;

		string temp = m_szBuf;

		m_szBuf = m_oldText + temp;

		UI_MGR->m_InputField->m_SonUI[0]->m_isTyping = true;
	}

	string sText = m_szBuf + m_szMixingString;

	UI_MGR->m_InputField->m_SonUI[0]->m_Text = sText;
}

LRESULT LobbyScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		//case WM_SETCURSOR: SetCursor(NULL); break;

	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);

		obj.m_Transform.SetPos((float)m_MousePos.x + 11.0f, (float)m_MousePos.y + 12.0f);
		////////////////

		//if (
		//	200 >= m_MousePos.y 
		//	&&
		//	100<m_MousePos.y
		//	)
		//{
		//	obj.m_Renderer.m_State = PLAYER_IDLE;
		//	obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);
		//	
		//		MK_LOG("%f, %f 클릭", UI_MGR->FindUI("createId_default")->m_Renderer.GetImgRT().bottom, UI_MGR->FindUI("createId_default")->m_Renderer.GetImgRT().top);
		//}
		//else
		//{
		//	obj.m_Renderer.m_State = -1;
		//	obj.m_Renderer.ChangeBitmap(0);
		//}

		if (checkEvent)
		{
			obj.m_Renderer.m_State = 0;
			//obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);
			//MK_LOG("머징");
		}
		else
		{
			obj.m_Renderer.m_State = -1;
			obj.m_Renderer.ChangeBitmap(0);
		}



		if (m_isClicked == true)
		{
			UI_MGR->OnMouseDrag(m_MousePos);
		}
		else
		{
			UI_MGR->OnMouseOver(m_MousePos);
			UI_MGR->OnMouseExit(m_MousePos);
		}

	}break;

	case WM_LBUTTONDOWN:
	{
		//obj.m_Transform.SetScale(0.7f, 0.7f);
		obj.m_Renderer.m_State = -1;
		obj.m_Renderer.ChangeBitmap(1);
		MK_LOG("%d, %d 클릭", m_MousePos.x, m_MousePos.y);

		UI_MGR->OnMouseDown(m_MousePos);

		m_isClicked = true;

	}break;

	case WM_LBUTTONUP:
	{
		//obj.m_Renderer.ChangeBitmap(0);
		if (checkEvent)
		{
			obj.m_Renderer.m_State = 0;
			//obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);

		}
		else
		{
			obj.m_Renderer.m_State = -1;
			obj.m_Renderer.ChangeBitmap(0);
		}
		UI_MGR->OnMouseUp(m_MousePos);

		m_isClicked = false;

	}break;

	// IME 용

	case WM_CHAR:
	{
		if (UI_MGR->m_isChating == false) break;


		char cWord = (char)wParam;

		//	백스페이스 버튼 클릭
		if (cWord == VK_BACK &&
			m_szMixingString[0] == NULL)
		{
			int nLen = m_szBuf.length();

			if (nLen > 0)
			{
				//	지워야할 문자가 조합체 인경우
				if (m_szBuf[nLen - 1] < 0)
				{
					m_szBuf = m_szBuf.substr(0, nLen - 2);
				}

				//	일반 문자를 지울 경우
				else
				{
					m_szBuf = m_szBuf.substr(0, nLen - 1);
				}
			}
		}
		//	엔터
		else if (cWord == VK_RETURN)
		{
			//CheckText = m_szBuf;
			m_szBuf = "";
			m_szMixingString[0] = NULL;

			m_oldText = "";

			UI_MGR->m_InputField->m_SonUI[0]->m_Text = "";

		}
		else
		{
			if (m_szBuf.size() > m_maxText)
			{
				break;
			}

			m_szBuf += (char)wParam;
		}

		SendText();


	}break;

	//	조합이 완전히 끝난 경우 조합중인 문자열을 비운다.
	case WM_IME_ENDCOMPOSITION:
	{
		if (UI_MGR->m_isChating == false) break;

		if (m_szBuf.size() >= m_maxText)
		{
			break;
		}

		m_szMixingString[0] = NULL;

		SendText();
	}
	break;

	//	IME 안에 있는 조합에 대한 내용을 얻을 수 있다.
	case WM_IME_COMPOSITION:
	{
		if (UI_MGR->m_isChating == false) break;

		if (m_szBuf.size() >= m_maxText)
		{
			break;
		}
		//	조합중일 경우 현재 조합중인 단어를 얻어온다.
		if (lParam & GCS_COMPSTR)
		{
			m_szMixingString[0] = CHAR(wParam >> 8);
			m_szMixingString[1] = CHAR(wParam);
		}

		//	조합이 끝난 경우	WM_IME_CHAR 와 같은 역활
		else if (lParam & GCS_RESULTSTR)
		{
			char szFinalString[3];

			szFinalString[0] = CHAR(wParam >> 8);
			szFinalString[1] = CHAR(wParam);
			szFinalString[2] = NULL;

			//	완성된 문자열을 추가 한다.
			m_szBuf += szFinalString;
		}
		SendText();
		//	기본 IME 에게 전달하지 않기 위해 바로 프로시저를 끝낸다.
		return 0;
	}
	break;
	//==================================================================================================
	// 게임 종료
	case WM_CLOSE:
		UI_MGR->FindUI("gameEnd")->m_isActive = true;
		UI_MGR->DrawFirst(UI_MGR->FindUI("gameEnd"));
		return 0;
		/*default:
		return FALSE;*/
		//==
	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}

