#include "stdafx.h"
#include "cUIMgr.h"


cUIMgr::~cUIMgr()
{
	Destroy();
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

	cUI* Iter = FindParent(_fSTui);	

	while (Iter != nullptr)
	{
		m_UIList.remove(Iter);

		m_UIList.push_back(Iter);

		Iter = Iter->m_SonUI;
	}
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
	list<cUI*>::iterator Iter;

	for (Iter = m_UIList.end(); Iter != m_UIList.begin(); Iter--)
	{

		if (Iter == m_UIList.end()) continue;

		if ((*Iter)->m_RayCast == false) continue;

		D2D1_RECT_F rect = (*Iter)->m_Renderer.GetImgRT();

		rect.left	= rect.left		*	(*Iter)->m_Transform.GetScale().x  + (*Iter)->m_Transform.GetPos().x;
		rect.right	= rect.right	*	(*Iter)->m_Transform.GetScale().x  + (*Iter)->m_Transform.GetPos().x;
		rect.bottom = rect.bottom   *	(*Iter)->m_Transform.GetScale().y  + (*Iter)->m_Transform.GetPos().y;
		rect.top	= rect.top		*	(*Iter)->m_Transform.GetScale().y  + (*Iter)->m_Transform.GetPos().y;

		if (RayCastCheck(_mousePos, rect) == true)
		{
			(*Iter)->OnMouseDown();

			return;
		}
	}
}

void cUIMgr::OnMouseUp(POINT _mousePos)
{
	list<cUI*>::iterator Iter;


	for (Iter = m_UIList.end(); Iter != m_UIList.begin(); Iter--)
	{
		if (Iter == m_UIList.end()) continue;

		if ((*Iter)->m_RayCast == false) continue;

		D2D1_RECT_F rect = (*Iter)->m_Renderer.GetImgRT();

		rect.left = rect.left		*	(*Iter)->m_Transform.GetScale().x + (*Iter)->m_Transform.GetPos().x;
		rect.right = rect.right	*	(*Iter)->m_Transform.GetScale().x + (*Iter)->m_Transform.GetPos().x;
		rect.bottom = rect.bottom   *	(*Iter)->m_Transform.GetScale().y + (*Iter)->m_Transform.GetPos().y;
		rect.top = rect.top		*	(*Iter)->m_Transform.GetScale().y + (*Iter)->m_Transform.GetPos().y;

		if (RayCastCheck(_mousePos, rect) == true)
		{
			(*Iter)->OnMouseClick();
			return;
		}
		else
		{
			(*Iter)->OnMouseUp();
			return;
		}
	}
}

void cUIMgr::OnMouseOver(POINT _mousePos)
{
	m_MosuePoint = _mousePos;

	list<cUI*>::iterator Iter;

	for (Iter = m_UIList.end(); Iter != m_UIList.begin(); Iter--)
	{
		if (Iter == m_UIList.end()) continue;

		if ((*Iter)->m_RayCast == false) continue;


		D2D1_RECT_F rect = (*Iter)->m_Renderer.GetImgRT();

		rect.left = rect.left		*	(*Iter)->m_Transform.GetScale().x + (*Iter)->m_Transform.GetPos().x;
		rect.right = rect.right	*	(*Iter)->m_Transform.GetScale().x + (*Iter)->m_Transform.GetPos().x;
		rect.bottom = rect.bottom   *	(*Iter)->m_Transform.GetScale().y + (*Iter)->m_Transform.GetPos().y;
		rect.top = rect.top		*	(*Iter)->m_Transform.GetScale().y + (*Iter)->m_Transform.GetPos().y;


		if (RayCastCheck(_mousePos, rect) == true)
		{		

			(*Iter)->OnMouseOver();

			return;
		}
	}
}

void cUIMgr::OnMouseDrag(POINT _mousePos)
{
	m_MosuePoint = _mousePos;

	list<cUI*>::iterator Iter;

	for (Iter = m_UIList.end(); Iter != m_UIList.begin(); Iter--)
	{
		if (Iter == m_UIList.end()) continue;

		if ((*Iter)->m_RayCast == false) continue;

		if ((*Iter)->m_isClicked == false) continue;

		(*Iter)->OnMouseDrag();

		return;

	}
}

void cUIMgr::OnMouseExit(POINT _mousePos)
{
	list<cUI*>::iterator Iter;

	for (Iter = m_UIList.end(); Iter != m_UIList.begin(); Iter--)
	{
		if (Iter == m_UIList.end()) continue;

		if ((*Iter)->m_RayCast == false) continue;

		D2D1_RECT_F rect = (*Iter)->m_Renderer.GetImgRT();

		rect.left = rect.left		*	(*Iter)->m_Transform.GetScale().x + (*Iter)->m_Transform.GetPos().x;
		rect.right = rect.right	*	(*Iter)->m_Transform.GetScale().x + (*Iter)->m_Transform.GetPos().x;
		rect.bottom = rect.bottom   *	(*Iter)->m_Transform.GetScale().y + (*Iter)->m_Transform.GetPos().y;
		rect.top = rect.top		*	(*Iter)->m_Transform.GetScale().y + (*Iter)->m_Transform.GetPos().y;

		if (RayCastCheck(_mousePos, rect) == false && (*Iter)->m_isMouseOver == true)
		{
			(*Iter)->OnMouseExit();

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
	case Event_OnMouseDown:		FindUI(_name)->m_OnMouseDown.push_back(_func);
		break;
	case Event_OnMouseUP:		FindUI(_name)->m_OnMouseUp.push_back(_func);
		break;
	case Event_OnMouseClick:	FindUI(_name)->m_OnMouseClick.push_back(_func);
		break;
	case Event_OnMouseOver:     FindUI(_name)->m_OnMouseOver.push_back(_func);
		break;
	case Event_OnMouseExit:		FindUI(_name)->m_OnMouseExit.push_back(_func);
		break;
	case Event_OnMouseDrag:     FindUI(_name)->m_OnMouseDrag.push_back(_func);
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
	
	SonUI->m_parentUI = ParentUI;
	ParentUI->m_SonUI = SonUI;

	SonUI->m_Transform.m_pParent = &(ParentUI->m_Transform);

	m_UIList.remove(SonUI);

	list<cUI*>::iterator Iter;

	Iter = m_UIList.begin();

	for (auto &i : m_UIList)
	{
		if ((*Iter)->m_Name == _Parent)
		{
			break;
		}

		Iter++;
	}

	Iter++;

	m_UIList.insert(Iter, SonUI);

}

void cUIMgr::AddText(string _name, string _text, D2D1_POINT_2F _pos, D2D1_COLOR_F _FontColor, wstring _FontName,
	                 float _FontSize, bool _isActive, bool _isRayCast, bool _canDrag)
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
	UI->m_CanDrag = _canDrag;

	UI->m_Font.SetFont(UI->m_FontName.c_str());


	UI->m_Transform.SetPos(_pos);

	m_UIList.push_back(UI);
}

void cUIMgr::AddImage(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale, float _alpha, bool _isActive, bool _isRayCast, bool _canDrag)
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
	UI->m_CanDrag = _canDrag;

	m_UIList.push_back(UI);
}

void cUIMgr::AddImage(string _name, wstring _bitmapName, D2D1_RECT_F _rect, float _alpha, bool _isActive, bool _isRayCast, bool _canDrag)
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
	UI->m_CanDrag = _canDrag;

	m_UIList.push_back(UI);
}

void cUIMgr::AddButton(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale, float _alpha, bool _isActive, bool _isRayCast, bool _canDrag)
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
	UI->m_CanDrag = _canDrag;

	m_UIList.push_back(UI);
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

void cUIMgr::Update(float _DelayTime)
{
	for (auto &i : m_UIList)
	{
		i->Update(_DelayTime);
	}
}

void cUIMgr::Render()
{
	for (auto &i : m_UIList)
	{
		if (i->m_isActive == false) continue;

		i->Render();

		if (i->m_Type == UI_TEXT)
		{
			i->TextRender();
		}
	}
}

void cUIMgr::Destroy()
{
	for (auto &i : m_UIList)
	{
		i = {};
		delete i;
		i = nullptr;
	}
}
