#pragma once

enum eCharactorState
{
	Charac_IDLE,
	Charac_MOVE,
	Charac_JUMP,
	Charac_ATTACK,

};



class cCharacter : public Object2D
{
	float  m_MoveSpeed = 200.0f;
	bool   m_isJumping = false;
	bool   m_JumpStart = false;



public:

	cCharacter();
	~cCharacter();

	void Init();

	void LeftMove(float _DelayTime);
	void RightMove(float _DelayTime);

	void StopMove();

	void JumpMove();

	void Update(float _DelayTime = 0.0f);


};

