#pragma once
#include "cMobMove.h"
class cNormalMove : public cMobMove
{
public:
	cNormalMove();
	~cNormalMove();

	void Update(float _DelayTime);
	void Setting();
};

