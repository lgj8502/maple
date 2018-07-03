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

	map<wstring, ImgInfo>	m_Imglist;

	IWICImagingFactory		*m_pIWICFactory = nullptr;
	IWICFormatConverter		*m_pConvertedSourceBitmap = nullptr;

	ID2D1RenderTarget	*m_pRT = nullptr;
	ID2D1SolidColorBrush *m_pBrush = nullptr;

private:


	BOOL AddImg(LPCWSTR _FilePath);

	BOOL AddImg(LPCWSTR _FilePath, map<wstring, ImgInfo> &_Imglist);

	ID2D1Bitmap *ImageAsBitmap(LPCWSTR _FilePath);


public:

	~ImageMgr();

	void Init(ID2D1RenderTarget *_pRT);

	void FileFindDir(wstring _Path);
	void FileFindDir_Take(wstring _Path, map<wstring, ImgInfo> &_Imglist);

	inline void ClearImgList()
	{
		m_Imglist.clear();
	}

	inline void SetBrush(ID2D1SolidColorBrush *_pBrush)
	{
		m_pBrush = _pBrush;
	}
	inline ID2D1SolidColorBrush* GetBrush()
	{
		return m_pBrush;
	}

	inline ID2D1Bitmap *GetImage(wstring _bitmapName)
	{
		return m_Imglist[_bitmapName].m_Bitmap;
	}

	inline ID2D1RenderTarget* GetpRT()
	{
		return m_pRT;
	}
};

#define IMG_MGR	ImageMgr::GetInstance()