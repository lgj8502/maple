#pragma once

#include <map>
#include "cMobIdle.h"
#include "cMobMove.h"
#include "cMobHit.h"
#include "cMobDie.h"
#include "cMobAggro.h"



enum eMobState
{
	MOBSTATE_IDLE,
	MOBSTATE_MOVE,	
	MOBSTATE_HIT,
	MOBSTATE_DIE,
	MOBSTATE_JUMP,
	MOBSTATE_ATTACK,
	MOBSTATE_AGGRO,
};

class cMob : public Object2D
{

protected :

	cMobIdle		*m_pIdle		= nullptr;
	cMobMove		*m_pMove		= nullptr;
	cMobHit			*m_pHit			= nullptr;
	cMobDie			*m_pDie			= nullptr;
	cMobAggro		*m_pAggro		= nullptr;

	float			m_MoveSpeed		= 100.0f;	

public:

	Object2D		m_HPBar[3];

	float			m_StayTime = 0.0f;

	int				m_HP			= 0;
	int				m_MaxHp			= 0;
	int				m_AttackPower	= 0;

	float			m_minX			= 0.0f;
	float			m_maxX			= 0.0f;

	int				m_Exp			= 0;

	int				m_dir			= 0;

	int				m_Meso			= 0;


	bool			m_isDead		= false;

	bool			m_isActiveHPBar = false;
	bool			m_HitBar		= false;
	float			m_RedBarTime	= 0.5f;

	int				m_GroupNum		= -1;

	int				m_state			= MOBSTATE_IDLE;


public:

	virtual ~cMob() = default;

	void Init();

	virtual void Setting() = 0;

	void StateUpdate(float _DelayTime);
	void StateChagne();
	void StateSetting();

	void Hit(int _Damage);

	void HPBarUpdate(float _DelayTime);

	void HPBarRender();

	void LeftWalk(float _DelayTime);
	void RightWalk(float _DelayTime);

	void Die();
	
	void RecvList(map<wstring, ImgInfo> _ImgList);

	void Destroy();
};

