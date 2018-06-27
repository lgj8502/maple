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

	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"FLY1"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"FLY2"));

	m_Renderer.AddAnimation(PLAYER_JUMP, 5, 6, 0.2, 10);

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

	if (m_Renderer.m_State != PLAYER_JUMP)
	{
		m_Renderer.m_State = PLAYER_MOVE;
	}
}

void cPlayer::RightMove(float _DelayTime)
{
	m_Transform.m_velocityX = +m_MoveSpeed;

	m_Transform.VelocityTrans(_DelayTime);

	if (m_Renderer.m_State != PLAYER_JUMP)
	{
		m_Renderer.m_State = PLAYER_MOVE;
	}
}

void cPlayer::JumpMove()
{
	m_isJumping = true;
}

void cPlayer::Update(float _DelayTime)
{
	Object2D::Update(_DelayTime);

	if (m_Transform.GetPos().y > 700.0f)
	{
		m_Transform.m_gravity = false;

		m_JumpStart = false;

		m_Transform.m_velocityY = 0.0f;

		m_Renderer.m_State = PLAYER_IDLE;

		m_Transform.Translate(0, -2);

	}

	if (m_Transform.m_velocityX == 0 && m_Transform.m_velocityY == 0)
	{
		m_Renderer.m_State = PLAYER_IDLE;
	}

	if (m_isJumping == true)
	{
		m_Renderer.m_State = PLAYER_JUMP;

		if (m_JumpStart == false)
		{
			m_Transform.m_velocityY = -350.0f;

			m_JumpStart = true;
		}

		m_Transform.m_velocityY += 9.81f * 0.016 * 200.0f;

		if (m_Transform.m_velocityY > 0.0f)
		{
			m_Transform.m_gravity = true;

			m_isJumping = false;
		}
		else
		{
			m_Transform.Translate(0, m_Transform.m_velocityY * 0.016);
		}

		MK_LOG("%f", m_Transform.m_velocityY);

	}

}


