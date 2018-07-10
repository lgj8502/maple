#include "stdafx.h"
#include "cEffectMgr.h"


cEffectMgr::~cEffectMgr()
{
	Destoy();
}

void cEffectMgr::EffectSingle(wstring _bitmapName, D2D1_POINT_2F _pos, float _DestroyTime)
{
	cEffect *Effect = new cEffect;

	Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(_bitmapName));

	Effect->m_destroyTime = _DestroyTime;

	Effect->m_Transform.SetPos(_pos);

	Effect->m_Transform.m_isCamera = true;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::EffectMultiBtimap(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, double _holdingTIme, ...)
{
	cEffect *Effect = new cEffect;

	Effect->m_Transform.SetPos(_pos);

	for (auto &i : _bitmapList)
	{
		Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(i));
	}
	vector<float> timelist;

	va_list arglist;
	va_start(arglist, _pos);

	for (size_t i = 0; i < _bitmapList.size(); i++)
	{
		timelist.push_back((float)va_arg(arglist, double));
	}

	va_end(arglist);

	float result = 0.0f;

	for (auto &i : timelist)
	{
		result += i;
	}

	Effect->m_destroyTime = result;

	Effect->m_Renderer.AddAnimation(0, 0, _bitmapList.size() - 1, timelist);
	Effect->m_Renderer.m_State = 0;

	Effect->m_Transform.m_isCamera = true;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::EffectMultiBtimap_const(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme)
{
	cEffect *Effect = new cEffect;

	Effect->m_Transform.SetPos(_pos);

	for (auto &i : _bitmapList)
	{
		Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(i));
	}

	Effect->m_destroyTime = _holdingTIme * _bitmapList.size();

	Effect->m_Renderer.AddAnimation_const(0, 0, _bitmapList.size() - 1, _holdingTIme);
	Effect->m_Renderer.m_State = 0;

	Effect->m_Transform.m_isCamera = true;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::Update(float _DelayTime)
{
	vector<cEffect*> delList;

	for (auto &i : m_EffectList)
	{
		i->Update(_DelayTime);

		if (i->CheckTime(_DelayTime) == true)
		{
			delList.push_back(i);
		}
	}

	for (auto &i : delList)
	{
		m_EffectList.remove(i);
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

