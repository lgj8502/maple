#pragma once

#include "TemplateSingleton.h"

#include <list>

enum eMobName
{
	MOB_MUSHROOM,



	MOB_END,
};

class cMonsterMgr : public TemplateSingleton<cMonsterMgr>
{
	BASESET(cMonsterMgr);

private:

	list<cMob*> m_MobList;

	void CreateMob(eMobName _MobName, D2D1_POINT_2F _pos, int _range);

public:

	~cMonsterMgr();

	void MobSetting(eMobName _MobName, int _MaxCount, D2D1_POINT_2F _pos, int _range);



	

};

#define MOB_MGR	cMonsterMgr::GetInstance()