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

// ���漱�� 
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

	//	�ʱ�ȭ
	//VOID	Init(HWND _hWnd);

	inline void SetHwnd(HWND _hWnd)
	{
		m_hWnd = _hWnd;
	}
	//	����
	VOID	Release(void);

	//	���� ����
	BOOL	SoundCreate(char *_FileName, MCIDEVICEID *_RecvId);

	//	���� ����
	BOOL	SoundDelete(MCIDEVICEID _Id);

	//	���� ���
	BOOL	SoundPlay(MCIDEVICEID _Id);

	//	���� ����
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
	//	// �� ���� ��û
	//	void ChangeScene(int _Type);
	//
	//	// HWND ����
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