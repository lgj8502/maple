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

//	�ð��� �����ϴ� ����
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

	//	��Ŀ�� Ȯ�� �� ����
	BOOL	GetFocus(VOID)
	{
		return m_bOnFocus;
	}

	VOID	SetFocus(BOOL bFocus)
	{
		m_bOnFocus	=	bFocus;
	}

	//	���� Ű ������ ���Ǵ� ���� �ð� ������Ʈ
	VOID	TickTimeUpdate(VOID)
	{
		m_dwTime	=	timeGetTime();
	}

	//	Ű ���� üũ
	BOOL	StayKeyDown( INT nKey )
	{
		if( m_bOnFocus == TRUE &&
			GetAsyncKeyState( nKey ) & 0x8000 )
		{
			return TRUE;
		}

		return FALSE;
	}

	//	Ű ���� üũ ( ���� �ð� �������� ������ �� )
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

	//	�ѹ� ����
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

	//	�ѹ� ��
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

	//	���Ű Ȯ��
	BOOL	IsToggleKey( INT nKey )
	{
		if( OnceKeyDown(nKey) == TRUE )
		{
			m_bToggle[nKey]	= !m_bToggle[nKey];
		}

		return m_bToggle[nKey];
	}
}
