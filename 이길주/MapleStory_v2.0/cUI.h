#pragma once

typedef void(*FUNC)();

class cUI : public Object2D 
{

public:

	// UI ������Ʈ �̸�
	string m_Name = "";

	// UI ����
	int m_Type = -1;

	// ����ĳ��Ʈ ���� ����
	bool m_RayCast = true;	

	// Ȱ��ȭ/��Ȱ��ȭ
	bool m_isActive = true;

	bool m_isClicked = false;
	bool m_isMouseOver = false;

	// UI_TEXT ��
	Text2D m_Font;
	string m_Text = "";
	float m_FontSize = 20.0f;
	D2D1_COLOR_F m_FontColor = ColorF(ColorF::White);
	wstring m_FontName = L"���";

	vector<FUNC> m_OnMouseDown;
	vector<FUNC> m_OnMouseUp;
	vector<FUNC> m_OnMouseClick;
	vector<FUNC> m_OnMouseOver;

public:
	cUI();
	~cUI();

	// UI_TEXT ��
	void TextRender();

	void OnMouseDown();
	void OnMouseUp();
	void OnMouseClick();
	void OnMouseOver();



};

