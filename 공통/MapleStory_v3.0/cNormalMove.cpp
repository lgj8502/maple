#include "stdafx.h"
#include "cNormalMove.h"


cNormalMove::cNormalMove()
{
}


cNormalMove::~cNormalMove()
{
}

void cNormalMove::Update(float _DelayTime)
{
	m_pMob->m_StayTime -= _DelayTime;

	if (m_pMob->m_dir == 0)
	{
		m_pMob->LeftWalk(_DelayTime);
	}
	else
	{
		m_pMob->RightWalk(_DelayTime);
	}

	if (m_pMob->m_StayTime < 0)
	{
		m_pMob->StateChagne();
	}
}

void cNormalMove::Setting()
{
	m_pMob->m_StayTime = (float)(rand() % 3) + 4.0f;
	m_pMob->m_Renderer.m_State = MOBSTATE_MOVE;
	m_pMob->m_dir = rand() % 2;
}
