#include "stdafx.h"

#include <timeapi.h>
#include "cTimer.h"

// ���̺귯�� ��ũ ( timeGetTime() )
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
	///< ����Ÿ�̸� �������� üũ
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

		//	timeGetTime �ػ� ����
		timeBeginPeriod(1);
	}
	m_nFrameRate		=0;
	m_nFPSFrameCount	=0;
	m_fFPSTimeElapsed	=0.0f;
}

void cTimer::Tick(float fLockFPS)
{
	//����ð��� ���´�.
	if (m_bIsHardWare)	
	{
		///< �����е� ����ũ����(������ ��� )
		///< QueryPerformanceCounter �� ��Ƽ�ھ�� ����ȭ ������ �ִ�.
		QueryPerformanceCounter((LARGE_INTEGER*)&m_nCurTime);
	}
	else	
	{
		///< �������� ������� Time�Լ��� ����Ѵ�.
		m_nCurTime = timeGetTime();
	}
	///< ������ �ð��� ����ð��� ����� ����
	m_fTimeElapsed = (m_nCurTime - m_nLastTime) * m_fTimeScale;

	///< ���� ������ ó��
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
			///< ������ �ð��� ����ð��� ����� ����
			m_fTimeElapsed = (m_nCurTime - m_nLastTime) * m_fTimeScale;
		}
	}
	///< ������ �ð��� ���.
	m_nLastTime = m_nCurTime;

	///< �ʴ� ������ ī��Ʈ ����
	m_nFPSFrameCount++;

	///< FPS�ð� ����� ���� 
	m_fFPSTimeElapsed += m_fTimeElapsed;

	///< ������ �ʱ�ȭ(1��üũ)
	if (m_fFPSTimeElapsed > 1.0f)
	{
		m_nFrameRate		= m_nFPSFrameCount;
		m_nFPSFrameCount	= 0;
		m_fFPSTimeElapsed = 0.0f;
	}
}