#pragma once

#include "D2D.h"


class D3D
{
	ID3D11Device			*m_pD3DDevice			= nullptr;
	ID3D11DeviceContext		*m_pImm					= nullptr;
	IDXGISwapChain			*m_pSwapChain			= nullptr;
	ID3D11RenderTargetView	*m_pRTV					= nullptr;
							 
	ID3D11Texture2D			*m_pDepthStencil		= nullptr;
	ID3D11DepthStencilView	*m_pDepthStrecilView	= nullptr;
							 
	ID3D11Buffer			*m_pConstBuffer			= nullptr;
	ConstBuffer				m_cb					= {};

	XMVECTOR				m_vEye = { 0, 3, -10.0f, 0 };
	XMVECTOR				m_vAt = { 0, 0, 0, 0 };
	XMVECTOR				m_vUp = { 0, 1, 0, 0 };

	HWND					m_hWnd;
	D2D						m_D2D;

	POINT					m_MousePos = { 0,0 };
	bool					m_showCursur = true;

	TRACKMOUSEEVENT tme = {};

public:
	D3D();
	~D3D();

	HRESULT Init3D(HWND _hWnd);
	void	Update(float _DelayTime = 0);
	void	Render();

	LRESULT MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);




};

