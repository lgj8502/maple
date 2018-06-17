#pragma once


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

	// UI_TEXT ��
	Text2D m_Font;
	string m_Text = "";
	float m_FontSize = 20.0f;
	D2D1_COLOR_F m_FontColor = ColorF(ColorF::White);
	wstring m_FontName = L"���";

public:
	cUI();
	~cUI();

	// UI_TEXT ��
	void TextRender();

	void OnMouseDown();
	void OnMouseUp();
	void OnMouseOver();
	void OnMouseDrag();


};

