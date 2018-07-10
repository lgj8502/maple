#pragma once

enum eCharactorState
{
	Charac_IDLE,
	Charac_MOVE,
	Charac_HIT,
	Charac_DIE,
	Charac_JUMP,
	Charac_ATTACK,

};



class cCharacter : public Object2D
{
	float  m_MoveSpeed = 200.0f;




public:

	cCharacter();
	~cCharacter();

	void Init();




};

