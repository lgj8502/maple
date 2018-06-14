#pragma once

#include "TemplateSingleton.h"
#include <map>

struct ImgInfo
{
	wstring m_Name;
	wstring m_Path;
	ID2D1Bitmap *m_Bitmap = nullptr;
};

class ImageMgr : public TemplateSingleton<ImageMgr>
{
	BASESET(ImageMgr);

private :

	map<wstring, ImgInfo>	m_Imglist;

	IWICImagingFactory		*m_pIWICFactory = nullptr;
	IWICFormatConverter		*m_pConvertedSourceBitmap = nullptr;

	D2D1_RECT_F				m_ImgRT = {};

	ID2D1RenderTarget	*m_pRT = nullptr;

private:


	BOOL AddImg(LPCWSTR _FilePath);

	ID2D1Bitmap *ImageAsBitmap(LPCWSTR _FilePath);

	Matrix3x2F		m_matSRT = Matrix3x2F::Identity();

public:

	~ImageMgr();

	void Init(ID2D1RenderTarget *_pRT);

	void FileFindDir(wstring _Path);



	inline ID2D1Bitmap				*GetImage(wstring _bitmapName)
	{
		return m_Imglist[_bitmapName].m_Bitmap;
	}


	inline ID2D1RenderTarget	*GetRT()
	{
		return m_pRT;
	}

	
	VOID RendRect(wstring _bitmapName);
	VOID RendRect(wstring _bitmapName, D2D1_RECT_F _rt);
	
};

#define IMG_MGR	ImageMgr::GetInstance()