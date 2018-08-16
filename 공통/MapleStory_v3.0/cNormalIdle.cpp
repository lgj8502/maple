#include "stdafx.h"
#include "cNormalIdle.h"


cNormalIdle::cNormalIdle()
{
}


cNormalIdle::~cNormalIdle()
{
}

void cNormalIdle::Update(float _DelayTime)
{
	m_pMob->m_StayTime -= _DelayTime;

	if (m_pMob->m_StayTime < 0)
	{
		m_pMob->StateChagne();
	}
}

void cNormalIdle::Setting()
{
	m_pMob->m_StayTime = (float)(rand() % 3) + 2.0f;
	m_pMob->m_Renderer.m_State = MOBSTATE_IDLE;
}
