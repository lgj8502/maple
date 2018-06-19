#pragma once

#include "TEST.h"
#include "cUI.h"
#include "cPlayer.h"

class ServerScene : public Scene
{
	POINT m_MousePos = { 0,0 };

	//Text2D m_Font;

	TEST m_test;

	cPlayer m_player;

	bool m_isClicked = false;

public:

	~ServerScene();

	void Init(HWND hWnd);
	void Update(float _DelayTime = 0.0f);
	void Render();

	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};
