#pragma once

#include "TemplateSingleton.h"

enum	LOG_TYPE
{
	LOG_NONE			=	0x0000,	//	�α� ����
	LOG_DEBUG			=	0x0001,	//	����� ���â
	LOG_CONSOLE			=	0x0002,	//	����â ���
	LOG_WINDOW			=	0x0004,	//	�α� ������ ����
	LOG_FILE			=	0x0010,	//	���Ϸ� ����
	LOG_ALL				=	LOG_DEBUG | LOG_CONSOLE | LOG_WINDOW | LOG_FILE
};

//	�ܼ� ����â
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
	//	�α� Ÿ��
	DWORD		m_dwLogType;

	//	�α� ������� �ڵ�
	HWND		m_hLogWnd;
	HWND		m_hListView;

	//	�ܼ� ����
	FILE		*m_pConsoleBuffer;
	FILE		*m_pLogFile;

	//	��¿� ���ڿ�
	CHAR		m_szBuf[256];

	//	��¥ �ð� ��¿�
	CHAR		m_szDate[256];
	CHAR		m_szTime[256];
	std::string	m_szFileName;

	//	���������
	CHAR		m_szSaveFile[256];

private:
	VOID	WindowInit( HWND hParentWnd );
	VOID	ConsoleInit( HWND hParentWnd );
	VOID	FileInit(VOID);

	//	�α� ������ �÷� �߰�
	VOID	AddCollmn( LPSTR pszText, int nSubNum, int nWidth );

	//	�α� ������ ���� �߰�
	VOID	AddLog( LPSTR szDate, LPSTR szTime, LPSTR szFileName, int nLine, LPSTR szText );
	

public:

	cLogMgr(void);
	~cLogMgr(void);

	//	�ʱ�ȭ
	VOID	Init( DWORD dwLogType, HWND hPrentWnd = NULL );

	//	����
	VOID	ReleaseSet(VOID);

	//	�α� ������ ��ġ ����
	VOID	UpdateLogWindowPos( HWND hParentWnd );

	//////////////////////////////////////////////////////////////////////////
	//	��輱 �����
	VOID	AddLineBar( VOID );

	//	�α� ���
	VOID	LogTexOut( LPCSTR szFilePath, INT nLineNum, BOOL bMsgBox, LPCSTR szFormat, ... );
};

#define	MK_LOG(format, ...)			cLogMgr::GetInstance()->LogTexOut(__FILE__, __LINE__, FALSE, format, __VA_ARGS__)
#define MK_MessageBox(format, ...)	cLogMgr::GetInstance()->LogTexOut(__FILE__, __LINE__, TRUE, format, __VA_ARGS__)