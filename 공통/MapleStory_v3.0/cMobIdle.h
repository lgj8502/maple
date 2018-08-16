#pragma once

class cMob;

class cMobIdle
{
public:

	cMob	*m_pMob = nullptr;

public:
	cMobIdle();
	~cMobIdle();

	virtual void Update(float _DelayTime) = 0;
	virtual void Setting() = 0;

};

