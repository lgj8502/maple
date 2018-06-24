#include "stdafx.h"
#include "ServerScene.h"

ServerScene::~ServerScene()
{
	
}

void ServerScene::Init(HWND hWnd)
{

	UI_MGR->AddImage("ServerMain", L"ServerMain", { 0,0,1200,800 });


	UI_MGR->AddImage("플레이어", L"test1", { 300,300 }, { 0.3f, 0.3f });

	UI_MGR->AddText("Son", "자식", { 30,0 }, ColorF(ColorF::Black), L"고딕", 50.0f);

	UI_MGR->SetParent("플레이어", "Son");

	UI_MGR->FindUI("플레이어")->m_RayCast = true;

	UI_MGR->BitMapAdd("플레이어", L"test2");	

	

	auto Func1 = [](void) { UI_MGR->FindUI("플레이어")->m_Transform.SetPos({ 500,500 }); };
	auto Func2 = [](void) { UI_MGR->FindUI("플레이어")->m_Renderer.ChangeBitmap(1); };
	auto Func3 = [](void) { UI_MGR->FindUI("플레이어")->m_Renderer.ChangeBitmap(0); };


	//UI_MGR->AddEvent("플레이어", Event_OnMouseDown, Func1);
	UI_MGR->AddEvent("플레이어", Event_OnMouseOver, Func2);
	UI_MGR->AddEvent("플레이어", Event_OnMouseExit, Func3);


	UI_MGR->AddButton("베라서버", L"bera", { 100,500 }, { 1.0f, 1.0f });

	UI_MGR->FindUI("베라서버")->m_UseDrag = true;


//////////////////////// 탭바 예시 //////////////////////////////////////////////////

	// 토글 버튼 추가
	UI_MGR->AddToggle("토글1", L"toggle1", { -80,-200 }, { 0.8f, 0.8f });
	UI_MGR->BitMapAdd("토글1", L"toggle2");

	UI_MGR->AddToggle("토글2", L"toggle1", { 80,-200 }, { 0.8f, 0.8f });
	UI_MGR->BitMapAdd("토글2", L"toggle2");

	// 토글 on/off 시 이미지 변경 함수
	auto tog1_1 = [](void) { UI_MGR->FindUI("토글1")->m_Renderer.ChangeBitmap(1); };
	auto tog1_2 = [](void) { UI_MGR->FindUI("토글1")->m_Renderer.ChangeBitmap(0); };
	auto tog2_1 = [](void) { UI_MGR->FindUI("토글2")->m_Renderer.ChangeBitmap(1); };
	auto tog2_2 = [](void) { UI_MGR->FindUI("토글2")->m_Renderer.ChangeBitmap(0); };

	UI_MGR->AddEvent("토글1", Event_ToggleOn, tog1_1);
	UI_MGR->AddEvent("토글1", Event_ToggleOff, tog1_2);
	UI_MGR->AddEvent("토글2", Event_ToggleOn, tog2_1);
	UI_MGR->AddEvent("토글2", Event_ToggleOff, tog2_2);

	// 토글1 버튼은 활성화
	UI_MGR->FindUI("토글1")->m_isOn = true;
	UI_MGR->FindUI("토글1")->m_Renderer.ChangeBitmap(1);

	// 토글 그룹 지정
	vector<cUI*> vUI;

	vUI.push_back(UI_MGR->FindUI("토글1"));
	vUI.push_back(UI_MGR->FindUI("토글2"));

	UI_MGR->AddToggleGroup("토글그룹", { 0, 0 }, vUI);

	// 탭바 몸체 추가
	UI_MGR->AddImage("탭바", L"TabBar", { 600,200 }, { 0.5f, 0.5f });

	// 탭바 드래그 가능
	UI_MGR->FindUI("탭바")->m_RayCast = true;
	UI_MGR->FindUI("탭바")->m_UseDrag = true;

	// 탭바 구성
	UI_MGR->SetParent("탭바", "토글그룹");
	UI_MGR->AddImage("탭바글씨", L"탭바글씨", { 0, -300 }, { 0.8f, 0.8f });
	UI_MGR->SetParent("탭바", "탭바글씨");

	// 토글키 클릭시 나올 화면 표시
	UI_MGR->AddImage("왼쪽", L"왼쪽", { 0, 100 }, { 0.6f, 0.6f });
	UI_MGR->AddImage("오른쪽", L"오른쪽", { 0, 100 }, { 0.6f, 0.6f });

	UI_MGR->SetParent("탭바", "왼쪽");
	UI_MGR->SetParent("탭바", "오른쪽");	

	auto tog1_3 = [](void) { UI_MGR->FindUI("왼쪽")->m_isActive = true; };
	auto tog1_4 = [](void) { UI_MGR->FindUI("왼쪽")->m_isActive = false; };
	auto tog2_3 = [](void) { UI_MGR->FindUI("오른쪽")->m_isActive = true; };
	auto tog2_4 = [](void) { UI_MGR->FindUI("오른쪽")->m_isActive = false; };

	UI_MGR->AddEvent("토글1", Event_ToggleOn, tog1_3);
	UI_MGR->AddEvent("토글1", Event_ToggleOff, tog1_4);

	UI_MGR->AddEvent("토글2", Event_ToggleOn, tog2_3);
	UI_MGR->AddEvent("토글2", Event_ToggleOff, tog2_4);

	UI_MGR->FindUI("오른쪽")->m_isActive = false;

	// 창닫기 버튼 추가

	UI_MGR->AddButton("탭바닫기", L"창닫기", { 200,-250 }, { 0.8f, 0.8f });

	UI_MGR->SetParent("탭바", "탭바닫기");

	auto tabBar_off = [](void) { UI_MGR->FindUI("탭바")->m_isActive = false; };

	UI_MGR->AddEvent("탭바닫기", Event_OnMouseClick, tabBar_off);

	// 스크롤바 추가
	UI_MGR->AddScrollBar("스크롤바", L"Scrollbar", L"ScrollHandle", { 200,100 }, 0.9f, { 0.8f, 1.2f });

	UI_MGR->SetParent("탭바", "스크롤바");

	UI_MGR->AddText("스크롤값", "값", { 0, 130 }, ColorF(1, 1, 1));

	UI_MGR->SetParent("탭바", "스크롤값");


	auto scrollvalue = [](void) { 
		char value[5] = "";

		sprintf_s(value, 5, "%.2f", UI_MGR->FindUI("스크롤바")->m_Value);

		UI_MGR->FindUI("스크롤값")->m_Text = value;
	  };

	UI_MGR->AddEvent("스크롤값", Event_Update, scrollvalue);


	//////////////인풋필드 예시//////////////////////////////////////////////////////////

	//UI_MGR->AddInputField("인풋필드", L"InputField", { 300,600 }, { 0.5 , 1 }, ColorF(ColorF::White), L"굴림", 20.0f, 0.7f);



	
	m_player.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"test2"));



}

void ServerScene::Update(float _DelayTime)
{


	UI_MGR->Update(_DelayTime);

	m_player.Update(_DelayTime);
}

void ServerScene::Render()
{


	UI_MGR->Render();

	m_player.Render();


}

LRESULT ServerScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);

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
		MK_LOG("%d, %d 클릭", m_MousePos.x, m_MousePos.y);

		UI_MGR->OnMouseDown(m_MousePos);

		m_isClicked = true;

	}break;

	case WM_LBUTTONUP:
	{
		UI_MGR->OnMouseUp(m_MousePos);

		m_isClicked = false;

	}break;

	// IME 용

	case WM_CHAR:
	{
		if (UI_MGR->m_isTyping == false) break;

		char cWord = (char)wParam;

		//	백스페이스 버튼 클릭
		if (cWord == VK_BACK &&
			UI_MGR->m_szMixingString[0] == NULL)
		{

			int nLen = UI_MGR->m_szBuf.length();

			if (nLen > 0)
			{
				//	지워야할 문자가 조합체 인경우
				if (UI_MGR->m_szBuf[nLen - 1] < 0)
				{
					UI_MGR->m_szBuf = UI_MGR->m_szBuf.substr(0, nLen - 2);
				}

				//	일반 문자를 지울 경우
				else
				{
					UI_MGR->m_szBuf = UI_MGR->m_szBuf.substr(0, nLen - 1);
				}
			}
		}
		//	엔터
		else if (cWord == VK_RETURN)
		{
			//CheckText = UI_MGR->m_szBuf;
			UI_MGR->m_szBuf = "";
		}
		else
		{
			UI_MGR->m_szBuf += (char)wParam;
		}


	}break;

	//	조합이 완전히 끝난 경우 조합중인 문자열을 비운다.
	case WM_IME_ENDCOMPOSITION:
	{

		if (UI_MGR->m_isTyping == false) break;

		UI_MGR->m_szMixingString[0] = NULL;
	}
	break;

	//	IME 안에 있는 조합에 대한 내용을 얻을 수 있다.
	case WM_IME_COMPOSITION:
	{

		if (UI_MGR->m_isTyping == false) break;

		//	조합중일 경우 현재 조합중인 단어를 얻어온다.
		if (lParam & GCS_COMPSTR)
		{
			UI_MGR->m_szMixingString[0] = CHAR(wParam >> 8);
			UI_MGR->m_szMixingString[1] = CHAR(wParam);
		}

		//	조합이 끝난 경우	WM_IME_CHAR 와 같은 역활
		else if (lParam & GCS_RESULTSTR)
		{
			char szFinalString[3];

			szFinalString[0] = CHAR(wParam >> 8);
			szFinalString[1] = CHAR(wParam);
			szFinalString[2] = NULL;

			//	완성된 문자열을 추가 한다.
			UI_MGR->m_szBuf += szFinalString;
		}

		//	기본 IME 에게 전달하지 않기 위해 바로 프로시저를 끝낸다.
		return 0;
	}
	break;

	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
