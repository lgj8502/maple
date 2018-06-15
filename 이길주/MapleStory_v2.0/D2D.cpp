#include "stdafx.h"
#include "D2D.h"

D2D::D2D()
{
}


D2D::~D2D()
{
	SafeRelease(m_pBrush);
	SafeRelease(m_pRT);
	SafeRelease(m_pD2DFactory);
}

HRESULT D2D::Init2D(IDXGISwapChain * _pSwapChain)
{
	HRESULT hr = S_OK;

	hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&m_pD2DFactory);

	HR_CHECK_MSG("2D ���丮 ���� ����");

	IDXGISurface	*pSurface = nullptr;
	hr = _pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pSurface));

	HR_CHECK_MSG("�����̽� ��� ����");

	D2D1_RENDER_TARGET_PROPERTIES	RTP = D2D1::RenderTargetProperties(
		D2D1_RENDER_TARGET_TYPE_DEFAULT,
		D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED));

	hr = m_pD2DFactory->CreateDxgiSurfaceRenderTarget(pSurface, RTP, &m_pRT);

	SafeRelease(pSurface);

	HR_CHECK_MSG("����Ÿ�� ���� ����");

	hr = m_pRT->CreateSolidColorBrush(ColorF(ColorF::White), &m_pBrush);

	HR_CHECK_MSG("�귯�� ���� ����");

	m_Font.SetFont(L"���");

	IMG_MGR->Init(m_pRT);

	SCENE_MGR->SetRT_Brush(m_pRT, m_pBrush);

	return hr;
}

void D2D::Update(float _DelayTime)
{
	SCENE_MGR->Update(_DelayTime);
}

void D2D::Render()
{

	m_pRT->BeginDraw();
	//////////////////////////////////////////////////


	SCENE_MGR->Render();

	

	//////////////////////////////////////////////////
	m_pRT->EndDraw();

}
