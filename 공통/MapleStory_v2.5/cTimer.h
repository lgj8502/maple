#pragma once

class cTimer
{
private:
	bool			m_bIsHardWare;			///< ����Ÿ�̸� ��������.
	float			m_fTimeScale;			///< �ð��� ������� ����.
	float			m_fTimeElapsed;			///< ������ �ð��� ����ð��� �����.
	__int64			m_nCurTime;				///< �����ð�.
	__int64			m_nLastTime;			///< �����ð�.
	__int64			m_nPeriodFrequency;		///< �ð��� �ֱ�.

	unsigned long	m_nFrameRate;			///< FPS
	unsigned long	m_nFPSFrameCount;		///< FPS ī��Ʈ
	float			m_fFPSTimeElapsed;

public:
	cTimer(void);
	~cTimer(void);

	void			Initialize();
	///< ���� �ð��� ����Ѵ�.
	void			Tick(float fLockFPS = 0.f);

	///< ���� FPS�� ���´�.
	unsigned long	GetFrameRate() const
	{
		return m_nFrameRate;
	}

	///< ������ �ð��� ����ð��� ������� �����Ѵ�.
	inline float	GetElapsedTime() const
	{	
		return m_fTimeElapsed;
	}	
};
