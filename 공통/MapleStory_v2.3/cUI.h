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

	// Over 용
	bool m_isMouseOver = false;
	
	//drag 용
	bool m_UseDrag = false;
	D2D1_POINT_2F m_ClickPos = {};
	bool m_isClicked = false;

	// 계층 구조용
	cUI* m_parentUI = nullptr;
	vector<cUI*> m_SonUI;

	//toggle 용
	bool m_isOn = false;


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
	vector<FUNC> m_ToggleOn;
	vector<FUNC> m_ToggleOff;

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

	void ToggleOn();
	void ToggleOff();

	D2D1_POINT_2F GetUIPos()
	{
		if (m_parentUI == nullptr)	return m_Transform.GetPos();

		D2D1_POINT_2F pos = m_parentUI->GetUIPos();

		pos.x += m_Transform.GetPos().x;
		pos.y += m_Transform.GetPos().y;

		return pos;
	}

	D2D1_POINT_2F GetUIScale()
	{
		if (m_parentUI == nullptr)	return m_Transform.GetScale();

		D2D1_POINT_2F scale = m_parentUI->GetUIScale();

		scale.x *= m_Transform.GetScale().x;
		scale.y *= m_Transform.GetScale().y;

		return scale;
	}

};

