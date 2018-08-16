#pragma once

class cMob;

class cMobDie
{	
public:

	cMob *m_pMob = nullptr;


public:
	cMobDie();
	~cMobDie();

	virtual void Update(float _DelayTime) = 0;
	virtual void Setting() = 0;
};

