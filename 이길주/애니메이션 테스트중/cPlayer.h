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
	cPlayer();
	~cPlayer();
};

