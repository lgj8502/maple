#include "stdafx.h"
#include "Renderer2D.h"
#include <cstdarg>

Renderer2D::Renderer2D()
{
	
}


Renderer2D::~Renderer2D()
{

}

void Renderer2D::Render(Matrix3x2F _mat, ID2D1RenderTarget *_pRT)
{
	if (m_BitmapList[m_BitmapIndex] == nullptr)	return;

	// 행렬을 랜더타켓에 적용한다.
	_pRT->SetTransform(_mat);

	_pRT->DrawBitmap(
		m_BitmapList[m_BitmapIndex],
		m_ImgRT,
		m_Alpha,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		m_ImgRT);
}

void Renderer2D::AddBitmap(wstring _name)
{
	m_BitmapList.push_back(IMG_MGR->GetImage(_name));	
}


