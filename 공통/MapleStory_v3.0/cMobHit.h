#pragma once

class cMob;

class cMobHit
{

public:
	bool			m_HitLeft = false;

	cMob*			m_pMob			= nullptr;


public:
	cMobHit();
	~cMobHit();

	virtual void Update(float _DelayTime) = 0;
	virtual void Setting() = 0;
};

