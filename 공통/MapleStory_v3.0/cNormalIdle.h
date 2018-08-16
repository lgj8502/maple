#pragma once
#include "cMobIdle.h"

class cNormalIdle : public cMobIdle
{
public:
	cNormalIdle();
	~cNormalIdle();

	void Update(float _DelayTime);
	void Setting();
};

