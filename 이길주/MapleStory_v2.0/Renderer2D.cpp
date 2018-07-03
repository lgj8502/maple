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
	if (m_HaveBitmap == false)	return;

	_pRT->SetTransform(_mat);

	_pRT->DrawBitmap(
		m_BitmapList[m_BitmapIndex],
		m_ImgRTList[m_BitmapIndex],
		m_Alpha);
}

void Renderer2D::AddBitmap(ID2D1Bitmap* _bitmap)
{
	m_BitmapList.push_back(_bitmap);	

	auto Size = m_BitmapList.back()->GetSize();

	D2D1_RECT_F ImgRT;

	ImgRT.left = -Size.width / 2;
	ImgRT.right = +Size.width / 2;
	ImgRT.top = -Size.height / 2;
	ImgRT.bottom = Size.height / 2;

	m_ImgRTList.push_back(ImgRT);

	m_HaveBitmap = true;
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
//void Renderer2D::AddAnimation(int _state, int _start, int _count, vector<float> _timelist)
void Renderer2D::AddAnimation(int _state, int _start, int _end, double _time, ...)
{
	Ani_Info Ani;

	Ani.m_FrameStart = _start;

	Ani.m_FrameEnd = _end ;

	Ani.m_Count = _end - _start + 1;

	va_list arglist;
	va_start(arglist, _end);

	for (int i = 0; i < Ani.m_Count; i++)
	{
		Ani.m_Timer.push_back((float)va_arg(arglist, double));		
	}

	va_end(arglist);

	//Ani.m_Timer = _timelist;

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
	if (m_AniList.find(m_State) == m_AniList.end())
	{
		return;
	}

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

	m_OldState = NowState;

}


