#include "stdafx.h"
#include "cNormalDie.h"


cNormalDie::cNormalDie()
{
}


cNormalDie::~cNormalDie()
{
}

void cNormalDie::Update(float _DelayTime)
{
	m_pMob->m_StayTime -= _DelayTime;

	if (m_pMob->m_StayTime < 0)
	{
		m_pMob->Die();
		return;
	}
}

void cNormalDie::Setting()
{
	m_pMob->m_StayTime = 1.4f;
	m_pMob->m_Renderer.m_State = MOBSTATE_DIE;
}
