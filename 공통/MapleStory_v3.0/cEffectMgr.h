#pragma once

#include "TemplateSingleton.h"
#include "cEffect.h"
#include <list>

enum eNumColor
{
	NUMC_BLUE,
	NUMC_PINK,
	NUMC_RED,
};

class cEffectMgr : public TemplateSingleton<cEffectMgr>
{
	BASESET(cEffectMgr);

	list<cEffect*> m_EffectList;

public:

	~cEffectMgr();

	void EffectSingle(wstring _bitmapName, D2D1_POINT_2F _pos, bool _Left, float _watingTime, float _holdingTIme, bool _camera = true);
	void EffectMultiBtimap(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, bool _Left, bool _camera, double _holdingTIme, ...);
	void EffectMultiBtimap_const(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme, bool _camera = true);
	void EffectMultiBtimap_const_B(vector<ID2D1Bitmap*> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme, bool _camera = true);
	void EffectMultiBtimap_const_PlayerFollow(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme);
	void EffectMultiBtimap_const_PlayerFollow_B(vector<ID2D1Bitmap*> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme, FUNC _func);

	void NumberEffect(eNumColor _color, int _Number, D2D1_POINT_2F _pos);

	void DieEffect(D2D1_POINT_2F _pos);

	int CipherCalc(int _Num);

	void Update(float _DelayTime = 0);
	void Render();

	void Destoy();


};

#define EFF_MGR	cEffectMgr::GetInstance()