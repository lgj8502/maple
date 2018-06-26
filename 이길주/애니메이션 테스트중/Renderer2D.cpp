#include "stdafx.h"
#include "Renderer2D.h"
#include <cstdarg>

Renderer2D::Renderer2D()
{
	m_BitmapList.push_back(nullptr);
}


Renderer2D::~Renderer2D()
{

}

void Renderer2D::Render(Matrix3x2F _mat, ID2D1RenderTarget *_pRT)
{	
	if (m_BitmapList[m_BitmapIndex] == nullptr)	return;



	_pRT->SetTransform(_mat);

	_pRT->DrawBitmap(
		m_BitmapList[m_BitmapIndex],
		m_ImgRTList[m_BitmapIndex],
		m_Alpha);
}

void Renderer2D::AddBitmap(ID2D1Bitmap* _bitmap)
{
	if (m_BitmapList[m_BitmapIndex] == nullptr)
	{
		m_BitmapList.clear();
	}

	m_BitmapList.push_back(_bitmap);	

	auto Size = m_BitmapList[m_BitmapIndex]->GetSize();

	D2D1_RECT_F ImgRT;

	ImgRT.left = -Size.width / 2;
	ImgRT.right = +Size.width / 2;
	ImgRT.top = -Size.height / 2;
	ImgRT.bottom = Size.height / 2;

	m_ImgRTList.push_back(ImgRT);
}

void Renderer2D::ChangeBitmap(size_t _index)
{
	if (_index >= m_BitmapList.size())
	{
		MK_LOG("ChangeBitmap ½ÇÆÐ");
		return;
	}

	m_BitmapIndex = _index;
}

void Renderer2D::AddAnimation(int _state, int _start, int _count, vector<float> _timelist)
{
	Ani_Info Ani;

	Ani.m_FrameStart = _start;

	Ani.m_FrameEnd = _start + _count -1 ;

	Ani.m_Count = _count;

	Ani.m_Timer = _timelist;

	float result = 0.0f;

	for (auto &i : Ani.m_Timer)
	{
		result += i;
	}

	Ani.m_TotalTime = result;

	m_AniList.insert(pair<int, Ani_Info>(_state, Ani));
}

void Renderer2D::AniUpdate(float _DelayTime)
{
	int NowState = m_State;

	if (NowState != m_OldState)
	{
		m_CountTime = 0.0f;
	}

	m_CountTime += _DelayTime;

	if (m_CountTime >= m_AniList[NowState].m_TotalTime)
	{
		m_CountTime = 0.0f;
	}

	m_BitmapIndex = m_AniList[NowState].CurrentIndex(m_CountTime);
	//m_BitmapIndex = 1;

	m_OldState = NowState;
}


