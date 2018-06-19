#pragma once
class RenderObject3D
{
public:

	ID3D11Buffer			*m_pVertexBuffer = nullptr;
	ID3D11Buffer			*m_pIndexBuffer = nullptr;
	ID3D11InputLayout		*m_pInputLayout = nullptr;
	ID3D11VertexShader		*m_pVertexShader = nullptr;
	ID3D11PixelShader		*m_pPixelShader = nullptr;

	XMFLOAT4				m_Color = { 1,1,0,1 };
	XMFLOAT4				m_OldColor = { 1,1,0,1 };

	int	m_VerCnt = 0;
	int m_IndexCnt = 0;

	HRESULT Init(ID3D11Device *_pDevice = nullptr, LPCSTR _PSName = "PS_Color" );
	void Release();
	void Render(ID3D11DeviceContext *_pImm = nullptr);
};

