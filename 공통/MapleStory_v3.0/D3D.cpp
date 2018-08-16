#include "stdafx.h"
#include "D3D.h"



D3D::D3D()
{
}


D3D::~D3D()
{
	SafeRelease(m_pConstBuffer);

	SafeRelease(m_pDepthStrecilView);
	SafeRelease(m_pDepthStencil);

	SafeRelease(m_pRTV);
	SafeRelease(m_pImm);
	SafeRelease(m_pSwapChain);
	SafeRelease(m_pD3DDevice);
}

HRESULT D3D::Init3D(HWND _hWnd)
{
	HRESULT hr = S_OK;

	m_hWnd = _hWnd;	

	tme.cbSize = sizeof(tme);
	tme.dwFlags = TME_LEAVE;
	tme.hwndTrack = m_hWnd;
	tme.dwHoverTime = 10;

#pragma region 3D Init
	DXGI_SWAP_CHAIN_DESC		sd = {};

	sd.BufferCount = 1;
	sd.BufferDesc.Width = WIN_WIDTH;
	sd.BufferDesc.Height = WIN_HEIGHT;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.OutputWindow = m_hWnd;
	sd.Windowed = TRUE;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	D3D_FEATURE_LEVEL	FeautureArray[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1
	};

	hr = D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		D3D11_CREATE_DEVICE_BGRA_SUPPORT,
		FeautureArray,
		ARRAYSIZE(FeautureArray),
		D3D11_SDK_VERSION,
		&sd,
		&m_pSwapChain,
		&m_pD3DDevice,
		nullptr,
		&m_pImm);


	HR_CHECK_MSG("디바이스 & 스왑체인 생성 실패");

	ID3D11Texture2D* pBackBuffer = nullptr;
	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&pBackBuffer));

	HR_CHECK_MSG("스왑체인 백버퍼 얻기 실패");

	hr = m_pD3DDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRTV);
	pBackBuffer->Release();

	HR_CHECK_MSG("렌더타켓뷰 생성 실패");


	D3D11_VIEWPORT vp = {};

	vp.Width = (FLOAT)WIN_WIDTH;
	vp.Height = (FLOAT)WIN_HEIGHT;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	m_pImm->RSSetViewports(1, &vp);
	//////////////////////////////////////////////////////////////////////


	D3D11_BUFFER_DESC cbd = {};
	cbd.ByteWidth = sizeof(ConstBuffer);
	cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	hr = m_pD3DDevice->CreateBuffer(&cbd, nullptr, &m_pConstBuffer);

	HR_CHECK_MSG("상수 버퍼 생성 실패");

	

	m_cb.matProjection = XMMatrixTranspose(
		XMMatrixPerspectiveFovLH(XM_PIDIV2, (float)WIN_WIDTH / WIN_HEIGHT, 0.01f, 100.0f)
	);

	D3D11_TEXTURE2D_DESC	DepthDC = {};

	DepthDC.Width = WIN_WIDTH;
	DepthDC.Height = WIN_HEIGHT;
	DepthDC.MipLevels = 1;
	DepthDC.ArraySize = 1;
	DepthDC.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	DepthDC.SampleDesc.Count = 1;
	DepthDC.SampleDesc.Quality = 0;
	DepthDC.BindFlags = D3D11_BIND_DEPTH_STENCIL;

	hr = m_pD3DDevice->CreateTexture2D(&DepthDC, nullptr, &m_pDepthStencil);

	HR_CHECK_MSG("스텐실 생성 실패");

	D3D11_DEPTH_STENCIL_VIEW_DESC	DSV_dc = {};

	DSV_dc.Format = DepthDC.Format;
	DSV_dc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

	hr = m_pD3DDevice->CreateDepthStencilView(m_pDepthStencil, nullptr, &m_pDepthStrecilView);

	HR_CHECK_MSG("스텐실뷰 생성 실패");

	m_pImm->OMSetRenderTargets(1, &m_pRTV, m_pDepthStrecilView);

#pragma endregion
	
	// D2D 초기화
	m_D2D.Init2D(m_pSwapChain);	

	return hr;
}

void D3D::Update(float _DelayTime)
{
	TrackMouseEvent(&tme);

	m_cb.matView = XMMatrixTranspose(XMMatrixLookAtLH(m_vEye, m_vAt, m_vUp));

	m_D2D.Update(_DelayTime);
}

void D3D::Render()
{
	m_pImm->ClearRenderTargetView(m_pRTV, Colors::MidnightBlue);
	m_pImm->ClearDepthStencilView(m_pDepthStrecilView, D3D11_CLEAR_DEPTH, 1.0f, 0);	
	
	
#pragma endregion
	m_D2D.Render();	

	m_pSwapChain->Present(0, 0);
}

LRESULT D3D::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	switch (iMessage)
	{
	case WM_MOUSELEAVE:
	{
		if (m_showCursur == false)
		{
			ShowCursor(true);
			m_showCursur = true;
		}
	}break;

	case WM_MOUSEMOVE:
	{
		if (m_showCursur == true)
		{
			ShowCursor(false);
			m_showCursur = false;
		}
	}break;
	
	case WM_LBUTTONDOWN :
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);
		
	}break;
	}

	return SCENE_MGR->MyWndProc(hWnd, iMessage, wParam, lParam);
}



