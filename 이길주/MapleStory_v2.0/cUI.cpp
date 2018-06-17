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
	UI_MGR->FirstUI(this);	
}
