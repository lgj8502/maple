#include "stdafx.h"
#include "D3D.h"

D3D g_D3D;


HRESULT	InitBase(HWND _hWnd)
{
	HRESULT hr = S_OK;

	InitKeyMgr();

	g_D3D.Init3D(_hWnd);	

	return hr;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_ACTIVATEAPP:
	{
		MK_API::SetFocus(wParam);
	}
	break;

	case WM_MOVE:
		cLogMgr::GetInstance()->UpdateLogWindowPos(hWnd);
		break;

	case WM_CREATE:
	{
		SCENE_MGR->SetHwnd(hWnd);
		SOUND_MGR->SetHwnd(hWnd);

		SCENE_MGR->ChangeScene(SCENE_LOGIN);

		DATA_MGR->Init();

		cLogMgr::GetInstance()->Init(LOG_WINDOW | LOG_FILE, hWnd);
	}break;

	case WM_DESTROY:
	{		
		DATA_MGR->AllMgrDestroy();

		PostQuitMessage(0);
		return 0;
	}
	}
	return  g_D3D.MyWndProc(hWnd, iMessage, wParam, lParam);
}

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpszCmdParam,
	int		  nCmdShow)
{
	WNDCLASSA	WndClass = {};

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursorA(nullptr, IDC_ARROW);
	WndClass.hIcon = LoadIconA(nullptr, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = "MapleStory";
	WndClass.lpszMenuName = nullptr;
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	//ShowCursor(false);

	RegisterClassA(&WndClass);	

	RECT	WinRt = { 0, 0, WIN_WIDTH, WIN_HEIGHT };
	AdjustWindowRect(&WinRt, WS_OVERLAPPEDWINDOW, FALSE);

	int Width = WinRt.right - WinRt.left;
	int Height = WinRt.bottom - WinRt.top;

	HWND hWnd = CreateWindowExA(
		0,
		WndClass.lpszClassName,
		"MapleStory",
		WS_OVERLAPPEDWINDOW,
		0, 0,
		Width, Height,
		nullptr,
		(HMENU)nullptr,
		hInstance,
		nullptr);

	if (hWnd == nullptr)
	{
		MessageBoxA(nullptr, "윈도우생성 실패", "오류", MB_OK);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);

	if (FAILED(InitBase(hWnd)))
	{
		MessageBoxA(nullptr, "초기화 실패", "오류", MB_OK);
		return 0;
	}

	MSG Message;
	cTimer Time;
	while (true)
	{
		if (PeekMessageA(&Message, nullptr, 0U, 0U, PM_REMOVE))
		{
			if (Message.message == WM_QUIT) break;

			TranslateMessage(&Message);
			DispatchMessageA(&Message);
		}
		else
		{
			Time.Tick(60);
			MK_API::TickTimeUpdate();

			g_D3D.Update(Time.GetElapsedTime());
			g_D3D.Render();			
			
		}
	}

	return static_cast<int>(Message.wParam);
}