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

	for (auto &i : m_DelCoin)
	{
		m_CoinList.remove(i);

		delete i;
		i = nullptr;
	}

	m_DelCoin.clear();

	for (auto &i : m_CoinList)
	{

		i->Update(_DelayTime);

		if (i->m_Start == true)
		{
			if (i->m_JumpStart == false)
			{
				i->m_Transform.m_velocityY = -400.0f;
			}
			i->m_Transform.m_velocityY += 9.81f * _DelayTime * 200.0f;

			i->m_Transform.Translate(0, i->m_Transform.m_velocityY * _DelayTime);

			i->m_StartTime -= _DelayTime;

			if (i->m_StartTime < 0)
			{
				i->m_Start = false;
				i->m_Transform.m_gravity = true;
			}
		}
		else
		{

			if (i->m_Transform.GetPos().y > i->m_posY)
			{

				i->m_Transform.m_gravity = false;

				D2D1_POINT_2F pos = i->m_Transform.GetPos();

				pos.y = i->m_posY;

				i->m_Transform.SetPos(pos);
			}
		}

		if (i->m_isDeleted == true)
		{

			D2D1_POINT_2F start = i->GetMapPos();

			D2D1_POINT_2F end = PLAYER_MGR->m_player->GetPos();

			i->m_Transform.SetPos(DATA_MGR->Lerp(start, end, 0.1f));

			i->m_DelTime -= _DelayTime;

			if (i->m_DelTime < 0.5f && i->m_DelTime > 0.0f)
			{
				float alpha = i->m_Renderer.GetAlpha();
				alpha -= _DelayTime * 2;

				i->m_Renderer.SetAlpha(alpha);

			}
			else if (i->m_DelTime <= 0.0f)
			{
				m_DelCoin.push_back(i);
			}
		}

	}

	for (auto &i : m_DelItem)
	{
		m_ItemList.remove(i);

		delete i;
		i = nullptr;
	}

	m_DelItem.clear();

	for (auto &i : m_ItemList)
	{

		i->Update(_DelayTime);

		if (i->m_Start == true)
		{
			if (i->m_JumpStart == false)
			{
				i->m_Transform.m_velocityY = -400.0f;
			}
			i->m_Transform.m_velocityY += 9.81f * _DelayTime * 200.0f;

			i->m_Transform.Translate(0, i->m_Transform.m_velocityY * _DelayTime);

			i->m_StartTime -= _DelayTime;

			if (i->m_StartTime < 0)
			{
				i->m_Start = false;
				i->m_Transform.m_gravity = true;
			}
		}
		else
		{

			if (i->m_Transform.GetPos().y > i->m_posY)
			{

				i->m_Transform.m_gravity = false;

				D2D1_POINT_2F pos = i->m_Transform.GetPos();

				pos.y = i->m_posY;

				i->m_Transform.SetPos(pos);
			}
		}

		if (i->m_isDeleted == true)
		{

			D2D1_POINT_2F start = i->GetMapPos();

			D2D1_POINT_2F end = PLAYER_MGR->m_player->GetPos();

			i->m_Transform.SetPos(DATA_MGR->Lerp(start, end, 0.1f));

			i->m_DelTime -= _DelayTime;

			if (i->m_DelTime < 0.5f && i->m_DelTime > 0.0f)
			{
				float alpha = i->m_Renderer.GetAlpha();
				alpha -= _DelayTime * 2;

				i->m_Renderer.SetAlpha(alpha);

			}
			else if (i->m_DelTime <= 0.0f)
			{
				m_DelItem.push_back(i);
			}
		}

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

	for (auto &i : m_ItemList)
	{
		i->Render();
	}

	for (auto &i : m_CoinList)
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
	DeleteMapList(m_Minimap_List);

	for (auto &i : m_CoinList)
	{
		i = {};
		delete i;
		i = nullptr;
	}
	m_CoinList.clear();

	for (auto &i : m_ItemList)
	{
		i = {};
		delete i;
		i = nullptr;
	}
	m_ItemList.clear();
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
