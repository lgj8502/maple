#include "stdafx.h"
#include "IngameScene.h"

IngameScene::~IngameScene()
{

}

void IngameScene::Init(HWND hWnd)
{
	m_Font.SetFont(L"���");
	IMG_MGR->FileFindDir(ImgDir);
}

void IngameScene::Update(float _DelayTime)
{


}

void IngameScene::Render(ID2D1RenderTarget *_pRT, ID2D1SolidColorBrush *_pBrush)
{
	m_Font.TextRender(_pRT, _pBrush, Point2F(20, 20), "�ΰ��Ӿ�");
}

LRESULT IngameScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
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
		SCENE_MGR->ChangeScene(SCENE_SERVER);

	}break;

	}

	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
