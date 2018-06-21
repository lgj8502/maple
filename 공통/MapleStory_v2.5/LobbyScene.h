#pragma once
class LobbyScene : public Scene
{
	POINT m_MousePos = { 0,0 };

	Text2D m_Font;

public:
	void Init(HWND hWnd);
	void Update(float _DelayTime = 0.0f);
	void Render();

	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

