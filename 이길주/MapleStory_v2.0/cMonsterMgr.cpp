#include "stdafx.h"
#include "cMonsterMgr.h"

#include "cMushroom.h"

#include <atlbase.h>

cMonsterMgr::~cMonsterMgr()
{
	Destoy();
}



void cMonsterMgr::CreateMob(eMobName _MobName, D2D1_POINT_2F _pos, int _range, map<wstring, ImgInfo> _ImgList)
{
	cMob *MOB = nullptr;

	switch (_MobName)
	{
	case MOB_MUSHROOM:
	{
		MOB = new cMushroom;		

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

	MOB->m_Transform.SetPos(_pos);

	m_MobList.push_back(MOB);
}


void cMonsterMgr::MobSetting(eMobName _MobName, int _MaxCount, D2D1_POINT_2F _pos, int _range)
{
	USES_CONVERSION;
	ostringstream addText;
	addText << _MobName << "\\";
	string Str = W2A(m_ImgDir);
	Str += addText.str().c_str();
	LPCWSTR Dir = A2W(Str.c_str());

	map<wstring, ImgInfo> ImgList;

	IMG_MGR->FileFindDir_Take(Dir, ImgList);

	for (int i = 0; i < _MaxCount; i++)
	{
		CreateMob(_MobName, _pos, _range, ImgList);
	}	

}

void cMonsterMgr::Init()
{
	for (auto &i : m_MobList)
	{
		i->Init();
	}
}

void cMonsterMgr::Update(float _DelayTime)
{
	for (auto &i : m_MobList)
	{
		i->Update(_DelayTime);
		i->StateUpdate(_DelayTime);
	}
}

void cMonsterMgr::Render()
{
	for (auto &i : m_MobList)
	{
		i->Render();
	}
}

void cMonsterMgr::DelMob(cMob * _obj)
{
	m_MobList.remove(_obj);

	delete _obj;
	_obj = nullptr;
}

void cMonsterMgr::Destoy()
{
	for (auto &i : m_MobList)
	{
		delete i;
		i = nullptr;
	}

	m_MobList.clear();
}
