#pragma once

#include "TemplateSingleton.h"

enum	LOG_TYPE
{
	LOG_NONE			=	0x0000,	//	로그 없음
	LOG_DEBUG			=	0x0001,	//	디버그 출력창
	LOG_CONSOLE			=	0x0002,	//	도스창 출력
	LOG_WINDOW			=	0x0004,	//	로그 윈도우 생성
	LOG_FILE			=	0x0010,	//	파일로 저장
	LOG_ALL				=	LOG_DEBUG | LOG_CONSOLE | LOG_WINDOW | LOG_FILE
};

//	콘솔 가로창
#define	CONSOLE_WIDTH			400
#define LOG_WINDOW_WIDTH		600
#define LOG_WINDOW_VIEWCOUNT	27

#include <string>
#include <Windows.h>

class cLogMgr : public TemplateSingleton<cLogMgr>
{
private:
	friend	TemplateSingleton;

private:
	//	로그 타입
	DWORD		m_dwLogType;

	//	로그 윈도우용 핸들
	HWND		m_hLogWnd;
	HWND		m_hListView;

	//	콘솔 버퍼
	FILE		*m_pConsoleBuffer;
	FILE		*m_pLogFile;

	//	출력용 문자열
	CHAR		m_szBuf[256];

	//	날짜 시간 출력용
	CHAR		m_szDate[256];
	CHAR		m_szTime[256];
	std::string	m_szFileName;

	//	파일저장용
	CHAR		m_szSaveFile[256];

private:
	VOID	WindowInit( HWND hParentWnd );
	VOID	ConsoleInit( HWND hParentWnd );
	VOID	FileInit(VOID);

	//	로그 윈도우 컬럼 추가
	VOID	AddCollmn( LPSTR pszText, int nSubNum, int nWidth );

	//	로그 윈도우 내용 추가
	VOID	AddLog( LPSTR szDate, LPSTR szTime, LPSTR szFileName, int nLine, LPSTR szText );
	

public:

	cLogMgr(void);
	~cLogMgr(void);

	//	초기화
	VOID	Init( DWORD dwLogType, HWND hPrentWnd = NULL );

	//	해제
	VOID	ReleaseSet(VOID);

	//	로그 윈도우 위치 변동
	VOID	UpdateLogWindowPos( HWND hParentWnd );

	//////////////////////////////////////////////////////////////////////////
	//	경계선 만들기
	VOID	AddLineBar( VOID );

	//	로그 찍기
	VOID	LogTexOut( LPCSTR szFilePath, INT nLineNum, BOOL bMsgBox, LPCSTR szFormat, ... );
};

#define	MK_LOG(format, ...)			cLogMgr::GetInstance()->LogTexOut(__FILE__, __LINE__, FALSE, format, __VA_ARGS__)
#define MK_MessageBox(format, ...)	cLogMgr::GetInstance()->LogTexOut(__FILE__, __LINE__, TRUE, format, __VA_ARGS__)