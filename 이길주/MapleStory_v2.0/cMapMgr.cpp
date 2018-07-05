#include "stdafx.h"
#include "cMapMgr.h"
#include "cErebMap.h"

cMapMgr::~cMapMgr()
{
	delete m_pMap;
}


void cMapMgr::SetMap()
{
	delete m_pMap;

	switch (m_MapName)
	{
	case MNAME_EREB:
		m_pMap = new cErebMap;
		break;

	}

	m_pMap->Init();

	m_isChange = false;
}

void cMapMgr::AddTile(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	MAP->m_Renderer.AddBitmap(AddBitmap);

	MAP->m_Transform.SetPos(_pos);

	m_pMap->m_Tile_List.push_back(MAP);

	SetParent(&(m_pMap->m_LayOut1), MAP);
}

void cMapMgr::AddFlatTileH(D2D1_POINT_2F _pos, int _count)
{
	srand(GetTickCount());

	wstring Mapname = L"edU.0";

	for (int i = 0; i < 2; i++)
	{
		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap(AddBitmap);

		MAP->m_CrashCheck = true;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(_pos.x - 45.0f, _pos.y);
		}
		else
		{
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 90.0f + 45.0f, _pos.y);
		}

		m_pMap->m_Tile_List.push_back(MAP);
		SetParent(&(m_pMap->m_LayOut1), MAP);
	}

	for (int i = 0; i < _count; i++)
	{		
		int randum = rand() % 3;

		switch (randum)
		{
		case 0: Mapname = L"enH0.0"; break;
		case 1: Mapname = L"enH0.1"; break;
		case 2: Mapname = L"enH0.2"; break;
		}

		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap(AddBitmap);

		MAP->m_CrashCheck = true;		

		MAP->m_Transform.SetPos(_pos.x + i * 90.0f, _pos.y);

		m_pMap->m_Tile_List.push_back(MAP);	

		SetParent(&(m_pMap->m_LayOut1), MAP);
	}
}

void cMapMgr::AddFlatTileM(D2D1_POINT_2F _pos, int _count)
{
	srand(GetTickCount());

	wstring Mapname = L"";

	for (int i = 0; i < 2; i++)
	{
		cMapObj *MAP = new cMapObj;

		if (i == 0)
		{
			Mapname = L"enV0.0";
		}
		else
		{
			Mapname = L"enV1.0";
		}

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap(AddBitmap);

		MAP->m_CrashCheck = true;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(_pos.x - 45.0f - 13.0f, _pos.y);
		}
		else
		{
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 90.0f + 45.0f +13.0f, _pos.y);
		}

		m_pMap->m_Tile_List.push_back(MAP);
		SetParent(&(m_pMap->m_LayOut1), MAP);
	}

	for (int i = 0; i < _count; i++)
	{
		int randum = rand() % 6;

		switch (randum)
		{
		case 0: Mapname = L"bsc.0"; break;
		case 1: Mapname = L"bsc.1"; break;
		case 2: Mapname = L"bsc.2"; break;
		case 3: Mapname = L"bsc.3"; break;
		case 4: Mapname = L"bsc.4"; break;
		case 5: Mapname = L"bsc.5"; break;
		}

		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap(AddBitmap);

		MAP->m_Transform.SetPos(_pos.x + i * 90.0f, _pos.y);

		m_pMap->m_Tile_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut1), MAP);
	}
}

void cMapMgr::AddFlatTileL(D2D1_POINT_2F _pos, int _count)
{
	srand(GetTickCount());

	wstring Mapname = L"edD.0";

	for (int i = 0; i < 2; i++)
	{
		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap(AddBitmap);

		MAP->m_CrashCheck = true;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(_pos.x - 45.0f, _pos.y - 4.5f);
		}
		else
		{
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 90.0f + 45.0f, _pos.y - 4.5f);
		}

		m_pMap->m_Tile_List.push_back(MAP);
		SetParent(&(m_pMap->m_LayOut1), MAP);
	}

	for (int i = 0; i < _count; i++)
	{
		int randum = rand() % 3;

		switch (randum)
		{
		case 0: Mapname = L"enH1.0"; break;
		case 1: Mapname = L"enH1.1"; break;
		case 2: Mapname = L"enH1.2"; break;
		}

		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap(AddBitmap);

		MAP->m_Transform.SetPos(_pos.x + i * 90.0f, _pos.y);

		m_pMap->m_Tile_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut1), MAP);
	}
}

void cMapMgr::Update(float _DelayTime)
{
	if (m_isChange == true)
	{
		SetMap();
	}

	if (m_pMap != nullptr)
	{
		m_pMap->Update(_DelayTime);
	}
}

void cMapMgr::BackRender()
{
	if (m_pMap != nullptr)
	{
		m_pMap->BackRender();
	}
}

void cMapMgr::FrontRender()
{
	if (m_pMap != nullptr)
	{
		m_pMap->FrontRender();
	}
}

void cMapMgr::LadderRender()
{
	if (m_pMap != nullptr)
	{
		m_pMap->LadderRender();
	}
}

void cMapMgr::PlayerMoveLeft(float _velocity, float _time)
{
	if (m_pMap != nullptr)
	{
		m_pMap->PlayerMoveLeft(_velocity, _time);
	}
}

void cMapMgr::PlayerMoveRight(float _velocity, float _time)
{
	if (m_pMap != nullptr)
	{
		m_pMap->PlayerMoveRight(_velocity, _time);
	}
}

void cMapMgr::ChangeMap(int _MapName)
{
	m_MapName = _MapName;
	m_isChange = true;


}

void cMapMgr::SetParent(cMapObj *_parent, cMapObj *_son)
{
	_son->m_Transform.m_pParent = &(_parent->m_Transform);
}

