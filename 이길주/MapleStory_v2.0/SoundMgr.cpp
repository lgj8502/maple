#include "stdafx.h"

//SoundMgr::SoundMgr()
//{
//	m_hWnd = nullptr;
//	m_IDIndex = 0;
//}

SoundMgr::~SoundMgr()
{
	Release();
}

//VOID SoundMgr::Init(HWND _hWnd)
//{
//	m_hWnd = _hWnd;
//	m_IDIndex = 0;
//}

VOID SoundMgr::Release(void)
{
	while (m_SoundList.empty() == false)
	{
		MCIDEVICEID Id = *m_SoundList.begin();
		//SoundStop(Id);
		SoundDelete(Id);
	}
}

BOOL SoundMgr::SoundCreate(char * _FileName, MCIDEVICEID * _RecvId)
{
	MCIERROR		Error;
	MCI_OPEN_PARMSA	Data;

	Data.dwCallback = (DWORD_PTR)m_hWnd;
	Data.lpstrDeviceType = "MPEGVideo";	//	파일 형식
	Data.lpstrElementName = _FileName;

	char	Buf[256];
	sprintf_s(Buf, 256, "%d", ++m_IDIndex);
	Data.lpstrAlias = Buf;

	Error = mciSendCommandA(
		0,
		MCI_OPEN,
		MCI_OPEN_TYPE | MCI_OPEN_ELEMENT | MCI_OPEN_ALIAS,
		(DWORD_PTR)&Data);

	if (Error)
	{
		return FALSE;
	}

	m_SoundList.insert(Data.wDeviceID);

	*_RecvId = Data.wDeviceID;

	return TRUE;
}

BOOL SoundMgr::SoundDelete(MCIDEVICEID _Id)
{
	MCIERROR	Error = mciSendCommandA(_Id, MCI_CLOSE, 0, 0);

	if (Error)
	{
		return FALSE;
	}

	m_SoundList.erase(_Id);

	return TRUE;
}

BOOL SoundMgr::SoundPlay(MCIDEVICEID _Id)
{
	MCIERROR		Error;
	MCI_PLAY_PARMS	Play;

	Play.dwCallback = (DWORD_PTR)m_hWnd;
	Error = mciSendCommandA(_Id, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&Play);

	return Error ? FALSE : TRUE;
}

BOOL SoundMgr::SoundStop(MCIDEVICEID _Id)
{
	MCIERROR		Error;
	Error = mciSendCommandA(_Id, MCI_STOP, 0, 0);

	if (Error)
	{
		return FALSE;
	}

	Error = mciSendCommandA(_Id, MCI_SEEK, MCI_SEEK_TO_START, 0);

	return Error ? FALSE : TRUE;
}
