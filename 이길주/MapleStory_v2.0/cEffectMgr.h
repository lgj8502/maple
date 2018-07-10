#pragma once

#include "TemplateSingleton.h"
#include "cEffect.h"
#include <list>


class cEffectMgr : public TemplateSingleton<cEffectMgr>
{
	BASESET(cEffectMgr);

	list<cEffect*> m_EffectList;

public:

	~cEffectMgr();

	void EffectSingle(wstring _bitmapName, D2D1_POINT_2F _pos, float _time);

	void Update(float _DelayTime = 0);
	void Render();

	void Destoy();


};

#define EFF_MGR	cEffectMgr::GetInstance()