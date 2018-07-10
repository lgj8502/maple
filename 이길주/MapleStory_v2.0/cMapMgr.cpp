#include "stdafx.h"
#include "cMapMgr.h"
#include "cErebMap.h"
#include "cArcana.h"

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

	case MNAME_ARCANA:
		m_pMap = new cArcana;
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

	SetParent(&(m_pMap->m_LayOut6), MAP);
}

void cMapMgr::AddFlatTileH(D2D1_POINT_2F _pos, int _count, bool _isBaseTile)
{
	wstring Mapname = L"edU.0";	

	for (int i = 0; i < 2; i++)
	{
		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

		MAP->m_isBaseTile = _isBaseTile;

		MAP->m_CrashCheck = true;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(_pos.x - 44.5f, _pos.y);
		}
		else
		{
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 89.5f + 44.5f, _pos.y);
		}

		m_pMap->m_Tile_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut6), MAP);
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

		MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

		MAP->m_isBaseTile = _isBaseTile;

		MAP->m_CrashCheck = true;

		MAP->m_Transform.SetPos(_pos.x + i * 89.5f, _pos.y);

		m_pMap->m_Tile_List.push_back(MAP);	

		SetParent(&(m_pMap->m_LayOut6), MAP);

	}
}

void cMapMgr::AddFlatTileM(D2D1_POINT_2F _pos, int _count)
{
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

		MAP->m_CrashCheck = false;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(_pos.x - 44.5f - 13.0f, _pos.y);
		}
		else
		{
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 89.5f + 44.5f +13.0f, _pos.y);
		}

		m_pMap->m_Tile_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut6), MAP);

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


		MAP->m_Transform.SetPos(_pos.x + i * 89.5f, _pos.y);

		m_pMap->m_Tile_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut6), MAP);

	}
}

void cMapMgr::AddFlatTileL(D2D1_POINT_2F _pos, int _count)
{
	wstring Mapname = L"edD.0";

	for (int i = 0; i < 2; i++)
	{
		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap_Top(AddBitmap);

		MAP->m_CrashCheck = false;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(_pos.x - 44.5f, _pos.y);
		}
		else
		{
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 89.5f + 44.5f, _pos.y);
		}

		m_pMap->m_Tile_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut6), MAP);

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

		MAP->m_Renderer.AddBitmap_Top(AddBitmap);

		MAP->m_Transform.SetPos(_pos.x + i * 89.5f, _pos.y);

		m_pMap->m_Tile_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut6), MAP);
	}
}

void cMapMgr::AddBackGround1(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

	MAP->m_Renderer.AddBitmap(AddBitmap);

	MAP->m_Transform.SetPos(_pos);

	m_pMap->m_BackGround1_List.push_back(MAP);
	
}

void cMapMgr::AddBackGround1_Back1()
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[L"back.1"].m_Bitmap;

	MAP->m_Renderer.AddBitmap(AddBitmap);

	MAP->m_Renderer.SetImgRT({ 0,0, (float)WIN_WIDTH, (float)WIN_HEIGHT });

	m_pMap->m_BackGround1_List.push_back(MAP);
	
}

void cMapMgr::AddBackGround2(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

	MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

	MAP->m_Transform.SetPos(_pos);

	m_pMap->m_BackGround2_List.push_back(MAP);

	SetParent(&(m_pMap->m_LayOut2), MAP);
}

void cMapMgr::AddBackGround3(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

	MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

	MAP->m_Transform.SetPos(_pos);

	m_pMap->m_BackGround3_List.push_back(MAP);

	SetParent(&(m_pMap->m_LayOut3), MAP);
}

void cMapMgr::AddBackGround4(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

	MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

	MAP->m_Transform.SetPos(_pos);

	m_pMap->m_BackGround4_List.push_back(MAP);

	SetParent(&(m_pMap->m_LayOut4), MAP);
}

void cMapMgr::AddBackGround5(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

	MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

	MAP->m_Transform.SetPos(_pos);

	m_pMap->m_BackGround5_List.push_back(MAP);

	SetParent(&(m_pMap->m_LayOut5), MAP);
}

void cMapMgr::AddBackGround6(wstring _bitmapName, D2D1_POINT_2F _pos)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

	MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);	

	MAP->m_Transform.SetPos(_pos);

	m_pMap->m_BackGround6_List.push_back(MAP);

	SetParent(&(m_pMap->m_LayOut6), MAP);

}

void cMapMgr::AddScroll(wstring _bitmapName, D2D1_POINT_2F _pos)
{

	for (int i = 0; i < 2; i++)
	{
		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

		MAP->m_Renderer.AddBitmap(AddBitmap);

		D2D1_POINT_2F pos = _pos;

		pos.y -= MAP->m_Renderer.GetImgRT().bottom;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(pos);
		}
		else
		{
			MAP->m_Transform.SetPos(pos.x + WIN_WIDTH, pos.y);
		}

		m_pMap->m_Scroll_List.push_back(MAP);

		SetParent(&(m_pMap->m_Scroll), MAP);
	}

}

void cMapMgr::AddLadder(wstring _bitmapName, D2D1_POINT_2F _pos, bool _isLadderTop)
{
		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[_bitmapName].m_Bitmap;

		MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

		MAP->m_CrashCheck = true;

		MAP->m_isLadderTop = _isLadderTop;

		D2D1_POINT_2F pos = _pos;

		MAP->m_Transform.SetPos(pos);

		if (_isLadderTop == false)
		{
			if (m_pMap->m_Ladder_List.back()->m_isLadderTop == true)
			{
				MAP->m_LadderTop = m_pMap->m_Ladder_List.back();
			}
			else
			{
				MAP->m_LadderTop = m_pMap->m_Ladder_List.back()->m_LadderTop;
			}
		}

		m_pMap->m_Ladder_List.push_back(MAP);

		SetParent(&(m_pMap->m_LayOut6), MAP);
}

void cMapMgr::AddPortal(int _ID, D2D1_POINT_2F _pos, vector<wstring> _bitmapNamelist, eMapName _ChangeMap, int _ChangeMapPortalID)
{
	cMapObj *MAP = new cMapObj;

	for (auto &i : _bitmapNamelist)
	{
		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[i].m_Bitmap;
		MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);
	}

	MAP->m_Renderer.AddAnimation_const(0, 0, _bitmapNamelist.size() - 1, 0.1f);
	MAP->m_Renderer.m_State = 0;

	MAP->m_Transform.SetPos(_pos);

	MAP->m_CrashCheck = true;

	MAP->m_PortalID = _ID;
	MAP->m_ChangeMap = _ChangeMap;
	MAP->m_ChangeMapPortalID = _ChangeMapPortalID;

	m_pMap->m_Portal_List.push_back(MAP);

	SetParent(&(m_pMap->m_LayOut6), MAP);

}


void cMapMgr::AddAnimation(D2D1_POINT_2F _pos, eMap_Type _Type, float _time, vector<wstring> _bitmapNamelist)
{
	cMapObj *MAP = new cMapObj;

	for (auto &i : _bitmapNamelist)
	{
		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[i].m_Bitmap;
		MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);
	}

	_pos.y -= MAP->m_Renderer.GetImgRT().bottom;

	MAP->m_Transform.SetPos(_pos);

	MAP->m_Renderer.AddAnimation_const(0, 0, _bitmapNamelist.size() - 1, _time);
	MAP->m_Renderer.m_State = 0;

	switch (_Type)
	{
	case MAP_BACKGROUND1: 	m_pMap->m_BackGround1_List.push_back(MAP);
		break;
	case MAP_BACKGROUND2:	m_pMap->m_BackGround2_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut2), MAP);
		break;
	case MAP_BACKGROUND3:	m_pMap->m_BackGround3_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut3), MAP);
		break;
	case MAP_BACKGROUND4:	m_pMap->m_BackGround4_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut4), MAP);
		break;
	case MAP_BACKGROUND5:	m_pMap->m_BackGround5_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut5), MAP); 
		break;
	case MAP_BACKGROUND6:	m_pMap->m_BackGround6_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut6), MAP);
		break;
	case MAP_SCROLL:		m_pMap->m_Scroll_List.push_back(MAP); SetParent(&(m_pMap->m_Scroll), MAP);
		break;
	case MAP_TILE:			m_pMap->m_Tile_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut6), MAP);
		break;
	case MAP_PORTAL:		m_pMap->m_Portal_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut6), MAP);
		break;
	case MAP_LADDER:		m_pMap->m_Ladder_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut6), MAP);
		break;
	case MAP_FRONTOBJECT:	m_pMap->m_FrontObject_List.push_back(MAP); SetParent(&(m_pMap->m_LayOut6), MAP);
		break;
	default:
		break;
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




void cMapMgr::ChangeMap(int _MapName)
{
	m_MapName = _MapName;
	m_isChange = true;

	srand(GetTickCount());

}

void cMapMgr::SetParent(cMapObj *_parent, cMapObj *_son)
{
	_son->m_Transform.m_pParent = &(_parent->m_Transform);
}

