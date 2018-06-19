#pragma once

typedef void(*FUNC)();

class cUI : public Object2D 
{

public:

	// UI 오브젝트 이름
	string m_Name = "";

	// UI 종류
	int m_Type = -1;

	// 레이캐스트 가능 여부
	bool m_RayCast = false;	

	// 활성화/비활성화
	bool m_isActive = true;

	bool m_isClicked = false;
	bool m_isMouseOver = false;
	
	//drag 용
	bool m_CanDrag = false;
	D2D1_POINT_2F m_ClickPos = {};

	cUI* m_parentUI = nullptr;
	cUI* m_SonUI = nullptr;

	// UI_TEXT 용
	Text2D m_Font;
	string m_Text = "";
	float m_FontSize = 20.0f;
	D2D1_COLOR_F m_FontColor = ColorF(ColorF::White);
	wstring m_FontName = L"고딕";

	vector<FUNC> m_OnMouseDown;
	vector<FUNC> m_OnMouseUp;
	vector<FUNC> m_OnMouseClick;
	vector<FUNC> m_OnMouseOver;
	vector<FUNC> m_OnMouseExit;
	vector<FUNC> m_OnMouseDrag;


public:
	cUI();
	~cUI();

	// UI_TEXT 용
	void TextRender();

	void OnMouseDown();
	void OnMouseUp();
	void OnMouseClick();
	void OnMouseOver();
	void OnMouseExit();
	void OnMouseDrag();



};

