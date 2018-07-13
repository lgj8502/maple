#include "stdafx.h"
#include "cMushroom.h"

cMushroom::~cMushroom()
{
}

void cMushroom::Init()
{
	m_stateTime = (float)(rand() % 3) + 4.0f;

	m_HP = 100;
}

void cMushroom::StateUpdate(float _DelayTime)
{
	if (MAP_MGR->m_isPlaying == false) return;

	switch (m_state)
	{
	case MOBSTATE_IDLE:
	{
		m_stateTime -= _DelayTime;

		if (m_stateTime < 0)
		{
			StateChagne();
		}

	}break;

	case MOBSTATE_MOVE:
	{
		m_stateTime -= _DelayTime;

		if (m_dir == 0)
		{
			LeftWalk(_DelayTime);
		}
		else
		{
			RightWalk(_DelayTime);
		}

		if (m_stateTime < 0)
		{
			StateChagne();
		}
	}break;

	case MOBSTATE_HIT:
	{
		m_stateTime -= _DelayTime;

		if (m_HitLeft == true)
		{

			m_Transform.m_velocityX = -50.0f;
		}
		else
		{
			m_Transform.m_velocityX = 50.0f;

		}

		if (m_Transform.GetPos().x > m_minX || m_Transform.GetPos().x < m_maxX) m_Transform.VelocityTransX(_DelayTime);

		if (m_stateTime < 0)
		{
			m_state = MOBSTATE_AGGRO;

			StateChagne();			
		}
	}break;

	case MOBSTATE_DIE:
	{
		m_stateTime -= _DelayTime;

		if (m_stateTime < 0)
		{		
			Die();
			return;			
		}
	}
		break;
	case MOBSTATE_JUMP:
		break;
	case MOBSTATE_ATTACK:
		break;
	case MOBSTATE_AGGRO:
	{
		m_stateTime -= _DelayTime;

		if (m_dir == 0)
		{
			LeftWalk(_DelayTime);
		}
		else
		{
			RightWalk(_DelayTime);

		}

		if (m_stateTime < 0)
		{
			m_state = MOBSTATE_AGGRO;
		
			StateChagne();
		
		}

	}
		break;
	default:
		break;
	}

}

void cMushroom::StateChagne()
{
	if (m_state == MOBSTATE_IDLE)
	{
		m_state = MOBSTATE_MOVE;
	}
	else if (m_state == MOBSTATE_MOVE)
	{
		m_state = MOBSTATE_IDLE;
	}

	StateSetting();
}

void cMushroom::StateSetting()
{
	switch (m_state)
	{
	case MOBSTATE_IDLE: m_stateTime = (float)(rand() % 3) + 2.0f; m_Renderer.m_State = MOBSTATE_IDLE;
		break;

	case MOBSTATE_MOVE:
	{	m_stateTime = (float)(rand() % 3) + 4.0f; 
		m_Renderer.m_State = MOBSTATE_MOVE;
		m_dir = rand() % 2;
	}break;

	case MOBSTATE_HIT:
	{
		m_stateTime = 0.5f;
		m_Renderer.m_State = MOBSTATE_HIT;
	}break;
	case MOBSTATE_DIE:
	{
		m_stateTime = 1.5f;
		m_Renderer.m_State = MOBSTATE_DIE;
	}
		break;
	case MOBSTATE_JUMP:
		break;
	case MOBSTATE_ATTACK:
		break;
	case MOBSTATE_AGGRO: 
	{
		m_Renderer.m_State = MOBSTATE_AGGRO;

		m_stateTime = 1.0f;

		if (m_Transform.GetPos().x > PLAYER_MGR->m_player->GetPos().x)
		{
			m_dir = 0;
		}
		else
		{
			m_dir = 1;
		}
	}break;

	default:
		break;
	}
}

void cMushroom::Hit()
{
	m_HP -= PLAYER_MGR->m_player->m_AttackPower;

	if (m_HP <= 0)
	{
		m_state = MOBSTATE_DIE;
		StateChagne();

		return;
	}

	if (m_Transform.GetPos().x < PLAYER_MGR->m_player->GetPos().x)
	{
		m_HitLeft = true;
	}
	else
	{
		m_HitLeft = false;
	}

	m_state = MOBSTATE_HIT;

	StateChagne();

}

