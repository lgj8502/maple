#include "stdafx.h"
#include "Transform3D.h"

void Transform3D::UpdateMatrix()
{
	m_matScale	= XMMatrixScalingFromVector(m_Scale);
	m_matRot	= XMMatrixRotationRollPitchYawFromVector(m_Rot);
	m_matTrans	= XMMatrixTranslationFromVector(m_Trans);
	m_matRev	= XMMatrixRotationRollPitchYawFromVector(m_Rev);

	m_Dir		= XMVector3TransformNormal({ 0, 0, 1 }, m_matRot);
	m_DirRight	= XMVector3TransformNormal({ 1, 0, 0 }, m_matRot);
	m_DirUp		= XMVector3TransformNormal({ 0, 1, 0 }, m_matRot);

	m_matTotal	= m_matScale * m_matRot * m_matTrans * m_matRev;

	if (m_pParent != nullptr)
	{
		m_matTotal *= m_pParent->m_matTotal;
	}

	CalcEveryPoint();

}

void Transform3D::CalcEveryPoint()
{
	m_EdgePoint[0] = XMVector3TransformCoord({ -1, +1, +1 }, m_matTotal);
	m_EdgePoint[1] = XMVector3TransformCoord({ +1, +1, +1 }, m_matTotal);
	m_EdgePoint[2] = XMVector3TransformCoord({ -1, +1, -1 }, m_matTotal);
	m_EdgePoint[3] = XMVector3TransformCoord({ +1, +1, -1 }, m_matTotal);
	m_EdgePoint[4] = XMVector3TransformCoord({ -1, -1, +1 }, m_matTotal);
	m_EdgePoint[5] = XMVector3TransformCoord({ +1, -1, +1 }, m_matTotal);
	m_EdgePoint[6] = XMVector3TransformCoord({ -1, -1, -1 }, m_matTotal);
	m_EdgePoint[7] = XMVector3TransformCoord({ +1, -1, -1 }, m_matTotal);
}

