#include "stdafx.h"
#include "ServerScene.h"

ServerScene::~ServerScene()
{
	
}

void ServerScene::Init(HWND hWnd)
{
	//m_Font.SetFont(L"°íµñ");
	UI_MGR->AddImage("ServerMain", L"ServerMain", { 0,0,1200,800 });

	UI_MGR->AddText("Son", "ÀÚ½Ä", { 0,0 }, ColorF(ColorF::Red), L"±Ã¼­");
	
	UI_MGR->AddImage("test1", L"test1", { 300,300 }, { 1.0f, 1.0f });

	UI_MGR->SetParent("test1", "Son");


}

void ServerScene::Update(float _DelayTime)
{
	//m_test.Update();

	UI_MGR->Update(_DelayTime);
}

void ServerScene::Render()
{
	//m_Font.TextRender(IMG_MGR->GetpRT(), IMG_MGR->GetBrush(), Point2F(20, 20), "¼­¹ö¾À");


	//m_test.Render();

	UI_MGR->Render();



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
		POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
		MK_LOG("%d, %d Å¬¸¯", pt.x, pt.y);




		//UI_MGR->FindUI("test1")->m_Transform.SetPos(m_MousePos.x, m_MousePos.y);



	}break;

	}

	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
