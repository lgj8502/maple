#include "stdafx.h"
#include "cLogMgr.h"

#include <iostream>
#include <ctime>



//	���� ��Ʈ�� ��뿡 �ʿ��� ��� < ����Ʈ �� >
#include <CommCtrl.h>
#pragma comment( lib, "Comctl32.lib" )


//	Dbghelp ������� �ش� ��� �߻� ( ����ü ������ typedef �� ���� �̸��� �������� ���� )
#pragma warning ( disable:4091 )

#include <Dbghelp.h>	//	���� ������ ���ؼ� �ʿ��� ���
#pragma comment( lib, "Dbghelp.lib" )	// �ش� ���̺귯���� �ʿ��ϴ�.

#pragma warning ( default:4091 )


//	�α� ������� �޽��� ���ν���
LRESULT	CALLBACK	LogWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
//	��ο���  �̸� ���
std::string		GetFileName(LPCSTR szPath);

cLogMgr::cLogMgr(void)
{
	m_hLogWnd			=	NULL;
	m_dwLogType			=	LOG_NONE;

	m_pLogFile			=	NULL;
	m_pConsoleBuffer	=	NULL;

	m_szBuf[0]			=	NULL;
	m_szDate[0]			=	NULL;
	m_szTime[0]			=	NULL;
}

cLogMgr::~cLogMgr(void)
{
	ReleaseSet();
}

//	�ʱ�ȭ
VOID	cLogMgr::Init( DWORD dwLogType, HWND hPrentWnd )
{
	m_dwLogType	=	dwLogType;

	//	�α� �������� ���
	if( m_dwLogType & LOG_WINDOW )
	{
		WindowInit( hPrentWnd );
	}

	//	�α� ������� ������� �ܼ��� �ϳ��� ����
	else if( m_dwLogType & LOG_CONSOLE )
	{
		ConsoleInit( hPrentWnd );	
	}

	//	���� ���� �ɼ��� ���� ���
	if( m_dwLogType & LOG_FILE )
	{
		FileInit();
	}	
}

//	����
VOID	cLogMgr::ReleaseSet(VOID)
{
	if( m_dwLogType & LOG_WINDOW )
	{
		if( m_hLogWnd != NULL )
		{
			DestroyWindow( m_hLogWnd );
		}
	}

	else if( m_dwLogType & LOG_CONSOLE )
	{
		if( m_pConsoleBuffer != NULL )
		{
			fclose( m_pConsoleBuffer );
		}

		// �ܼ� â ����
		FreeConsole();
	}

	//	���� ���� �ɼ��� ���� ���
	if( m_dwLogType & LOG_FILE )
	{
		//	���� ����
		m_pLogFile	=	_fsopen( m_szSaveFile, "a", SH_DENYNO );

		if( m_pLogFile != NULL )
		{
			//	��¥�� �ð��� ���ڿ��� ��´�.
			_strdate_s( m_szDate, 256 );
			_strtime_s( m_szTime, 256 );
			fprintf_s( m_pLogFile, "�α� ��¥ : %s �α� �ð� : %s\n", m_szDate, m_szTime );
			fprintf_s( m_pLogFile, "�α� ���� : �α� �Ŵ��� ����\n\n" );

			fclose(m_pLogFile);
		}
	}
}

VOID	cLogMgr::WindowInit( HWND hParentWnd )
{
	//	������ �ν��Ͻ�
	HINSTANCE	hInst	=	NULL;

	//������ Ŭ���� ����
	WNDCLASSA	WndClass;		

	// 1 ������ Ŭ���� �ۼ� (�������� �Ӽ��� ���� �Ѵ�)
	WndClass.cbClsExtra		= 0;									//������� ���������� ����� ���и޸�	
	WndClass.cbWndExtra		= 0;									//������� ���������� ����� ���и޸�
	WndClass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);	//������ ����
	WndClass.hCursor		= LoadCursor(NULL,IDC_ARROW);			//Ŀ���� �����Ѵ�(���ҽ��� ���ؼ� ���ϴ� �׷��ȸ� ��� �Ҽ��� �ִ�)
	WndClass.hIcon			= LoadIcon(NULL,IDI_APPLICATION);		//�������� �д´�(���ҽ��� ���ؼ� ���ϴ� �׷��ȸ� ��� �Ҽ��� �ִ�)
	WndClass.lpfnWndProc	= (WNDPROC)LogWndProc;					//������ ���ν����� �̸�(�������� �޽��� ó�� �Լ��� ����)
	WndClass.lpszClassName	= "LogWindow";							//������ Ŭ������ �̸�(�������� Ŭ���� �̸��� ���̴�)
	WndClass.lpszMenuName	= NULL;									//�޴��� �̸�(���ҽ� ������ ���� ������ �������, ����� ���ϸ� NULL)
	WndClass.hInstance		= GetModuleHandle( NULL );	
	WndClass.style			= CS_HREDRAW | CS_VREDRAW;				//�������� ��Ÿ��(�������� ũ�Ⱑ ���Ҷ� �ٽ� �׸���.)

	if( hParentWnd == NULL )
	{
		hInst		= GetModuleHandle( NULL );
	}

	else
	{
		hInst	=	(HINSTANCE)GetWindowLong( hParentWnd, GWL_HINSTANCE );
	}

	// 2 Ŭ������ ����Ѵ� (������ ������ Ŭ������ ����Ѵ�)
	RegisterClass(&WndClass);

	// 3 �����츦 ����� (�޸� �� �����츦 �����Ѵ�)
	m_hLogWnd  =		CreateWindowA(
		"LogWindow",													// ������Ŭ���� ���ڿ� 
		"LogWindow",													// Ÿ��Ʋ�ٿ� ��Ÿ�� ���ڿ�
		WS_POPUP | WS_CAPTION | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_THICKFRAME,		// �������� ���� �ɼ�(OR ������ ���)Ÿ��Ʋ��, ��ũ�ѹ�, ũ���������� ���
		0, 0,															// ������ ������ġ
		0, 0,															// ������ ũ��
		hParentWnd,														// �θ��������� �ڵ� (�θ� �����찡 ���� �ڽ��� �ֻ��� ������ �϶� NULL)
		(HMENU)NULL,													// �޴��� �ڵ� (�޴��� ��� ���ϹǷ� NULL)			
		hInst,															// �ν��Ͻ�
		NULL);															// createStruct��� ����ü�� �ּ� (�������� �����츦 ���鶧 ��� �ǳ� ���� ������� �ʴ´�.)

	//////////////////////////////////////////////////////////////////////////
	//	���̾�α�

	InitCommonControls();

	m_hListView	=	CreateWindowA( 
		WC_LISTVIEWA, 
		NULL, 
		WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_NOSORTHEADER, 
		0, 0, LOG_WINDOW_WIDTH - 15, LOG_WINDOW_WIDTH, 
		m_hLogWnd, NULL, hInst, NULL );

	//	�� ��ü ���� ����
	//	�巹�׷� ��� �ٲٱ�
	ListView_SetExtendedListViewStyle( m_hListView, 
		LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP );

	AddCollmn( "No",		0, 40 );
	AddCollmn( "��¥",		1, 70 );
	AddCollmn( "�ð�",		2, 60 );
	AddCollmn( "���ϸ�",	3, 100 );
	AddCollmn( "����",		4, 40 );
	AddCollmn( "����",		5, LOG_WINDOW_WIDTH - 350 );

	InvalidateRect( m_hListView, NULL, TRUE );

	//////////////////////////////////////////////////////////////////////////

	UpdateLogWindowPos( hParentWnd );

	ShowWindow( m_hLogWnd, SW_SHOW );
}

VOID	cLogMgr::ConsoleInit( HWND hParentWnd )
{
	//	�ܼ�â ����
	AllocConsole();

	HWND	hConsole	=	GetConsoleWindow();
	RECT	rcWin		=	{};

	if( hParentWnd != NULL )
	{
		GetWindowRect( hParentWnd, &rcWin );

		//	�����쿡 ĸ�ǹٰ� ���� ��� �׸�ŭ Y ũ�⸦ ����
		LONG Style	=	GetWindowLong( hParentWnd, GWL_STYLE );

		if( Style & WS_CAPTION )
		{
			rcWin.bottom += GetSystemMetrics( SM_CYCAPTION );
		}
	}

	else
	{
		GetWindowRect( hConsole, &rcWin );
	}

	//	�ܼ�â ��ġ ����
	MoveWindow( hConsole, 
		rcWin.right, 
		rcWin.top, 
		CONSOLE_WIDTH, 
		rcWin.bottom - rcWin.top, 
		TRUE );

	//	��� ���� ����
	freopen_s( &m_pConsoleBuffer, "CONOUT$", "wb", stdout );

	//	���� �ܼ�â�� cout ��ü�� �����Ѵ�.
	std::ios::sync_with_stdio();
}

VOID	cLogMgr::FileInit(VOID)
{
	GetCurrentDirectoryA(_MAX_FNAME, m_szSaveFile );

	//	��ο� Log ��� ����
	strcat_s( m_szSaveFile, _MAX_FNAME, "\\Log\\" );

	//	���� �����ϱ�
	MakeSureDirectoryPathExists(m_szSaveFile);

	//	�ð� ���ϱ�
	SYSTEMTIME	stime;
	GetLocalTime( &stime );

	//	������ ���ϸ� �����		
	sprintf_s( m_szSaveFile, 256, "Log/LogFile[%d_%d_%d][%dh_%dm_%ds].txt", stime.wYear, stime.wMonth, stime.wDay, stime.wHour, stime.wMinute, stime.wSecond );

	//	���� ����
	m_pLogFile	=	_fsopen( m_szSaveFile, "a", SH_DENYNO );

	//	��¥�� �ð��� ���ڿ��� ��´�.
	_strdate_s( m_szDate, 256 );
	_strtime_s( m_szTime, 256 );
	fprintf_s( m_pLogFile, "�α� ��¥ : %s �α� �ð� : %s\n", m_szDate, m_szTime );
	fprintf_s( m_pLogFile, "�α� ���� : �α� �Ŵ��� ����\n\n" );

	fclose(m_pLogFile);
}

//	�α� ������ �÷� �߰�
VOID	cLogMgr::AddCollmn( LPSTR pszText, int nSubNum, int nWidth )
{
	LVCOLUMN	COL;

	COL.mask	=	LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt		=	LVCFMT_CENTER;

	COL.pszText		=	pszText;
	COL.iSubItem	=	nSubNum;
	COL.cx			=	nWidth;

	SendMessage( m_hListView, LVM_INSERTCOLUMN, nSubNum, (LPARAM)&COL );
}

//	�α� ������ ���� �߰�
VOID	cLogMgr::AddLog( LPSTR szDate, LPSTR szTime, LPSTR szFileName, int nLine, LPSTR szText )
{
	LVITEM		LI;
	CHAR		szChangeNum[11];

	LI.iItem	=	SendMessage( m_hListView, LVM_GETITEMCOUNT, 0, 0 );

	//	���ڸ� ���ڷ� �ٲٱ�
	_itoa_s( LI.iItem+1, szChangeNum, 11, 10 );

	//	�α� ��ȣ �ֱ�
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	0;
	LI.pszText		=	szChangeNum;
	SendMessage( m_hListView, LVM_INSERTITEM, 0, (LPARAM)&LI );

	//	��¥ �ֱ�
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	1;
	LI.pszText		=	szDate;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	�ð� �ֱ�
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	2;
	LI.pszText		=	szTime;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	���ϸ� �ֱ�
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	3;
	LI.pszText		=	szFileName;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	���ι�ȣ �ֱ�
	_itoa_s( nLine, szChangeNum, 11, 10 );

	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	4;
	LI.pszText		=	szChangeNum;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	���� �ֱ�
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	5;
	LI.pszText		=	szText;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	if( LI.iItem > LOG_WINDOW_VIEWCOUNT )
	{
		SendMessage( m_hListView, LVM_SCROLL, 0, (LPARAM)(LI.iItem - LOG_WINDOW_VIEWCOUNT) );
	}
}

//	�α� ������ ��ġ ����
VOID	cLogMgr::UpdateLogWindowPos( HWND hParentWnd )
{
	if( hParentWnd != NULL )
	{
		RECT	rcWin;
		GetWindowRect( hParentWnd, &rcWin );

		MoveWindow( m_hLogWnd, 
			rcWin.right, 
			rcWin.top,
			LOG_WINDOW_WIDTH,
			rcWin.bottom - rcWin.top - GetSystemMetrics( SM_CYFRAME )/2, 
			TRUE );
	}
}

//////////////////////////////////////////////////////////////////////////
//	��輱 �����
VOID	cLogMgr::AddLineBar( VOID )
{
	CHAR	szBuf[72]	=	"\n============================== ��輱 ==============================\n\n";

	if( m_dwLogType & LOG_DEBUG )
	{
		OutputDebugString(szBuf);
	}

	if( m_dwLogType & LOG_WINDOW )
	{
		AddLog( NULL, NULL, NULL, 0, szBuf );
	}

	else if( m_dwLogType & LOG_CONSOLE )
	{
		std::cout << szBuf;
	}

	if( m_dwLogType & LOG_FILE )
	{
		//	���� ����
		m_pLogFile	=	_fsopen( m_szSaveFile, "a", SH_DENYNO );

		if( m_pLogFile != NULL )
		{
			fprintf_s( m_pLogFile, szBuf );

			fclose(m_pLogFile);
			m_pLogFile	=	NULL;
		}
	}
}

//	�α� ���
VOID	cLogMgr::LogTexOut( LPCSTR szFilePath, INT nLineNum, BOOL bMsgBox, LPCSTR szFormat, ... )
{
	//	��¥�� �ð��� ���ڿ��� ��´�.
	_strdate_s( m_szDate, 256 );
	_strtime_s( m_szTime, 256 );

	//	�α� ���ڿ��� �ϼ��Ѵ�.
	va_list args;
	va_start( args, szFormat );
	vsprintf_s( m_szBuf, 256, szFormat, args );
	va_end( args );

	//	��ο��� ���ϸ� �߶󳽴�.
	m_szFileName = GetFileName( szFilePath );

	CHAR	szBuf[3][256]	=	{};

	sprintf_s( szBuf[0], "�α� ��¥ : %s �α� �ð� : %s\n", m_szDate, m_szTime );
	sprintf_s( szBuf[1], "�α� ��ġ : %s, ����  %d ��\n", m_szFileName.c_str(), nLineNum );
	sprintf_s( szBuf[2], "�α� ���� : %s\n\n", m_szBuf );

	

	if( m_dwLogType & LOG_DEBUG )
	{
		for( int i = 0; i < 3; ++i )
		{
			OutputDebugString(szBuf[i]);
		}
	}

	if( m_dwLogType & LOG_WINDOW )
	{
		AddLog( m_szDate, m_szTime, &m_szFileName[0], nLineNum, m_szBuf );
	}

	else if( m_dwLogType & LOG_CONSOLE )
	{
		for( int i = 0; i < 3; ++i )
		{
			std::cout << szBuf[i];
		}
	}

	if( m_dwLogType & LOG_FILE )
	{
		//	���� ����
		m_pLogFile	=	_fsopen( m_szSaveFile, "a", SH_DENYNO );

		if( m_pLogFile != NULL )
		{
			for( int i = 0; i < 3; ++i )
			{
				fprintf_s( m_pLogFile, szBuf[i] );
			}

			fclose( m_pLogFile );
			m_pLogFile	=	NULL;
		}
	}

	if( bMsgBox == TRUE )
	{
		MessageBox( NULL, m_szBuf, "�޽��� ����", MB_OK );
	}
}

//	��ο���  �̸� ���
std::string		GetFileName(LPCSTR szPath)
{
	std::string		FileName = szPath;

	//	�� ���� ��ġ
	INT nPointPos = FileName.find_last_of('.');

	//	��θ� �������÷� �Ѱ��
	INT nLastPathPos = FileName.find_last_of('\\');

	//	��θ� / �� �Ѱ��
	if (nLastPathPos == -1)
	{
		nLastPathPos = FileName.find_last_of('/');
	}

	INT nLen = nPointPos - (nLastPathPos + 1);

	//	Ȯ���� �ڸ���
	FileName = FileName.substr(nLastPathPos + 1, nLen);

	return FileName;
}

LRESULT	CALLBACK	LogWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}