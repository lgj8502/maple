#include "stdafx.h"
#include "cMap.h"

void cMap::Update(float _DelayTime)
{

	m_Scroll.m_Transform.Translate(-0.5f, 0.0f);

	if (m_Scroll.m_Transform.GetPos().x < - WIN_WIDTH)
	{
		m_Scroll.m_Transform.SetPos(0.0f, 0.0f);
	}


	m_LayOut2.Update(_DelayTime);
	m_LayOut3.Update(_DelayTime);
	m_LayOut4.Update(_DelayTime);
	m_LayOut5.Update(_DelayTime);
	m_LayOut6.Update(_DelayTime);
	m_Scroll.Update(_DelayTime);

	m_MiniMap.Update(_DelayTime);

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
	for (auto &i : m_BackGround5_List)
	{
		i->Update(_DelayTime);
	}
	for (auto &i : m_BackGround6_List)
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

	for (auto &i : m_FrontPortal_List)
	{
		i->Update(_DelayTime);
	}

	for (auto &i : m_Minimap_List)
	{
		i->Update(_DelayTime);
	}

}

void cMap::BackRender()
{
	for (auto &i : m_BackGround1_List)
	{
		i->Render();
	}


	for (auto &i : m_BackGround2_List)
	{
		i->Render();
	}

	for (auto &i : m_Scroll_List)
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

	for (auto &i : m_BackGround5_List)
	{
		i->Render();
	}	
	
	for (auto &i : m_BackGround6_List)
	{
		i->Render();
	}

	for (auto &i : m_Tile_List)
	{
		i->Render();
	}
}

void cMap::FrontRender()
{
	for (auto &i : m_Portal_List)
	{
		i->Render();
	}


	for (auto &i : m_FrontObject_List)
	{
		i->Render();
	}

	for (auto &i : m_Minimap_List)
	{
		i->Render();
	}
}

void cMap::LadderRender()
{
	for (auto &i : m_Ladder_List)
	{
		i->Render();
	}
}

void cMap::PortalRender()
{

	for (auto &i : m_FrontPortal_List)
	{
		i->Render();
	}

}


void cMap::Destroy()
{
	DeleteMapList(m_BackGround1_List);
	DeleteMapList(m_BackGround2_List);
	DeleteMapList(m_BackGround3_List);
	DeleteMapList(m_BackGround4_List);
	DeleteMapList(m_BackGround5_List);
	DeleteMapList(m_BackGround6_List);
	DeleteMapList(m_FrontObject_List);
	DeleteMapList(m_Ladder_List);
	DeleteMapList(m_Portal_List);
	DeleteMapList(m_Scroll_List);
	DeleteMapList(m_Tile_List);
}

void cMap::DeleteMapList(vector<cMapObj*> _list)
{
	for (auto &i : _list)
	{
		i = {};
		delete i;
		i = nullptr;
	}
	_list.clear();
}
