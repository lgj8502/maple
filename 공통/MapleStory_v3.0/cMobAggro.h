#pragma once

class cMob;

class cMobAggro
{

public:

	cMob	*m_pMob = nullptr;

public:
	cMobAggro();
	~cMobAggro();

	virtual void Update(float _DelayTime) = 0;
	virtual void Setting() = 0;
};

