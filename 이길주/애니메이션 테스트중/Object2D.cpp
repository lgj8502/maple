#include "stdafx.h"
#include "Object2D.h"

Object2D::Object2D()
{
	m_pRT = IMG_MGR->GetpRT();
}

void Object2D::Update(float _DelayTime)
{
	m_Transform.UpdateMatrix(m_pRT);


	if (m_Renderer.m_State != -1)
	{
		m_Renderer.AniUpdate(_DelayTime);
	}

	if (m_Transform.m_gravity == true)
	{
		m_Transform.Gravity(_DelayTime);
	}

}

void Object2D::Render()
{
	m_Renderer.Render(m_Transform.m_matSRT, m_pRT);

}