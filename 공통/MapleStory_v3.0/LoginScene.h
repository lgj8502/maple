#pragma once

#include "cUI.h"



class LoginScene : public Scene
{

	POINT m_MousePos = { 0,0 };

	bool m_isClicked = false;

	//  IME ¿ë
	bool m_isTyping = false;
	string m_szBuf;
	char m_szMixingString[3] = "";
	size_t m_maxText = 70;
	Object2D obj;
	string m_oldText = "";

public:

	~LoginScene();

	void Init(HWND hWnd);
	void Update(float _DelayTime = 0.0f);
	void Render();

	void SendText();

	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};
