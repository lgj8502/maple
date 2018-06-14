#include "stdafx.h"
#include "LobbyScene.h"

void LobbyScene::Init(HWND hWnd)
{
	m_Font.SetFont(L"°íµñ");
}

void LobbyScene::Update(float _DelayTime)
{
}

void LobbyScene::Render(ID2D1RenderTarget * _pRT, ID2D1SolidColorBrush * _pBrush)
{
	//m_Font.TextRender(_pRT, _pBrush, Point2F(20, 20), "·Îºñ¾À");

	IMG_MGR->RendRect(L"LobbyMain", { 0,0,1200,800 });
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
		Log_MGR("·Îºñ¾À¿¡¼­ Å¬¸¯ÇÔ");

	}break;

	}

	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
