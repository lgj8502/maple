#include "stdafx.h"
#include "cEffectMgr.h"


cEffectMgr::~cEffectMgr()
{
	Destoy();
}

void cEffectMgr::EffectSingle(wstring _bitmapName, D2D1_POINT_2F _pos, bool _Left, float _watingTime, float _holdingTIme, bool _camera)
{
	cEffect *Effect = new cEffect;

	Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(L"HideEff"));
	Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(_bitmapName));

	Effect->m_destroyTime = _holdingTIme + _watingTime;

	Effect->m_Transform.SetPos(_pos);

	if (_Left == false)
	{
		Effect->m_Transform.SetScale(-1, 1);
	}

	Effect->m_Renderer.AddAnimation(0, 0, 1, _watingTime, _holdingTIme);
	Effect->m_Renderer.m_State = 0;

	Effect->m_Transform.m_isCamera = _camera;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::EffectMultiBtimap(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, bool _Left, bool _camera, double _holdingTIme, ...)
{
	cEffect *Effect = new cEffect;

	Effect->m_Transform.SetPos(_pos);

	for (auto &i : _bitmapList)
	{
		Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(i));
	}
	vector<float> timelist;

	va_list arglist;
	va_start(arglist, _camera);

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

	if (_Left == false)
	{
		Effect->m_Transform.SetScale(-1, 1);
	}

	Effect->m_Transform.m_isCamera = _camera;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::EffectMultiBtimap_const(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme, bool _camera)
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

	Effect->m_Transform.m_isCamera = _camera;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::EffectMultiBtimap_const_B(vector<ID2D1Bitmap*> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme, bool _camera)
{
	cEffect *Effect = new cEffect;

	Effect->m_Transform.SetPos(_pos);

	for (auto &i : _bitmapList)
	{
		Effect->m_Renderer.AddBitmap_Bottom(i);
	}

	Effect->m_destroyTime = _holdingTIme * _bitmapList.size();

	Effect->m_Renderer.AddAnimation_const(0, 0, _bitmapList.size() - 1, _holdingTIme);
	Effect->m_Renderer.m_State = 0;

	Effect->m_Transform.m_isCamera = _camera;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::EffectMultiBtimap_const_PlayerFollow(vector<wstring> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme)
{
	cEffect *Effect = new cEffect;

	Effect->m_Transform.SetPos(_pos);
	Effect->m_Transform.m_pParent = PLAYER_MGR->m_player->TransformAddress();

	for (auto &i : _bitmapList)
	{
		Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(i));
	}

	Effect->m_destroyTime = _holdingTIme * _bitmapList.size();

	Effect->m_Renderer.AddAnimation_const(0, 0, _bitmapList.size() - 1, _holdingTIme);
	Effect->m_Renderer.m_State = 0;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::EffectMultiBtimap_const_PlayerFollow_B(vector<ID2D1Bitmap*> _bitmapList, D2D1_POINT_2F _pos, float _holdingTIme, FUNC _func)
{
	cEffect *Effect = new cEffect;

	Effect->m_Transform.SetPos(_pos);
	Effect->m_Transform.m_pParent = PLAYER_MGR->m_player->TransformAddress();

	for (auto &i : _bitmapList)
	{
		Effect->m_Renderer.AddBitmap_Bottom(i);
	}

	Effect->m_destroyTime = _holdingTIme * _bitmapList.size();

	Effect->m_Renderer.AddAnimation_const(0, 0, _bitmapList.size() - 1, _holdingTIme);
	Effect->m_Renderer.m_State = 0;

	Effect->m_Func = _func;

	m_EffectList.push_back(Effect);
}

void cEffectMgr::NumberEffect(eNumColor _color, int _Number, D2D1_POINT_2F _pos)
{
	int Cipher = CipherCalc(_Number);

	if (_Number == 0)
	{
		D2D1_POINT_2F pos = _pos;

		pos.y -= 50.0f;

		cEffect *Effect = new cEffect;
		Effect->m_Transform.SetPos(pos);
		Effect->m_isNumber = true;

		Effect->m_Renderer.AddBitmap(IMG_MGR->GetImage(L"NoRed0.Miss"));

		Effect->m_Transform.m_isCamera = true;

		Effect->m_destroyTime = 1.0f;

		m_EffectList.push_back(Effect);

		return;
	}
	

	for (int i = 0; i < Cipher; i++)
	{	
		D2D1_POINT_2F pos = _pos;

		pos.x += 15.0f * (Cipher - 1) - 30.0f * i;
		pos.y -= 50.0f;
		cEffect *Effect = new cEffect;

		Effect->m_Transform.SetPos(pos);
		
		Effect->m_isNumber = true;

		int Num =  _Number % (int)pow(10, (i + 1)) / (int)pow( 10 , i );

		wstring  color = L"";

		switch (_color)
		{
		case NUMC_BLUE: color = L"NoBlue0.";
			break;
		case NUMC_PINK: color = L"NoCri0.";
			break;
		case NUMC_RED:  color = L"NoCri2.";
			break;
		default:
			break;
		}

		wstring wstr = L"";

		switch (Num)
		{
		case 0: wstr = L"0"; break;
		case 1: wstr = L"1"; break;
		case 2: wstr = L"2"; break;
		case 3: wstr = L"3"; break;
		case 4: wstr = L"4"; break;
		case 5: wstr = L"5"; break;
		case 6: wstr = L"6"; break;
		case 7: wstr = L"7"; break;
		case 8: wstr = L"8"; break;
		case 9: wstr = L"9"; break;

		default:
			break;
		}

		color += wstr;

		Effect->m_Renderer.AddBitmap(IMG_MGR->GetImage(color));

		Effect->m_Transform.m_isCamera = true;

		Effect->m_destroyTime = 1.0f;

		m_EffectList.push_back(Effect);
		
	}




}

void cEffectMgr::DieEffect(D2D1_POINT_2F _pos)
{
	cEffect *Effect = new cEffect;

	D2D1_POINT_2F pos = _pos;

	pos.y += 20.0f;

	Effect->m_Transform.SetPos(pos);

	Effect->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(L"fall.0"));

	Effect->m_Transform.m_isCamera = true;

	Effect->m_NotDestroy = true;

	m_EffectList.push_back(Effect);
}

int cEffectMgr::CipherCalc(int _Num)
{
	int result = 1;

	int quotient = _Num / 10;

	while (true)
	{
		if (quotient == 0)
		{
			return result;
		}
		else
		{
			result++;
			quotient /= 10;
		}
	}	
}

void cEffectMgr::Update(float _DelayTime)
{
	vector<cEffect*> delList;

	for (auto &i : m_EffectList)
	{
		if (i->m_isNumber == true)
		{
			i->m_Transform.m_velocityY = -200.0f;

			i->m_Transform.VelocityTransY(_DelayTime);

			i->m_AplhaTime -= _DelayTime;

			if (i->m_AplhaTime < 0)
			{
				float alpha = i->m_Renderer.GetAlpha();
				alpha -= _DelayTime * 2;

				i->m_Renderer.SetAlpha(alpha);
				
			}
		}

		i->Update(_DelayTime);

		if (i->m_NotDestroy == true) continue;

		if (i->CheckTime(_DelayTime) == true)
		{
			if (i->m_Func != nullptr)
			{
				i->m_Func();
			}

			delList.push_back(i);
		}
	}

	for (auto &i : delList)
	{
		m_EffectList.remove(i);

	}

	for (auto &i : delList)
	{
		delete i;
		i = nullptr;
	}

	delList.clear();
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

