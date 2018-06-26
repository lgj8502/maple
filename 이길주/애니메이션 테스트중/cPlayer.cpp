#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_Renderer.m_State = PLAYER_IDLE;

	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE1"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE2"));

	m_Renderer.AddAnimation(PLAYER_IDLE, 0, 1, 0.5, 0.5);

	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move1"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move2"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move3"));


	m_Renderer.AddAnimation(PLAYER_MOVE, 2, 4, 0.2, 0.2, 0.2);



	m_Transform.SetPos({ 300,500 });

}


cPlayer::~cPlayer()
{
}
