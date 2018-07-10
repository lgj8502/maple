#pragma once

#include "TemplateSingleton.h"
#include "cEffect.h"
#include <vector>


class cEffectMgr : public TemplateSingleton<cEffectMgr>
{
	BASESET(cEffectMgr);

	vector<cEffect*> m_UIList;

public:

	~cEffectMgr();

	void AxeSwing1();


};

#define EFF_MGR	cEffectMgr::GetInstance()