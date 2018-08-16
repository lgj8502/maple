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
	UI_GAGE,

};

enum eEvent_Type
{
	ADDEVENT_OnMouseDown,
	ADDEVENT_OnMouseUP,
	ADDEVENT_OnMouseClick,
	ADDEVENT_OnMouseDbClick,
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

	// 인벤토리용
	bool m_isInvenPicked = false;
	int m_InvenPickedNum = 0;
	int m_ClickedInvenNum = 0;

	float m_time = 0.0f;

	vector<Object2D*> m_HP;
	vector<Object2D*> m_HPmax;
	vector<Object2D*> m_MP;
	vector<Object2D*> m_MPmax;
	vector<Object2D*> m_Level;
	vector<Object2D*> m_Exp;
	vector<Object2D*> m_UsetemCount;

public:
	bool	RayCastCheck(POINT _Ray, D2D1_RECT_F _object);

	cUI* m_ClickedUI = nullptr;

	// IME 용
	cUI* m_InputField = nullptr;
	bool m_isChating = false;
	bool m_ExitField = false;

	// 단축키 용
	cUI* m_Skill = nullptr;

	FUNC m_ShiftDown = nullptr;


	void	Destroy();

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
	void BitMapAdd(string _name, ID2D1Bitmap* _pBitmap);
	void BitMapDel(string _name);


	void OnMouseDown(POINT _mousePos);
	void OnMouseUp(POINT _mousePos);
	void OnMouseOver(POINT _mousePos);
	void OnMouseDrag(POINT _mousePos);
	void OnMouseExit(POINT _mousePos);


	void AddEvent(string _name, eEvent_Type _Type, FUNC _func);

	void SetParent(string _Parent, string _Son);
	void SetParent(cUI* _Parent, cUI* _Son);

	void AddText(string _name, string _text, D2D1_POINT_2F _pos, D2D1_COLOR_F _FontColor = ColorF(0, 0, 0), wstring _FontName = L"고딕", 
		         float _FontSize = 10.0f,  bool _isActive = true, bool _isRayCast = false);

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

	void AddToggleGroup(string _name, D2D1_POINT_2F _pos, int _count, cUI* _pUI, ...);

	void AddScrollBar(string _name, wstring _barBitmap, wstring _handleBitmap, D2D1_POINT_2F _pos, float _value = 0.0f, D2D1_POINT_2F _scale = { 1.0f, 1.0f },
		         float _alpha = 1.0f, bool _isActive = true, bool _isRayCast = true);

	void AddInputField(string _name, wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale = { 1.0f, 1.0f }, D2D1_COLOR_F _FontColor = ColorF(ColorF::White),
		wstring _FontName = L"고딕",  float _alpha = 1.0f, float _FontSize = 30.0f, bool _isActive = true, bool _isRayCast = true);

	void AddPanel(string _name, D2D1_POINT_2F _pos, int _count ,cUI* _pUI, ...);

	void AddAnimation(string _name, D2D1_POINT_2F _pos, float _time, vector<wstring> _bitmapList);
	//void AddAnimation(string _name, D2D1_RECT_F _rect, float _time, vector<wstring> _bitmapList);

	void AddHPgauge(D2D1_POINT_2F _pos);
	void AddMPgauge(D2D1_POINT_2F _pos);
	void AddEXPgauge(D2D1_POINT_2F _pos);

	void HPSetting(int _Number);
	void HPMaxSetting(int _Number);
	void MPSetting(int _Number);
	void MPMaxSetting(int _Number);
	void LevelSetting(int _Lv, D2D1_POINT_2F _pos = { 95, 710 }, D2D1_POINT_2F _scale = { 1.0f, 1.0f });

	void ExpSetting(int _Exp, int _ExpMax);

	void InventoryClick();
	void InventoryDbClick();
	void InventoryRender(int _array[28]);

	void EquipDbClick();
	void EquipRender();

	void SkillClick();

	void ShiftDown();

	void Update(float _DelayTime = 0);
	void Render();

	void VectorClear(vector<Object2D*> &_vec);

};

#define UI_MGR	cUIMgr::GetInstance()