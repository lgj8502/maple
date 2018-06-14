#include "stdafx.h"
#include "MK_KeyMgr.h"

#include <windows.h>
#include <bitset>
#include <vector>
#include <mmsystem.h>

#pragma comment ( lib, "winmm.lib" )

CONST INT KEYMAX	=	256;

BOOL					m_bOnFocus;

std::bitset<KEYMAX>		m_bDown;
std::bitset<KEYMAX>		m_bUp;
std::bitset<KEYMAX>		m_bToggle;
std::vector<DWORD>		m_bDelayKey;

//	시간을 저장하는 변수
DWORD					m_dwTime;

namespace MK_API
{
	VOID	InitKeyMgr(VOID)
	{
		m_bDown.reset();
		m_bUp.reset();
		m_bToggle.reset();
		m_bDelayKey.resize( KEYMAX, 0 );

		m_bOnFocus	=	TRUE;
	}

	//	포커스 확인 및 설정
	BOOL	GetFocus(VOID)
	{
		return m_bOnFocus;
	}

	VOID	SetFocus(BOOL bFocus)
	{
		m_bOnFocus	=	bFocus;
	}

	//	지연 키 눌림에 사용되는 기준 시간 업데이트
	VOID	TickTimeUpdate(VOID)
	{
		m_dwTime	=	timeGetTime();
	}

	//	키 눌림 체크
	BOOL	StayKeyDown( INT nKey )
	{
		if( m_bOnFocus == TRUE &&
			GetAsyncKeyState( nKey ) & 0x8000 )
		{
			return TRUE;
		}

		return FALSE;
	}

	//	키 눌림 체크 ( 일정 시간 간격으로 눌리는 것 )
	BOOL	StayKeyDown( INT nKey, DWORD dwDelay )
	{	
		if( m_bOnFocus == TRUE &&
			GetAsyncKeyState( nKey ) & 0x8000 )
		{
			if( m_dwTime - m_bDelayKey[nKey] > dwDelay )
			{
				m_bDelayKey[nKey]	=	m_dwTime;

				return TRUE;
			}
		}

		return FALSE;
	}

	//	한번 눌림
	BOOL	OnceKeyDown( INT nKey )
	{
		if( m_bOnFocus == TRUE &&
			GetAsyncKeyState( nKey ) & 0x8000 )
		{
			if( m_bDown[nKey] == FALSE )
			{	
				m_bDown[nKey]	=	TRUE;
				return TRUE;
			}
		}

		else
		{
			m_bDown[nKey]	=	FALSE;
		}

		return FALSE;
	}

	//	한번 뗌
	BOOL	OnceKeyUp( INT nKey )
	{
		if( m_bOnFocus == TRUE &&
			GetAsyncKeyState( nKey ) & 0x8000 )
		{
			m_bUp[nKey]	=	TRUE;
		}

		else
		{
			if( m_bUp[nKey] == TRUE )
			{
				m_bUp[nKey] = FALSE;
				return TRUE;
			}
		}

		return FALSE;
	}

	//	토글키 확인
	BOOL	IsToggleKey( INT nKey )
	{
		if( OnceKeyDown(nKey) == TRUE )
		{
			m_bToggle[nKey]	= !m_bToggle[nKey];
		}

		return m_bToggle[nKey];
	}
}
