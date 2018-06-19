#include "stdafx.h"
#include "cLogMgr.h"

#include <iostream>
#include <ctime>



//	공통 컨트롤 사용에 필요한 헤더 < 리스트 뷰 >
#include <CommCtrl.h>
#pragma comment( lib, "Comctl32.lib" )


//	Dbghelp 헤더에서 해당 경고 발생 ( 열거체 지정시 typedef 를 쓰고 이름을 지정하지 않음 )
#pragma warning ( disable:4091 )

#include <Dbghelp.h>	//	폴더 생성을 위해서 필요한 헤더
#pragma comment( lib, "Dbghelp.lib" )	// 해당 라이브러리가 필요하다.

#pragma warning ( default:4091 )


//	로그 윈도우용 메시지 프로시저
LRESULT	CALLBACK	LogWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
//	경로에서  이름 얻기
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

//	초기화
VOID	cLogMgr::Init( DWORD dwLogType, HWND hPrentWnd )
{
	m_dwLogType	=	dwLogType;

	//	로그 윈도우일 경우
	if( m_dwLogType & LOG_WINDOW )
	{
		WindowInit( hPrentWnd );
	}

	//	로그 윈도우는 윈도우와 콘솔중 하나만 가능
	else if( m_dwLogType & LOG_CONSOLE )
	{
		ConsoleInit( hPrentWnd );	
	}

	//	파일 저장 옵션이 있을 경우
	if( m_dwLogType & LOG_FILE )
	{
		FileInit();
	}	
}

//	해제
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

		// 콘솔 창 제거
		FreeConsole();
	}

	//	파일 저장 옵션이 있을 경우
	if( m_dwLogType & LOG_FILE )
	{
		//	버퍼 열기
		m_pLogFile	=	_fsopen( m_szSaveFile, "a", SH_DENYNO );

		if( m_pLogFile != NULL )
		{
			//	날짜와 시간을 문자열로 얻는다.
			_strdate_s( m_szDate, 256 );
			_strtime_s( m_szTime, 256 );
			fprintf_s( m_pLogFile, "로그 날짜 : %s 로그 시간 : %s\n", m_szDate, m_szTime );
			fprintf_s( m_pLogFile, "로그 내용 : 로그 매니저 종료\n\n" );

			fclose(m_pLogFile);
		}
	}
}

VOID	cLogMgr::WindowInit( HWND hParentWnd )
{
	//	윈도우 인스턴스
	HINSTANCE	hInst	=	NULL;

	//윈도우 클래스 선언
	WNDCLASSA	WndClass;		

	// 1 윈도우 클래스 작성 (윈도우의 속성을 정의 한다)
	WndClass.cbClsExtra		= 0;									//윈도우즈가 내부적으로 사용할 여분메모리	
	WndClass.cbWndExtra		= 0;									//윈도우즈가 내부적으로 사용할 여분메모리
	WndClass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);	//배경색상 지정
	WndClass.hCursor		= LoadCursor(NULL,IDC_ARROW);			//커서를 설정한다(리소스를 통해서 원하는 그래픽를 등록 할수도 있다)
	WndClass.hIcon			= LoadIcon(NULL,IDI_APPLICATION);		//아이콘을 읽는다(리소스를 통해서 원하는 그래픽를 등록 할수도 있다)
	WndClass.lpfnWndProc	= (WNDPROC)LogWndProc;					//윈도우 프로시저의 이름(윈도우의 메시지 처리 함수를 지정)
	WndClass.lpszClassName	= "LogWindow";							//윈도우 클래스의 이름(어디까지나 클래스 이름일 뿐이다)
	WndClass.lpszMenuName	= NULL;									//메뉴의 이름(리소스 에디터 의해 별도로 만들어짐, 사용을 안하면 NULL)
	WndClass.hInstance		= GetModuleHandle( NULL );	
	WndClass.style			= CS_HREDRAW | CS_VREDRAW;				//윈도우의 스타일(윈도우의 크기가 변할때 다시 그린다.)

	if( hParentWnd == NULL )
	{
		hInst		= GetModuleHandle( NULL );
	}

	else
	{
		hInst	=	(HINSTANCE)GetWindowLong( hParentWnd, GWL_HINSTANCE );
	}

	// 2 클래스를 등록한다 (정의한 윈도우 클래스를 등록한다)
	RegisterClass(&WndClass);

	// 3 윈도우를 만든다 (메모리 상에 윈도우를 생성한다)
	m_hLogWnd  =		CreateWindowA(
		"LogWindow",													// 윈도우클래스 문자열 
		"LogWindow",													// 타이틀바에 나타날 문자열
		WS_POPUP | WS_CAPTION | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_THICKFRAME,		// 윈도우의 형태 옵션(OR 연산자 사용)타이틀바, 스크롤바, 크기조절가능 등등
		0, 0,															// 윈도우 시작위치
		0, 0,															// 윈도우 크기
		hParentWnd,														// 부모윈도우의 핸들 (부모 윈도우가 없고 자신이 최상위 윈도우 일때 NULL)
		(HMENU)NULL,													// 메뉴의 핸들 (메뉴를 사용 안하므로 NULL)			
		hInst,															// 인스턴스
		NULL);															// createStruct라는 구조체의 주소 (여러개의 윈도우를 만들때 사용 되나 거의 사용하지 않는다.)

	//////////////////////////////////////////////////////////////////////////
	//	다이얼로그

	InitCommonControls();

	m_hListView	=	CreateWindowA( 
		WC_LISTVIEWA, 
		NULL, 
		WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_NOSORTHEADER, 
		0, 0, LOG_WINDOW_WIDTH - 15, LOG_WINDOW_WIDTH, 
		m_hLogWnd, NULL, hInst, NULL );

	//	행 전체 선택 가능
	//	드레그로 헤더 바꾸기
	ListView_SetExtendedListViewStyle( m_hListView, 
		LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP );

	AddCollmn( "No",		0, 40 );
	AddCollmn( "날짜",		1, 70 );
	AddCollmn( "시간",		2, 60 );
	AddCollmn( "파일명",	3, 100 );
	AddCollmn( "라인",		4, 40 );
	AddCollmn( "내용",		5, LOG_WINDOW_WIDTH - 350 );

	InvalidateRect( m_hListView, NULL, TRUE );

	//////////////////////////////////////////////////////////////////////////

	UpdateLogWindowPos( hParentWnd );

	ShowWindow( m_hLogWnd, SW_SHOW );
}

VOID	cLogMgr::ConsoleInit( HWND hParentWnd )
{
	//	콘솔창 생성
	AllocConsole();

	HWND	hConsole	=	GetConsoleWindow();
	RECT	rcWin		=	{};

	if( hParentWnd != NULL )
	{
		GetWindowRect( hParentWnd, &rcWin );

		//	윈도우에 캡션바가 있을 경우 그만큼 Y 크기를 더함
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

	//	콘솔창 위치 조정
	MoveWindow( hConsole, 
		rcWin.right, 
		rcWin.top, 
		CONSOLE_WIDTH, 
		rcWin.bottom - rcWin.top, 
		TRUE );

	//	출력 버퍼 생성
	freopen_s( &m_pConsoleBuffer, "CONOUT$", "wb", stdout );

	//	생성 콘솔창에 cout 객체를 연동한다.
	std::ios::sync_with_stdio();
}

VOID	cLogMgr::FileInit(VOID)
{
	GetCurrentDirectoryA(_MAX_FNAME, m_szSaveFile );

	//	경로에 Log 경로 설정
	strcat_s( m_szSaveFile, _MAX_FNAME, "\\Log\\" );

	//	폴더 생성하기
	MakeSureDirectoryPathExists(m_szSaveFile);

	//	시간 구하기
	SYSTEMTIME	stime;
	GetLocalTime( &stime );

	//	저장할 파일명 만들기		
	sprintf_s( m_szSaveFile, 256, "Log/LogFile[%d_%d_%d][%dh_%dm_%ds].txt", stime.wYear, stime.wMonth, stime.wDay, stime.wHour, stime.wMinute, stime.wSecond );

	//	버퍼 열기
	m_pLogFile	=	_fsopen( m_szSaveFile, "a", SH_DENYNO );

	//	날짜와 시간을 문자열로 얻는다.
	_strdate_s( m_szDate, 256 );
	_strtime_s( m_szTime, 256 );
	fprintf_s( m_pLogFile, "로그 날짜 : %s 로그 시간 : %s\n", m_szDate, m_szTime );
	fprintf_s( m_pLogFile, "로그 내용 : 로그 매니저 시작\n\n" );

	fclose(m_pLogFile);
}

//	로그 윈도우 컬럼 추가
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

//	로그 윈도우 내용 추가
VOID	cLogMgr::AddLog( LPSTR szDate, LPSTR szTime, LPSTR szFileName, int nLine, LPSTR szText )
{
	LVITEM		LI;
	CHAR		szChangeNum[11];

	LI.iItem	=	SendMessage( m_hListView, LVM_GETITEMCOUNT, 0, 0 );

	//	숫자를 문자로 바꾸기
	_itoa_s( LI.iItem+1, szChangeNum, 11, 10 );

	//	로그 번호 넣기
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	0;
	LI.pszText		=	szChangeNum;
	SendMessage( m_hListView, LVM_INSERTITEM, 0, (LPARAM)&LI );

	//	날짜 넣기
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	1;
	LI.pszText		=	szDate;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	시간 넣기
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	2;
	LI.pszText		=	szTime;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	파일명 넣기
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	3;
	LI.pszText		=	szFileName;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	라인번호 넣기
	_itoa_s( nLine, szChangeNum, 11, 10 );

	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	4;
	LI.pszText		=	szChangeNum;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	//	내용 넣기
	LI.mask			=	LVIF_TEXT;
	LI.iSubItem		=	5;
	LI.pszText		=	szText;
	SendMessage( m_hListView, LVM_SETITEM, 0, (LPARAM)&LI );

	if( LI.iItem > LOG_WINDOW_VIEWCOUNT )
	{
		SendMessage( m_hListView, LVM_SCROLL, 0, (LPARAM)(LI.iItem - LOG_WINDOW_VIEWCOUNT) );
	}
}

//	로그 윈도우 위치 변동
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
//	경계선 만들기
VOID	cLogMgr::AddLineBar( VOID )
{
	CHAR	szBuf[72]	=	"\n============================== 경계선 ==============================\n\n";

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
		//	버퍼 열기
		m_pLogFile	=	_fsopen( m_szSaveFile, "a", SH_DENYNO );

		if( m_pLogFile != NULL )
		{
			fprintf_s( m_pLogFile, szBuf );

			fclose(m_pLogFile);
			m_pLogFile	=	NULL;
		}
	}
}

//	로그 찍기
VOID	cLogMgr::LogTexOut( LPCSTR szFilePath, INT nLineNum, BOOL bMsgBox, LPCSTR szFormat, ... )
{
	//	날짜와 시간을 문자열로 얻는다.
	_strdate_s( m_szDate, 256 );
	_strtime_s( m_szTime, 256 );

	//	로그 문자열을 완성한다.
	va_list args;
	va_start( args, szFormat );
	vsprintf_s( m_szBuf, 256, szFormat, args );
	va_end( args );

	//	경로에서 파일명만 잘라낸다.
	m_szFileName = GetFileName( szFilePath );

	CHAR	szBuf[3][256]	=	{};

	sprintf_s( szBuf[0], "로그 날짜 : %s 로그 시간 : %s\n", m_szDate, m_szTime );
	sprintf_s( szBuf[1], "로그 위치 : %s, 파일  %d 행\n", m_szFileName.c_str(), nLineNum );
	sprintf_s( szBuf[2], "로그 내용 : %s\n\n", m_szBuf );

	

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
		//	버퍼 열기
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
		MessageBox( NULL, m_szBuf, "메시지 내용", MB_OK );
	}
}

//	경로에서  이름 얻기
std::string		GetFileName(LPCSTR szPath)
{
	std::string		FileName = szPath;

	//	뒷 점의 위치
	INT nPointPos = FileName.find_last_of('.');

	//	경로를 역슬러시로 한경우
	INT nLastPathPos = FileName.find_last_of('\\');

	//	경로를 / 로 한경우
	if (nLastPathPos == -1)
	{
		nLastPathPos = FileName.find_last_of('/');
	}

	INT nLen = nPointPos - (nLastPathPos + 1);

	//	확장자 자르기
	FileName = FileName.substr(nLastPathPos + 1, nLen);

	return FileName;
}

LRESULT	CALLBACK	LogWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}