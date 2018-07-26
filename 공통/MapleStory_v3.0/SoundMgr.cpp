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

	// ���� �̸��� �����ϱ� ���� �غ�
	wstring t_FilePath = temp;

	// �ڿ������� �˻��Ͽ� \ �� ã�Ƽ� ��ġ ����
	int t_FindNum = (int)t_FilePath.find_last_of(L"\\");
	//.find_last_of("/\\");
	// �ڿ������� �˻��Ͽ� . �� ã�Ƽ� ��ġ ����
	int t_ListNum = (int)t_FilePath.find_last_of(L".");

	// ã�� ��ġ�� �������� �̹��� �̸��� ����
	wstring name = t_FilePath.substr(t_FindNum + 1, (t_ListNum - t_FindNum - 1));

	MCIERROR		Error;
	MCI_OPEN_PARMSA	Data;


	Data.dwCallback = (DWORD_PTR)m_hWnd;
	Data.lpstrDeviceType = "MPEGVideo";	//	���� ����
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
	//MCI_NOTIFY �Ϲ�
	//MCI_DGV_PLAY_REPEAT �ݺ�
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
	//MCI_NOTIFY �Ϲ�
	//MCI_DGV_PLAY_REPEAT �ݺ�
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
	// ���� ��θ� ���� ù��° ���� ������ �޾ƿ�
	t_hSrch = FindFirstFileW((_Path + L"*.*").c_str(), &t_wfd);

	// ù��° ���� ���� �޾ƿ��� ������ ���� ó�� (���� ��ΰ� �߸��� ��� ��)
	if (t_hSrch == INVALID_HANDLE_VALUE)
	{
		MK_LOG("FileFindDir ����");
		return VOID();
	}
	while (t_bResult)
	{

		// ������ "dwFileAttributes" �Ӽ��� 16 (����)�̰� ù��° ���ڰ� '.' �� �ƴ϶�� ������ ó��
		// ù��° ���ڰ� '.' �� ��� ���� ��� ���� �ǹ��ϴ� ������ ����
		if (t_wfd.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY && t_wfd.cFileName[0] != '.')
		{
			// ���� ������ ������� �ٽ� Ȯ�� �Լ� ȣ��(���)
			FileFindDir((_Path + t_wfd.cFileName + L"\\").c_str());
		}
		// ������ "dwFileAttributes" �Ӽ��� 32(����) �̶�� ���� ���� ó��
		else if (t_wfd.dwFileAttributes != FILE_ATTRIBUTE_COMPRESSED && t_wfd.cFileName[0] != '.')
		{
			// wstring �� find �Լ��� ����ϱ� ���� ���ϸ��� wstring ������ ����
			wstring t_FileTypeChk = t_wfd.cFileName;
			// ".mp3" Ȯ���ڰ� �ִ� ��쿡�� AddImg �Լ��� ȣ����
			if (t_FileTypeChk.find(L".mp3"))
			{
				//�̹��� ���Ͽ� ���� bitmap ���� �� ����Ʈ ������ ���� AddImg�Լ��� ��� ����(��� ����) ���� �Է�
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

		// Ȯ�� �۾��� �����ٸ� ���� ���Ϸ� ��� ���� (���� ������ ���ٸ� false �� �ݸ��� �ߴܵ�
		t_bResult = FindNextFileW(t_hSrch, &t_wfd);
	}
	// �۾� ���ῡ ���� close ó��
	FindClose(t_hSrch);

	return VOID();
}