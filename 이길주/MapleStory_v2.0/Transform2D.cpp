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
	if (m_isAniTrans == true && m_PosIndex != -1)
	{
		SetPos(m_PosList[m_PosIndex]);
	}
	

	//	행렬계산
	m_matScale = Matrix3x2F::Scale(m_Scale.x, m_Scale.y);
	m_matRot = Matrix3x2F::Rotation(m_Angle, m_Pivot);

	if (m_isCamera == true)
	{
		m_matTrans = Matrix3x2F::Translation(m_Pos.x - m_Pivot.x - (MAP_MGR->m_CameraPos.x * m_CameraRate.x), m_Pos.y - m_Pivot.y - (MAP_MGR->m_CameraPos.y * m_CameraRate.y) );
	}
	else
	{
		m_matTrans = Matrix3x2F::Translation(m_Pos.x - m_Pivot.x, m_Pos.y - m_Pivot.y);
	}

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

void Transform2D::VelocityTransX(float _time)
{
	Translate(m_velocityX * _time, 0);

	if (m_velocityX < 0 && m_Scale.x < 0)
	{
		m_Scale.x *= -1;
	}

	if (m_velocityX > 0 && m_Scale.x > 0)
	{
		m_Scale.x *= -1;
	}


}

void Transform2D::VelocityTransY(float _time)
{
	Translate(0, m_velocityY = _time);
}

void Transform2D::VelocityTrans_Map(float _time)
{
	Translate(m_velocityX * _time, 0);
}

void Transform2D::Gravity(float _DelayTime)
{
	m_velocityY += 9.81f * _DelayTime * 100.0f;

	Translate(0, m_velocityY * _DelayTime);

}

void Transform2D::AddTransAnimation(int _state, int _start, int _end, double _time, ...)
{
	AniTrans_Info Ani;

	Ani.m_FrameStart = _start;

	Ani.m_FrameEnd = _end;

	Ani.m_Count = _end - _start + 1;

	va_list arglist;
	va_start(arglist, _end);

	for (int i = 0; i < Ani.m_Count; i++)
	{
		Ani.m_Timer.push_back((float)va_arg(arglist, double));
	}

	va_end(arglist);

	//Ani.m_Timer = _timelist;

	float result = 0.0f;

	for (auto &i : Ani.m_Timer)
	{
		result += i;
	}

	Ani.m_TotalTime = result;

	m_AniTransList.insert(pair<int, AniTrans_Info>(_state, Ani));

	m_isAniTrans = true;
}

void Transform2D::AddAniPos(D2D1_POINT_2F _pos)
{
	m_PosList.push_back(_pos);
}

void Transform2D::AniTransUpdate(float _DelayTime)
{
	if (m_AniTransList.find(m_State) == m_AniTransList.end())
	{
		return;
	}

	int NowState = m_State;

	if (NowState != m_OldState)
	{
		m_CountTime = 0.0f;
	}

	m_CountTime += _DelayTime;

	if (m_CountTime >= m_AniTransList[NowState].m_TotalTime)
	{
		m_CountTime = 0.0f;
	}

	m_PosIndex = m_AniTransList[NowState].CurrentIndex(m_CountTime);

	m_OldState = NowState;

}

void Transform2D::SetPos(float _x, float _y)
{

	m_Pos.x = _x;
	m_Pos.y = _y;

}

void Transform2D::SetPos(D2D1_POINT_2F _pos)
{

	m_Pos = _pos;

}

D2D1_POINT_2F Transform2D::GetPos()
{
	return m_Pos;
}


Transform2D::Transform2D()
{
}


Transform2D::~Transform2D()
{
}
