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
	UI_TOGGLEGROUP,
	UI_SCROLLBAR,
	UI_SCROLLBAR_HANDLE,
	UI_INPUTFIELD,
	UI_PANEL,
	UI_SCROLLVIEW,
	UI_SLIDER,
};

enum eEvent_Type
{
	ADDEVENT_OnMouseDown,
	ADDEVENT_OnMouseUP,
	ADDEVENT_OnMouseClick,
	ADDEVENT_OnMouseOver,
	ADDEVENT_OnMouseExit,
	ADDEVENT_OnMouseDrag,
	ADDEVENT_ToggleOn,
	ADDEVENT_ToggleOff,
	ADDEVENT_Update,
};

class cUIMgr : public TemplateSingleton<cUIMgr>
{
	BASESET(cUIMgr);

	Text2D m_font;

	int m_LayOutCount = 0;

	list<cUI*> m_UIList;

	POINT m_MosuePoint = {};

	cUI* m_ClickedUI = nullptr;

	float m_time = 0.0f;

private:

	bool	RayCastCheck(POINT _Ray, D2D1_RECT_F _object);
	void	Destroy();

public:

	// IME ¿ë
	cUI* m_InputFiled = nullptr;
	bool m_isChating = false;
	string m_text;

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
	void SetParent(cUI* _Parent, cUI* _Son);

	void AddText(string _name, string _text, D2D1_POINT_2F _pos, D2D1_COLOR_F _FontColor = ColorF(1, 1, 1), wstring _FontName = L"°íµñ", 
		         float _FontSize = 40.0f,  bool _isActive = true, bool _isRayCast = false);

	void AddImage(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f }, 
		         float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = false);
	void AddImage(string _name, wstring _bitmapName, D2D1_RECT_F _rect,
				 float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = false);

	void AddButton(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f },
		         float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = true);

	void AddButton(string _name, wstring _bitmapName, D2D1_RECT_F _rect, float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = true);

	void AddToggle(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f },
				 float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = true);

	void AddToggle(string _name, wstring _bitmapName, D2D1_RECT_F _rect,
		float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = true);

	void AddToggleGroup(string _name, D2D1_POINT_2F _pos, vector<cUI*> _Toggles);

	void AddScrollBar(string _name, wstring _barBitmap, wstring _handleBitmap, D2D1_POINT_2F _pos, float _value = 0.0f, D2D1_POINT_2F _scale = { 1.0f, 1.0f },
		         float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = true);

	void AddInputField(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f }, D2D1_COLOR_F _FontColor = ColorF(ColorF::White),
		wstring _FontName = L"°íµñ",  float _alpha = 0.7f, float _FontSize = 30.0f, bool _isActive = true, bool _isRayCast = true);

	void AddPanel(string _name, D2D1_POINT_2F _pos, vector<cUI*> _list);

	void	Update(float _DelayTime = 0);
	void	Render();


};

#define UI_MGR	cUIMgr::GetInstance()