#pragma once

#include <Windows.h>
/////
#include <mmsystem.h>
#include <Digitalv.h>
#pragma comment (lib, "winmm.lib")

#include <map>
//#include <set>
////////
#include "TemplateSingleton.h"

//typedef	std::set< MCIDEVICEID >			SOUND_SET;

enum
{
	SOUND_LOGIN
};

// 전방선언 
//class Scene;

struct SoundInfo
{
	MCIDEVICEID  a[10];
};

class SoundMgr
	: public TemplateSingleton<SoundMgr>
{
	BASESET(SoundMgr);
public:
	map<wstring, SoundInfo>	m_SoundMap;
	HWND			m_hWnd;
	int				m_IDIndex;
	//SOUND_SET		m_SoundList;

	int		m_Type = SCENE_END;
	bool	m_IsChange = false;


public:
	~SoundMgr();

	inline void SetHwnd(HWND _hWnd)
	{
		m_hWnd = _hWnd;
	}
	//	해제
	VOID	Release(void);

	BOOL IsPlaying(MCIDEVICEID _Id);

	BOOL SoundCreate(char * _FileName);

	BOOL SoundPlay(wstring _file);

	BOOL SoundStop(wstring _file);

	BOOL SoundDelete(wstring _file);

	BOOL SoundBGM(wstring _file);

	VOID SoundResume(wstring _file);

	void FileFindDir(wstring _Path);

};
#define SOUND_MGR	SoundMgr::GetInstance()