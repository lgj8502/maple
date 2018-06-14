#include "stdafx.h"
#include "ServerScene.h"

ServerScene::~ServerScene()
{

}

void ServerScene::Init(HWND hWnd)
{
	m_Font.SetFont(L"���");

}

void ServerScene::Update(float _DelayTime)
{
}

void ServerScene::Render(ID2D1RenderTarget *_pRT, ID2D1SolidColorBrush *_pBrush)
{
	//m_Font.TextRender(_pRT, _pBrush, Point2F(20, 20), "������");


	IMG_MGR->RendRect(L"ServerMain", { 0,0,1200,800 });

}

LRESULT ServerScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
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
		SCENE_MGR->ChangeScene(SCENE_LOBBY);

		Log_MGR("���������� Ŭ����");
	}break;

	}

	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
