#pragma once


class cUI : public Object2D 
{

public:

	// UI 오브젝트 이름
	string m_Name = "";

	// UI 종류
	int m_Type = -1;

	// 레이캐스트 가능 여부
	bool m_RayCast = true;	

	// 활성화/비활성화
	bool m_isActive = true;

	// UI_TEXT 용
	Text2D m_Font;
	string m_Text = "";
	float m_FontSize = 20.0f;
	D2D1_COLOR_F m_FontColor = ColorF(ColorF::White);
	wstring m_FontName = L"고딕";

public:
	cUI();
	~cUI();

	// UI_TEXT 용
	void TextRender();

	void OnMouseDown();
	void OnMouseUp();
	void OnMouseOver();
	void OnMouseDrag();


};

