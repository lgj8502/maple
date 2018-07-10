#pragma once

#include <vector>
#include <map>

struct AniTrans_Info
{
	int m_FrameStart = 0;
	int m_FrameEnd = 0;
	int m_Count = 0;
	float m_TotalTime = 0.0f;
	vector<float> m_Timer;

	int CurrentIndex(float _time)
	{
		for (int i = 0; i < m_Count; i++)
		{
			_time -= m_Timer[i];

			if (_time < 0)
			{
				return i + m_FrameStart;
			}
		}

		return -1;
	}
};

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



	float			m_gravityTime = 0.0f;

	// Ani 용
	int				m_PosIndex = -1;
	float			m_CountTime = 0.0f;
	vector<D2D1_POINT_2F> m_PosList;
	map< int, AniTrans_Info> m_AniTransList;



public:

	Matrix3x2F		m_matSRT = Matrix3x2F::Identity();

	Transform2D		*m_pParent = nullptr;

	bool			m_gravity = false;

	bool			m_isCrashed = false;

	float			m_velocityX = 0.0f;
	float			m_velocityY = 0.0f;

	bool			m_isMoving = false;

	int				m_State = -1;
	int				m_OldState = -1;

	bool			m_isAniTrans = false;

	bool			m_isCamera = false;
	D2D1_POINT_2F	m_CameraRate = { 1.0f, 1.0f };

protected:
	//	방향 갱신
	void	UpdateDir();

public:
	Transform2D();
	~Transform2D();

	//	행렬 갱신
	void	UpdateMatrix(ID2D1RenderTarget *_pRT = nullptr);

	void	Gravity(float _DelayTime);

	void	AddTransAnimation(int _state, int _start, int _end, double _time, ...);

	void	AddAniPos(D2D1_POINT_2F _pos);
	void	AniTransUpdate(float _DelayTime);

	void	SetScale(float _x, float _y)
	{
		m_Scale.x = _x;
		m_Scale.y = _y;
	}

	void	SetScale(D2D1_POINT_2F _scale)
	{
		m_Scale = _scale;
	}

	D2D1_POINT_2F GetScale()
	{
		return m_Scale;
	}	

	void	SetPos(float _x, float _y);

	void	SetPos(D2D1_POINT_2F _pos);


	D2D1_POINT_2F	GetPos();

	float			GetAngle()
	{
		return m_Angle;
	}

	void Translate(float _x, float _y)
	{
		m_Pos.x += _x;
		m_Pos.y += _y;
	}

	void VelocityTransX(float _time);
	void VelocityTransY(float _time);
	void VelocityTrans_Map(float _time);

};



