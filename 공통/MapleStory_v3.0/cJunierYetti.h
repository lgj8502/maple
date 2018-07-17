#pragma once

class cJunierYetti : public cMob
{
public:
	~cJunierYetti();

	void Init();

	void StateUpdate(float _DelayTime);
	void StateChagne();
	void StateSetting();

	void Hit();

	void HPBarUpdate(float _DelayTime);

};

