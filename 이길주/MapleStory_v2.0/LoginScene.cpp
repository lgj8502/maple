#include "stdafx.h"
#include "LoginScene.h"

//////추가 사항
static bool checkEvent = false;
//////////////////
LoginScene::~LoginScene()
{

}

void LoginScene::Init(HWND hWnd)
{
	IMG_MGR->FileFindDir(L".\\Img\\LoginScene\\");

	SOUND_MGR->SetHwnd(hWnd);
	SOUND_MGR->SoundCreate("floralife.mp3", &(SOUND_MGR->a[0]));
	//MoonlightShadow  floralife
	SOUND_MGR->SoundPlay(SOUND_MGR->a[0]);
	//UI_MGR->AddImage("mouseDefault", L"mouseDefault", { 0,0 }, {1.0f,1.0f});
	//	mouse default image 
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseDefault"));	//0
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseClick"));		// 1
	
	//mouse animation
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver0"));		// 2
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver1"));		// 3
	obj.m_Renderer.AddAnimation(0, 2, 3, 0.5, 0.5);
	obj.m_Renderer.m_State = -1;
	//obj.m_Renderer.m_State = PLAYER_IDLE;
	//obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);
	//mouse animation
	

	//loginScene_BackGround
	UI_MGR->AddImage("loginScene_BackGround", L"loginScene_BackGround", { 0,0,1200,800 });
	//799 x 597  -> 1200x800

	//	1.50188  : 1.34

	//////////////////////////////////////////////default button
	//loginScene_00_createId_default
	UI_MGR->AddButton("createId_default", L"loginScene_00_createId_default", { 483,499 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("createId_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("createId_default", L"loginScene_00_createId_Over");

	
	auto Func2 = [](void) { UI_MGR->FindUI("createId_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func3 = [](void) { UI_MGR->FindUI("createId_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("createId_default", ADDEVENT_OnMouseOver, Func2);
	UI_MGR->AddEvent("createId_default", ADDEVENT_OnMouseExit, Func3);
	
	

	//void Func22 = [](Object2D oo) ->void{ oo.m_Renderer.ChangeBitmap(2); }(obj);
	//auto Func22 = [](Object2D oo){ oo.m_Renderer.ChangeBitmap(2); };
	
	//auto mouseFunc =[](Object2D oo) { oo.m_Renderer.ChangeBitmap(2); };
	//UI_MGR->AddEvent("createId_default", ADDEVENT_OnMouseOver, mouseFunc(obj)  );

	//UI_MGR->AddEvent("createId_default", ADDEVENT_OnMouseOver, 	[](){oo.m_Renderer.ChangeBitmap(2); });

	//loginScene_01_HomePage_default
	UI_MGR->AddButton("HomePage_default", L"loginScene_01_HomePage_default", { 591,499 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("HomePage_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("HomePage_default", L"loginScene_01_HomePage_Over");
	auto Func4 = [](void) { UI_MGR->FindUI("HomePage_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func5 = [](void) { UI_MGR->FindUI("HomePage_default")->m_Renderer.ChangeBitmap(0); checkEvent = false; };
	UI_MGR->AddEvent("HomePage_default", ADDEVENT_OnMouseOver, Func4);
	UI_MGR->AddEvent("HomePage_default", ADDEVENT_OnMouseExit, Func5);

	//loginScene_03_Finish_default
	UI_MGR->AddButton("Finish_default", L"loginScene_03_Finish_default", { 699,499 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("Finish_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("Finish_default", L"loginScene_03_Finish_Over");
	auto Func6 = [](void) { UI_MGR->FindUI("Finish_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func7 = [](void) { UI_MGR->FindUI("Finish_default")->m_Renderer.ChangeBitmap(0); checkEvent = false; };
	UI_MGR->AddEvent("Finish_default", ADDEVENT_OnMouseOver, Func6);
	UI_MGR->AddEvent("Finish_default", ADDEVENT_OnMouseExit, Func7);

	//loginScene_04_id_check_Not
	//on click/////////////////////////
	/*


	*////
	UI_MGR->AddToggle("id_check_Not", L"loginScene_04_id_check_Not", { 439,463 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("id_check_Not")->m_RayCast = true;
	UI_MGR->FindUI("id_check_Not")->m_isActive = true;
	UI_MGR->BitMapAdd("id_check_Not", L"loginScene_04_id_check_Check");
	auto Func8 = [](void) { UI_MGR->FindUI("id_check_Not")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func9 = [](void) { UI_MGR->FindUI("id_check_Not")->m_Renderer.ChangeBitmap(0); checkEvent = false; };
	UI_MGR->AddEvent("id_check_Not", ADDEVENT_OnMouseClick, Func8);
	UI_MGR->AddEvent("id_check_Not", ADDEVENT_ToggleOff, Func9);


	auto tog1_3 = [](void) { UI_MGR->FindUI("id_check_Not")->m_isActive = true; checkEvent = true; };
	auto tog1_4 = [](void) { UI_MGR->FindUI("id_check_Not")->m_isActive = false; checkEvent = false; };
	//auto tog2_3 = [](void) { UI_MGR->FindUI("오른쪽")->m_isActive = true; };
	//	auto tog2_4 = [](void) { UI_MGR->FindUI("오른쪽")->m_isActive = false; };

	UI_MGR->AddEvent("id_check_Not", ADDEVENT_ToggleOn, tog1_3);
	UI_MGR->AddEvent("id_check_Not", ADDEVENT_ToggleOff, tog1_4);


	//loginScene_05_idsave_default
	UI_MGR->AddToggle("idsave_default", L"loginScene_05_idsave_default", { 479,464 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("idsave_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("idsave_default", L"loginScene_05_idsave_Over");
	auto Func10 = [](void) { UI_MGR->FindUI("idsave_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func11 = [](void) { UI_MGR->FindUI("idsave_default")->m_Renderer.ChangeBitmap(0); checkEvent = false; };
	UI_MGR->AddEvent("idsave_default", ADDEVENT_OnMouseOver, Func10);
	UI_MGR->AddEvent("idsave_default", ADDEVENT_OnMouseExit, Func11);

	UI_MGR->AddEvent("idsave_default", ADDEVENT_ToggleOn, Func8);
	UI_MGR->AddEvent("idsave_default", ADDEVENT_ToggleOff, Func9);
	//////////////////////////////////////////////////


	//loginScene_06_idFind_default //y::465
	UI_MGR->AddButton("idFind_default", L"loginScene_06_idFind_default", { 581,465 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("idFind_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("idFind_default", L"loginScene_06_idFind_Over");
	auto Func12 = [](void) { UI_MGR->FindUI("idFind_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func13 = [](void) { UI_MGR->FindUI("idFind_default")->m_Renderer.ChangeBitmap(0); checkEvent = false; };
	UI_MGR->AddEvent("idFind_default", ADDEVENT_OnMouseOver, Func12);
	UI_MGR->AddEvent("idFind_default", ADDEVENT_OnMouseExit, Func13);

	//loginScene_07_passFind_default
	UI_MGR->AddButton("passFind_default", L"loginScene_07_passFind_default", { 698,464 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("passFind_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("passFind_default", L"loginScene_07_passFind_Over");
	auto Func14 = [](void) { UI_MGR->FindUI("passFind_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func15 = [](void) { UI_MGR->FindUI("passFind_default")->m_Renderer.ChangeBitmap(0); checkEvent = false; };
	UI_MGR->AddEvent("passFind_default", ADDEVENT_OnMouseOver, Func14);
	UI_MGR->AddEvent("passFind_default", ADDEVENT_OnMouseExit, Func15);

	//loginScene_08_login_default
	UI_MGR->AddButton("login_default", L"loginScene_08_login_default", { 714,411 }, { 1.50188f, 1.34003f });
	UI_MGR->FindUI("login_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("login_default", L"loginScene_08_login_Over");
	auto Func16 = [](void) { UI_MGR->FindUI("login_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto Func17 = [](void) { UI_MGR->FindUI("login_default")->m_Renderer.ChangeBitmap(0); checkEvent = false; };
	auto Func18 = [](void) { 		SOUND_MGR->SoundStop(SOUND_MGR->a[0]);
									SOUND_MGR->SoundDelete(SOUND_MGR->a[0]);
									SCENE_MGR->ChangeScene(SCENE_CHANNEL); checkEvent = false; 
						   };
	UI_MGR->AddEvent("login_default", ADDEVENT_OnMouseOver, Func16);
	UI_MGR->AddEvent("login_default", ADDEVENT_OnMouseExit, Func17);
	UI_MGR->AddEvent("login_default", ADDEVENT_OnMouseDown, Func18);

	//textField
	UI_MGR->AddButton("nexonEmail", L"loginScene_nexonEmail", { 553,393 }, { 1.50188f, 1.34003f });
	UI_MGR->AddButton("password", L"loginScene_password", { 553,427 }, { 1.50188f, 1.34003f });
	////////////////추가예정
	UI_MGR->AddInputField("loginScene_textBar1", L"loginScene_textBar_", { 553,393 }, { 1.50188f, 1.34003f }, ((D2D1::ColorF)(ColorF::Black)), L"고딕", 1.0f, 15.0f);
	UI_MGR->AddInputField("loginScene_textBar2", L"loginScene_textBar_", { 553,427 }, { 1.50188f, 1.34003f }, ((D2D1::ColorF)(ColorF::Black)), L"고딕", 1.0f, 15.0f);
}

void LoginScene::Update(float _DelayTime)
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

void LoginScene::Render()
{
	UI_MGR->Render();

	//m_player.Render();
	obj.Render();
}

void LoginScene::SendText()
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

LRESULT LoginScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	//case WM_SETCURSOR: SetCursor(NULL); break;
	case WM_CREATE:
		//SOUND_MGR ->Init(hWnd);
		//SOUND_MGR->SoundCreate("floralife.mp3", &(SOUND_MGR->a[0]));
		//SOUND_MGR->SoundPlay(SOUND_MGR->a[0]);
	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);

		obj.m_Transform.SetPos((float)m_MousePos.x, (float)m_MousePos.y);
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

		if (checkEvent	)
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

	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}

