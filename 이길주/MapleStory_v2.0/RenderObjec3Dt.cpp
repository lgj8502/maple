#include "stdafx.h"
#include "RenderObject3D.h"

HRESULT RenderObject3D::Init(ID3D11Device * _pDevice, LPCSTR _PSName)
{
	HRESULT hr = S_OK;

	XMFLOAT3 CubePos[] =
	{
		XMFLOAT3(-1, +1, +1),
		XMFLOAT3(+1, +1, +1),
		XMFLOAT3(-1, +1, -1),
		XMFLOAT3(+1, +1, -1),
		XMFLOAT3(-1, -1, +1),
		XMFLOAT3(+1, -1, +1),
		XMFLOAT3(-1, -1, -1),
		XMFLOAT3(+1, -1, -1),
	};

	VertexPositionColor	vertives[] =
	{
		{ CubePos[0], m_Color },
		{ CubePos[1], m_Color },
		{ CubePos[2], m_Color },
		{ CubePos[3], m_Color },
		{ CubePos[4], m_Color },
		{ CubePos[5], m_Color },
		{ CubePos[6], m_Color },
		{ CubePos[7], m_Color },
	};

	m_VerCnt = ARRAYSIZE(vertives);

	D3D11_BUFFER_DESC bd = {};
	bd.ByteWidth = sizeof(VertexPositionColor) * m_VerCnt;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA InitData = {};
	InitData.pSysMem = vertives;

	hr = _pDevice->CreateBuffer(&bd, &InitData, &m_pVertexBuffer);

	HR_CHECK_MSG("버텍스버퍼 생성 오류");

	DWORD	IndexList[] =
	{
		0,1,2,
		2,1,3,

		5,4,7,
		7,4,6,

		2,3,6,
		6,3,7,

		1,0,5,
		5,0,4,

		3,1,7,
		7,1,5,

		0,2,4,
		4,2,6,		
	};
	m_IndexCnt = ARRAYSIZE(IndexList);

	bd.ByteWidth = sizeof(DWORD) * m_IndexCnt;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;

	InitData.pSysMem = IndexList;

	hr = _pDevice->CreateBuffer(&bd, &InitData, &m_pIndexBuffer);

	HR_CHECK_MSG("인덱스버퍼 생성 오류");


	ID3DBlob  *pBlob = nullptr;

	hr = D3DCompileFromFile(
		L"Sample2.fx",
		nullptr, nullptr,
		"VS_Color",
		"vs_4_0",
		D3DCOMPILE_ENABLE_STRICTNESS,
		0,
		&pBlob,
		nullptr);

	HR_CHECK_MSG("버텍스셰이더 오류");


	hr = _pDevice->CreateVertexShader(
		pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(),
		nullptr,
		&m_pVertexShader);

	if (FAILED(hr))
	{
		pBlob->Release();
		return hr;
	}

	hr = _pDevice->CreateInputLayout(
		VertexPositionColor::Layout,
		VertexPositionColor::LayoutCnt,
		pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(),
		&m_pInputLayout);

	pBlob->Release();

	HR_CHECK_MSG("인풋레이아웃 생성 오류");

	hr = D3DCompileFromFile(
		L"Sample2.fx",
		nullptr, nullptr,
		_PSName,		
		"ps_4_0",
		D3DCOMPILE_ENABLE_STRICTNESS,
		0,
		&pBlob,
		nullptr);

	HR_CHECK_MSG("픽셀세이더 오류");

	hr = _pDevice->CreatePixelShader(
		pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(),
		nullptr,
		&m_pPixelShader);

	pBlob->Release();

	return hr;
}

void RenderObject3D::Release()
{
	SafeRelease(m_pIndexBuffer);
	SafeRelease(m_pVertexBuffer);
	SafeRelease(m_pInputLayout);
	SafeRelease(m_pVertexShader);
	SafeRelease(m_pPixelShader);
}

void RenderObject3D::Render(ID3D11DeviceContext * _pImm)
{
	if (_pImm == nullptr			||
		m_pVertexBuffer == nullptr	||
		m_pIndexBuffer == nullptr	||
		m_pInputLayout == nullptr	||
		m_pVertexShader == nullptr	||
		m_pPixelShader == nullptr)
	{
		return;
	}

	_pImm->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	UINT Stride = sizeof(VertexPositionColor);
	UINT Offset = 0;
	_pImm->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &Stride, &Offset);
	_pImm->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	_pImm->IASetInputLayout(m_pInputLayout);

	_pImm->VSSetShader(m_pVertexShader, nullptr, 0);
	_pImm->PSSetShader(m_pPixelShader, nullptr, 0);

	_pImm->DrawIndexed(m_IndexCnt, 0, 0);
}
