#pragma once

#include "cMapObj.h"
#include <vector>

class cMap
{
public:
	map<wstring, ImgInfo>	m_MapImgList;

	vector<cMapObj*> m_BackGround1_List;
	vector<cMapObj*> m_BackGround2_List;
	vector<cMapObj*> m_BackGround3_List;
	vector<cMapObj*> m_BackGround4_List;
	vector<cMapObj*> m_BackGround5_List;
	vector<cMapObj*> m_BackGround6_List;
	vector<cMapObj*> m_Scroll_List;
	vector<cMapObj*> m_Tile_List;
	vector<cMapObj*> m_Portal_List;
	vector<cMapObj*> m_FrontPortal_List;
	vector<cMapObj*> m_FrontObject_List;
	vector<cMapObj*> m_Ladder_List;

	vector<cMapObj*> m_Minimap_List;

	list<cMapObj*> m_CoinList;
	vector<cMapObj*> m_DelCoin;

	list<cMapObj*> m_ItemList;
	vector<cMapObj*> m_DelItem;


	cMapObj m_LayOut2 = {};
	cMapObj m_LayOut3 = {};
	cMapObj m_LayOut4 = {};
	cMapObj m_LayOut5 = {};
	cMapObj m_LayOut6 = {};

	cMapObj m_MiniMap = {};


	cMapObj m_Scroll = {};

	D2D1_POINT_2F m_LayOut2_Size = {};
	D2D1_POINT_2F m_LayOut3_Size = {};
	D2D1_POINT_2F m_LayOut4_Size = {};
	D2D1_POINT_2F m_LayOut5_Size = {};
	D2D1_POINT_2F m_LayOut6_Size = {};

	// ��Ȱ ����
	D2D1_POINT_2F m_RevivalPos = {};

	string m_MapName = "";

public:
	virtual ~cMap() = default;
	
	virtual void Init() = 0;
	void Update(float _DelayTime = 0.0f);
	void BackRender() ;
	void FrontRender();
	void LadderRender();
	void PortalRender();

	void Destroy();
	void DeleteMapList(vector<cMapObj*> _list);
};

