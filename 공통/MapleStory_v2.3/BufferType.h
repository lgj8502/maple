#pragma once

struct VertexPositionColor
{
	XMFLOAT3	Pos;
	XMFLOAT4	Color;

	static const int						LayoutCnt = 2;
	static const D3D11_INPUT_ELEMENT_DESC	Layout[LayoutCnt];
};

struct VertexPostionNormalTex
{
	XMFLOAT3	Pos;
	XMFLOAT3	Normal;
	XMFLOAT2	Tex;

	static const int						LayoutCnt = 3;
	static const D3D11_INPUT_ELEMENT_DESC	Layout[LayoutCnt];
};

struct ConstBuffer
{
	XMMATRIX	matWorld;
	XMMATRIX	matView;
	XMMATRIX	matProjection;

	//	조명 방향과 색상
	XMVECTOR	LightDir;
	XMVECTOR	LightColor;

	// 색상
	XMVECTOR	OutputColor;
};