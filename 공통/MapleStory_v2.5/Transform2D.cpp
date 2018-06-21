#include "stdafx.h"
#include "Transform2D.h"

void Transform2D::UpdateDir()
{
	Matrix3x2F		Rot = Matrix3x2F::Rotation(m_Angle);
	D2D1_POINT_2F	BaseDir = { 0, -1 };
	m_vDir = Rot.TransformPoint(BaseDir);
}

void Transform2D::UpdateMatrix(ID2D1RenderTarget * _pRT)
{
	//	행렬계산
	m_matScale = Matrix3x2F::Scale(m_Scale.x, m_Scale.y);
	m_matRot = Matrix3x2F::Rotation(m_Angle, m_Pivot);
	m_matTrans = Matrix3x2F::Translation(m_Pos.x - m_Pivot.x, m_Pos.y - m_Pivot.y);
	m_matSRT = m_matScale * m_matRot * m_matTrans;

	if (m_pParent != nullptr)
	{
		m_matSRT = m_matSRT * m_pParent->m_matSRT;
	}

	//	방향갱신
	UpdateDir();

	// 행렬을 랜더타켓에 적용한다.
	if (_pRT != nullptr)
	{
		_pRT->SetTransform(m_matSRT);
	}
}

Transform2D::Transform2D()
{
}


Transform2D::~Transform2D()
{
}
