#pragma once

#include <Windows.h>

class Scene
{
	POINT m_MousePos = { 0,0 };

public:
	virtual ~Scene() = default;

	virtual void Init(HWND hWnd) = 0;
	virtual	void Update(float _DelayTime = 0.0f) = 0;
	virtual void Render() = 0;

	virtual LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) = 0;
};