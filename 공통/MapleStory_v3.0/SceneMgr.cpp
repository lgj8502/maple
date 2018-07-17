#include "stdafx.h"
#include "SceneMgr.h"
#include "LobbyScene.h"
#include "IngameScene.h"
#include "LoginScene.h"
#include "ChannelScene.h"
#include "CreateScene0.h"
#include "CreateScene1.h"

void SceneMgr::SetScene()
{
	delete m_pScene;

	switch (m_Type)
	{
	case SCENE_LOGIN:
		m_pScene = new LoginScene;
		break;
	case SCENE_CHANNEL:
		m_pScene = new ChannelScene;
		break;
	case SCENE_LOBBY:
		m_pScene = new LobbyScene;
		break;
	case SCENE_CREATE0:
		m_pScene = new CreateScene0;
		break;
	case SCENE_CREATE1:
		m_pScene = new CreateScene1;
		break;
	case SCENE_INGAME:
		m_pScene = new IngameScene;
		break;
	}

	// 클래스 초기화
	m_pScene->Init(m_hWnd);

	m_IsChange = false;
}

SceneMgr::~SceneMgr()
{
	delete m_pScene;
}

void SceneMgr::Update(float _DelayTime)
{
	if (m_IsChange == true)
	{
		SetScene();
	}

	if (m_pScene != nullptr)
	{
		m_pScene->Update(_DelayTime);
	}
}

void SceneMgr::Render()
{
	if (m_pScene != nullptr)
	{
		m_pScene->Render();
	}
}

void SceneMgr::ChangeScene(int _Type)
{
	m_Type		= _Type;
	m_IsChange	= true;

	UI_MGR->Destroy();
	IMG_MGR->ClearImgList();
}

LRESULT SceneMgr::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{	
	if (m_pScene != nullptr)
	{
		return m_pScene->MyWndProc(hWnd, iMessage, wParam, lParam);
	}
	else
	{
		return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
	}	
}
