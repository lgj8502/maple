#pragma once
#include "TemplateSingleton.h"

#include "cUI.h"
#include <list>

enum eUI_Type
{
	UI_TEXT,
	UI_IMAGE,
	UI_BUTTON,
	UI_TOGGLE,
	UI_SLIDER,
	UI_SCROLLBAR,
	UI_INPUTFIELD,
	UI_PANEL,
};

enum eEvent_Type
{
	Event_OnMouseDown,
	Event_OnMouseUP,
	Event_OnMouseClick,
	Event_OnMouseOver,
	Event_OnMouseExit,
	Event_OnMouseDrag,
};

class cUIMgr : public TemplateSingleton<cUIMgr>
{
	BASESET(cUIMgr);

	Text2D m_font;

	int m_LayOutCount = 0;

	list<cUI*> m_UIList;

	POINT m_MosuePoint = {};

private:

	bool	RayCastCheck(POINT _Ray, D2D1_RECT_F _object);
	void	Destroy();

public:

	~cUIMgr();

	inline POINT GetMousePoint()
	{
		return m_MosuePoint;
	}

	cUI* FindUI(string _name);
	void DeleteUI(cUI * _delUI);
	void DrawFirst(cUI *_fSTui);
	cUI* FirstUI();
	cUI* FindParent(cUI *_UI);


	void BitMapAdd(string _name, wstring _bitmapName);

	void OnMouseDown(POINT _mousePos);
	void OnMouseUp(POINT _mousePos);
	void OnMouseOver(POINT _mousePos);
	void OnMouseDrag(POINT _mousePos);
	void OnMouseExit(POINT _mousePos);


	void AddEvent(string _name, eEvent_Type _Type, FUNC _func);

	void SetParent(string _Parent, string _Son);

	void AddText(string _name, string _text, D2D1_POINT_2F _pos, D2D1_COLOR_F _FontColor = ColorF(1, 1, 1), wstring _FontName = L"°íµñ", 
		         float _FontSize = 20.0f,  bool _isActive = true, bool _isRayCast = false, bool _canDrag = false);

	void AddImage(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f }, 
		         float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = false, bool _canDrag = false);
	void AddImage(string _name, wstring _bitmapName, D2D1_RECT_F _rect,
				 float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = false, bool _canDrag = false);

	void AddButton(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f },
		         float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = true, bool _canDrag = false);



	void	Update(float _DelayTime = 0);
	void	Render();


};

#define UI_MGR	cUIMgr::GetInstance()