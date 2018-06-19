#pragma once
class Transform2D
{

protected:

	D2D1_POINT_2F	m_Scale = { 1,  1 };	//	크기
	float			m_Angle = 0.0f;			//	Z축 회전량
	D2D1_POINT_2F	m_Pos = { 0,  0 };	//	위치
	D2D1_POINT_2F	m_Pivot = { 0,  0 };
	D2D1_POINT_2F	m_vDir = { 0, -1 };	//	물체가 바라보는 방향

	Matrix3x2F		m_matScale = Matrix3x2F::Identity();
	Matrix3x2F		m_matRot = Matrix3x2F::Identity();
	Matrix3x2F		m_matTrans = Matrix3x2F::Identity();

public:

	Matrix3x2F		m_matSRT = Matrix3x2F::Identity();

	Transform2D		*m_pParent = nullptr;

protected:
	//	방향 갱신
	void	UpdateDir();

public:
	Transform2D();
	~Transform2D();

	//	행렬 갱신
	void	UpdateMatrix(ID2D1RenderTarget *_pRT = nullptr);

	void	SetScale(float _x, float _y)
	{
		m_Scale.x = _x / 2;
		m_Scale.y = _y / 2;
	}
	D2D1_POINT_2F GetScale()
	{
		return m_Scale;
	}

	

	void	SetPos(float _x, float _y)
	{
		m_Pos.x = _x;
		m_Pos.y = _y;
	}
	void	SetPos(D2D1_POINT_2F _pos)
	{
		m_Pos = _pos;
	}

	D2D1_POINT_2F	GetPos()
	{
		return m_Pos;
	}
	float			GetAngle()
	{
		return m_Angle;
	}
};



