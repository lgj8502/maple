#pragma once
#include "cMobDie.h"
class cNormalDie : public cMobDie
{
public:
	cNormalDie();
	~cNormalDie();

	void Update(float _DelayTime);
	void Setting();
};

