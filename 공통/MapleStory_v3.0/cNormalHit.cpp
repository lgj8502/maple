#include "stdafx.h"
#include "cNormalHit.h"


cNormalHit::cNormalHit()
{
}


cNormalHit::~cNormalHit()
{
}
void cNormalHit::Update(float _DelayTime)
{
	m_pMob->m_StayTime -= _DelayTime;

	if (m_HitLeft == true)
	{
		m_pMob->m_Transform.m_velocityX = -50.0f;
	}
	else
	{
		m_pMob->m_Transform.m_velocityX = 50.0f;
	}

	if (m_pMob->m_Transform.GetPos().x > m_pMob->m_minX || m_pMob->m_Transform.GetPos().x < m_pMob->m_maxX) m_pMob->m_Transform.VelocityTransX(_DelayTime);

	if (m_pMob->m_StayTime < 0)
	{
		m_pMob->m_state = MOBSTATE_AGGRO;

		m_pMob->StateChagne();
	}
}
void cNormalHit::Setting()
{
	m_pMob->m_StayTime = 0.5f;
	m_pMob->m_Renderer.m_State = MOBSTATE_HIT;
}
