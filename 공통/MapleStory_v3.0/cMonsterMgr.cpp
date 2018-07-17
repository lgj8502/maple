#include "stdafx.h"
#include "cMonsterMgr.h"

#include "cMushroom.h"
#include "cJunierYetti.h"

#include <atlbase.h>

cMonsterMgr::~cMonsterMgr()
{
	Destoy();
}



void cMonsterMgr::CreateMob(eMobName _MobName, D2D1_POINT_2F _pos, int _range, map<wstring, ImgInfo> _ImgList, int _GroupNum)
{
	cMob *MOB = nullptr;

	switch (_MobName)
	{
	case MOB_MUSHROOM:
	{
		MOB = new cMushroom;		

	}break;
	case MOB_JUNIERYETTI:
	{
		MOB = new cJunierYetti;

	}break;
	default:
		break;
	}

	MOB->m_Transform.m_isCamera = true;

	MOB->RecvList(_ImgList);

	MOB->m_minX = _pos.x;
	MOB->m_maxX = _pos.x + (float)_range;

	int Random = rand() % _range;

	_pos.x += (float)Random;

	MOB->Init();

	MOB->m_GroupNum = _GroupNum;

	MOB->m_Transform.SetPos(_pos);

	m_MobList.push_back(MOB);
}


void cMonsterMgr::MobSetting(eMobName _MobName, int _MaxCount, D2D1_POINT_2F _pos, int _range)
{
	sGroupInfo GI = {};

	GI.m_GroupNum = m_GrounpList.size();
	GI.m_MaxCount = _MaxCount;
	GI.m_MobName = _MobName;
	GI.m_Counting = _MaxCount;
	GI.m_pos = _pos;
	GI.m_range = _range;



	USES_CONVERSION;
	ostringstream addText;
	addText << _MobName << "\\";
	string Str = W2A(m_ImgDir);
	Str += addText.str().c_str();
	LPCWSTR Dir = A2W(Str.c_str());

	map<wstring, ImgInfo> ImgList;

	IMG_MGR->FileFindDir_Take(Dir, ImgList);

	GI.m_ImgList = ImgList;

	m_GrounpList.push_back(GI);

	for (int i = 0; i < _MaxCount; i++)
	{
		CreateMob(_MobName, _pos, _range, ImgList, GI.m_GroupNum);
	}



}

//void cMonsterMgr::Init()
//{
//	for (auto &i : m_MobList)
//	{
//		i->Init();
//	}
//}

void cMonsterMgr::Update(float _DelayTime)
{
	//if (m_MobList.size() == 0) return;

	for (auto &i : m_DelList)
	{
		m_MobList.remove(i);

		delete i;
		i = nullptr;
	}

	m_DelList.clear();

	for (auto &i : m_MobList)
	{
		i->Update(_DelayTime);
		i->StateUpdate(_DelayTime);
	}

	MobCountCheck(_DelayTime);
}

void cMonsterMgr::Render()
{
	//if (m_MobList.size() == 0) return;

	for (auto &i : m_MobList)
	{
		i->Render();
		i->HPBarRender();
	}
}

void cMonsterMgr::DelMob(cMob * _obj)
{
	m_DelList.push_back(_obj);

	_obj->m_Transform.SetPos(-1000.0f, - 1000.0f);

	//for (auto &i : m_GrounpList)
	//{
	//	if (_obj->m_GroupNum == i.m_GroupNum)
	//	{
	//		i.m_Counting--;
	//
	//		break;
	//	}
	//}

	


}

void cMonsterMgr::Destoy()
{
	for (auto &i : m_MobList)
	{
		delete i;
		i = nullptr;
	}

	for (auto &i : m_DelList)
	{
		delete i;
		i = nullptr;
	}


	m_DelList.clear();
	m_MobList.clear();
	m_GrounpList.clear();
}

void cMonsterMgr::MobCountCheck(float _DelayTime)
{
	m_CreateTime -= _DelayTime;

	if (m_CreateTime < 0)
	{
		for (auto &i : m_MobList)
		{
			m_GrounpList[i->m_GroupNum].m_Counting--;

		}

		for (auto &i : m_GrounpList)
		{
			if (i.m_Counting > 0)
			{
				CreateMob(i.m_MobName, i.m_pos, i.m_range, i.m_ImgList, i.m_GroupNum);
			}

			i.m_Counting = i.m_MaxCount;
		}



		m_CreateTime = 5.0f;

	}

}
