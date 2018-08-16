#pragma once
#include "cMobHit.h"

class cNormalHit : public cMobHit
{
public:
	cNormalHit();
	~cNormalHit();

	void Update(float _DelayTime);
	void Setting();
};

