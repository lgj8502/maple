#pragma once

enum ePlayerState
{
	PLAYER_IDLE,
	PLAYER_MOVE,
	PLAYER_JUMP,
	PLAYER_ATTACK,

};

class cPlayer : public Object2D
{
public:
	
	float  m_MoveSpeed = 200.0f;

	cPlayer();
	~cPlayer();
	
	void LeftMove(float _DelayTime);
	void RightMove(float _DelayTime);

	void JumpMove(float _DelayTime);

	void NotMove();

};

