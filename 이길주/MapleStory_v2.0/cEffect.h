#pragma once
class cEffect : public Object2D
{
public:
	cEffect();
	~cEffect();

	float m_destroyTime = 0.0f;
	
	float m_NowTime = 0.0f;


	bool CheckTime(float _time);
};

