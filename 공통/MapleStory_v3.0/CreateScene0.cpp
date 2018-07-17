#include "stdafx.h"
#include "CreateScene0.h"



//////추가 사항
static bool checkEvent = false;
//////////////////
CreateScene0::~CreateScene0()
{

}

void CreateScene0::Init(HWND hWnd)
{
	IMG_MGR->FileFindDir(L".\\Img\\CreateScene0\\");

	////	mouse default image 
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"CreateScene0_create_mouse"));	//0


	UI_MGR->AddImage("create_Background", L"CreateScene0_create_Background", { 0,0,1200,800 }); //0

	UI_MGR->AddImage("create_Background1", L"CreateScene0_create_Background1", { 0,0,1200,800 });
	UI_MGR->AddImage("create_Background2", L"CreateScene0_create_Background2", { 0,0,1200,800 });
	UI_MGR->AddImage("create_Background3", L"CreateScene0_create_Background3", { 0,0,1200,800 });
	UI_MGR->AddImage("create_Background4", L"CreateScene0_create_Background4", { 0,0,1200,800 });

	UI_MGR->FindUI("create_Background1")->m_isActive = false;
	UI_MGR->FindUI("create_Background2")->m_isActive = false;
	UI_MGR->FindUI("create_Background3")->m_isActive = false;
	UI_MGR->FindUI("create_Background4")->m_isActive = false;

	//UI_MGR->BitMapAdd("create_Background", L"CreateScene0_create_Background1");
	//UI_MGR->BitMapAdd("create_Background", L"CreateScene0_create_Background2");
	//UI_MGR->BitMapAdd("create_Background", L"CreateScene0_create_Background3");
	//UI_MGR->BitMapAdd("create_Background", L"CreateScene0_create_Background4");
	////800 : 600  -> 1200 800  :: 1.5  1.33333

	//이전으로
	UI_MGR->AddButton("ChannelReturn_Default", L"LobbyScene_ChannelReturn_Default", { 59,694 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("ChannelReturn_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("ChannelReturn_Default", L"LobbyScene_ChannelReturn_Over");
	auto CreateScene0_Func10 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func11 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseOver, CreateScene0_Func10);
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseExit, CreateScene0_Func11);
	auto CreateScene0_Func16 = [](void) {SCENE_MGR->ChangeScene(SCENE_LOBBY); };
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseClick, CreateScene0_Func16);


	//UI_MGR->AddButton("create_adventures_Default", L"CreateScene0_create_adventures_Default", { 59,694 }, { 1.50f, 1.33333f });
	//UI_MGR->FindUI("create_adventures_Default")->m_RayCast = true;
	//UI_MGR->BitMapAdd("create_adventures_Default", L"CreateScene0_create_adventures_Over");
	//auto CreateScene0_Func10 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	//auto CreateScene0_Func11 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };

	//////////////////////////////////////////////////
	//adventures 버튼
	UI_MGR->AddButton("adventures_Default", L"CreateScene0_create_adventures_Default", { 227,648 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("adventures_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("adventures_Default", L"CreateScene0_create_adventures_Over");
	auto CreateScene0_Func21 = [](void) { UI_MGR->FindUI("adventures_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true;
	UI_MGR->FindUI("create_Background")->m_isActive = true;
	//UI_MGR->FindUI("create_Background1")->m_isActive = true;
	};
	auto CreateScene0_Func22 = [](void) { UI_MGR->FindUI("adventures_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false;
	UI_MGR->FindUI("create_Background")->m_isActive = true;
	};
	UI_MGR->AddEvent("adventures_Default", ADDEVENT_OnMouseOver, CreateScene0_Func21);
	UI_MGR->AddEvent("adventures_Default", ADDEVENT_OnMouseExit, CreateScene0_Func22);

	////////////////

	UI_MGR->AddButton("DualBlade_Default", L"CreateScene0_DualBlade_Default", { 413,648 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("DualBlade_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("DualBlade_Default", L"CreateScene0_DualBlade_Over");
	auto CreateScene0_Func41 = [](void) { UI_MGR->FindUI("DualBlade_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true;
	UI_MGR->FindUI("create_Background")->m_isActive = false;
	UI_MGR->FindUI("RightArrow_Default")->m_Renderer.ChangeBitmap(2);
	UI_MGR->FindUI("create_Background1")->m_isActive = true;
	};
	auto CreateScene0_Func42 = [](void) { UI_MGR->FindUI("DualBlade_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false;
	UI_MGR->FindUI("create_Background1")->m_isActive = false;
	UI_MGR->FindUI("RightArrow_Default")->m_Renderer.ChangeBitmap(0);
	UI_MGR->FindUI("create_Background")->m_isActive = true;
	};
	UI_MGR->AddEvent("DualBlade_Default", ADDEVENT_OnMouseOver, CreateScene0_Func41);
	UI_MGR->AddEvent("DualBlade_Default", ADDEVENT_OnMouseExit, CreateScene0_Func42);

	UI_MGR->AddButton("CannonShooter_Default", L"CreateScene0_CannonShooter_Default", { 603,648 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("CannonShooter_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CannonShooter_Default", L"CreateScene0_CannonShooter_Over");
	auto CreateScene0_Func43 = [](void) { UI_MGR->FindUI("CannonShooter_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true;
	UI_MGR->FindUI("create_Background")->m_isActive = false;
	UI_MGR->FindUI("create_Background2")->m_isActive = true;
	};
	auto CreateScene0_Func44 = [](void) { UI_MGR->FindUI("CannonShooter_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false;
	UI_MGR->FindUI("create_Background2")->m_isActive = false;
	UI_MGR->FindUI("create_Background")->m_isActive = true;
	};
	UI_MGR->AddEvent("CannonShooter_Default", ADDEVENT_OnMouseOver, CreateScene0_Func43);
	UI_MGR->AddEvent("CannonShooter_Default", ADDEVENT_OnMouseExit, CreateScene0_Func44);

	UI_MGR->AddButton("Kaise_Default", L"CreateScene0_Kaise_Default", { 793,648 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("Kaise_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("Kaise_Default", L"CreateScene0_Kaise_Over");
	auto CreateScene0_Func45 = [](void) { UI_MGR->FindUI("Kaise_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true;
	UI_MGR->FindUI("create_Background")->m_isActive = false;
	UI_MGR->FindUI("create_Background3")->m_isActive = true;
	};
	auto CreateScene0_Func46 = [](void) { UI_MGR->FindUI("Kaise_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false;
	UI_MGR->FindUI("create_Background3")->m_isActive = false;
	UI_MGR->FindUI("create_Background")->m_isActive = true;
	};
	UI_MGR->AddEvent("Kaise_Default", ADDEVENT_OnMouseOver, CreateScene0_Func45);
	UI_MGR->AddEvent("Kaise_Default", ADDEVENT_OnMouseExit, CreateScene0_Func46);


	UI_MGR->AddButton("AngelicBuster_Default", L"CreateScene0_AngelicBuster_Default", { 983,648 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("AngelicBuster_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("AngelicBuster_Default", L"CreateScene0_AngelicBuster_Over");
	auto CreateScene0_Func47 = [](void) { UI_MGR->FindUI("AngelicBuster_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true;
	UI_MGR->FindUI("create_Background")->m_isActive = false;
	UI_MGR->FindUI("create_Background4")->m_isActive = true;
	};
	auto CreateScene0_Func48 = [](void) { UI_MGR->FindUI("AngelicBuster_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false;
	UI_MGR->FindUI("create_Background4")->m_isActive = false;
	UI_MGR->FindUI("create_Background")->m_isActive = true;
	};
	UI_MGR->AddEvent("AngelicBuster_Default", ADDEVENT_OnMouseOver, CreateScene0_Func47);
	UI_MGR->AddEvent("AngelicBuster_Default", ADDEVENT_OnMouseExit, CreateScene0_Func48);



	//케릭터 생성 버튼
	UI_MGR->AddButton("charCreate_Default", L"CreateScene0_create_charCreate_Default", { 404,506 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("charCreate_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("charCreate_Default", L"CreateScene0_create_charCreate_Over");
	auto CreateScene0_Func23 = [](void) { UI_MGR->FindUI("charCreate_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func24 = [](void) { UI_MGR->FindUI("charCreate_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("charCreate_Default", ADDEVENT_OnMouseOver, CreateScene0_Func23);
	UI_MGR->AddEvent("charCreate_Default", ADDEVENT_OnMouseExit, CreateScene0_Func24);
	////////////////////////////////////
	UI_MGR->AddButton("SelectMenu", L"CreateScene0_SelectMenu", { 620,355 }, { 1.50f, 1.33333f });
	//644, 462 부모 설정 안했을 시 좌표
	UI_MGR->AddButton("SelectMenu_No", L"ChannelScene_returnPage_no_Default", { 30,26 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("SelectMenu_No")->m_RayCast = true;
	UI_MGR->BitMapAdd("SelectMenu_No", L"ChannelScene_returnPage_no_Over");
	auto CreateScene0_Func25 = [](void) { UI_MGR->FindUI("SelectMenu_No")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func26 = [](void) { UI_MGR->FindUI("SelectMenu_No")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("SelectMenu_No", ADDEVENT_OnMouseOver, CreateScene0_Func25);
	UI_MGR->AddEvent("SelectMenu_No", ADDEVENT_OnMouseExit, CreateScene0_Func26);
	// 556, 462 부모 설정 안했을 시 좌표


	UI_MGR->AddButton("SelectMenu_Select_Default", L"CreateScene0_SelectMenu_Select_Default", { -43,26 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("SelectMenu_Select_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("SelectMenu_Select_Default", L"CreateScene0_SelectMenu_Select_Over");
	auto CreateScene0_Func27 = [](void) { UI_MGR->FindUI("SelectMenu_Select_Default")->m_Renderer.ChangeBitmap(1);/* checkEvent = true;*/ };
	auto CreateScene0_Func28 = [](void) { UI_MGR->FindUI("SelectMenu_Select_Default")->m_Renderer.ChangeBitmap(0); /* checkEvent = false; */};
	UI_MGR->AddEvent("SelectMenu_Select_Default", ADDEVENT_OnMouseOver, CreateScene0_Func27);
	UI_MGR->AddEvent("SelectMenu_Select_Default", ADDEVENT_OnMouseExit, CreateScene0_Func28);
	UI_MGR->SetParent("SelectMenu", "SelectMenu_No");
	UI_MGR->SetParent("SelectMenu", "SelectMenu_Select_Default");
	UI_MGR->FindUI("SelectMenu")->m_isActive = false;
	//페이지 띄우는것
	auto CreateScene0_Func29 = [](void) { UI_MGR->FindUI("SelectMenu")->m_isActive = true; };
	UI_MGR->AddEvent("adventures_Default", ADDEVENT_OnMouseClick, CreateScene0_Func29);
	UI_MGR->AddEvent("charCreate_Default", ADDEVENT_OnMouseClick, CreateScene0_Func29);

	auto CreateScene0_Func30 = [](void) { UI_MGR->FindUI("SelectMenu")->m_isActive = false; };
	UI_MGR->AddEvent("SelectMenu_No", ADDEVENT_OnMouseClick, CreateScene0_Func30);
	auto CreateScene0_Func31 = [](void) {SCENE_MGR->ChangeScene(SCENE_CREATE1); };
	UI_MGR->AddEvent("SelectMenu_Select_Default", ADDEVENT_OnMouseClick, CreateScene0_Func31);



	//////////////////////////////////////////////////////
	//leftArrow
	UI_MGR->AddButton("LeftArrow_Default", L"CreateScene0_LeftArrow_Default", { 92,644 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("LeftArrow_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("LeftArrow_Default", L"CreateScene0_LeftArrow_Over");
	auto CreateScene0_Func12 = [](void) { UI_MGR->FindUI("LeftArrow_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func13 = [](void) { UI_MGR->FindUI("LeftArrow_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("LeftArrow_Default", ADDEVENT_OnMouseOver, CreateScene0_Func12);
	UI_MGR->AddEvent("LeftArrow_Default", ADDEVENT_OnMouseExit, CreateScene0_Func13);


	//RightArrow
	UI_MGR->AddButton("RightArrow_Default", L"CreateScene0_RightArrow_Default", { 1106,644 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("RightArrow_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("RightArrow_Default", L"CreateScene0_RightArrow_Over");
	UI_MGR->BitMapAdd("RightArrow_Default", L"CreateScene0_create_Background1_rightArrow_default"); //2 
	auto CreateScene0_Func14 = [](void) { UI_MGR->FindUI("RightArrow_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func15 = [](void) { UI_MGR->FindUI("RightArrow_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("RightArrow_Default", ADDEVENT_OnMouseOver, CreateScene0_Func14);
	UI_MGR->AddEvent("RightArrow_Default", ADDEVENT_OnMouseExit, CreateScene0_Func15);



	//ChannelScene_returnLogin_Default
	//처음으로
	UI_MGR->AddButton("returnLogin_Default", L"ChannelScene_returnLogin_Default", { 59,747 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("returnLogin_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnLogin_Default", L"ChannelScene_returnLogin_Over");
	auto CreateScene0_Func8 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func9 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseOver, CreateScene0_Func8);
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseExit, CreateScene0_Func9);


	UI_MGR->AddButton("returnPage", L"ChannelScene_returnPage", { 600,400 }, { 1.50f, 1.33333f });
	//644, 462 부모 설정 안했을 시 좌표
	UI_MGR->AddButton("returnPage_no_Default", L"ChannelScene_returnPage_no_Default", { 30,47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("returnPage_no_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_no_Default", L"ChannelScene_returnPage_no_Over");
	auto CreateScene0_Func1 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func2 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseOver, CreateScene0_Func1);
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseExit, CreateScene0_Func2);
	// 556, 462 부모 설정 안했을 시 좌표


	UI_MGR->AddButton("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Default", { -30,47 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("returnPage_ok_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Over");
	auto CreateScene0_Func3 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func4 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseOver, CreateScene0_Func3);
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseExit, CreateScene0_Func4);
	UI_MGR->SetParent("returnPage", "returnPage_no_Default");
	UI_MGR->SetParent("returnPage", "returnPage_ok_Default");
	UI_MGR->FindUI("returnPage")->m_isActive = false;
	auto CreateScene0_Func5 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = true; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseClick, CreateScene0_Func5);
	auto CreateScene0_Func6 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseClick, CreateScene0_Func6);
	auto CreateScene0_Func7 = [](void) {SCENE_MGR->ChangeScene(SCENE_LOGIN); };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseClick, CreateScene0_Func7);

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
	auto End_Func6 = [](void) {PostQuitMessage(WM_DESTROY); };
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseClick, End_Func6);
	//============
}

void CreateScene0::Update(float _DelayTime)
{
	if (UI_MGR->m_ExitField == true)
	{
		m_szBuf = "";
		m_szMixingString[0] = NULL;

		UI_MGR->m_ExitField = false;

	}

	UI_MGR->Update(_DelayTime);

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

void CreateScene0::Render()
{
	UI_MGR->Render();

	//m_player.Render();
	obj.Render();
}

void CreateScene0::SendText()
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

LRESULT CreateScene0::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		//case WM_SETCURSOR: SetCursor(NULL); break;

	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);

		obj.m_Transform.SetPos((float)m_MousePos.x + 14.0f, (float)m_MousePos.y + 2.0f);
		////////////////


		//if (checkEvent)
		//{
		//	obj.m_Renderer.m_State = PLAYER_IDLE;
		//	//obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);
		//	//MK_LOG("머징");
		//}
		//else
		//{
		//	obj.m_Renderer.m_State = -1;
		//	obj.m_Renderer.ChangeBitmap(0);
		//}



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
		//obj.m_Renderer.m_State = -1;
		//obj.m_Renderer.ChangeBitmap(1);
		MK_LOG("%d, %d 클릭", m_MousePos.x, m_MousePos.y);

		UI_MGR->OnMouseDown(m_MousePos);

		m_isClicked = true;

	}break;

	case WM_LBUTTONUP:
	{
		//obj.m_Renderer.ChangeBitmap(0);
		//if (checkEvent)
		//{
		//	obj.m_Renderer.m_State = PLAYER_IDLE;
		//	//obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);

		//}
		//else
		//{
		//	obj.m_Renderer.m_State = -1;
		//	obj.m_Renderer.ChangeBitmap(0);
		//}
		UI_MGR->OnMouseUp(m_MousePos);

		m_isClicked = false;

	}break;

	case WM_MOUSEWHEEL:
	{
		SCENE_MGR->ChangeScene(SCENE_CHANNEL);
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
		return 0;
		/*default:
		return FALSE;*/
		//====
	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}


