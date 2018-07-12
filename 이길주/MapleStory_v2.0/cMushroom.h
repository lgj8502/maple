#pragma once

class cMushroom : public cMob
{
public:
	~cMushroom();

	void Init();

	void StateUpdate(float _DelayTime);
	void StateChagne() ;
	void StateSetting();

};

