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



	MNAME_NONE,

};

class cMapMgr : public TemplateSingleton<cMapMgr>
{
	BASESET(cMapMgr);

public:
	~cMapMgr();

	cMap *m_pMap = nullptr;

	int m_MapName = MNAME_NONE;
	bool m_isChange = false;

	bool m_LeftEnd = false;
	bool m_RightEnd = false;

private:

	void SetMap();

public:


	void AddTile(wstring _bitmapName, D2D1_POINT_2F _pos);
	void AddFlatTileH(D2D1_POINT_2F _pos, int _count);
	void AddFlatTileM(D2D1_POINT_2F _pos, int _count);
	void AddFlatTileL(D2D1_POINT_2F _pos, int _count);

	void AddBackGround1(wstring _bitmapName, D2D1_POINT_2F _pos);
	void AddBackGround1_Back1();

	void AddBackGround2(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround3(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround4(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround5(wstring _bitmapName, D2D1_POINT_2F _pos);

	void AddBackGround6(wstring _bitmapName, D2D1_POINT_2F _pos);

	//void AddAnimation(D2D1_POINT_2F _pos, eMap_Type _Type, float _time, int _count, wstring _bitmapName, ...);
	void AddAnimation(D2D1_POINT_2F _pos, eMap_Type _Type, float _time, vector<wstring> _bitmapNamelist);

	void Update(float _DelayTime = 0);
	void BackRender();
	void FrontRender();
	void LadderRender();

	void PlayerMoveLeft(float _velocity, float _time);
	void PlayerMoveRight(float _velocity, float _time);

	void ChangeMap(int _MapName);

	void SetParent(cMapObj *_parent, cMapObj *_son);


};

#define MAP_MGR	cMapMgr::GetInstance()