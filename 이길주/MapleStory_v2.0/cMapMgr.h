#pragma once

#include "TemplateSingleton.h"

#include "cMap.h"
#include <vector>

enum eMap_Type
{
	MAP_BACKGROUND1,
	MAP_BACKGROUND2,
	MAP_BACKGROUND3,
	MAP_BACKGROUND4,
	MAP_SCROLL,
	MAP_TILE,
	MAP_PORTAL,
	MAP_LADDER,
	MAP_FRONTOBJECT,
};

class cMapMgr : public TemplateSingleton<cMapMgr>
{
	BASESET(cMapMgr);


public:
	~cMapMgr();

	vector<cMap*> m_BackGround1_List;
	vector<cMap*> m_Scroll_List;
	vector<cMap*> m_BackGround2_List;
	vector<cMap*> m_BackGround3_List;
	vector<cMap*> m_BackGround4_List;
	vector<cMap*> m_Tile_List;
	vector<cMap*> m_Portal_List;
	vector<cMap*> m_FrontObject_List;
	vector<cMap*> m_Ladder_List;

	void AddTile(wstring _bitmapName, D2D1_POINT_2F _pos);
	void AddFlatTileS(wstring _bitmapName, D2D1_POINT_2F _pos, int _count);

	void Update(float _DelayTime = 0);
	void BackRender();
	void FrontRender();
	void LadderRender();

	void Destroy();

	void DeleteMapList(vector<cMap*> _list);


};

#define MAP_MGR	cMapMgr::GetInstance()