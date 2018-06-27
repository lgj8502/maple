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
	float  m_MoveSpeed = 200.0f;
	bool   m_isJumping = false;
	bool   m_JumpStart = false;

public:

	cPlayer();
	~cPlayer();
	
	void LeftMove(float _DelayTime);
	void RightMove(float _DelayTime);

	void JumpMove();

	void Update(float _DelayTime = 0.0f);


};

