#pragma once

#include <map>

enum eMobState
{
	MOBSTATE_IDLE,
	MOBSTATE_MOVE,	
	MOBSTATE_HIT,
	MOBSTATE_DIE,
	MOBSTATE_JUMP,
	MOBSTATE_ATTACK,
	MOBSTATE_ROMING,
};

class cMob : public Object2D
{
	float  m_MoveSpeed = 50.0f;

public:

	int m_HP = 0;

	float m_minX = 0.0f;
	float m_maxX = 0.0f;

	eMobState	 m_state		= MOBSTATE_IDLE;
	float		 m_stateTime	= 0;

	virtual ~cMob() = default;

	virtual void Init() = 0;

	virtual void StateUpdate(float _DelayTime) = 0;
	virtual void StateChagne() = 0;
	virtual void StateSetting() = 0;

	void LeftWalk(float _DelayTime);
	void RightWalk(float _DelayTime);

	void Hit(int _Damage, float _PlayerPosX);
	
	void RecvList(map<wstring, ImgInfo> _ImgList);

	
};

