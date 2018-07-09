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

	//  IME ¿ë
	bool m_isTyping = false;
	string m_szBuf;
	char m_szMixingString[3] = "";
	size_t m_maxText = 70;

public:

	~ServerScene();

	void Init(HWND hWnd);
	void Update(float _DelayTime = 0.0f);
	void Render();

	void SendText();

	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};
