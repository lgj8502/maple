#include "stdafx.h"

#include <timeapi.h>
#include "cTimer.h"

// 라이브러리 링크 ( timeGetTime() )
#pragma comment (lib, "Winmm.lib")

cTimer::cTimer(void)
{
	Initialize();

	
}

cTimer::~cTimer(void)
{
	if( m_bIsHardWare == false )	timeEndPeriod(1);
}

void cTimer::Initialize()
{
	///< 고성능타이머 지원여부 체크
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&m_nPeriodFrequency))
	{
		m_bIsHardWare		= true;
		QueryPerformanceCounter((LARGE_INTEGER*)&m_nLastTime);
		m_fTimeScale		= 1.0f / m_nPeriodFrequency;
	}
	else
	{
		m_bIsHardWare	= false;
		m_nLastTime		= timeGetTime();
		m_fTimeScale	= 0.001f;

		//	timeGetTime 해상도 증가
		timeBeginPeriod(1);
	}
	m_nFrameRate		=0;
	m_nFPSFrameCount	=0;
	m_fFPSTimeElapsed	=0.0f;
}

void cTimer::Tick(float fLockFPS)
{
	//현재시간을 얻어온다.
	if (m_bIsHardWare)	
	{
		///< 초정밀도 마이크로초(단위로 계산 )
		///< QueryPerformanceCounter 는 멀티코어에서 동기화 문제가 있다.
		QueryPerformanceCounter((LARGE_INTEGER*)&m_nCurTime);
	}
	else	
	{
		///< 지원하지 않을경우 Time함수를 사용한다.
		m_nCurTime = timeGetTime();
	}
	///< 마지막 시간과 현재시간의 경과량 측정
	m_fTimeElapsed = (m_nCurTime - m_nLastTime) * m_fTimeScale;

	///< 고정 프레임 처리
	if (fLockFPS > 0.0f)
	{
		while (m_fTimeElapsed < (1.0f / fLockFPS))
		{
			if (m_bIsHardWare)
			{
				QueryPerformanceCounter((LARGE_INTEGER*)&m_nCurTime);
			}
			else	
			{
				m_nCurTime = timeGetTime();
			}
			///< 마지막 시간과 현재시간의 경과량 측정
			m_fTimeElapsed = (m_nCurTime - m_nLastTime) * m_fTimeScale;
		}
	}
	///< 마지막 시간을 기록.
	m_nLastTime = m_nCurTime;

	///< 초당 프레임 카운트 증가
	m_nFPSFrameCount++;

	///< FPS시간 경과량 증가 
	m_fFPSTimeElapsed += m_fTimeElapsed;

	///< 프레임 초기화(1초체크)
	if (m_fFPSTimeElapsed > 1.0f)
	{
		m_nFrameRate		= m_nFPSFrameCount;
		m_nFPSFrameCount	= 0;
		m_fFPSTimeElapsed = 0.0f;
	}
}