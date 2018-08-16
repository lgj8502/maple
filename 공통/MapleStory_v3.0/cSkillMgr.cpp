#include "stdafx.h"
#include "cSkillMgr.h"

cSkillMgr::~cSkillMgr()
{
}

void cSkillMgr::SoulDriver()
{
	if (m_isSoulDriver == true) return;

	if (PLAYER_MGR->m_player->m_CharacInfo.m_MP < 25.0f)
	{
		return;
	}

	PLAYER_MGR->m_player->m_CharacInfo.m_MP -= 25;
	UI_MGR->MPSetting(PLAYER_MGR->m_player->m_CharacInfo.m_MP);

	m_isSoulDriver = true;

	map<wstring, ImgInfo> ImgList;

	IMG_MGR->FileFindDir_Take(L".\\Img\\skill\\10000\\", ImgList);

	vector<wstring> strList;

	map<wstring, ImgInfo>::iterator Iter;

	vector<ID2D1Bitmap*> bitmpaList;
	vector<ID2D1Bitmap*> bitmpaList2;
	vector<ID2D1Bitmap*> bitmpaList3;


	for (Iter = ImgList.begin(); Iter != ImgList.end(); Iter++)
	{
		strList.push_back(Iter->first);
	}

	for (auto &i : strList)
	{
		wchar_t wbuf[256] = L"";

		wcscpy_s(wbuf, i.c_str());

		switch (wbuf[8])
		{
		case L'e': 
		{
			if (wbuf[16] == L'\0')
			{
				bitmpaList.push_back(ImgList[i.c_str()].m_Bitmap);
			}
			else
			{
				bitmpaList2.push_back(ImgList[i.c_str()].m_Bitmap);
			}
			
		}break;
		case L'h':
		{
			bitmpaList3.push_back(ImgList[i.c_str()].m_Bitmap);
		}break;


		default:
			break;
		}
	}

	for (auto &i : bitmpaList2)
	{
		bitmpaList.push_back(i);
	}

	auto SoulDriver = [](void) { SKILL_MGR->m_isSoulDriver = false; };

	EFF_MGR->EffectMultiBtimap_const_PlayerFollow_B(bitmpaList, { 0, 30 }, 0.1f, SoulDriver);

	SOUND_MGR->SoundResume(L"0001075.Use");


	list<cMob*>::iterator IterMob;

	for (IterMob = MOB_MGR->m_MobList.begin(); IterMob != MOB_MGR->m_MobList.end(); IterMob++)
	{
		if (CrashCheckMob((*IterMob), PLAYER_MGR->m_player->GetPos(), {500, 50}) == true)	
		{
			int a = PLAYER_MGR->m_player->m_AttackPower;

			(*IterMob)->Hit((int)(PLAYER_MGR->m_player->m_AttackPower * 7.6));

			D2D1_POINT_2F pos = (*IterMob)->m_Transform.GetPos();

			pos.y += (*IterMob)->m_Renderer.GetImgRT().bottom * 2;

			EFF_MGR->EffectMultiBtimap_const_B(bitmpaList3, pos, 0.15f);

		}
	}



}

void cSkillMgr::Update(float _DelayTime)
{

}

bool cSkillMgr::CrashCheckMob(cMob * _Mob, D2D1_POINT_2F _pos, D2D1_POINT_2F _range)
{
	float left = _pos.x - _range.x;
	float right = _pos.x + _range.x;
	float up = _pos.y - _range.y;
	float down = _pos.y + _range.y;

	D2D1_POINT_2F pos = _Mob->m_Transform.GetPos();
	D2D1_RECT_F rect = _Mob->m_Renderer.GetImgRT();

	rect.left += pos.x;
	rect.right += pos.x;
	rect.top += pos.y;
	rect.bottom += pos.y;

	if (right > rect.left && left < rect.right &&
		up < rect.bottom && down > rect.top)
	{
		return true;
	}
	return false;
}

