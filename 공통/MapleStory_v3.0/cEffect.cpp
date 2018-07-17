#include "stdafx.h"
#include "cEffect.h"


cEffect::cEffect()
{
}


cEffect::~cEffect()
{
}

bool cEffect::CheckTime(float _time)
{
	m_NowTime += _time;

	if (m_NowTime > m_destroyTime)
	{
		return true;
	}

	return false;
}
