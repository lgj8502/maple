#include "stdafx.h"
#include "cMap.h"

void cMap::Update(float _DelayTime)
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

void cMap::BackRender()
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
}

void cMap::LadderRender()
{
	for (auto &i : m_Ladder_List)
	{
		i->Render();
	}
}

void cMap::PlayerMoveLeft(float _velocity, float _time)
{
	for (auto &i : m_Tile_List)
	{
		i->m_Transform.m_velocityX = -_velocity;
		i->m_Transform.VelocityTrans(_time);
	}
}

void cMap::Destroy()
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
