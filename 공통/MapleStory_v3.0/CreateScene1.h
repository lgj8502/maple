#pragma once
#include "PlayerTest.h"
#include "cUI.h"


class CreateScene1 : public Scene
{

	POINT m_MousePos = { 0,0 };

	bool m_isClicked = false;

	//  IME ¿ë
	bool m_isTyping = false;
	string m_szBuf;
	char m_szMixingString[3] = "";
	size_t m_maxText = 70;
	string m_oldText = "";

	Object2D obj;

	PlayerTest m_player;
	
public:
	//map<string, size_t>	m_firstMap;
	~CreateScene1();

	void Init(HWND hWnd);
	void Update(float _DelayTime = 0.0f);
	void Render();

	void SendText();

	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};
