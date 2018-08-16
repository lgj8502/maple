#include "stdafx.h"
#include "cMob.h"


void cMob::Init()
{
	m_HPBar[0].m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"Mob_HP_0"));
	m_HPBar[1].m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"Mob_HP_2"));
	m_HPBar[2].m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"Mob_HP_1"));

	m_HPBar[1].m_Transform.m_pParent = &(m_HPBar[0].m_Transform);
	m_HPBar[2].m_Transform.m_pParent = &(m_HPBar[0].m_Transform);
	//m_HPBar[0].m_Transform.m_pParent = &(m_Transform);

	m_HPBar[0].m_Transform.m_isCamera = true;
	m_HPBar[1].m_Transform.SetPos(3.0f, -3.0f);
	m_HPBar[2].m_Transform.SetPos(3.0f, -3.0f);

	Setting();
}

void cMob::StateUpdate(float _DelayTime)
{
	if (MAP_MGR->m_isPlaying == false) return;

	HPBarUpdate(_DelayTime);

	switch (m_state)
	{
	case MOBSTATE_IDLE:
	{
		if (m_pIdle != nullptr)
		{
			m_pIdle->Update(_DelayTime);
		}
	}break;

	case MOBSTATE_MOVE:
	{
		if (m_pMove != nullptr)
		{
			m_pMove->Update(_DelayTime);
		}
	}break;

	case MOBSTATE_HIT:
	{
		if (m_pHit != nullptr)
		{
			m_pHit->Update(_DelayTime);
		}
	}break;

	case MOBSTATE_DIE:
	{
		if (m_pDie != nullptr)
		{
			m_pDie->Update(_DelayTime);
		}
	}
	break;
	case MOBSTATE_JUMP:
		break;
	case MOBSTATE_ATTACK:
		break;
	case MOBSTATE_AGGRO:
	{		
		if (m_pAggro != nullptr)
		{
			m_pAggro->Update(_DelayTime);
		}
	}
	break;
	default:
		break;
	}
}

void cMob::StateChagne()
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

void cMob::StateSetting()
{
	switch (m_state)
	{
	case MOBSTATE_IDLE:
	{
		if (m_pIdle != nullptr)
		{
			m_pIdle->Setting();
		}
	}break;

	case MOBSTATE_MOVE:
	{	
		if (m_pMove != nullptr)
		{
			m_pMove->Setting();
		}

	}break;

	case MOBSTATE_HIT:
	{
		if (m_pHit != nullptr)
		{
			m_pHit->Setting();
		}
	}break;
	case MOBSTATE_DIE:
	{
		if (m_pDie != nullptr)
		{
			m_pDie->Setting();
		}
	}
	break;
	case MOBSTATE_JUMP:
		break;
	case MOBSTATE_ATTACK:
		break;
	case MOBSTATE_AGGRO:
	{
		if (m_pAggro != nullptr)
		{
			m_pAggro->Setting();
		}
	}break;

	default:
		break;
	}
}

void cMob::Hit(int _Damage)
{
	m_HP -= _Damage;

	m_isActiveHPBar = true;
	m_HitBar = true;

	vector<wstring> str;

	str.push_back(L"sword1.0");
	str.push_back(L"sword1.1");
	str.push_back(L"sword1.2");

	if (m_state == MOBSTATE_DIE) return;

	EFF_MGR->EffectMultiBtimap_const(str, m_Transform.GetPos(), 0.2f);
	EFF_MGR->NumberEffect(NUMC_PINK, _Damage, m_Transform.GetPos());

	if (m_HP <= 0)
	{
		SOUND_MGR->SoundResume(L"0100004.Die");
		m_state = MOBSTATE_DIE;
		StateChagne();
		MAP_MGR->AddCoin(m_Transform.GetPos(), m_Meso);
		MAP_MGR->AddItem(m_Transform.GetPos(), 1000);
		return;
	}

	if (m_Transform.GetPos().x < PLAYER_MGR->m_player->GetPos().x && m_pHit != nullptr)
	{
		m_pHit->m_HitLeft = true;
	}
	else if (m_pHit != nullptr)
	{
		m_pHit->m_HitLeft = false;
	}
	SOUND_MGR->SoundResume(L"0100004.Damage");

	m_state = MOBSTATE_HIT;

	StateChagne();
}

void cMob::HPBarUpdate(float _DelayTime)
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

void cMob::HPBarRender()
{
	if (m_isActiveHPBar == true)
	{
		for (int i = 0; i < 3; i++)
		{
			m_HPBar[i].Render();
		}
	}
}

void cMob::LeftWalk(float _DelayTime)
{
	if (m_Transform.GetPos().x < m_minX)
	{
		m_dir = 1;
		return;
	}

	m_Transform.m_velocityX = -m_MoveSpeed;
	m_Transform.VelocityTransX(_DelayTime);
	
}

void cMob::RightWalk(float _DelayTime)
{
	if (m_Transform.GetPos().x > m_maxX)
	{
		m_dir = 0;
		return;
	}

	m_Transform.m_velocityX = m_MoveSpeed;
	m_Transform.VelocityTransX(_DelayTime);
}

void cMob::Die()
{
	MOB_MGR->DelMob(this);

	m_isDead = true;

	PLAYER_MGR->m_player->m_CharacInfo.m_Exp += m_Exp;
	
	DATA_MGR->Save_Charater();
}


void cMob::RecvList(map<wstring, ImgInfo> _ImgList)
{
	map<wstring, ImgInfo>::iterator Iter;

	vector<wstring> wstr;	

	for (Iter = _ImgList.begin(); Iter != _ImgList.end(); Iter++)
	{
		wstr.push_back(Iter->first);

		m_Renderer.AddBitmap_Bottom(Iter->second.m_Bitmap);
	}

	int Idle = 0;
	int Move = 0;
	int Hit = 0;
	int Die = 0;
	int Fly = 0;
	int Attack = 0;

	int current = 0;

	for (auto &i : wstr)
	{
		wchar_t wbuf[256] = L"";

		wcscpy_s(wbuf, i.c_str());

		switch (wbuf[0])
		{
		case L'a': Attack++; break;
		case L'd': Die++; break;
		case L'f': Fly++; break;
		case L'h': Hit++; break;
		case L'm': Move++; break;
		case L's': Idle++; break;		

		default:
			break;
		}
	}

	if (Attack != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_ATTACK, current, Attack - 1, 0.2f);

		current += Attack;
	}

	if (Die != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_DIE, current, Die - 1, 0.5f);

		current += Die;
	}

	if (Fly != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_JUMP, current, current + Fly - 1, 0.2f);

		current += Fly;
	}

	if (Hit != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_HIT, current, current+ Hit - 1, 0.5f);

		current += Hit;
	}

	if (Move != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_MOVE, current, current + Move - 1, 0.2f);
		m_Renderer.AddAnimation_const(MOBSTATE_AGGRO, current, current + Move - 1, 0.2f);

		current += Move;
	}

	if (Idle != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_IDLE, current, current + Idle - 1, 0.5f);

		current = +Idle;
	}
}

void cMob::Destroy()
{
	delete m_pIdle;
	delete m_pMove;
	delete m_pHit;
	delete m_pDie;
	delete m_pAggro;
}




