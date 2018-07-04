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

	cMapObj m_LayOut1 = {};
	cMapObj m_LayOut2 = {};
	cMapObj m_LayOut3 = {};

	D2D1_POINT_2F m_LayOut1_Size = {};
	D2D1_POINT_2F m_LayOut2_Size = {};
	D2D1_POINT_2F m_LayOut3_Size = {};	

public:
	virtual ~cMap() = default;
	
	virtual void Init() = 0;
	void Update(float _DelayTime = 0.0f);
	void BackRender() ;
	void FrontRender();
	void LadderRender() ;

	void PlayerMoveLeft(float _velocity, float _time);
	void PlayerMoveRight(float _velocity, float _time);

	void Destroy();
	void DeleteMapList(vector<cMapObj*> _list);
};

