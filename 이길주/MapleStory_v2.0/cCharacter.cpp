#include "stdafx.h"
#include "cCharacter.h"


cCharacter::cCharacter()
{

}


cCharacter::~cCharacter()
{
}

void cCharacter::Init()
{
	m_Renderer.m_State = Charac_IDLE;

	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE1"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE2"));

	m_Renderer.AddAnimation(Charac_IDLE, 0, 1, 0.5, 0.5);

	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move1"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move2"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move3"));


	m_Renderer.AddAnimation(Charac_MOVE, 2, 4, 0.2, 0.2, 0.2);

	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"FLY1"));
	m_Renderer.AddBitmap(IMG_MGR->GetImage(L"FLY2"));

	m_Renderer.AddAnimation(Charac_JUMP, 5, 6, 0.2, 10);

	m_Transform.m_gravity = false;

	m_Transform.SetPos({ 400,400 });
}

void cCharacter::LeftMove(float _DelayTime)
{
	m_Transform.m_velocityX = -m_MoveSpeed;

	m_Transform.VelocityTransX(_DelayTime);

	if (m_Renderer.m_State != Charac_JUMP)
	{
		m_Renderer.m_State = Charac_MOVE;
	}
}

void cCharacter::RightMove(float _DelayTime)
{
	m_Transform.m_velocityX = +m_MoveSpeed;

	m_Transform.VelocityTransX(_DelayTime);

	if (m_Renderer.m_State != Charac_JUMP)
	{
		m_Renderer.m_State = Charac_MOVE;
	}
}

void cCharacter::StopMove()
{
	m_Transform.m_velocityX = 0.0f;
}

void cCharacter::JumpMove()
{
	m_isJumping = true;
}

void cCharacter::Update(float _DelayTime)
{
	Object2D::Update(_DelayTime);

	if (m_Transform.GetPos().y > 700.0f)
	{
		m_Transform.m_gravity = false;

		m_JumpStart = false;

		m_Transform.m_velocityY = 0.0f;

		m_Renderer.m_State = Charac_IDLE;

		m_Transform.Translate(0, -2);

	}

	if (m_Transform.m_velocityX == 0 && m_Transform.m_velocityY == 0)
	{
		m_Renderer.m_State = Charac_IDLE;
	}

	if (m_isJumping == true && m_Transform.m_gravity == false)
	{
		m_Renderer.m_State = Charac_JUMP;

		if (m_JumpStart == false)
		{
			m_Transform.m_velocityY = -400.0;

			m_JumpStart = true;
		}

		m_Transform.m_velocityY += 9.81f * _DelayTime * 200.0f;

		if (m_Transform.m_velocityY > 0.0f)
		{
			m_Transform.m_gravity = true;

			m_isJumping = false;
		}
		else
		{
			m_Transform.Translate(0, m_Transform.m_velocityY * _DelayTime);
		}



	}

}


