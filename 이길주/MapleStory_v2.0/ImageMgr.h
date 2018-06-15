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

private:


	BOOL AddImg(LPCWSTR _FilePath);

	ID2D1Bitmap *ImageAsBitmap(LPCWSTR _FilePath);


public:

	~ImageMgr();

	void Init(ID2D1RenderTarget *_pRT);

	void FileFindDir(wstring _Path);

	ID2D1Bitmap *GetImage(wstring _bitmapName);


	inline ID2D1RenderTarget* GetpRT()
	{
		return m_pRT;
	}
};

#define IMG_MGR	ImageMgr::GetInstance()