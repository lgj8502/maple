#include "stdafx.h"
#include "cMonsterMgr.h"

#include "cMushroom.h"

cMonsterMgr::~cMonsterMgr()
{
}



void cMonsterMgr::CreateMob(eMobName _MobName, D2D1_POINT_2F _pos, int _range)
{
	cMob *MOB = nullptr;

	MOB->m_Transform.m_isCamera = true;

	switch (_MobName)
	{
	case MOB_MUSHROOM:
	{
		MOB = new cMushroom;
	}break;

	default:
		break;
	}

	int Random = rand() % _range;

	_pos.x += (float)Random;

	MOB->minX = _pos.x;
	MOB->maxX = _pos.x + (float)_range;

	MOB->m_Transform.SetPos(_pos);

	m_MobList.push_back(MOB);
}


void cMonsterMgr::MobSetting(eMobName _MobName, int _MaxCount, D2D1_POINT_2F _pos, int _range)
{
	D2D1_POINT_2F pos = _pos;	
	for (int i = 0; i < _MaxCount; i++)
	{
		CreateMob(_MobName, _pos, _range);
	}

}
