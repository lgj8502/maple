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

	m_Transform.m_gravity = true;

	m_Transform.SetPos({ 300,100 });	
}


cPlayer::~cPlayer()
{
}

void cPlayer::LeftMove(float _DelayTime)
{
	m_Transform.m_velocityX = -m_MoveSpeed;

	m_Transform.VelocityTrans(_DelayTime);

	m_Renderer.m_State = PLAYER_MOVE;

}

void cPlayer::RightMove(float _DelayTime)
{
	m_Transform.m_velocityX = +m_MoveSpeed;

	m_Transform.VelocityTrans(_DelayTime);

	m_Renderer.m_State = PLAYER_MOVE;
}

void cPlayer::JumpMove(float _DelayTime)
{

}

void cPlayer::NotMove()
{
	m_Transform.m_velocityX = 0.0f;

	m_Renderer.m_State = PLAYER_IDLE;
}


