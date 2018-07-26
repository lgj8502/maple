#include "stdafx.h"
#include "ChannelScene.h"

//////추가 사항
static bool checkEvent = false;
//////////////////
ChannelScene::~ChannelScene()
{

}

void ChannelScene::Init(HWND hWnd)
{
	IMG_MGR->FileFindDir(L".\\Img\\ChannelScene\\");

	//SOUND_MGR->FileFindDir(L".\\Sound\\");
	//SOUND_MGR->SoundBGM(L"MoonlightShadow");
	////SOUND_MGR->SoundDelete
	//	mouse default image 
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseDefault"));	//0
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseClick"));		// 1

																	//mouse animation
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver0"));		// 2
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver1"));		// 3
	obj.m_Renderer.AddAnimation(0, 2, 3, 0.5, 0.5);
	obj.m_Renderer.m_State = -1;


	background.m_Renderer.m_State = 0;
	background.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_1first"));			//0
	background.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_2second"));		// 1
	background.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_3third"));			// 2
	background.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_4four"));			// 3

	background.m_Renderer.ChangeBitmap(0);
	background.m_Renderer.SetImgRT({ 0,0,1200,800 });
	background.m_Renderer.ChangeBitmap(1);
	background.m_Renderer.SetImgRT({ 0,0,1200,800 });
	background.m_Renderer.ChangeBitmap(2);
	background.m_Renderer.SetImgRT({ 0,0,1200,800 });
	background.m_Renderer.ChangeBitmap(3);
	background.m_Renderer.SetImgRT({ 0,0,1200,800 });
	background.m_Renderer.AddAnimation(0, 0, 3, 0.18, 0.18, 0.18, 0.18);


	//background.m_Renderer.SetImgRT
	//background.m_Transform.SetPos({ background.m_Renderer.GetImgRT().left,background.m_Renderer.GetImgRT().bottom });
	//UI_MGR->AddImage("channel_1first", L"ChannelScene_channel_1first", { 0,0,1200,800 });
	//UI_MGR->FindUI("channel_1first")->m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_1first"));	//0
	//UI_MGR->FindUI("channel_1first")->m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_2second"));		// 1
	//UI_MGR->FindUI("channel_1first")->m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_3third"));		// 2
	//UI_MGR->FindUI("channel_1first")->m_Renderer.AddBitmap(IMG_MGR->GetImage(L"ChannelScene_channel_4four"));		// 3
	//UI_MGR->FindUI("channel_1first")->m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5);

	//800 : 600  -> 1200 800  :: 1.5  1.33333

	//1065,304
	//UI_MGR->Destroy();	


	//ChannelScene_returnLogin_Default
	UI_MGR->AddButton("returnLogin_Default", L"ChannelScene_returnLogin_Default", { 59,747 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("returnLogin_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnLogin_Default", L"ChannelScene_returnLogin_Over");
	auto ChannelScene_Func2 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto ChannelScene_Func3 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseOver, ChannelScene_Func2);
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseExit, ChannelScene_Func3);

	//ChannelScene_returnPage
	UI_MGR->AddButton("returnPage", L"ChannelScene_returnPage", { 600,400 }, { 1.50f, 1.33333f });
	//644, 462 부모 설정 안했을 시 좌표
	UI_MGR->AddButton("returnPage_no_Default", L"ChannelScene_returnPage_no_Default", { 30,47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("returnPage_no_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_no_Default", L"ChannelScene_returnPage_no_Over");
	auto ChannelScene_Func4 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto ChannelScene_Func5 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseOver, ChannelScene_Func4);
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseExit, ChannelScene_Func5);
	// 556, 462 부모 설정 안했을 시 좌표
	UI_MGR->AddButton("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Default", { -30,47 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("returnPage_ok_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Over");
	auto ChannelScene_Func6 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto ChannelScene_Func7 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseOver, ChannelScene_Func6);
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseExit, ChannelScene_Func7);
	UI_MGR->SetParent("returnPage", "returnPage_no_Default");
	UI_MGR->SetParent("returnPage", "returnPage_ok_Default");
	UI_MGR->FindUI("returnPage")->m_isActive = false;
	auto ChannelScene_Func8 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = true; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseClick, ChannelScene_Func8);
	auto ChannelScene_Func9 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseClick, ChannelScene_Func9);
	auto ChannelScene_Func10 = [](void) {SCENE_MGR->ChangeScene(SCENE_LOGIN); };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseClick, ChannelScene_Func10);

	//ChannelScene_union_Default
	UI_MGR->AddButton("union_Default", L"ChannelScene_union_Default", { 1065,304 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("union_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("union_Default", L"ChannelScene_union_Over");
	auto Func2 = [](void) { UI_MGR->FindUI("union_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func3 = [](void) { UI_MGR->FindUI("union_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("union_Default", ADDEVENT_OnMouseOver, Func2);
	UI_MGR->AddEvent("union_Default", ADDEVENT_OnMouseExit, Func3);
	auto ChannelScene_Func11 = [](void) {SCENE_MGR->ChangeScene(SCENE_LOBBY); };
	UI_MGR->AddEvent("union_Default", ADDEVENT_OnMouseClick, ChannelScene_Func11);


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
	auto End_Func6 = [](void) {		DATA_MGR->AllMgrDestroy(); PostQuitMessage(WM_DESTROY); };
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseClick, End_Func6);

}

void ChannelScene::Update(float _DelayTime)
{
	if (UI_MGR->m_ExitField == true)
	{
		m_szBuf = "";
		m_szMixingString[0] = NULL;

		UI_MGR->m_ExitField = false;

	}

	background.Update(_DelayTime);
	UI_MGR->Update(_DelayTime);

	obj.Update(_DelayTime);

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (UI_MGR->m_isChating == false)
		{
			UI_MGR->m_isChating = true;
		}
	}
}

void ChannelScene::Render()
{
	background.Render();
	UI_MGR->Render();

	obj.Render();
}

void ChannelScene::SendText()
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

LRESULT ChannelScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
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
		//SCENE_MGR->ChangeScene(SCENE_SERVER);
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
