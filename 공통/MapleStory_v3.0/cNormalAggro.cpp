#include "stdafx.h"
#include "cNormalAggro.h"


cNormalAggro::cNormalAggro()
{
}


cNormalAggro::~cNormalAggro()
{
}

void cNormalAggro::Update(float _DelayTime)
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
		m_pMob->m_state = MOBSTATE_AGGRO;

		m_pMob->StateChagne();

	}
}

void cNormalAggro::Setting()
{
	m_pMob->m_Renderer.m_State = MOBSTATE_AGGRO;

	m_pMob->m_StayTime = 1.0f;

	if (m_pMob->m_Transform.GetPos().x > PLAYER_MGR->m_player->GetPos().x)
	{
		m_pMob->m_dir = 0;
	}
	else
	{
		m_pMob->m_dir = 1;
	}
}
