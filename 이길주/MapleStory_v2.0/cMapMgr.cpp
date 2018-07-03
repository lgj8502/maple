#include "stdafx.h"
#include "cMapMgr.h"

cMapMgr::~cMapMgr()
{
	Destroy();
}


void cMapMgr::AddTile(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMap *MAP = new cMap;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	MAP->m_Renderer.AddBitmap(AddBitmap);

	MAP->m_Transform.SetPos(_pos);

	m_Tile_List.push_back(MAP);
}

void cMapMgr::Update(float _DelayTime)
{
	for (auto &i : m_BackGround1_List)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_BackGround2_List)
	{
		i->Update(_DelayTime);
	}
	for (auto &i : m_BackGround3_List)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_BackGround4_List)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_Scroll_List)
	{
		i->Update(_DelayTime);
	}


	for (auto &i : m_Tile_List)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_Portal_List)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_Ladder_List)
	{
		i->Update(_DelayTime);
	}


	for (auto &i : m_FrontObject_List)
	{
		i->Update(_DelayTime);
	}
}

void cMapMgr::BackRender()
{
	for (auto &i : m_BackGround1_List)
	{
		i->Render();
	}

	for (auto &i : m_Scroll_List)
	{
		i->Render();
	}

	for (auto &i : m_BackGround2_List)
	{
		i->Render();
	}

	for (auto &i : m_BackGround3_List)
	{
		i->Render();
	}

	for (auto &i : m_BackGround4_List)
	{
		i->Render();
	}

	for (auto &i : m_Tile_List)
	{
		i->Render();
	}
}

void cMapMgr::FrontRender()
{
	for (auto &i : m_Portal_List)
	{
		i->Render();
	}

	for (auto &i : m_FrontObject_List)
	{
		i->Render();
	}
}

void cMapMgr::LadderRender()
{
	for (auto &i : m_Ladder_List)
	{
		i->Render();
	}
}

void cMapMgr::Destroy()
{
	DeleteMapList(m_BackGround1_List);
	DeleteMapList(m_BackGround2_List);
	DeleteMapList(m_BackGround3_List);
	DeleteMapList(m_BackGround4_List);
	DeleteMapList(m_FrontObject_List);
	DeleteMapList(m_Ladder_List);
	DeleteMapList(m_Portal_List);
	DeleteMapList(m_Scroll_List);
	DeleteMapList(m_Tile_List);

}

void cMapMgr::DeleteMapList(vector<cMap*> _list)
{
	for (auto &i : _list)
	{
		i = {};
		delete i;
		i = nullptr;
	}
	_list.clear();
}
