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
		MK_LOG("DeleteUI 실패");
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
		MK_LOG("BitMapAdd 실패");
	}

	UI->m_Renderer.AddBitmap(IMG_MGR->GetImage(_bitmapName));
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
		
		// Toggle 이라면
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

				UI->OnMouseDown();

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
						return;
					}
				}
			}
			
			return;
		}

		UI->OnMouseDown();
		m_ClickedUI = UI;
		return;		
	}

	if (UI_MGR->m_isChating == true)
	{
		//UI_MGR->m_InputFiled->m_FontColor.a = 0.0f;
		UI_MGR->m_isChating = false;
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
		MK_LOG("리스트에 이름 없음: SetFunc 실패");
		return;
	}

	switch (_Type)
	{
	case ADDEVENT_OnMouseDown:		FindUI(_name)->m_OnMouseDown.push_back(_func);
		break;
	case ADDEVENT_OnMouseUP:		FindUI(_name)->m_OnMouseUp.push_back(_func);
		break;
	case ADDEVENT_OnMouseClick:	FindUI(_name)->m_OnMouseClick.push_back(_func);
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
		MK_LOG("없는 이벤트 타입 : AddEvent 실패"); 
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
		MK_LOG("SetParent 실패");

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
		MK_LOG("SetParent 실패");

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
		MK_LOG("UI 이름 중복 : UI 생성 실패");

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
		MK_LOG("UI 이름 중복 : UI 생성 실패");

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
		MK_LOG("UI 이름 중복 : UI 생성 실패");

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
		MK_LOG("UI 이름 중복 : UI 생성 실패");

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
		MK_LOG("UI 이름 중복 : UI 생성 실패");
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
		MK_LOG("UI 이름 중복 : UI 생성 실패");
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
		MK_LOG("UI 이름 중복 : UI 생성 실패");
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





void cUIMgr::AddToggleGroup(string _name, D2D1_POINT_2F _pos, int _count, cUI* _UI, ...)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI 이름 중복 : UI 생성 실패");
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
		MK_LOG("UI 이름 중복 : UI 생성 실패");
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
		MK_LOG("UI 이름 중복 : UI 생성 실패");
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

void cUIMgr::AddPanel(string _name, D2D1_POINT_2F _pos,  int _count, cUI* _UI, ...)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI 이름 중복 : UI 생성 실패");

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
		MK_LOG("UI 이름 중복 : UI 생성 실패");

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

void cUIMgr::AddAnimation(string _name, D2D1_RECT_F _rect, float _time, vector<wstring> _bitmapList)
{
	if (FindUI(_name) != nullptr)
	{
		MK_LOG("UI 이름 중복 : UI 생성 실패");

		return;
	}

	cUI *UI = new cUI;

	UI->m_Type = UI_IMAGE;
	UI->m_Name = _name;

	for (size_t i = 0; i < _bitmapList.size(); i++)
	{
		ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapList[i]);

		UI->m_Renderer.AddBitmap(AddBitmap);
		UI->m_Renderer.SetImgRT(_rect, i);
	}

	UI->m_Renderer.m_State = 0;

	UI->m_Renderer.AddAnimation_const(0, 0, _bitmapList.size() - 1, _time);

	m_UIList.push_back(UI);
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
}

