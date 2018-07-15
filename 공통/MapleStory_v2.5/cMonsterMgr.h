#pragma once

#include "TemplateSingleton.h"

#include <list>

enum eMobName
{
	MOB_MUSHROOM,



	MOB_END,
};

struct sGroupInfo
{
	int m_GroupNum = -1;

	int m_MaxCount = 0;

	int m_Counting = 0;

	eMobName m_MobName = MOB_END;
	D2D1_POINT_2F m_pos = {};
	int m_range = 0;

	map<wstring, ImgInfo> m_ImgList;
};



class cMonsterMgr : public TemplateSingleton<cMonsterMgr>
{
	BASESET(cMonsterMgr);

private:

	//int m_MobGroupNum = 0;

	float m_CreateTime = 5.0f;

	//float m_CheckCountTime = 2.0f;

	vector<sGroupInfo> m_GrounpList;

	void CreateMob(eMobName _MobName, D2D1_POINT_2F _pos, int _range, map<wstring, ImgInfo> _ImgList, int _GroupNum);

	LPCWSTR m_ImgDir = L".\\Img\\Mob\\";

public:

	list<cMob*> m_MobList;
	vector<cMob*> m_DelList;

	~cMonsterMgr();

	void MobSetting(eMobName _MobName, int _MaxCount, D2D1_POINT_2F _pos, int _range);

	//void Init();
	void Update(float _DelayTime = 0.0f);
	void Render();

	void DelMob(cMob* _obj);

	void Destoy();

	void MobCountCheck(float _DelayTime);

};

#define MOB_MGR	cMonsterMgr::GetInstance()