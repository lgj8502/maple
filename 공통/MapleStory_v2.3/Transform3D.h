#pragma once
class Transform3D
{
public:

	XMVECTOR m_Scale = { 1,1,1 };
	XMVECTOR m_Rot = {};
	XMVECTOR m_Trans = {};
	XMVECTOR m_Rev = {};

	XMMATRIX m_matScale = XMMatrixIdentity();
	XMMATRIX m_matTrans = XMMatrixIdentity();
	XMMATRIX m_matRot = XMMatrixIdentity();
	XMMATRIX m_matRev = XMMatrixIdentity();
	XMMATRIX m_matTotal = XMMatrixIdentity();

	Transform3D *m_pParent = nullptr;

	XMVECTOR m_BaseDir = { 0,0,1 };
	XMVECTOR m_Dir = { 0,0,1 };
	XMVECTOR m_DirRight = { 1, 0, 0 };
	XMVECTOR m_DirUp = { 0,1,0 };


	void UpdateMatrix();

	inline	XMVECTOR GetWorldPos()
	{
		return XMVector3TransformCoord({}, m_matTotal);
	}

	XMVECTOR m_EdgePoint[8];

	void	CalcEveryPoint();
	

};

