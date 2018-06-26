#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE1"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE2"));

	m_Renderer.m_State = PS_IDLE;

	vector<float> timelist;

	timelist.push_back(0.5f);
	timelist.push_back(0.5f);

	m_Renderer.AddAnimation(PS_IDLE, 0, 2, timelist);

	m_Transform.SetPos({ 300,500 });

}


cPlayer::~cPlayer()
{
}
