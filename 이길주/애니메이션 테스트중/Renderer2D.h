#pragma once

#include <vector>

#define	GET_SET_MEMBER(type, x, init)						\
protected:											\
type	m_##x = init;										\
public:												\
type	Get##x()		{	return m_##x;	}		\
void	Set##x(type _##x) {	m_##x = _##x;		}

struct Ani_Info
{
	int m_FrameStart = 0;
	int m_FrameEnd = 0;
	int m_Count = 0;
	vector<float> m_Timer;
};

class Renderer2D
{
	GET_SET_MEMBER(int, BitmapIndex, 0);
	GET_SET_MEMBER(float, Alpha, 1.0f);
	
private:

	vector<D2D1_RECT_F>		m_ImgRTList;
	vector<ID2D1Bitmap*>    m_BitmapList;
	map<int, Ani_Info>		m_AniList;
	int						m_state			= -1;
	float					m_CountTime		= 0.0f;
	//int						m_StartIndex	= -1;

public:

	Renderer2D();
	~Renderer2D();

	void Render(Matrix3x2F _mat, ID2D1RenderTarget *_pRT);

	void AddBitmap(ID2D1Bitmap* _bitmap);
	void ChangeBitmap(size_t _index);

	void AddAnimation(int _state, int _start, int _end, float _time, ...);

	void AniUpdate(float _DelayTime = 0.0f);

	inline void ClearBitmap()
	{
		m_BitmapList.clear();
	}

	inline void EraseBitmap(int _index)
	{
		m_BitmapList.erase(m_BitmapList.begin() + _index);
	}

	inline void SetImgRT(D2D1_RECT_F _rt)
	{
		m_ImgRTList[m_BitmapIndex] = _rt;

	}
	inline D2D1_RECT_F GetImgRT()
	{
		return m_ImgRTList[m_BitmapIndex];
	}


};