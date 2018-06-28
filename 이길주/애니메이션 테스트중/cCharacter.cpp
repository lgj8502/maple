#include "stdafx.h"
#include "cCharacter.h"


cCharacter::cCharacter()
{

}


cCharacter::~cCharacter()
{
}

void cCharacter::LeftMove(float _DelayTime)
{
	m_Transform.m_velocityX = -m_MoveSpeed;

	m_Transform.VelocityTrans(_DelayTime);

	if (m_Renderer.m_State != PLAYER_JUMP)
	{
		m_Renderer.m_State = PLAYER_MOVE;
	}
}

void cCharacter::RightMove(float _DelayTime)
{
	m_Transform.m_velocityX = +m_MoveSpeed;

	m_Transform.VelocityTrans(_DelayTime);

	if (m_Renderer.m_State != PLAYER_JUMP)
	{
		m_Renderer.m_State = PLAYER_MOVE;
	}
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

		m_Renderer.m_State = PLAYER_IDLE;

		m_Transform.Translate(0, -2);

	}

	if (m_Transform.m_velocityX == 0 && m_Transform.m_velocityY == 0)
	{
		m_Renderer.m_State = PLAYER_IDLE;
	}

	if (m_isJumping == true && m_Transform.m_gravity == false)
	{
		m_Renderer.m_State = PLAYER_JUMP;

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

		MK_LOG("%f", m_Transform.m_velocityY);

	}

}


