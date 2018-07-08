#pragma once

#include <vector>
#include <map>

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
	float m_TotalTime = 0.0f;
	vector<float> m_Timer;

	int CurrentIndex(float _time)
	{
		for (int i = 0 ; i < m_Count; i++)
		{
			_time -= m_Timer[i];

			if (_time < 0)
			{
				return i + m_FrameStart;
			}
		}

		return -1;
	}
};

class Renderer2D
{
	GET_SET_MEMBER(int, BitmapIndex, 0);
	GET_SET_MEMBER(float, Alpha, 1.0f);
	
private:

	vector<D2D1_RECT_F>		m_ImgRTList;
	vector<ID2D1Bitmap*>    m_BitmapList;

	//Animation ¿ë
	map <int, Ani_Info>		m_AniList;
	int						m_OldState		= -1;
	float					m_CountTime		= 0.0f;

public:

	int						m_State = -1;
	bool					m_HaveBitmap = false;

public:

	Renderer2D();
	~Renderer2D();

	void Render(Matrix3x2F _mat, ID2D1RenderTarget *_pRT);

	void AddBitmap(ID2D1Bitmap* _bitmap);
	void AddBitmap_Bottom(ID2D1Bitmap* _bitmap);
	void AddBitmap_Top(ID2D1Bitmap* _bitmap);
	void AddBitmap_RighitBottom(ID2D1Bitmap* _bitmap);
	void AddBitmap_LeftBottom(ID2D1Bitmap* _bitmap);

	void ChangeBitmap(size_t _index);

	void AddAnimation(int _state, int _start, int _end, double _time, ...);
	void AddAnimation_const(int _state, int _start, int _end, float _time);

	void AniUpdate(float _DelayTime = 0.0f);

	inline void ClearBitmap()
	{
		m_BitmapList.clear();
		m_ImgRTList.clear();

		m_BitmapIndex = 0;
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