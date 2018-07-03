#include "stdafx.h"
#include "IngameScene.h"

IngameScene::~IngameScene()
{

}

void IngameScene::Init(HWND hWnd)
{
	IMG_MGR->FileFindDir(L".\\Img\\IngameScene\\");

	MAP_MGR->AddTile(L"enH0.1", { 500,500 });
	MAP_MGR->AddTile(L"enH0.2", { 590,500 });

	m_monster.Init();

}

void IngameScene::Update(float _DelayTime)
{
	if (UI_MGR->m_ExitField == true)
	{
		m_szBuf = "";
		m_szMixingString[0] = NULL;

		UI_MGR->m_ExitField = false;

	}

	UI_MGR->Update(_DelayTime);

	m_monster.Update(_DelayTime);


	MAP_MGR->Update(_DelayTime);
	m_player.Update(_DelayTime);



	if (OnceKeyDown(VK_RETURN))
	{
		if (UI_MGR->m_isChating == false)
		{
			UI_MGR->m_isChating = true;
		}
	}

	if (StayKeyDown(VK_LEFT))
	{
		m_player.LeftWalk(_DelayTime);

	}
	if (OnceKeyUp(VK_LEFT) || OnceKeyUp(VK_RIGHT))
	{
		m_player.StopWalk();

	}

	if (StayKeyDown(VK_RIGHT))
	{
		m_player.RightWalk(_DelayTime);

	}

	if (OnceKeyDown(VK_F1))
	{
		m_player.ChangeCoat(101);
	}

	if (OnceKeyDown(VK_F2))
	{
		m_player.ChangeCoat(100);
	}

	if (StayKeyDown(VK_F3))
	{
		m_monster.LeftMove(_DelayTime);
	}
	if (StayKeyDown(VK_F4))
	{
		m_monster.RightMove(_DelayTime);
	}

	if (OnceKeyUp(VK_F3) || OnceKeyUp(VK_F4))
	{
		m_monster.StopMove();
	}

	if (OnceKeyDown(VK_MENU))
	{
		m_player.JumpMove();
	}
}

void IngameScene::Render()
{
	UI_MGR->Render();

	MAP_MGR->BackRender();
	m_monster.Render();
	m_player.Render();

	MAP_MGR->LadderRender();

	MAP_MGR->FrontRender();
}

void IngameScene::SendText()
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

LRESULT IngameScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
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


	case WM_SYSKEYDOWN:
	{
		if (wParam == VK_MENU)
		{
			return 0;
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
