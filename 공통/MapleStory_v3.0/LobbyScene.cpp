#include "stdafx.h"
#include "LobbyScene.h"

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
	IMG_MGR->FileFindDir(L".\\Img\\LobbyScene\\");

	//	mouse default image 
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseDefault"));	//0
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseClick"));		// 1

																	//mouse animation
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver0"));		// 2
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver1"));		// 3
	obj.m_Renderer.AddAnimation(0, 2, 3, 0.5, 0.5);
	obj.m_Renderer.m_State = -1;

	UI_MGR->AddImage("background", L"LobbyScene_background", { 0,0,1200,800 });
	//800 : 600  -> 1200 800  :: 1.5  1.33333


	////케릭터 주변 이펙트 보이기
	////Object2D charBackground1;
	//UI_MGR->AddImage("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.0", { 400,  400 }, { 1.0f, 1.0f });
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.0");//0
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.0");//0
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.0");//0
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.0");//0
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.1");//1
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.1");//1
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.1");//1
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.1");//1
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.1");//1
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.2");//2
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.2");//2
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.2");//2
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.2");//2
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.2");//2
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.3");//3 15
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.3");//3
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.3");//3
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.3");//3
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.3");//3
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.4");//4 20 
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.4");//4
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.4");//4
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.4");//4
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.4");//4
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.4");//4
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.5");//5 26
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.5");//5
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.5");//5
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.5");//5
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.5");//5
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.6");//6 31 
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.6");//6
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.6");//6
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.6");//6
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.6");//6
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.7");//7  36
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.7");//7
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.7");//7
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.7");//7
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.7");//7
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.8");//8 41 
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.8");//8
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.8");//8
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.8");//8
	//UI_MGR->BitMapAdd("LobbyScene_charBackground1.5.0", L"LobbyScene_charBackground1.5.8");//8

	//																					   //charBackground1.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseDefault"));
	//																					   //케릭터 주변 이펙트 보이기









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
	//=====
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
		//==
	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}

