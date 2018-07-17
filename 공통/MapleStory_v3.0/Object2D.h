#pragma once

#include "Transform2D.h"
#include "Renderer2D.h"


class Object2D
{

public:

	Object2D();

	ID2D1RenderTarget * m_pRT = nullptr;

	Transform2D m_Transform;
	Renderer2D	m_Renderer;

	void	Update(float _DelayTime = 0.0f);
	void	Render();


};

