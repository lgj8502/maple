#pragma once
#include "Text2D.h"

class D2D
{

	ID2D1Factory			*m_pD2DFactory = nullptr;
	ID2D1RenderTarget		*m_pRT = nullptr;
	ID2D1SolidColorBrush	*m_pBrush = nullptr;

	//Text2D					m_Font;

public:
	D2D();
	~D2D();

	HRESULT Init2D(IDXGISwapChain *_pSwapChain);
	void	Update(float _DelayTime = 0);
	void	Render();

};

