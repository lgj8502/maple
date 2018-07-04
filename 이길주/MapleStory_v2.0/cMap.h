#pragma once

#include "cMapObj.h"
#include <vector>

class cMap
{
public:
	map<wstring, ImgInfo>	m_MapImgList;

	vector<cMapObj*> m_BackGround1_List;
	vector<cMapObj*> m_Scroll_List;
	vector<cMapObj*> m_BackGround2_List;
	vector<cMapObj*> m_BackGround3_List;
	vector<cMapObj*> m_BackGround4_List;
	vector<cMapObj*> m_Tile_List;
	vector<cMapObj*> m_Portal_List;
	vector<cMapObj*> m_FrontObject_List;
	vector<cMapObj*> m_Ladder_List;

	D2D1_POINT_2F m_BG2_pos = {};
	D2D1_POINT_2F m_BG3_pos = {};
	D2D1_POINT_2F m_BG4_pos = {};

public:
	virtual ~cMap() = default;
	
	virtual void Init() = 0;
	void Update(float _DelayTime = 0.0f);
	void BackRender() ;
	void FrontRender();
	void LadderRender() ;

	void PlayerMoveLeft(float _velocity, float _time);

	void Destroy();
	void DeleteMapList(vector<cMapObj*> _list);
};

