#include "stdafx.h"
#include "cMushroom.h"

cMushroom::~cMushroom()
{
}

void cMushroom::Init()
{
}

void cMushroom::StateUpdate(float _DelayTime)
{
	switch (m_state)
	{
	case MOBSTATE_IDLE:
	{
		m_stateTime -= _DelayTime;

		m_Renderer.m_State = MOBSTATE_IDLE;

		if (m_stateTime < 0)
		{
			StateChagne();
		}

	}break;

	case MOBSTATE_MOVE:
	{
		m_stateTime -= _DelayTime;

		m_Renderer.m_State = MOBSTATE_MOVE;

		int dir = rand() % 2;

		if (m_Transform.GetPos().x == m_maxX) dir = 0;
		if (m_Transform.GetPos().x == m_minX) dir = 1;

		if (dir == 0)
		{
			LeftWalk(_DelayTime);
		}
		else if (dir == 1)
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
		m_Renderer.m_State = MOBSTATE_HIT;


	}break;

	case MOBSTATE_DIE:
		break;
	case MOBSTATE_JUMP:
		break;
	case MOBSTATE_ATTACK:
		break;
	case MOBSTATE_ROMING:
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
	case MOBSTATE_IDLE: m_stateTime = (float)(rand() % 3) + 2.0f;
		break;
	case MOBSTATE_MOVE: m_stateTime = (float)(rand() % 3) + 4.0f;
		break;
	case MOBSTATE_HIT:m_stateTime = 0.5f;
		break;
	case MOBSTATE_DIE:
		break;
	case MOBSTATE_JUMP:
		break;
	case MOBSTATE_ATTACK:
		break;
	case MOBSTATE_ROMING:
		break;
	default:
		break;
	}
}
