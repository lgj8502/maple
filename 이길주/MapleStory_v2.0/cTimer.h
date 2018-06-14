#pragma once

class cTimer
{
private:
	bool			m_bIsHardWare;			///< 고성능타이머 지원여부.
	float			m_fTimeScale;			///< 시간의 경과량을 조절.
	float			m_fTimeElapsed;			///< 마지막 시간과 현재시간의 경과량.
	__int64			m_nCurTime;				///< 현지시간.
	__int64			m_nLastTime;			///< 이전시간.
	__int64			m_nPeriodFrequency;		///< 시간의 주기.

	unsigned long	m_nFrameRate;			///< FPS
	unsigned long	m_nFPSFrameCount;		///< FPS 카운트
	float			m_fFPSTimeElapsed;

public:
	cTimer(void);
	~cTimer(void);

	void			Initialize();
	///< 현재 시간을 계산한다.
	void			Tick(float fLockFPS = 0.f);

	///< 현재 FPS를 얻어온다.
	unsigned long	GetFrameRate() const
	{
		return m_nFrameRate;
	}

	///< 마지막 시간과 현재시간의 경과량을 누적한다.
	inline float	GetElapsedTime() const
	{	
		return m_fTimeElapsed;
	}	
};
