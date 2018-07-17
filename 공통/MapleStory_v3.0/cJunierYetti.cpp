#include "stdafx.h"
#include "cJunierYetti.h"

cJunierYetti::~cJunierYetti()
{
}

void cJunierYetti::Init()
{
	m_HP = 150;
	m_MaxHp = 150;
	m_AttackPower = 30;

	m_HPBar[0].m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"Mob_HP_0"));
	m_HPBar[1].m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"Mob_HP_2"));
	m_HPBar[2].m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"Mob_HP_1"));

	m_HPBar[1].m_Transform.m_pParent = &(m_HPBar[0].m_Transform);
	m_HPBar[2].m_Transform.m_pParent = &(m_HPBar[0].m_Transform);
	//m_HPBar[0].m_Transform.m_pParent = &(m_Transform);

	m_HPBar[0].m_Transform.m_isCamera = true;
	m_HPBar[1].m_Transform.SetPos(3.0f, -4.0f);
	m_HPBar[2].m_Transform.SetPos(3.0f, -4.0f);

}

void cJunierYetti::StateUpdate(float _DelayTime)
{
	if (MAP_MGR->m_isPlaying == false) return;

	HPBarUpdate(_DelayTime);

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

void cJunierYetti::StateChagne()
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

void cJunierYetti::StateSetting()
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
		m_stateTime = 1.4f;
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

void cJunierYetti::Hit()
{
	m_HP -= PLAYER_MGR->m_player->m_AttackPower;

	m_isActiveHPBar = true;
	m_HitBar = true;

	vector<wstring> str;

	str.push_back(L"sword1.0");
	str.push_back(L"sword1.1");
	str.push_back(L"sword1.2");

	if (m_state == MOBSTATE_DIE) return;

	EFF_MGR->EffectMultiBtimap_const(str, m_Transform.GetPos(), 0.2f);
	EFF_MGR->NumberEffect(NUMC_PINK, PLAYER_MGR->m_player->m_AttackPower, m_Transform.GetPos());

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

void cJunierYetti::HPBarUpdate(float _DelayTime)
{
	if (m_isActiveHPBar == false) return;

	m_HPBar[0].m_Transform.SetPos(m_Transform.GetPos().x - 40.0f, m_Transform.GetPos().y - 80.0f);

	for (int i = 0; i < 3; i++)
	{
		m_HPBar[i].Update(_DelayTime);
	}

	if (m_HitBar == true)
	{


		float ratio = (float)m_HP / (float)m_MaxHp;

		if (ratio < 0) ratio = 0;

		m_HPBar[2].m_Transform.SetScale(ratio, 1.0f);

		m_RedBarTime -= _DelayTime;

		if (m_RedBarTime < 0)
		{
			m_HPBar[1].m_Transform.SetScale(ratio, 1.0f);

			m_HitBar = false;

			m_RedBarTime = 0.5f;
		}


	}


}

