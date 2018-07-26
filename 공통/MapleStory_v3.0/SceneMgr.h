#pragma once

#include <Windows.h>

#include "TemplateSingleton.h"

enum
{
	SCENE_LOGIN,
	SCENE_CHANNEL,
	SCENE_LOBBY,
	SCENE_CREATE0,
	SCENE_CREATE1,
	SCENE_INGAME,
	SCENE_END
};

// 전방선언 
class Scene;

class SceneMgr
	: public TemplateSingleton<SceneMgr>
{
	BASESET(SceneMgr);
public:
	Scene	*m_pScene	= nullptr;
	ID2D1RenderTarget *m_pRT = nullptr;
	ID2D1SolidColorBrush *m_pBrush = nullptr;

	int		m_Type		= SCENE_END;
	bool	m_IsChange	= false;

	// 윈도우 정보용
	HWND	m_hWnd		= nullptr;

private:
	void	SetScene();

public:
	~SceneMgr();

	void Update(float _DelayTime = 0.0f);
	void Render();

	// 씬 변경 요청
	void ChangeScene(int _Type);

	// HWND 저장
	inline void SetHwnd(HWND _hWnd)
	{
		m_hWnd = _hWnd;
	}
	inline void SetRT_Brush(ID2D1RenderTarget *_pRT, ID2D1SolidColorBrush *_pBrush)
	{
		m_pRT = _pRT;
		m_pBrush = _pBrush;
	}

	void Destroy();


	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

#define SCENE_MGR	SceneMgr::GetInstance()