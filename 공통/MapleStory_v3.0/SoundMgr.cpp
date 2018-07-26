#include "stdafx.h"



SoundMgr::~SoundMgr()
{
	Release();
}


VOID SoundMgr::Release(void)
{
	while (m_SoundMap.empty() == false)
	{
		//MCIDEVICEID Id = *m_SoundMap.begin()->second.a;
		//SoundStop(Id);
		SoundDelete(m_SoundMap.begin()->first);
	}
}

BOOL	SoundMgr::IsPlaying(MCIDEVICEID _Id)
{
	MCI_STATUS_PARMS	Parms;
	Parms.dwItem = MCI_STATUS_MODE;

	mciSendCommandA(
		_Id,
		MCI_STATUS,
		MCI_STATUS_ITEM,
		(DWORD_PTR)&Parms);

	if (Parms.dwReturn == MCI_MODE_PLAY)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL SoundMgr::SoundCreate(char * _FileName)
{
	SoundInfo soundInfo;

	string ss = _FileName;
	wstring temp(ss.length(), L' ');
	copy(ss.begin(), ss.end(), temp.begin());

	// 파일 이름을 저장하기 위한 준비
	wstring t_FilePath = temp;

	// 뒤에서부터 검색하여 \ 를 찾아서 위치 저장
	int t_FindNum = (int)t_FilePath.find_last_of(L"\\");
	//.find_last_of("/\\");
	// 뒤에서부터 검색하여 . 을 찾아서 위치 저장
	int t_ListNum = (int)t_FilePath.find_last_of(L".");

	// 찾은 위치를 기준으로 이미지 이름을 저장
	wstring name = t_FilePath.substr(t_FindNum + 1, (t_ListNum - t_FindNum - 1));

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

	//wstring aa = _FileName;
	soundInfo.a[0] = Data.wDeviceID;
	//m_SoundMap.insert(Data.wDeviceID);
	m_SoundMap.insert(pair<wstring, SoundInfo>(name, soundInfo));
	//*_RecvId = Data.wDeviceID;
	//m_IDIndex = 0;
	return TRUE;
}



BOOL SoundMgr::SoundPlay(wstring _file)
{
	MCIERROR		Error;
	MCI_PLAY_PARMS	Play;

	Play.dwCallback = (DWORD_PTR)m_hWnd;
	Error = mciSendCommandA(m_SoundMap.find(_file)->second.a[0], MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&Play);
	//MCI_NOTIFY 일반
	//MCI_DGV_PLAY_REPEAT 반복
	return Error ? FALSE : TRUE;
}

BOOL SoundMgr::SoundStop(wstring _file)
{
	MCIERROR		Error;
	Error = mciSendCommandA(m_SoundMap.find(_file)->second.a[0], MCI_STOP, 0, 0);

	if (Error)
	{
		return FALSE;
	}

	Error = mciSendCommandA(m_SoundMap.find(_file)->second.a[0], MCI_SEEK, MCI_SEEK_TO_START, 0);

	return Error ? FALSE : TRUE;
}

BOOL SoundMgr::SoundDelete(wstring _file)
{
	MCIERROR	Error = mciSendCommandA(m_SoundMap.find(_file)->second.a[0], MCI_CLOSE, 0, 0);

	if (Error)
	{
		return FALSE;
	}
	m_SoundMap.erase(m_SoundMap.find(_file));
	//m_SoundList.erase(m_SoundMap.find(_file)->second.a[0]);

	return TRUE;
}

BOOL SoundMgr::SoundBGM(wstring _file)
{
	MCIERROR		Error;
	MCI_PLAY_PARMS	Play;

	Play.dwCallback = (DWORD_PTR)m_hWnd;
	Error = mciSendCommandA(m_SoundMap.find(_file)->second.a[0], MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&Play);
	//MCI_NOTIFY 일반
	//MCI_DGV_PLAY_REPEAT 반복
	return Error ? FALSE : TRUE;
}

VOID SoundMgr::SoundResume(wstring _file)
{
	SoundStop(_file);
	SoundPlay(_file);

	
}


void SoundMgr::FileFindDir(wstring _Path)
{
	HANDLE t_hSrch;
	WIN32_FIND_DATAW t_wfd;
	BOOL t_bResult = TRUE;
	// 파일 경로를 에서 첫번째 파일 정보를 받아옴
	t_hSrch = FindFirstFileW((_Path + L"*.*").c_str(), &t_wfd);

	// 첫번째 파일 정보 받아오기 오류시 종료 처리 (폴더 경로가 잘못된 경우 등)
	if (t_hSrch == INVALID_HANDLE_VALUE)
	{
		MK_LOG("FileFindDir 실패");
		return VOID();
	}
	while (t_bResult)
	{

		// 파일의 "dwFileAttributes" 속성이 16 (폴더)이고 첫번째 문자가 '.' 이 아니라면 폴더로 처리
		// 첫번째 문자가 '.' 인 경우 상위 경로 등을 의미하는 폴더로 무시
		if (t_wfd.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY && t_wfd.cFileName[0] != '.')
		{
			// 하위 폴더를 대상으로 다시 확인 함수 호출(재귀)
			FileFindDir((_Path + t_wfd.cFileName + L"\\").c_str());
		}
		// 파일의 "dwFileAttributes" 속성이 32(파일) 이라면 파일 관련 처리
		else if (t_wfd.dwFileAttributes != FILE_ATTRIBUTE_COMPRESSED && t_wfd.cFileName[0] != '.')
		{
			// wstring 의 find 함수를 사용하기 위해 파일명을 wstring 변수에 대입
			wstring t_FileTypeChk = t_wfd.cFileName;
			// ".mp3" 확장자가 있는 경우에만 AddImg 함수를 호출함
			if (t_FileTypeChk.find(L".mp3"))
			{
				//이미지 파일에 대한 bitmap 생성 및 리스트 관리를 위한 AddImg함수에 대상 파일(경로 포함) 정보 입력
				//wstring -> char
				size_t outputSize = (_Path + t_wfd.cFileName).length() + 1;
				char * outputString = new char[outputSize];
				size_t charsConverted = 0;
				wcstombs_s(&charsConverted, outputString, outputSize, (_Path + t_wfd.cFileName).c_str(), (_Path + t_wfd.cFileName).length());
				MK_LOG(outputString);

				SoundCreate(outputString);

				delete[] outputString;
			}

		}

		// 확인 작업이 끝났다면 다음 파일로 대상 변경 (다음 파일이 없다면 false 로 반목이 중단됨
		t_bResult = FindNextFileW(t_hSrch, &t_wfd);
	}
	// 작업 종료에 따른 close 처리
	FindClose(t_hSrch);

	return VOID();
}