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



	void CreateMob(eMobName _MobName, D2D1_POINT_2F _pos, int _range, map<wstring, ImgInfo> _ImgList);

	LPCWSTR m_ImgDir = L".\\Img\\Mob\\";

public:

	list<cMob*> m_MobList;

	~cMonsterMgr();

	void MobSetting(eMobName _MobName, int _MaxCount, D2D1_POINT_2F _pos, int _range);

	void Init();
	void Update(float _DelayTime = 0.0f);
	void Render();

	void DelMob(cMob* _obj);

	void Destoy();

};

#define MOB_MGR	cMonsterMgr::GetInstance()