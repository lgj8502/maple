#pragma once

#include <dwrite.h>
#pragma comment(lib, "dwrite.lib")

#define BASE_FONTSIZE	5

class Text2D
{
	IDWriteFactory				*m_pWriteFactory	= nullptr;
	IDWriteTextFormat			*m_pTextFormat		= nullptr;
	IDWriteTextLayout			*m_pTextLayOut		= nullptr;

public:
	DWRITE_WORD_WRAPPING		m_WordWrap			= DWRITE_WORD_WRAPPING_NO_WRAP;
	DWRITE_TEXT_ALIGNMENT		m_WidthAlignment	= DWRITE_TEXT_ALIGNMENT_LEADING;
	DWRITE_PARAGRAPH_ALIGNMENT	m_HeightAlignment	= DWRITE_PARAGRAPH_ALIGNMENT_CENTER;

	DWRITE_TEXT_METRICS			m_Metrics = {};

public:
	Text2D();
	~Text2D();

	HRESULT		SetFont(const wchar_t *_FontName);
	VOID		TextRender(ID2D1RenderTarget *_pRT, ID2D1Brush *_pBrush, D2D1_POINT_2F _Pos, const char *_Format, ...);
	VOID		TextRender(ID2D1RenderTarget *_pRT, ID2D1Brush *_pBrush, float _Size, D2D1_POINT_2F _Pos, const char *_Format, ...);

	VOID		TextLayOut(ID2D1RenderTarget *_pRT, ID2D1Brush *_pBrush, D2D1_POINT_2F _Pos, const char *_Format, ...);
	VOID		TextLayOut(ID2D1RenderTarget *_pRT, ID2D1Brush *_pBrush, float _Size ,D2D1_POINT_2F _Pos, const char *_Format, ...);
};


