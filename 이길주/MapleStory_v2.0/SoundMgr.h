#pragma once

#include <Windows.h>
/////
#include <mmsystem.h>
#include <Digitalv.h>
#pragma comment (lib, "winmm.lib")

#include <map>
#include <set>
////////
#include "TemplateSingleton.h"

typedef	std::set< MCIDEVICEID >			SOUND_SET;

enum
{
	SOUND_LOGIN
};

// 전방선언 
//class Scene;


class SoundMgr
	: public TemplateSingleton<SoundMgr>
{
	BASESET(SoundMgr);
public:
	HWND			m_hWnd;
	int				m_IDIndex;
	SOUND_SET		m_SoundList;

	int		m_Type = SCENE_END;
	bool	m_IsChange = false;
	MCIDEVICEID		a[10];
	MCIDEVICEID		b[10];

public:
	//SoundMgr();
	~SoundMgr();

	//	초기화
	//VOID	Init(HWND _hWnd);

	inline void SetHwnd(HWND _hWnd)
	{
		m_hWnd = _hWnd;
	}
	//	해제
	VOID	Release(void);

	//	사운드 생성
	BOOL	SoundCreate(char *_FileName, MCIDEVICEID *_RecvId);

	//	사운드 제거
	BOOL	SoundDelete(MCIDEVICEID _Id);

	//	사운드 재생
	BOOL	SoundPlay(MCIDEVICEID _Id);

	//	사운드 정지
	BOOL	SoundStop(MCIDEVICEID _Id);
	//
	//private:
	//	void	SetSound();
	//
	//public:
	//	~SoundMgr();
	//
	//	void Update(float _DelayTime = 0.0f);
	//	void Render();
	//
	//	// 씬 변경 요청
	//	void ChangeScene(int _Type);
	//
	//	// HWND 저장
	//	inline void SetHwnd(HWND _hWnd)
	//	{
	//		m_hWnd = _hWnd;
	//	}
	//	inline void SetRT_Brush(ID2D1RenderTarget *_pRT, ID2D1SolidColorBrush *_pBrush)
	//	{
	//		m_pRT = _pRT;
	//		m_pBrush = _pBrush;
	//	}
	//
	//	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	//};
};
#define SOUND_MGR	SoundMgr::GetInstance()