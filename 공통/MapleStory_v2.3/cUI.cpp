#include "stdafx.h"
#include "cUI.h"


cUI::cUI()
{
}


cUI::~cUI()
{
}

void cUI::TextRender()
{
	if (m_isActive == false)
	{
		return;
	}

	D2D1_COLOR_F oldColor = IMG_MGR->GetBrush()->GetColor();

	IMG_MGR->GetBrush()->SetColor(m_FontColor);

	if (m_Transform.m_pParent != nullptr)
	{
		D2D1_POINT_2F pos = m_Transform.m_pParent->GetPos();

		pos.x += m_Transform.GetPos().x;
		pos.y += m_Transform.GetPos().y;

		m_Font.TextRender(m_pRT, IMG_MGR->GetBrush(), m_FontSize, pos, m_Text.c_str());
	}
	else
	{
		m_Font.TextRender(m_pRT, IMG_MGR->GetBrush(), m_FontSize, m_Transform.GetPos(), m_Text.c_str());
	}	

	IMG_MGR->GetBrush()->SetColor(oldColor);
}

void cUI::OnMouseDown()
{

	if (m_RayCast == false)	return;

	m_isClicked = true;


	UI_MGR->DrawFirst(this);


	for (auto &i : m_OnMouseDown)
	{
		i();
	}

	m_ClickPos = m_Transform.GetPos();

	m_ClickPos.x -= (float)UI_MGR->GetMousePoint().x;
	m_ClickPos.y -= (float)UI_MGR->GetMousePoint().y;
}

void cUI::OnMouseUp()
{
	if (m_RayCast == false)	return;

	m_isClicked = false;

	for (auto &i : m_OnMouseUp)
	{
		i();
	}
}

void cUI::OnMouseClick()
{
	if (m_RayCast == false)	return;

	m_isClicked = false;

	for (auto &i : m_OnMouseClick)
	{
		i();
	}
}

void cUI::OnMouseOver()
{
	if (m_RayCast == false)	return;

	if (m_isMouseOver == true) return;

	m_isMouseOver = true;

	for (auto &i : m_OnMouseOver)
	{
		i();
	}
}

void cUI::OnMouseExit()
{
	if (m_RayCast == false)	return;

	if (m_isMouseOver == false) return;

	m_isMouseOver = false;

	for (auto &i : m_OnMouseExit)
	{
		i();
	}
}

void cUI::OnMouseDrag()
{
	if (m_RayCast == false)	return;
	if (m_isClicked == false)	return;
	if (m_CanDrag == false)	return;

	POINT moustPos = UI_MGR->GetMousePoint();

	float x = (float)moustPos.x + m_ClickPos.x;
	float y = (float)moustPos.y + m_ClickPos.y;

	m_Transform.SetPos(x, y);

	for (auto &i : m_OnMouseDrag)
	{
		i();
	}
}
