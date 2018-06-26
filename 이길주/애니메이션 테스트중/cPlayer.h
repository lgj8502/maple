#pragma once

enum ePlayerState
{
	PS_IDLE,
	PS_MOVE,
	PS_JUMP,
	PS_ATTACK,

};

class cPlayer : public Object2D
{
public:
	cPlayer();
	~cPlayer();
};

