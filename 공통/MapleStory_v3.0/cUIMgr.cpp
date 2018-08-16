#include "stdafx.h"
#include "cUIMgr.h"


cUIMgr::~cUIMgr()
{
	Destroy();
}

bool cUIMgr::RayCastCheck(POINT _Ray, D2D1_RECT_F _object)
{
	if (_Ray.x > _object.left && _Ray.x < _object.right &&
		_Ray.y < _object.bottom && _Ray.y > _object.top)
	{
		return true;
	}

	return false;
}


void cUIMgr::Destroy()
{
	for (auto &i : m_UIList)
	{		
		i = {};
		delete i;
		i = nullptr;
	}
	m_UIList.clear();

	VectorClear(m_HP);
	VectorClear(m_HPmax);
	VectorClear(m_MP);
	VectorClear(m_MPmax);
	VectorClear(m_Level);
	VectorClear(m_Exp);
	VectorClear(m_UsetemCount);


}



cUI * cUIMgr::FindUI(string _name)
{
	for (auto &i : m_UIList)
	{
		if (i->m_Name == _name)
		{
			return i;
		}
	}

	return nullptr;
}

void cUIMgr::DeleteUI(cUI * _delUI)
{
	if (_delUI == nullptr)
	{
		MK_LOG("DeleteUI ����");
	}

	m_UIList.remove(_delUI);

	delete _delUI;
	_delUI = nullptr;

}

void cUIMgr::DrawFirst(cUI * _fSTui)
{

	cUI* UI = FindParent(_fSTui);
	vector<cUI*> temp;

	for (auto &i : m_UIList)
	{
		if (FindParent(i) == UI)
		{
			temp.push_back(i);	
		}
	}

	for (auto &i : temp)
	{
		m_UIList.remove(i);
	}

	for (auto &i : temp)
	{
		m_UIList.push_back(i);
	}

	temp.clear();

}


cUI * cUIMgr::FirstUI()
{
	cUI* UI = m_UIList.back();

	return FindParent(UI);
	
}

cUI * cUIMgr::FindParent(cUI *UI)
{
	if (UI->m_parentUI != nullptr)
	{
		return FindParent(UI->m_parentUI);
	}

	return UI;
}

void cUIMgr::BitMapAdd(string _name, wstring _bitmapName)
{
	cUI* UI = FindUI(_name);

	if (UI == nullptr)
	{
		MK_LOG("BitMapAdd ����");
	}

	UI->m_Renderer.AddBitmap(IMG_MGR->GetImage(_bitmapName));
}

void cUIMgr::BitMapAdd(string _name, ID2D1Bitmap * _pBitmap)
{
	cUI* UI = FindUI(_name);

	if (UI == nullptr)
	{
		MK_LOG("BitMapAdd ����");
	}

	UI->m_Renderer.AddBitmap(_pBitmap);
}

void cUIMgr::BitMapDel(string _name)
{
	cUI* UI = FindUI(_name);

	UI->m_Renderer.DelLastBitmap();
}

void cUIMgr::OnMouseDown(POINT _mousePos)
{
	list<cUI*>::reverse_iterator Iter;

	for (Iter = m_UIList.rbegin(); Iter != m_UIList.rend(); Iter++)
	{
		cUI* UI = (*Iter);

		if (UI->m_RayCast == false) continue;
		if (FindParent(UI)->m_isActive == false) continue;

		D2D1_RECT_F rect = UI->m_Renderer.GetImgRT();
		D2D1_POINT_2F Scale = UI->GetUIScale();

		float posX = UI->m_Transform.m_matSRT.dx;
		float posY = UI->m_Transform.m_matSRT.dy;

		rect.left	= rect.left		*	Scale.x  + posX;
		rect.right	= rect.right	*	Scale.x  + posX;
		rect.bottom = rect.bottom   *	Scale.y  + posY;
		rect.top	= rect.top		*	Scale.y  + posY;

		if (RayCastCheck(_mousePos, rect) == false) continue;
		
		// Toggle �̶��
		if (UI->m_Type == UI_TOGGLE)
		{
			if (UI->m_isOn == true)
			{
				if (UI->m_parentUI != nullptr)
				{
					if (UI->m_parentUI->m_Type == UI_TOGGLEGROUP) return;
				}				

				UI->m_isOn = false;
				UI->OnMouseDown();
			}
			else
			{
				UI->m_isOn = true;

				cUI* parent = UI->m_parentUI;

				if (parent != nullptr)
				{
					if (parent->m_Type == UI_TOGGLEGROUP)
					{
						for (auto &i : parent->m_SonUI)
						{
							if (i == UI) continue;

							if (i->m_isOn == true)
							{
								i->m_isOn = false;
								i->ToggleOff();
							}
						}

						UI->OnMouseDown();
						return;
					}
				}


				UI->OnMouseDown();
			}
			
			return;
		}

		m_ClickedUI = UI;
		UI->OnMouseDown();

		return;		
	}

	if (m_isChating == true)
	{
		//m_InputFiled->m_FontColor.a = 0.0f;
		m_isChating = false;
	}

}

void cUIMgr::OnMouseUp(POINT _mousePos)
{
	if (m_ClickedUI == nullptr) return;

	m_ClickedUI->m_isClicked = false;

	list<cUI*>::reverse_iterator Iter;

	for (Iter = m_UIList.rbegin(); Iter != m_UIList.rend(); Iter++)
	{

		cUI* UI = (*Iter);

		if (UI->m_RayCast == false) continue;
		if (FindParent(UI)->m_isActive == false) continue;

		D2D1_RECT_F rect = UI->m_Renderer.GetImgRT();
		D2D1_POINT_2F Scale = UI->GetUIScale();

		float posX = UI->m_Transform.m_matSRT.dx;
		float posY = UI->m_Transform.m_matSRT.dy;

		rect.left = rect.left		*	Scale.x + posX;
		rect.right = rect.right	*	Scale.x + posX;
		rect.bottom = rect.bottom   *	Scale.y + posY;
		rect.top = rect.top		*	Scale.y + posY;


		if (RayCastCheck(_mousePos, rect) == true)
		{

			UI->OnMouseClick();

			return;
		}
		else
		{
			UI->OnMouseUp();
		}
	}
}

void cUIMgr::OnMouseOver(POINT _mousePos)
{
	m_MosuePoint = _mousePos;

	list<cUI*>::reverse_iterator Iter;

	for (Iter = m_UIList.rbegin(); Iter != m_UIList.rend(); Iter++)
	{
		cUI* UI = (*Iter);

		if (UI->m_RayCast == false) continue;
		if (FindParent(UI)->m_isActive == false) continue;

		D2D1_RECT_F rect = UI->m_Renderer.GetImgRT();
		D2D1_POINT_2F Scale = UI->GetUIScale();

		float posX = UI->m_Transform.m_matSRT.dx;
		float posY = UI->m_Transform.m_matSRT.dy;

		rect.left = rect.left		*	Scale.x + posX;
		rect.right = rect.right	*	Scale.x + posX;
		rect.bottom = rect.bottom   *	Scale.y + posY;
		rect.top = rect.top		*	Scale.y + posY;


		if (RayCastCheck(_mousePos, rect) == true)
		{		

			UI->OnMouseOver();

			return;
		}
	}
}

void cUIMgr::OnMouseDrag(POINT _mousePos)
{
	m_MosuePoint = _mousePos;

	list<cUI*>::reverse_iterator Iter;

	for (Iter = m_UIList.rbegin(); Iter != m_UIList.rend(); Iter++)
	{

		if ((*Iter)->m_UseDrag == false) continue;

		if ((*Iter)->m_RayCast == false) continue;

		if ((*Iter)->m_isClicked == false) continue;

		(*Iter)->OnMouseDrag();

		return;

	}
}

void cUIMgr::OnMouseExit(POINT _mousePos)
{
	list<cUI*>::reverse_iterator Iter;

	for (Iter = m_UIList.rbegin(); Iter != m_UIList.rend(); Iter++)
	{

		cUI* UI = (*Iter);

		if (UI->m_RayCast == false) continue;
		if (FindParent(UI)->m_isActive == false) continue;

		D2D1_RECT_F rect = UI->m_Renderer.GetImgRT();
		D2D1_POINT_2F Scale = UI->GetUIScale();

		float posX = UI->m_Transform.m_matSRT.dx;
		float posY = UI->m_Transform.m_matSRT.dy;

		rect.left = rect.left		*	Scale.x + posX;
		rect.right = rect.right	*	Scale.x + posX;
		rect.bottom = rect.bottom   *	Scale.y + posY;
		rect.top = rect.top		*	Scale.y + posY;

		if (RayCastCheck(_mousePos, rect) == false && (*Iter)->m_isMouseOver == true)
		{
			UI->OnMouseExit();

			return;
		}
	}
}

void cUIMgr::AddEvent(string _name, eEvent_Type _Type, FUNC _func)
{
	if (FindUI(_name) == nullptr)
	{
		MK_LOG("����Ʈ�� �̸� ����: SetFunc ����");
		return;
	}

	switch (_Type)
	{
	case ADDEVENT_OnMouseDown:		FindUI(_name)->m_OnMouseDown.push_back(_func);
		break;
	case ADDEVENT_OnMouseUP:		FindUI(_name)->m_OnMouseUp.push_back(_func);
		break;
	case ADDEVENT_OnMouseClick:		FindUI(_name)->m_OnMouseClick.push_back(_func);
		break;
	case ADDEVENT_OnMouseOver:     FindUI(_name)->m_OnMouseOver.push_back(_func);
		break;
	case ADDEVENT_OnMouseExit:		FindUI(_name)->m_OnMouseExit.push_back(_func);
		break;
	case ADDEVENT_OnMouseDrag:     FindUI(_name)->m_OnMouseDrag.push_back(_func);
		break;
	case ADDEVENT_ToggleOn :		FindUI(_name)->m_ToggleOn.push_back(_func);
		break;
	case ADDEVENT_ToggleOff:		FindUI(_name)->m_ToggleOff.push_back(_func);
		break;
	case ADDEVENT_Update:		    FindUI(_name)->m_Update.push_back(_func);
		break;

	default: 
	{
		MK_LOG("���� �̺�Ʈ Ÿ�� : AddEvent ����"); 
		return;
	}
		break;
	}
}




void cUIMgr::SetParent(string _Parent, string _Son)
{
	cUI *ParentUI = FindUI(_Parent);
	cUI *SonUI = FindUI(_Son);

	if (ParentUI == nullptr || SonUI == nullptr)
	{
		MK_LOG("SetParent ����");

		MK_LOG("%s, %s", _Parent, _Son);


		return;
	}	

	vector<cUI*> temp;

	temp.push_back(ParentUI);
	temp.push_back(SonUI);

	m_UIList.remove(ParentUI);
	m_UIList.remove(SonUI);

	for (auto &i : m_UIList)
	{
		if (FindParent(i) == ParentUI)
		{
			temp.push_back(i);
		}
	}

	for (auto &i : m_UIList)
	{
		if (FindParent(i) == SonUI)
		{
			temp.push_back(i);
		}
	}

	for (auto &i : temp)
	{
		m_UIList.remove(i);
	}

	for (auto &i : temp)
	{
		m_UIList.push_back(i);
	}

	temp.clear();

	SonUI->m_parentUI = ParentUI;
	ParentUI->m_SonUI.push_back(SonUI);

	SonUI->m_Transform.m_pParent = &(ParentUI->m_Transform);

}

void cUIMgr::SetParent(cUI * _Parent, cUI * _Son)
{
	if (_Parent == nullptr || _Son == nullptr)
	{
		MK_LOG("SetParent ����");

		return;
	}



	vector<cUI*> temp;

	temp.push_back(_Parent);
	temp.push_back(_Son);

	m_UIList.remove(_Parent);
	m_UIList.remove(_Son);

	for (auto &i : m_UIList)
	{
		if (FindParent(i) == _Parent)
		{
			temp.push_back(i);
		}
	}

	for (auto &i : m_UIList)
	{
		if (FindParent(i) == _Son)
		{
			temp.push_back(i);
		}
	}

	for (auto &i : temp)
	{
		m_UIList.remove(i);
	}

	for (auto &i : temp)
	{
		m_UIList.push_back(i);
	}

	temp.clear();

	_Son->m_parentUI = _Parent;
	_Parent->m_SonUI.push_back(_Son);

	_Son->m_Transform.m_pParent = &(_Parent->m_Transform);

}

void cUIMgr::AddText(string _name, string _text, D2D1_POINT_2F _pos, D2D1_COLOR_F _FontColor, wstring _FontName,
	                 float _FontSize, bool _isActive, bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");

		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_TEXT;
	UI->m_Name = _name;
	UI->m_Text = _text;
	UI->m_FontSize = _FontSize;
	UI->m_FontColor = _FontColor;
	UI->m_FontName = _FontName;
	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;


	UI->m_Font.SetFont(UI->m_FontName.c_str());


	UI->m_Transform.SetPos(_pos);

	m_UIList.push_back(UI);
}

void cUIMgr::AddImage(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale, float _alpha, bool _isActive, bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");

		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_IMAGE;
	UI->m_Name = _name;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	UI->m_Renderer.AddBitmap(AddBitmap);

	UI->m_Transform.SetScale(_scale.x, _scale.y);
	UI->m_Transform.SetPos(_pos);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;


	m_UIList.push_back(UI);
}

void cUIMgr::AddImage(string _name, wstring _bitmapName, D2D1_RECT_F _rect, float _alpha, bool _isActive, bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");

		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_IMAGE;
	UI->m_Name = _name;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);


	UI->m_Renderer.AddBitmap(AddBitmap);
	UI->m_Renderer.SetImgRT(_rect);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;


	m_UIList.push_back(UI);
}

void cUIMgr::AddButton(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale, float _alpha, bool _isActive, bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");

		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_BUTTON;
	UI->m_Name = _name;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	UI->m_Renderer.AddBitmap(AddBitmap);

	UI->m_Transform.SetScale(_scale.x, _scale.y);
	UI->m_Transform.SetPos(_pos);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;


	m_UIList.push_back(UI);
}

void cUIMgr::AddButton(string _name, wstring _bitmapName, D2D1_RECT_F _rect, float _alpha, bool _isActive, bool _isRayCast)
{

	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");
		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_BUTTON;
	UI->m_Name = _name;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	UI->m_Renderer.AddBitmap(AddBitmap);
	UI->m_Renderer.SetImgRT(_rect);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;


	m_UIList.push_back(UI);
}

void cUIMgr::AddToggle(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale, float _alpha, bool _isActive , bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");
		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_TOGGLE;
	UI->m_Name = _name;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	UI->m_Renderer.AddBitmap(AddBitmap);

	UI->m_Transform.SetScale(_scale.x, _scale.y);
	UI->m_Transform.SetPos(_pos);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;


	m_UIList.push_back(UI);
}

void cUIMgr::AddToggle(string _name, wstring _bitmapName, D2D1_RECT_F _rect, float _alpha, bool _isActive, bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");
		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_TOGGLE;
	UI->m_Name = _name;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	UI->m_Renderer.AddBitmap(AddBitmap);
	UI->m_Renderer.SetImgRT(_rect);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;


	m_UIList.push_back(UI);
}





void cUIMgr::AddToggleGroup(string _name, D2D1_POINT_2F _pos, int _count, cUI* _pUI, ...)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");
		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_TOGGLEGROUP;
	UI->m_Name = _name;
	UI->m_Transform.SetPos(_pos);

	m_UIList.push_back(UI);

	va_list arglist;
	va_start(arglist, _count);

	for (int i = 0; i < _count; i++)
	{
		SetParent(UI, va_arg(arglist, cUI*));
	}

	va_end(arglist);


}

void cUIMgr::AddScrollBar(string _name, wstring _barBitmap, wstring _handleBitmap, D2D1_POINT_2F _pos, float _value, D2D1_POINT_2F _scale, float _alpha, bool _isActive, bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");
		return;
	}
	
	cUI *UI = new cUI;

	UI->m_Type = UI_SCROLLBAR;
	UI->m_Name = _name;
	
	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_barBitmap);

	UI->m_Renderer.AddBitmap(AddBitmap);

	UI->m_Transform.SetScale(_scale.x, _scale.y);
	UI->m_Transform.SetPos(_pos);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;

	UI->m_Value = _value;	
	UI->m_OldValue = _value;

	cUI *UI_handle = new cUI;

	UI_handle->m_Type = UI_SCROLLBAR_HANDLE;
	UI_handle->m_Name = _name + "_H";

	AddBitmap = IMG_MGR->GetImage(_handleBitmap);

	UI_handle->m_Renderer.AddBitmap(AddBitmap);

	D2D1_RECT_F rectBar = UI->m_Renderer.GetImgRT();

	D2D1_RECT_F rectHandle = UI_handle->m_Renderer.GetImgRT();	

	float maxRange = (rectBar.bottom - rectHandle.bottom) * 2.0f ;

	float pos =  -maxRange * (0.5f - _value);

	UI_handle->m_MinPos = -maxRange * 0.5f;
	UI_handle->m_MaxPos = maxRange * 0.5f;

	UI_handle->m_Transform.SetPos({0, pos});

	UI_handle->m_RayCast = true;
	UI_handle->m_UseDrag = true;

	SetParent(UI, UI_handle);

}

void cUIMgr::AddInputField(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale, D2D1_COLOR_F _FontColor, wstring _FontName,
	                       float _alpha, float _FontSize, bool _isActive, bool _isRayCast)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");
		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_INPUTFIELD;
	UI->m_Name = _name;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	UI->m_Renderer.AddBitmap(AddBitmap);

	UI->m_Transform.SetScale(_scale.x, _scale.y);
	UI->m_Transform.SetPos(_pos);
	UI->m_Renderer.SetAlpha(_alpha);

	UI->m_isActive = _isActive;
	UI->m_RayCast = _isRayCast;

	UI->m_Text = "l";
	UI->m_FontSize = _FontSize;
	UI->m_FontColor = ColorF(1,1,1,0);
	UI->m_FontName = _FontName;
	UI->m_Font.SetFont(UI->m_FontName.c_str());

	m_UIList.push_back(UI);

	cUI *UI_Text = new cUI;

	UI_Text->m_Type = UI_TEXT;
	UI_Text->m_Name = _name + "_S";
	UI_Text->m_Text = "";
	UI_Text->m_FontSize = _FontSize;
	UI_Text->m_FontColor = _FontColor;
	UI_Text->m_FontName = _FontName;


	UI_Text->m_Font.SetFont(UI_Text->m_FontName.c_str());

	UI_Text->m_Transform.SetPos((UI->m_Renderer.GetImgRT().left) * _scale.x + 10, 0);

	m_UIList.push_back(UI_Text);


	SetParent(UI, UI_Text);
}

void cUIMgr::AddPanel(string _name, D2D1_POINT_2F _pos,  int _count, cUI* _pUI, ...)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");

		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_PANEL;
	UI->m_Name = _name;

	UI->m_Transform.SetPos(_pos);

	UI->m_RayCast = false;

	m_UIList.push_back(UI);

	va_list arglist;
	va_start(arglist, _count);

	for (int i = 0; i < _count; i++)
	{
		SetParent(UI, va_arg(arglist, cUI*));
	}

	va_end(arglist);


}

void cUIMgr::AddAnimation(string _name, D2D1_POINT_2F _pos, float _time, vector<wstring> _bitmapList)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI �̸� �ߺ� : UI ���� ����");

		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_IMAGE;
	UI->m_Name = _name;

	UI->m_Transform.SetPos(_pos);

	for (size_t i = 0; i < _bitmapList.size(); i++)
	{
		ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapList[i]);

		UI->m_Renderer.AddBitmap(AddBitmap);
	}


	UI->m_Renderer.m_State = 0;

	UI->m_Renderer.AddAnimation_const(0, 0, _bitmapList.size() - 1, _time);

	m_UIList.push_back(UI);


}

//void cUIMgr::AddAnimation(string _name, D2D1_RECT_F _rect, float _time, vector<wstring> _bitmapList)
//{
//	if (FindUI(_name) != nullptr)
//	{
//		MK_LOG("UI �̸� �ߺ� : UI ���� ����");
//
//		return;
//	}
//
//	cUI *UI = new cUI;
//
//	UI->m_Type = UI_IMAGE;
//	UI->m_Name = _name;
//
//	for (size_t i = 0; i < _bitmapList.size(); i++)
//	{
//		ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapList[i]);
//
//		UI->m_Renderer.AddBitmap(AddBitmap);
//		UI->m_Renderer.SetImgRT(_rect, i);
//	}
//
//	UI->m_Renderer.m_State = 0;
//
//	UI->m_Renderer.AddAnimation_const(0, 0, _bitmapList.size() - 1, _time);
//
//	m_UIList.push_back(UI);
//}

void cUIMgr::AddHPgauge(D2D1_POINT_2F _pos)
{

	cUI *UI = new cUI;

	UI->m_Type = UI_IMAGE;
	UI->m_Name = "HPgauge";

	UI->m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"gauge.hp.layer0"));

	UI->m_Transform.SetPos(_pos);

	m_UIList.push_back(UI);


	auto FUNC1 = [](void) { 

		if (PLAYER_MGR->m_player->m_CharacInfo.m_HP <= 0) PLAYER_MGR->m_player->m_CharacInfo.m_HP = 0;

		float ratio = (float)PLAYER_MGR->m_player->m_CharacInfo.m_HP / PLAYER_MGR->m_player->m_CharacInfo.m_HPmax;
		UI_MGR->FindUI("HPgauge")->m_Transform.SetScale(ratio * 1.5f, 1.3333f);
		};


	AddEvent("HPgauge", ADDEVENT_Update, FUNC1);

}

void cUIMgr::AddMPgauge(D2D1_POINT_2F _pos)
{
	cUI *UI = new cUI;

	UI->m_Type = UI_IMAGE;
	UI->m_Name = "MPgauge";

	UI->m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"gauge.mp.layer0"));

	UI->m_Transform.SetPos(_pos);

	m_UIList.push_back(UI);


	auto FUNC1 = [](void) {

		float ratio = (float)PLAYER_MGR->m_player->m_CharacInfo.m_MP / PLAYER_MGR->m_player->m_CharacInfo.m_MPmax;
		UI_MGR->FindUI("MPgauge")->m_Transform.SetScale(ratio * 1.5f, 1.3333f);
	};


	AddEvent("MPgauge", ADDEVENT_Update, FUNC1);
}

void cUIMgr::AddEXPgauge(D2D1_POINT_2F _pos)
{
	cUI *UI = new cUI;

	UI->m_Type = UI_IMAGE;
	UI->m_Name = "EXPgauge";

	UI->m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"800.gauge"));

	UI->m_Transform.SetPos(_pos);

	m_UIList.push_back(UI);


	auto FUNC1 = [](void) {

		float ratio = (float)PLAYER_MGR->m_player->m_CharacInfo.m_Exp / PLAYER_MGR->m_player->m_CharacInfo.m_ExpMax;
		UI_MGR->FindUI("EXPgauge")->m_Transform.SetScale(ratio * 1.5f, 1.3333f);
	};


	AddEvent("EXPgauge", ADDEVENT_Update, FUNC1);
}



void cUIMgr::HPSetting(int _Number)
{
	for (auto &i : m_HP)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	m_HP.clear();

	if (_Number < 0) _Number = 0;

	int Cipher = EFF_MGR->CipherCalc(_Number);

	for (int i = 0; i < Cipher; i++)
	{
		D2D1_POINT_2F pos = { 165, 740 };

		pos.x -= 8.0f * i;

		Object2D *obj = new Object2D;

		obj->m_Transform.SetPos(pos);

		int Num = _Number % (int)pow(10, (i + 1)) / (int)pow(10, i);

		wstring wstr = L"";

		switch (Num)
		{
		case 0: wstr = L"status.0"; break;
		case 1: wstr = L"status.1"; break;
		case 2: wstr = L"status.2"; break;
		case 3: wstr = L"status.3"; break;
		case 4: wstr = L"status.4"; break;
		case 5: wstr = L"status.5"; break;
		case 6: wstr = L"status.6"; break;
		case 7: wstr = L"status.7"; break;
		case 8: wstr = L"status.8"; break;
		case 9: wstr = L"status.9"; break;

		default:
			break;
		}

		obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

		m_HP.push_back(obj);

	}

	//if (m_HPgage == nullptr)
	//{
	//	m_HPgage = new Object2D;
	//
	//	m_HPgage->m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"gauge.hp.layer0"));
	//
	//	m_HPgage->m_Transform.SetPos(150, 745);
	//}




}

void cUIMgr::HPMaxSetting(int _Number)
{
	for (auto &i : m_HPmax)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	m_HPmax.clear();

	int Cipher = EFF_MGR->CipherCalc(_Number);

	for (int i = 0; i < Cipher; i++)
	{
		D2D1_POINT_2F pos = { 185, 740 };

		pos.x += 8.0f * i;

		Object2D *obj = new Object2D;

		obj->m_Transform.SetPos(pos);

		int Num = _Number % (int)pow(10, (Cipher -i)) / (int)pow(10, Cipher - i - 1);

		wstring wstr = L"";

		switch (Num)
		{
		case 0: wstr = L"status.0"; break;
		case 1: wstr = L"status.1"; break;
		case 2: wstr = L"status.2"; break;
		case 3: wstr = L"status.3"; break;
		case 4: wstr = L"status.4"; break;
		case 5: wstr = L"status.5"; break;
		case 6: wstr = L"status.6"; break;
		case 7: wstr = L"status.7"; break;
		case 8: wstr = L"status.8"; break;
		case 9: wstr = L"status.9"; break;

		default:
			break;
		}

		obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

		m_HPmax.push_back(obj);

	}
}

void cUIMgr::MPSetting(int _Number)
{
	for (auto &i : m_MP)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	m_MP.clear();

	int Cipher = EFF_MGR->CipherCalc(_Number);

	for (int i = 0; i < Cipher; i++)
	{
		D2D1_POINT_2F pos = { 165, 761 };

		pos.x -= 8.0f * i;

		Object2D *obj = new Object2D;

		obj->m_Transform.SetPos(pos);

		int Num = _Number % (int)pow(10, (i + 1)) / (int)pow(10, i);

		wstring wstr = L"";

		switch (Num)
		{
		case 0: wstr = L"status.0"; break;
		case 1: wstr = L"status.1"; break;
		case 2: wstr = L"status.2"; break;
		case 3: wstr = L"status.3"; break;
		case 4: wstr = L"status.4"; break;
		case 5: wstr = L"status.5"; break;
		case 6: wstr = L"status.6"; break;
		case 7: wstr = L"status.7"; break;
		case 8: wstr = L"status.8"; break;
		case 9: wstr = L"status.9"; break;

		default:
			break;
		}

		obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

		m_MP.push_back(obj);

	}
}

void cUIMgr::MPMaxSetting(int _Number)
{
	for (auto &i : m_MPmax)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	m_MPmax.clear();

	int Cipher = EFF_MGR->CipherCalc(_Number);

	for (int i = 0; i < Cipher; i++)
	{
		D2D1_POINT_2F pos = { 185, 761 };

		pos.x += 8.0f * i;

		Object2D *obj = new Object2D;

		obj->m_Transform.SetPos(pos);

		int Num = _Number % (int)pow(10, (Cipher - i)) / (int)pow(10, Cipher - i - 1);

		wstring wstr = L"";

		switch (Num)
		{
		case 0: wstr = L"status.0"; break;
		case 1: wstr = L"status.1"; break;
		case 2: wstr = L"status.2"; break;
		case 3: wstr = L"status.3"; break;
		case 4: wstr = L"status.4"; break;
		case 5: wstr = L"status.5"; break;
		case 6: wstr = L"status.6"; break;
		case 7: wstr = L"status.7"; break;
		case 8: wstr = L"status.8"; break;
		case 9: wstr = L"status.9"; break;

		default:
			break;
		}

		obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

		m_MPmax.push_back(obj);

	}
}

void cUIMgr::LevelSetting(int _Lv, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale)
{
	for (auto &i : m_Level)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	m_Level.clear();

	int Cipher = EFF_MGR->CipherCalc(_Lv);

	for (int i = 0; i < Cipher; i++)
	{
		D2D1_POINT_2F pos = _pos;

		pos.x += 8.0f * _scale.x * i;

		Object2D *obj = new Object2D;

		obj->m_Transform.SetPos(pos);
		obj->m_Transform.SetScale(_scale);

		int Num = _Lv % (int)pow(10, (Cipher - i)) / (int)pow(10, Cipher - i - 1);

		wstring wstr = L"";

		switch (Num)
		{
		case 0: wstr = L"lvNumber.0"; break;
		case 1: wstr = L"lvNumber.1"; break;
		case 2: wstr = L"lvNumber.2"; break;
		case 3: wstr = L"lvNumber.3"; break;
		case 4: wstr = L"lvNumber.4"; break;
		case 5: wstr = L"lvNumber.5"; break;
		case 6: wstr = L"lvNumber.6"; break;
		case 7: wstr = L"lvNumber.7"; break;
		case 8: wstr = L"lvNumber.8"; break;
		case 9: wstr = L"lvNumber.9"; break;

		default:
			break;
		}

		obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

		m_Level.push_back(obj);

	}
}

void cUIMgr::ExpSetting(int _Exp, int _ExpMax)
{
	for (auto &i : m_Exp)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	m_Exp.clear();

	int Cipher = EFF_MGR->CipherCalc(_Exp);

	for (int i = 0; i < Cipher; i++)
	{
		D2D1_POINT_2F pos = { 600, 794 };

		pos.x -= 8.0f * i;

		Object2D *obj = new Object2D;

		obj->m_Transform.SetPos(pos);

		int Num = _Exp % (int)pow(10, (i + 1)) / (int)pow(10, i);

		wstring wstr = L"";

		switch (Num)
		{
		case 0: wstr = L"number.0"; break;
		case 1: wstr = L"number.1"; break;
		case 2: wstr = L"number.2"; break;
		case 3: wstr = L"number.3"; break;
		case 4: wstr = L"number.4"; break;
		case 5: wstr = L"number.5"; break;
		case 6: wstr = L"number.6"; break;
		case 7: wstr = L"number.7"; break;
		case 8: wstr = L"number.8"; break;
		case 9: wstr = L"number.9"; break;

		default:
			break;
		}

		obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

		m_Exp.push_back(obj);
	}

	for (int i = 0; i < 8; i++)
	{
		D2D1_POINT_2F pos = { 608, 794 };

		pos.x += 8.0f * i;

		Object2D *obj = new Object2D;

		obj->m_Transform.SetPos(pos);

		wstring wstr = L"";

		float x =  ( (float)_Exp / (float)_ExpMax ) * 100.0f ;

		if (i == 0)
		{
			wstr = L"number.[";
		}
		else if (i == 3)
		{
			wstr = L"number..";

			pos.y += 3.0f;

			obj->m_Transform.SetPos(pos);
		}
		else if (i == 6)
		{
			wstr = L"number.%";
		}
		else if (i == 7)
		{
			wstr = L"number.]";
		}
		else if (i == 1)
		{	

			int Num = (int)x / 10;

			switch (Num)
			{
			case 0: wstr = L"number.0"; break;
			case 1: wstr = L"number.1"; break;
			case 2: wstr = L"number.2"; break;
			case 3: wstr = L"number.3"; break;
			case 4: wstr = L"number.4"; break;
			case 5: wstr = L"number.5"; break;
			case 6: wstr = L"number.6"; break;
			case 7: wstr = L"number.7"; break;
			case 8: wstr = L"number.8"; break;
			case 9: wstr = L"number.9"; break;

			default:
				break;
			}
		}
		else if (i == 2)
		{
			int Num = (int)x % 10;

			switch (Num)
			{
			case 0: wstr = L"number.0"; break;
			case 1: wstr = L"number.1"; break;
			case 2: wstr = L"number.2"; break;
			case 3: wstr = L"number.3"; break;
			case 4: wstr = L"number.4"; break;
			case 5: wstr = L"number.5"; break;
			case 6: wstr = L"number.6"; break;
			case 7: wstr = L"number.7"; break;
			case 8: wstr = L"number.8"; break;
			case 9: wstr = L"number.9"; break;

			default:
				break;
			}
		}
		else if (i == 4)
		{
			int Num = (int)(x * 10.0f) % 10;

			switch (Num)
			{
			case 0: wstr = L"number.0"; break;
			case 1: wstr = L"number.1"; break;
			case 2: wstr = L"number.2"; break;
			case 3: wstr = L"number.3"; break;
			case 4: wstr = L"number.4"; break;
			case 5: wstr = L"number.5"; break;
			case 6: wstr = L"number.6"; break;
			case 7: wstr = L"number.7"; break;
			case 8: wstr = L"number.8"; break;
			case 9: wstr = L"number.9"; break;

			default:
				break;
			}
		}
		else if (i == 5)
		{
			int Num = (int)(x * 100.0f) % 10;

			switch (Num)
			{
			case 0: wstr = L"number.0"; break;
			case 1: wstr = L"number.1"; break;
			case 2: wstr = L"number.2"; break;
			case 3: wstr = L"number.3"; break;
			case 4: wstr = L"number.4"; break;
			case 5: wstr = L"number.5"; break;
			case 6: wstr = L"number.6"; break;
			case 7: wstr = L"number.7"; break;
			case 8: wstr = L"number.8"; break;
			case 9: wstr = L"number.9"; break;

			default:
				break;
			}
		}

		obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

		m_Exp.push_back(obj);
	}
}

void cUIMgr::InventoryClick()
{
	if (m_isInvenPicked == false)
	{
		if (m_ClickedUI == nullptr) return;

		int InvenNum = m_ClickedUI->m_InvenNum;

		if (InvenNum == -1) return;

		int a = (int)FindUI("�κ���ũ�ѹ�")->m_Value;
		int value = a * 4;

		ID2D1Bitmap* bitmap = nullptr;

		if (FindUI("�����")->m_isOn == true)
		{
			m_InvenPickedNum = PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value];

			bitmap = PLAYER_MGR->m_player->LoadIconImg(m_InvenPickedNum);
		}
		else if (FindUI("�Һ���")->m_isOn == true)
		{
			m_InvenPickedNum = PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[InvenNum + value];

			int ItemNo = m_InvenPickedNum / 1000;
			wstring wstr = to_wstring(ItemNo);
			wstr += L".icon";
			bitmap = IMG_MGR->GetImage(wstr);
		}

		if (m_InvenPickedNum == 0) return;



		if (bitmap == nullptr) return;

		AddImage("������Ŭ��", L"Hide", { 0,0 }, { 1.0f, 1.0f }, 0.5f);
		BitMapAdd("������Ŭ��", bitmap);
		FindUI("������Ŭ��")->m_Renderer.ChangeBitmap(1);

		auto itemClick = [](void) {
			POINT pos = UI_MGR->GetMousePoint();

			UI_MGR->FindUI("������Ŭ��")->m_Transform.SetPos((float)pos.x, (float)pos.y);
		};

		AddEvent("������Ŭ��", ADDEVENT_Update, itemClick);

		m_ClickedInvenNum = InvenNum + value;

		m_isInvenPicked = true;
		SOUND_MGR->SoundResume(L"DragStart");


	}
	else
	{
		//DeleteUI(FindUI("������Ŭ��"));

		m_isInvenPicked = false;

		if (m_ClickedUI == nullptr) return;

		int InvenNum = m_ClickedUI->m_InvenNum;

		m_ClickedUI = nullptr;

		if (InvenNum == -1) return;

		int a = (int)FindUI("�κ���ũ�ѹ�")->m_Value;
		int value = a * 4;


		if (FindUI("�����")->m_isOn == true)
		{
			int ItemNo = PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value];

			if (m_ClickedInvenNum == InvenNum + value)
			{
				return;
			}

			if (ItemNo == 0)
			{
				PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value] = m_InvenPickedNum;
				PLAYER_MGR->m_player->m_InvenInfo.m_Equip[m_ClickedInvenNum] = 0;

				InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);
				DATA_MGR->Save_Inventory();

				m_InvenPickedNum = 0;
				m_ClickedInvenNum = 0;
			}
			
		}
		else if(FindUI("�Һ���")->m_isOn == true)
		{
			int ItemNo = PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[InvenNum + value];

			if (ItemNo == 0)
			{
				PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[InvenNum + value] = m_InvenPickedNum;
				PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[m_ClickedInvenNum] = 0;

				InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_UseTem);
				DATA_MGR->Save_Inventory();

				m_InvenPickedNum = 0;
				m_ClickedInvenNum = 0;
			}
		}

		SOUND_MGR->SoundResume(L"DragEnd");

	}



}

void cUIMgr::InventoryDbClick()
{
	if (FindUI("�κ��丮â1")->m_isActive == false) return;

	DeleteUI(FindUI("������Ŭ��"));

	m_isInvenPicked = false;

	if (m_ClickedUI == nullptr) return;

	int InvenNum = m_ClickedUI->m_InvenNum;

	if (InvenNum == -1) return;

	m_ClickedUI = nullptr;

	int a = (int)FindUI("�κ���ũ�ѹ�")->m_Value;
	int value = a * 4;

	if (FindUI("�����")->m_isOn == true)
	{
		int ItemNum = PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value];

		int Sort = ItemNum / 100;

		int Old = 0;

		switch (Sort)
		{
		case 1:
		{
			Old = PLAYER_MGR->m_player->m_CharacInfo.m_Coat;
			PLAYER_MGR->m_player->ChangeCoat(ItemNum);
			PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value] = Old;

		}break;

		case 2:
		{
			if (PLAYER_MGR->m_player->m_CharacInfo.m_Pants != 0) return;

			Old = PLAYER_MGR->m_player->m_CharacInfo.m_Coat;
			PLAYER_MGR->m_player->ChangeCoat(ItemNum);
			PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value] = Old;

		}break;

		case 3:
		{
			Old = PLAYER_MGR->m_player->m_CharacInfo.m_Cap;
			PLAYER_MGR->m_player->ChangeCap(ItemNum);
			PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value] = Old;

		}break;

		case 4:
		{
			if (PLAYER_MGR->m_player->m_CharacInfo.m_Coat / 100 == 2) return;

			Old = PLAYER_MGR->m_player->m_CharacInfo.m_Pants;
			PLAYER_MGR->m_player->ChangePants(ItemNum);
			PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value] = Old;

		}break;

		case 5:
		{
			Old = PLAYER_MGR->m_player->m_CharacInfo.m_Shoes;
			PLAYER_MGR->m_player->ChangeShoes(ItemNum);
			PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value] = Old;

		}break;

		case 6:
		{
			Old = PLAYER_MGR->m_player->m_CharacInfo.m_Weapon;
			PLAYER_MGR->m_player->ChangeWeapon(ItemNum);
			PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value] = Old;

		}break;

		default:
			break;
		}

		DATA_MGR->Save_Inventory();
		EquipRender();

		if (Old == 0)
		{
			InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);
			return;
		}

		ostringstream str;
		str << "�κ�ĭ" << InvenNum;

		ID2D1Bitmap* pBitmap = PLAYER_MGR->m_player->LoadIconImg(PLAYER_MGR->m_player->m_InvenInfo.m_Equip[InvenNum + value]);

		if (pBitmap == nullptr) return;

		BitMapDel(str.str());
		BitMapAdd(str.str(), pBitmap);
		InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);
	}
	else if (FindUI("�Һ���")->m_isOn == true)
	{		
		int ItemNum = PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[InvenNum + value];


		ItemNum /= 1000;

		DATA_MGR->UseItem(ItemNum);
		PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[InvenNum + value]--;

		if (PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[InvenNum + value] % 1000 == 0)
		{
			PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[InvenNum + value] = 0;

		}

		InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_UseTem);
		DATA_MGR->Save_Inventory();
	}

	

}

void cUIMgr::InventoryRender(int _array[28])
{

	FindUI("�޼ұݾ�")->m_Text = to_string(PLAYER_MGR->m_player->m_InvenInfo.m_Meso);

	if (_array == nullptr) return;

	if (FindUI("�Һ���")->m_isOn == true)
	{
		for (auto &i : m_UsetemCount)
		{
			i = {};
			delete i;
			i = nullptr;
		}

		m_UsetemCount.clear();
	}

	for (int i = 0; i < 24; i++)
	{
		ostringstream str;
		str << "�κ�ĭ" << i;

		int a = (int)FindUI("�κ���ũ�ѹ�")->m_Value;
		int value = a * 4;

		BitMapDel(str.str());

		if (_array[i + value] == 0)
		{
			FindUI(str.str())->m_Renderer.SetAlpha(0.0f);
			BitMapAdd(str.str(), L"itemTile");
			continue;
		}

		ID2D1Bitmap* pBitmap= nullptr;

		if (FindUI("�����")->m_isOn == true)
		{
			pBitmap = PLAYER_MGR->m_player->LoadIconImg(_array[i + value]);
		}
		else if (FindUI("�Һ���")->m_isOn == true)
		{
			int ItemNo = _array[i + value] / 1000;
			wstring wstr = to_wstring(ItemNo);
			wstr += L".info.icon";
			pBitmap = IMG_MGR->GetImage(wstr);

			int Count = _array[i + value] % 1000;

			int Cipher = EFF_MGR->CipherCalc(Count);

			for (int j = 0; j < Cipher; j++)
			{
				D2D1_POINT_2F pos = { -10, 10 };

				pos.x += 8.0f * j;

				Object2D *obj = new Object2D;

				obj->m_Transform.SetPos(pos);
				obj->m_Transform.m_pParent = &(FindUI(str.str())->m_Transform);

				int Num = Count % (int)pow(10, (Cipher - j)) / (int)pow(10, Cipher - j - 1);

				wstring wstr = L"";

				switch (Num)
				{
				case 0: wstr = L"ItemNo.0"; break;
				case 1: wstr = L"ItemNo.1"; break;
				case 2: wstr = L"ItemNo.2"; break;
				case 3: wstr = L"ItemNo.3"; break;
				case 4: wstr = L"ItemNo.4"; break;
				case 5: wstr = L"ItemNo.5"; break;
				case 6: wstr = L"ItemNo.6"; break;
				case 7: wstr = L"ItemNo.7"; break;
				case 8: wstr = L"ItemNo.8"; break;
				case 9: wstr = L"ItemNo.9"; break;

				default:
					break;
				}

				obj->m_Renderer.AddBitmap(IMG_MGR->GetImage(wstr));

				m_UsetemCount.push_back(obj);
			}
		}	

		if (pBitmap == nullptr) return;

		
		BitMapAdd(str.str(), pBitmap);
		FindUI(str.str())->m_Renderer.SetAlpha(1.0f);
		FindUI("submenu.backgrnd.0.character")->m_isActive = false;
	}

	int cc = 0;
}

void cUIMgr::EquipDbClick()
{
	if (FindUI("���â1")->m_isActive == false) return;
		
	if (m_ClickedUI == nullptr) return;

	int ItemNum = FindUI(m_ClickedUI->m_Name)->m_ItemNum;	

	for (int i = 0; i < 28; i++)
	{
		if (PLAYER_MGR->m_player->m_InvenInfo.m_Equip[i] != 0) continue;

		PLAYER_MGR->m_player->m_InvenInfo.m_Equip[i] = ItemNum;

		FindUI(m_ClickedUI->m_Name)->m_ItemNum = 0;

		int Sort = ItemNum / 100;

		switch (Sort)
		{
		case 1:
		case 2:	PLAYER_MGR->m_player->ChangeCoat(0); break;
		case 3: PLAYER_MGR->m_player->ChangeCap(0); break;
		case 4: PLAYER_MGR->m_player->ChangePants(0); break;
		case 5: PLAYER_MGR->m_player->ChangeShoes(0); break;
		case 6: PLAYER_MGR->m_player->ChangeWeapon(0); break;
		default:
			break;
		}
		break;
	}

	EquipRender();
	InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);
	DATA_MGR->Save_Inventory();

	SOUND_MGR->SoundResume(L"DragEnd");

}

void cUIMgr::EquipRender()
{
	vector<string> m_EquipName;
	m_EquipName.push_back("���ĭ����");
	m_EquipName.push_back("���ĭ��");
	m_EquipName.push_back("���ĭ����");
	m_EquipName.push_back("���ĭ�Ź�");
	m_EquipName.push_back("���ĭ����");

	for (auto &i : m_EquipName)
	{
		if (FindUI(i)->m_ItemNum == 0)
		{
			FindUI(i)->m_Renderer.SetAlpha(0.0f);
			continue;
		}

		BitMapDel(i);

		ID2D1Bitmap* pBitmap = PLAYER_MGR->m_player->LoadIconImg(FindUI(i)->m_ItemNum);

		BitMapAdd(i, pBitmap);
		FindUI(i)->m_Renderer.SetAlpha(1.0f);
	}	
}

void cUIMgr::SkillClick()
{
	if (m_ClickedUI == nullptr) return;

	ID2D1Bitmap *pBitmap = m_ClickedUI->m_Renderer.GetBitmap();

	AddImage("������Ŭ��", L"Hide", { 0,0 }, { 1.0f, 1.0f }, 0.5f);
	BitMapAdd("������Ŭ��", pBitmap);
	FindUI("������Ŭ��")->m_Renderer.ChangeBitmap(1);
	m_Skill = m_ClickedUI;

	auto SkillClick = [](void) {
		POINT pos = UI_MGR->GetMousePoint();

		UI_MGR->FindUI("������Ŭ��")->m_Transform.SetPos((float)pos.x, (float)pos.y);
	};

	AddEvent("������Ŭ��", ADDEVENT_Update, SkillClick);

	SOUND_MGR->SoundResume(L"DragStart");
	
}

void cUIMgr::ShiftDown()
{
	if (m_ShiftDown != nullptr)
	{
		m_ShiftDown();
	}
}

void cUIMgr::Update(float _DelayTime)
{
	for (auto &i : m_UIList)
	{
		if (i->m_parentUI != nullptr)
		{
			if (FindParent(i)->m_isActive == false) continue;
		}

		if (i->m_isActive == false) continue;

		i->Update(_DelayTime);

		i->AddUpdate();		
	}

	if (m_isChating == true)
	{
		m_time += _DelayTime;

		m_InputField->m_FontColor.a = 1.0f;

		if (m_time > 0.5f)
		{
			m_InputField->m_FontColor.a = 0.0f;
		}

		if (m_time > 1.0f)
		{
			m_InputField->m_FontColor.a = 1.0f;

			m_time = 0.0f;
		}
	}


	for (auto &i : m_HP)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_HPmax)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_MP)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_MPmax)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_Level)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_Exp)
	{
		i->Update(_DelayTime);
	}

	if (FindUI("�Һ���") == nullptr) return;

	if (FindUI("�Һ���")->m_isOn == true)
	{
		for (auto &i : m_UsetemCount)
		{
			i->Update(_DelayTime);
		}
	}



}

void cUIMgr::Render()
{
	for (auto &i : m_UIList)
	{
		if (i->m_parentUI != nullptr)
		{
			if (FindParent(i)->m_isActive == false) continue;
		}

		if (i->m_isActive == false) continue;		

		if (i->m_Type == UI_TEXT)
		{
			i->TextRender();
			continue;
		}

		i->Render();

		if (i->m_Type == UI_INPUTFIELD && m_isChating == true ) i->TextRender();
	}

	for (auto &i : m_HP)
	{
		i->Render();
	}

	for (auto &i : m_HPmax)
	{
		i->Render();
	}

	for (auto &i : m_MP)
	{
		i->Render();
	}

	for (auto &i : m_MPmax)
	{
		i->Render();
	}

	for (auto &i : m_Level)
	{
		i->Render();
	}

	for (auto &i : m_Exp)
	{
		i->Render();
	}

	if (FindUI("�Һ���") == nullptr || FindUI("�κ��丮â1")->m_isActive == false) return;

	if (FindUI("�Һ���")->m_isOn == true)
	{
		for (auto &i : m_UsetemCount)
		{
			i->Render();
		}
	}

}

void cUIMgr::VectorClear(vector<Object2D*> &_vec)
{
	for (auto &i : _vec)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	_vec.clear();
}

