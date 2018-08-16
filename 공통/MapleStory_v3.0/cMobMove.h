#pragma once

class cMob;

class cMobMove
{

public:

	cMob	*m_pMob = nullptr;

protected:



public:
	cMobMove();
	~cMobMove();

	virtual void Update(float _DelayTime) = 0;
	virtual void Setting() = 0;
};

