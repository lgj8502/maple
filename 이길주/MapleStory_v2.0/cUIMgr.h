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

class cUIMgr : public TemplateSingleton<cUIMgr>
{
	BASESET(cUIMgr);

	Text2D m_font;

	int m_LayOutCount = 0;

	list<cUI*> m_UIList;

public:

	~cUIMgr();

	cUI* FindUI(string _name);
	void DeleteUI(cUI * _delUI);
	void FirstUI(cUI *_fSTui);


	void SetParent(string _Parent, string _Son);

	void AddText(string _name, string _text, D2D1_POINT_2F _pos, D2D1_COLOR_F _FontColor = ColorF(1, 1, 1), wstring _FontName = L"°íµñ", 
		         float _FontSize = 20.0f,  bool _isActive = true, bool _isRayCast = false);

	void AddImage(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f }, 
		         float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = false);
	void AddImage(string _name, wstring _bitmapName, D2D1_RECT_F _rect,
				 float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = false);

	void OnMouseDown(POINT _mousePos);
	bool RayCastCheck(POINT _Ray, D2D1_RECT_F _object);

	//void OnMouseOver();
	//void OnMouseUp();
	//void OnMouseDrag();

	void	Update(float _DelayTime = 0);
	void	Render();

	void	Destroy();
};

#define UI_MGR	cUIMgr::GetInstance()