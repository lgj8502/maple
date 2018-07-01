#pragma once

#include <map>
//enum ePlayerState
//{
//	PLAYER_IDLE,
//	PLAYER_MOVE,
//	PLAYER_JUMP,
//	PLAYER_ATTACK,
//
//};
//
//enum ePlayerParts
//{
//	//////////////
//	PART_HEAD,
//	PART_FACE,
//	PART_HAIR,
//	PART_BODY,
//	PART_ARM,
//
//	/////////////
//	PART_CAP,
//	PART_COAT,
//	PART_PANTS,
//	PART_SHOES,
//	PART_WEAPON,
//
//	PART_END,
//
//};

class cPlayer : public Object2D
{
	float  m_MoveSpeed = 200.0f;
	bool   m_isJumping = false;
	bool   m_JumpStart = false;

	map<int, Object2D> m_PartList;

	//Object2D *m_Parts = nullptr;

public:

	cPlayer();
	~cPlayer();
	
	void LeftMove(float _DelayTime);
	void RightMove(float _DelayTime);

	void JumpMove();

	void Update(float _DelayTime = 0.0f);
	void Rander();


};

