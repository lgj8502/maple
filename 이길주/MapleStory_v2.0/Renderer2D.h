#pragma once

#include <vector>

#define	GET_SET_MEMBER(type, x, init)						\
protected:											\
type	m_##x = init;										\
public:												\
type	Get##x()		{	return m_##x;	}		\
void	Set##x(type _##x) {	m_##x = _##x;		}

class Renderer2D
{
	GET_SET_MEMBER(int, BitmapIndex, 0);
	GET_SET_MEMBER(float, Alpha, 1.0f);
	
private:

	D2D1_RECT_F				m_ImgRT = {};	

	vector<ID2D1Bitmap*>    m_BitmapList;


public:

	Renderer2D();
	~Renderer2D();

	void Render(Matrix3x2F _mat, ID2D1RenderTarget *_pRT);

	void AddBitmap(ID2D1Bitmap* _bitmap);

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
		m_ImgRT = _rt;
	}
	inline D2D1_RECT_F GetImgRT()
	{
		return m_ImgRT;
	}


};