#include "stdafx.h"
#include "Text2D.h"



Text2D::Text2D()
{
	HRESULT hr = S_OK;

	hr = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED, __uuidof(m_pWriteFactory), (IUnknown**)(&m_pWriteFactory));

	if (FAILED(hr))
	{
		MessageBoxA(nullptr, "쓰기팩토리생성 실패", "오류", MB_OK);
	}
}

Text2D::~Text2D()
{
	SafeRelease(m_pTextFormat);
	SafeRelease(m_pWriteFactory);
}

HRESULT Text2D::SetFont(const wchar_t *_FontName)
{
	HRESULT hr = S_OK;

	if (m_pWriteFactory == nullptr)
	{
		MessageBoxA(nullptr, "폰트팩토리 nullptr", "오류", MB_OK);
		return E_FAIL;
	}

	SafeRelease(m_pTextFormat);

	hr = m_pWriteFactory->CreateTextFormat(
		_FontName,
		nullptr,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		BASE_FONTSIZE,
		L"",
		&m_pTextFormat);

	return hr;
}

VOID Text2D::TextRender(ID2D1RenderTarget * _pRT, ID2D1Brush *_pBrush, D2D1_POINT_2F _Pos, const char *_Format, ...)
{
	char Buf[256] = "";

	va_list ap;
	va_start(ap, _Format);

	vsprintf_s(Buf, 256, _Format, ap);

	va_end(ap);

	wchar_t wBuf[256] = L"";

	// 멀티바이트를 와이드캐릭터로 바꾸기
	MultiByteToWideChar(
		CP_ACP,				//	코드정보( ASCII )	
		0,					//	옵션
		Buf,				//	변환할 문자열
		strlen(Buf),		//	변환할 문자열의 길이
		wBuf,				//	받을 문자열
		256);				//	받을 문자열배열의 크기

	/////////////////////////////////////////////////////////
	
	Matrix3x2F	Old;
	_pRT->GetTransform(&Old);

	_pRT->SetTransform(Matrix3x2F::Translation(_Pos.x, _Pos.y));

	m_pTextFormat->SetWordWrapping(m_WordWrap);
	m_pTextFormat->SetTextAlignment(m_WidthAlignment);
	m_pTextFormat->SetParagraphAlignment(m_HeightAlignment);

	_pRT->DrawTextA(
		wBuf,
		lstrlenW(wBuf),
		m_pTextFormat,
		RectF(),
		_pBrush);

	_pRT->SetTransform(Old);
}

VOID Text2D::TextRender(ID2D1RenderTarget * _pRT, ID2D1Brush * _pBrush, float _Size, D2D1_POINT_2F _Pos, const char * _Format, ...)
{
	char Buf[256] = "";

	va_list ap;
	va_start(ap, _Format);

	vsprintf_s(Buf, 256, _Format, ap);

	va_end(ap);

	wchar_t wBuf[256] = L"";

	// 멀티바이트를 와이드캐릭터로 바꾸기
	MultiByteToWideChar(
		CP_ACP,				//	코드정보( ASCII )	
		0,					//	옵션
		Buf,				//	변환할 문자열
		strlen(Buf),		//	변환할 문자열의 길이
		wBuf,				//	받을 문자열
		256);				//	받을 문자열배열의 크기

							/////////////////////////////////////////////////////////

	Matrix3x2F	Old;
	_pRT->GetTransform(&Old);

	float Scale = _Size / BASE_FONTSIZE;

	_pRT->SetTransform(Matrix3x2F::Scale(Scale, Scale+1) * Matrix3x2F::Translation(_Pos.x, _Pos.y));


	m_pTextFormat->SetWordWrapping(m_WordWrap);
	m_pTextFormat->SetTextAlignment(m_WidthAlignment);
	m_pTextFormat->SetParagraphAlignment(m_HeightAlignment);

	_pRT->DrawTextA(
		wBuf,
		lstrlenW(wBuf),
		m_pTextFormat,
		RectF(),
		_pBrush);

	_pRT->SetTransform(Old);
}
