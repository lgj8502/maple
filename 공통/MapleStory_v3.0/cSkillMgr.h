#pragma once
#include "TemplateSingleton.h"

class cSkillMgr : public TemplateSingleton<cSkillMgr>
{
	BASESET(cSkillMgr);

public:

	bool m_isSoulDriver = false;

	~cSkillMgr();

	void SoulDriver();

	void Update(float _DelayTime);

	bool CrashCheckMob(cMob* _Mob, D2D1_POINT_2F _pos, D2D1_POINT_2F _range);

};

#define SKILL_MGR	cSkillMgr::GetInstance()