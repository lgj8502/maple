#pragma once
#include "cUI.h"
#include "cCharacter.h"
#include "PlayerTest.h"

CONST LPCWSTR ImgDir = L".\\Img\\ServerScene\\";

class ServerScene : public Scene
{
	POINT m_MousePos = { 0,0 };

	cCharacter m_monster;

	PlayerTest m_player;

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
