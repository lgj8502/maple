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
	
	if (m_LayOut6.m_Transform.GetPos().x >= 0)
	{

		MAP_MGR->m_LeftEnd = true;
	}
	else
	{
		float x = m_LayOut6_Size.x - WIN_WIDTH;

		float dx = (m_LayOut2_Size.x - WIN_WIDTH) / x;

		m_LayOut2.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut2.m_Transform.VelocityTrans_Map(_time);

		dx = (m_LayOut3_Size.x - WIN_WIDTH) / x;

		m_LayOut3.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut3.m_Transform.VelocityTrans_Map(_time);

		dx = (m_LayOut4_Size.x - WIN_WIDTH) / x;

		m_LayOut4.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut4.m_Transform.VelocityTrans_Map(_time);

		dx = (m_LayOut5_Size.x - WIN_WIDTH) / x;

		m_LayOut5.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut5.m_Transform.VelocityTrans_Map(_time);


		m_LayOut6.m_Transform.m_velocityX = -_velocity;
		m_LayOut6.m_Transform.VelocityTrans_Map(_time);

		D2D1_POINT_2F pos = m_LayOut6.m_Transform.GetPos();

		if (pos.x >= 0)
		{
			pos.x = 0;

			m_LayOut6.m_Transform.SetPos(pos);
		}

		MAP_MGR->m_RightEnd = false;
	}

}

void cMap::PlayerMoveRight(float _velocity, float _time)
{
	if (m_LayOut6.m_Transform.GetPos().x <= WIN_WIDTH - m_LayOut6_Size.x)
	{
		MAP_MGR->m_RightEnd = true;
	}
	else
	{
		float x = m_LayOut6_Size.x - WIN_WIDTH;

		float dx = (m_LayOut2_Size.x - WIN_WIDTH) / x;

		m_LayOut2.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut2.m_Transform.VelocityTrans_Map(_time);

		dx = (m_LayOut3_Size.x - WIN_WIDTH) / x;

		m_LayOut3.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut3.m_Transform.VelocityTrans_Map(_time);

		dx = (m_LayOut4_Size.x - WIN_WIDTH) / x;

		m_LayOut4.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut4.m_Transform.VelocityTrans_Map(_time);

		dx = (m_LayOut5_Size.x - WIN_WIDTH) / x;

		m_LayOut5.m_Transform.m_velocityX = -_velocity * dx;
		m_LayOut5.m_Transform.VelocityTrans_Map(_time);

		m_LayOut6.m_Transform.m_velocityX = -_velocity;
		m_LayOut6.m_Transform.VelocityTrans_Map(_time);


		D2D1_POINT_2F pos = m_LayOut6.m_Transform.GetPos();

		if (pos.x <= WIN_WIDTH - m_LayOut6_Size.x)
		{
			pos.x = WIN_WIDTH - m_LayOut6_Size.x;

			m_LayOut6.m_Transform.SetPos(pos);
		}

		MAP_MGR->m_LeftEnd = false;
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
