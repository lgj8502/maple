#pragma once

#include "cMap.h"



class IngameScene: public Scene
{
	POINT m_MousePos = { 0,0 };

	bool m_isClicked = false;

	//  IME ¿ë
	bool m_isTyping = false;
	string m_szBuf;
	char m_szMixingString[3] = "";
	size_t m_maxText = 70;
	string m_oldText = "";

public:

	~IngameScene();

	void Init(HWND hWnd);
	void Update(float _DelayTime = 0.0f);
	void Render();	

	void SendText();

	D2D1_POINT_2F Lerp(D2D1_POINT_2F _start, D2D1_POINT_2F _end, float _rate);

	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

