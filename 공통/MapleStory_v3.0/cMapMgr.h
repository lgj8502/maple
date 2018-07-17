#pragma once

#include "TemplateSingleton.h"

#include "cMapObj.h"
#include <vector>

class cMap;

enum eMap_Type
{
	MAP_BACKGROUND1,
	MAP_BACKGROUND2,
	MAP_BACKGROUND3,
	MAP_BACKGROUND4,
	MAP_BACKGROUND5,
	MAP_BACKGROUND6,
	MAP_SCROLL,
	MAP_TILE,
	MAP_PORTAL,
	MAP_LADDER,
	MAP_FRONTOBJECT,
};

enum eMapName
{
	MNAME_EREB,
	MNAME_ARCANA,
	MNAME_COKETOWN,
	MNAME_COKETOWNBOSS,
	MNAME_COKETOWNNORMAL,



	MNAME_NONE,

};

class cMapMgr : public TemplateSingleton<cMapMgr>
{
	BASESET(cMapMgr);

public:
	~cMapMgr();

	D2D1_POINT_2F m_CameraPos = {};

	cMap *m_pMap = nullptr;

	Object2D m_Fade;

	int m_MapName = MNAME_NONE;
	bool m_isChange = false;

	bool m_LeftEnd = false;
	bool m_RightEnd = false;

	bool m_isPlaying = false;


private:

	void SetMap();

public:


	void AddTile(wstring _bitmapName, D2D1_POINT_2F _pos, wstring _forlderName);
	void AddFlatTileH(D2D1_POINT_2F _pos, int _count, bool _isBaseTile = false);
	void AddFlatTileM(D2D1_POINT_2F _pos, int _count);
	void AddFlatTileL(D2D1_POINT_2F _pos, int _count);

	void AddBackGround1(wstring _bitmapName, D2D1_POINT_2F _pos);
	void AddBackGround1_Back1();

	void AddBackGround2(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround3(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround4(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround5(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround6(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddScroll(wstring  _bitmapName, D2D1_POINT_2F _pos);

	void AddLadder(wstring  _bitmapName, D2D1_POINT_2F _pos, bool _isLadderTop = false);

	void AddPortal(int _ID, D2D1_POINT_2F _pos, vector<wstring> _bitmapNamelist, eMapName _ChangeMap, int _ChangeMapPortalID, bool _front = false);

	void AddAnimation(D2D1_POINT_2F _pos, eMap_Type _Type, float _time, vector<wstring> _bitmapNamelist);



	void Update(float _DelayTime = 0);
	void BackRender();
	void FrontRender();
	void LadderRender();
	void PortalRender();

	void ChangeMap(int _MapName);

	void SetParent(cMapObj *_parent, cMapObj *_son);


};

#define MAP_MGR	cMapMgr::GetInstance()