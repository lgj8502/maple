#pragma once
class cEffect : public Object2D
{
public:
	cEffect();
	~cEffect();

	float m_destroyTime = 0.0f;
	
	float m_NowTime = 0.0f;

	float m_AplhaTime = 0.5f;

	bool  m_isNumber = false;

	bool  m_NotDestroy = false;


	FUNC m_Func = nullptr;

	bool CheckTime(float _time);

};

