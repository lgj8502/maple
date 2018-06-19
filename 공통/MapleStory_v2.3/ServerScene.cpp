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

	UI_MGR->AddEvent("플레이어", Event_OnMouseDown, Func1);
	UI_MGR->AddEvent("플레이어", Event_OnMouseOver, Func2);
	UI_MGR->AddEvent("플레이어", Event_OnMouseExit, Func3);


	UI_MGR->AddButton("베라서버", L"bera", { 100,500 });

	UI_MGR->FindUI("베라서버")->m_CanDrag = true;



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

		//UI_MGR->FindUI("test1")->m_Transform.SetPos(m_MousePos.x, m_MousePos.y);

	}break;

	case WM_LBUTTONUP:
	{
		UI_MGR->OnMouseUp(m_MousePos);

		m_isClicked = false;

	}break;
	}

	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
