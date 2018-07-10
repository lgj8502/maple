#include "stdafx.h"
#include "cEffectMgr.h"


cEffectMgr::~cEffectMgr()
{
}

void cEffectMgr::EffectSingle(wstring _bitmapName, D2D1_POINT_2F _pos, float _time)
{
	cEffect *Effect = new cEffect;

	Effect->m_Renderer.AddBitmap(IMG_MGR->GetImage(_bitmapName));

	Effect->m_destroyTime = _time;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::Update(float _DelayTime)
{
	for (auto &i : m_EffectList)
	{
		i->Update(_DelayTime);
	}
}

void cEffectMgr::Render()
{
	for (auto &i : m_EffectList)
	{
		i->Render();
	}
}

void cEffectMgr::Destoy()
{
	for (auto &i : m_EffectList)
	{
		i = {};
		delete i;
		i = nullptr;
	}
	m_EffectList.clear();
}

