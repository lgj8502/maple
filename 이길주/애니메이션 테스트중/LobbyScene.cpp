#include "stdafx.h"
#include "LobbyScene.h"

void LobbyScene::Init(HWND hWnd)
{
	m_Font.SetFont(L"����");
}

void LobbyScene::Update(float _DelayTime)
{
}

void LobbyScene::Render()
{
	//m_Font.TextRender(_pRT, _pBrush, Point2F(20, 20), "�κ��");


}

LRESULT LobbyScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);
	}break;
	case WM_LBUTTONDOWN:
	{
		SCENE_MGR->ChangeScene(SCENE_INGAME);


	}break;

	}

	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
