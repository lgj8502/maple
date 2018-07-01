#include "stdafx.h"
#include "cPlayer.h"


//cPlayer::cPlayer()
//{
//
//
//	//m_Renderer.m_State = PLAYER_IDLE;
//
//	//for (int i = 0; i < PART_END; i++)
//	//{
//	//	m_Parts[i] = {};
//	//}
//
//	//m_Parts = new Object2D[PART_END];
//
//	//m_Parts[PART_HEAD].m_Renderer.AddBitmap(IMG_MGR->GetImage(L"HEAD"));
//	//m_Parts[PART_BODY].m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Body1_IDLE"));
//	//m_Parts[PART_ARM].m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Arm1_IDLE"));
//
//	Object2D obj;
//
//	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"HEAD"));
//
//
//
//
//
//	//m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE1"));
//	//m_Renderer.AddBitmap(IMG_MGR->GetImage(L"IDLE2"));
//
//	//m_Renderer.AddAnimation(PLAYER_IDLE, 0, 1, 0.5, 0.5);
//
//	//m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move1"));
//	//m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move2"));
//	//m_Renderer.AddBitmap(IMG_MGR->GetImage(L"Move3"));
//
//
//	//m_Renderer.AddAnimation(PLAYER_MOVE, 2, 4, 0.2, 0.2, 0.2);
//
//	//m_Renderer.AddBitmap(IMG_MGR->GetImage(L"FLY1"));
//	//m_Renderer.AddBitmap(IMG_MGR->GetImage(L"FLY2"));
//
//	//m_Renderer.AddAnimation(PLAYER_JUMP, 5, 6, 0.2, 10);
//
//	//m_Transform.m_gravity = true;
//
//	m_Transform.SetPos({ 300,100 });	
//}
//
//
//cPlayer::~cPlayer()
//{
//	//delete[] m_Parts;
//	//m_Parts = nullptr;
//}
//
//void cPlayer::LeftMove(float _DelayTime)
//{
//	m_Transform.m_velocityX = -m_MoveSpeed;
//
//	m_Transform.VelocityTrans(_DelayTime);
//
//	if (m_Renderer.m_State != PLAYER_JUMP)
//	{
//		m_Renderer.m_State = PLAYER_MOVE;
//	}
//}
//
//void cPlayer::RightMove(float _DelayTime)
//{
//	m_Transform.m_velocityX = +m_MoveSpeed;
//
//	m_Transform.VelocityTrans(_DelayTime);
//
//	if (m_Renderer.m_State != PLAYER_JUMP)
//	{
//		m_Renderer.m_State = PLAYER_MOVE;
//	}
//}
//
//void cPlayer::JumpMove()
//{
//	m_isJumping = true;
//}
//
//void cPlayer::Update(float _DelayTime)
//{
//	Object2D::Update(_DelayTime);
//
//	if (m_Transform.GetPos().y > 700.0f)
//	{
//		m_Transform.m_gravity = false;
//
//		m_JumpStart = false;
//
//		m_Transform.m_velocityY = 0.0f;
//
//		m_Renderer.m_State = PLAYER_IDLE;
//
//		m_Transform.Translate(0, -2);
//
//	}
//
//	if (m_Transform.m_velocityX == 0 && m_Transform.m_velocityY == 0)
//	{
//		m_Renderer.m_State = PLAYER_IDLE;
//	}
//
//	if (m_isJumping == true && m_Transform.m_gravity == false)
//	{
//		m_Renderer.m_State = PLAYER_JUMP;
//
//		if (m_JumpStart == false)
//		{
//			m_Transform.m_velocityY = -400.0;
//
//			m_JumpStart = true;
//		}
//
//		m_Transform.m_velocityY += 9.81f * _DelayTime * 200.0f;
//
//		if (m_Transform.m_velocityY > 0.0f)
//		{
//			m_Transform.m_gravity = true;
//
//			m_isJumping = false;
//		}
//		else
//		{
//			m_Transform.Translate(0, m_Transform.m_velocityY * _DelayTime);
//		}
//
//		MK_LOG("%f", m_Transform.m_velocityY);
//
//	}
//
//}
//
//void cPlayer::Rander()
//{	
//	Object2D a;
//
//	a.Render();
//
//	//for (int i = 0; i < PART_END; i++)
//	//{
//	//	
//	//}
//}
//
//
