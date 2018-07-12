#pragma once

enum eMobState
{
	MOBSTATE_IDLE,
	MOBSTATE_MOVE,
	MOBSTATE_ROMING,
	MOBSTATE_HIT,
	MOBSTATE_DIE,
	MOBSTATE_JUMP,
	MOBSTATE_ATTACK,

};

class cMob : public Object2D
{
	float  m_MoveSpeed = 200.0f;

public:

	int m_HP = 0;

	float minX = 0.0f;
	float maxX = 0.0f;

	cMob();
	~cMob();

	void Init();

	


};

