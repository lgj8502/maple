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
	if (m_isActive == false) return;

	D2D1_COLOR_F oldColor = IMG_MGR->GetBrush()->GetColor();

	IMG_MGR->GetBrush()->SetColor(m_FontColor);

	D2D1_POINT_2F pos = {};

	pos = m_Transform.GetPos();

	if (m_parentUI != nullptr)
	{
		pos.x /= m_parentUI->m_Transform.m_matSRT.m11;
		pos.y /= m_parentUI->m_Transform.m_matSRT.m22;
	}

	if (m_Type == UI_INPUTFIELD )
	{

		pos.x = m_Renderer.GetImgRT().left + 5 + (m_SonUI[0]->m_Font.m_Metrics.width);
		pos.y = 0;

	}

	m_Font.TextLayOut(m_pRT, IMG_MGR->GetBrush(), m_FontSize, pos, m_Text.c_str());		

	IMG_MGR->GetBrush()->SetColor(oldColor);
}

void cUI::AddUpdate()
{
	for (auto &i : m_Update)
	{
		i();
	}
}

void cUI::OnMouseDown()
{
	if (m_isActive == false) return;
	if (m_RayCast == false)	return;

	m_isClicked = true;

	UI_MGR->DrawFirst(this);

	if (m_Type == UI_INPUTFIELD)
	{
		UI_MGR->m_InputFiled = this;
		return;
	}
	else
	{
		if (UI_MGR->m_InputFiled != nullptr)
		{
			UI_MGR->m_InputFiled->m_FontColor.a = 0.0f;

			UI_MGR->m_InputFiled = nullptr;
		}
		
	}

	if (m_Type == UI_TOGGLE)
	{
		if (m_isOn == true)
		{
			ToggleOn();
			return;
		}
	}


	m_ClickPos = m_Transform.GetPos();


	if (m_parentUI != nullptr)
	{
		m_ClickPos.x *= m_parentUI->m_Transform.m_matSRT.m11;
		m_ClickPos.y *= m_parentUI->m_Transform.m_matSRT.m22;
	}

	m_ClickPos.x -= (float)UI_MGR->GetMousePoint().x;
	m_ClickPos.y -= (float)UI_MGR->GetMousePoint().y;

	

	if (m_Type == UI_SCROLLBAR)
	{
		D2D1_POINT_2F sonPos = m_SonUI[0]->m_Transform.GetPos();

		float posY = m_SonUI[0]->m_Transform.m_matSRT.dy;

		if (posY - (float)UI_MGR->GetMousePoint().y > 0)
		{
			m_Value -= 0.3f;

			if (m_Value < 0.0f)
			{
				m_Value = 0.0f;
			}
		}
		else
		{
			m_Value += 0.3f;

			if (m_Value > 1.0f)
			{
				m_Value = 1.0f;
			}
		}
		sonPos.y = m_SonUI[0]->m_MinPos + (m_SonUI[0]->m_MaxPos * 2.0f) * m_Value;
		m_SonUI[0]->m_Transform.SetPos(sonPos);
	}



	for (auto &i : m_OnMouseDown)
	{
		i();
	}

}

void cUI::OnMouseUp()
{
	if (m_isActive == false) return;
	if (m_RayCast == false)	return;

	m_isClicked = false;

	for (auto &i : m_OnMouseUp)
	{
		i();
	}
}

void cUI::OnMouseClick()
{

	if (m_isActive == false) return;
	if (m_RayCast == false)	return;

	m_isClicked = false;

	for (auto &i : m_OnMouseClick)
	{
		i();
	}

}

void cUI::OnMouseOver()
{

	if (m_isActive == false) return;
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

	if (m_isActive == false) return;
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

	if (m_isActive == false) return;
	if (m_RayCast == false)	return;
	if (m_isClicked == false)	return;
	if (m_UseDrag == false)	return;

	POINT mousePos = UI_MGR->GetMousePoint();


	float y = (float)mousePos.y + m_ClickPos.y;

	if (m_parentUI != nullptr)
	{
		y /= m_parentUI->m_Transform.m_matSRT.m22;
	}


	if (m_Type == UI_SCROLLBAR_HANDLE)
	{
		float x = m_Transform.GetPos().x;

		if (y < m_MinPos)
		{
			y = m_MinPos;
		}

		if (y > m_MaxPos)
		{
			y = m_MaxPos;
		}
		m_Transform.SetPos(x, y);		

		m_parentUI->m_Value = (y + m_MaxPos) / (m_MaxPos * 2.0f);

	}
	else
	{
		float x = (float)mousePos.x + m_ClickPos.x;

		if (m_parentUI != nullptr)
		{
			x /= m_parentUI->m_Transform.m_matSRT.m11;
		}

		m_Transform.SetPos(x, y);
	}

	for (auto &i : m_OnMouseDrag)
	{
		i();
	}
}

void cUI::ToggleOn()
{
	if (m_parentUI != nullptr)
	{
		if (m_parentUI->m_isActive == false) return;
	}
	for (auto &i : m_ToggleOn)
	{
		i();
	}
}

void cUI::ToggleOff()
{
	if (m_parentUI != nullptr)
	{
		if (m_parentUI->m_isActive == false) return;
	}
	for (auto &i : m_ToggleOff)
	{
		i();
	}
}
