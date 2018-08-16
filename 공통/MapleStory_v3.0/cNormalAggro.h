#pragma once
#include "cMobAggro.h"
class cNormalAggro : public cMobAggro
{
public:
	cNormalAggro();
	~cNormalAggro();

	void Update(float _DelayTime);
	void Setting();
};

