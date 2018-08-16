#include "stdafx.h"
#include "cMapMgr.h"
#include "cErebMap.h"
#include "cArcana.h"
#include "cCokeTown.h"
#include "cCokeTownBoss.h"
#include "cCokeTownNormal.h"

cMapMgr::~cMapMgr()
{
	Destroy();
}


void cMapMgr::SetMap()
{
	delete m_pMap;
	delete m_pMapName;

	switch (m_MapName)
	{
	case MNAME_EREB:
		m_pMap = new cErebMap;
		break;

	case MNAME_ARCANA:
		m_pMap = new cArcana;
		break;
	case MNAME_COKETOWN:
		m_pMap = new cCokeTown;
		break;
	case MNAME_COKETOWNBOSS:
		m_pMap = new cCokeTownBoss;
		break;
	case MNAME_COKETOWNNORMAL:
		m_pMap = new cCokeTownNormal;
		break;

	}

	m_pMap->Init();

	m_pMapName = new Text2D;

	m_pMapName->SetFont(L"°íµñ");

	m_isChange = false;
}

void cMapMgr::AddTile(wstring _bitmapName, D2D1_POINT_2F _pos, wstring _forlderName)
{
	cMapObj *MAP = new cMapObj;
	//wstring ss = _forlderName + L"\\";
	IMG_MGR->FileFindDir(L".\\Img\\map\\" + _forlderName + L"\\");
	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	MAP->m_Renderer.AddBitmap(AddBitmap);
	MAP->m_isBaseTile = true;
	MAP->m_Transform.SetPos(_pos);
	MAP->m_CrashCheck = true; // Ãæµ¹ Ãß°¡»çÇ×
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

	//////////////////////////////////////////////////////////


	for (int i = 0; i < 2; i++)
	{
		cMapObj *MAP = new cMapObj;

		ID2D1Bitmap* AddBitmap = m_pMap->m_MapImgList[Mapname].m_Bitmap;

		MAP->m_Renderer.AddBitmap_Bottom(AddBitmap);

		MAP->m_CrashCheck = false;

		if (i == 0)
		{
			MAP->m_Transform.SetPos(_pos.x - 44.5f, _pos.y);
		}
		else
		{
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 89.5f + 44.5f, _pos.y);
		}

		m_pMap->m_Minimap_List.push_back(MAP);

		SetParent(&(m_pMap->m_MiniMap), MAP);
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

		MAP->m_CrashCheck = false;

		MAP->m_Transform.SetPos(_pos.x + i * 89.5f, _pos.y);

		m_pMap->m_Minimap_List.push_back(MAP);

		SetParent(&(m_pMap->m_MiniMap), MAP);

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

	//////////////////////////////////////////////////////////

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
			MAP->m_Transform.SetPos(_pos.x + (_count - 1) * 89.5f + 44.5f + 13.0f, _pos.y);
		}

		m_pMap->m_Minimap_List.push_back(MAP);

		SetParent(&(m_pMap->m_MiniMap), MAP);

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

		m_pMap->m_Minimap_List.push_back(MAP);

		SetParent(&(m_pMap->m_MiniMap), MAP);

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

	//////////////////////////////////////////////////////////

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

		m_pMap->m_Minimap_List.push_back(MAP);

		SetParent(&(m_pMap->m_MiniMap), MAP);

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

		m_pMap->m_Minimap_List.push_back(MAP);

		SetParent(&(m_pMap->m_MiniMap), MAP);
	}
}

void cMapMgr::AddMinimapWindow(wstring _bitmapName, D2D1_POINT_2F _pos, D2D1_POINT_2F _scale)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	MAP->m_Renderer.AddBitmap(AddBitmap);

	MAP->m_Transform.SetPos(_pos);
	MAP->m_Transform.SetScale(_scale);

	m_pMap->m_Minimap_List.push_back(MAP);
}

void cMapMgr::AddMinimapWindow_Rect(wstring _bitmapName, D2D1_RECT_F _rect)
{
	cMapObj *MAP = new cMapObj;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(_bitmapName);

	MAP->m_Renderer.AddBitmap(AddBitmap);

	MAP->m_Renderer.SetImgRT(_rect);

	m_pMap->m_Minimap_List.push_back(MAP);
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

	///////////////////////////////////////////////

	cMapObj *MAP2 = new cMapObj;	

	MAP2->m_Renderer.AddBitmap_Bottom(AddBitmap);

	MAP2->m_Transform.SetPos(_pos);

	m_pMap->m_Minimap_List.push_back(MAP2);

	SetParent(&(m_pMap->m_MiniMap), MAP2);

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

void cMapMgr::AddPortal(int _ID, D2D1_POINT_2F _pos, vector<wstring> _bitmapNamelist, eMapName _ChangeMap, int _ChangeMapPortalID, bool _front)
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

	if (_front == true)
	{
		m_pMap->m_FrontPortal_List.push_back(MAP);
	}
	else
	{
		m_pMap->m_Portal_List.push_back(MAP);
	}

	SetParent(&(m_pMap->m_LayOut6), MAP);

	//////////////////////////////////////////////

	cMapObj *MAP2 = new cMapObj;

	ID2D1Bitmap* AddBitmap = IMG_MGR->GetImage(L"minimap.portal");
	MAP2->m_Renderer.AddBitmap_Bottom(AddBitmap);

	MAP2->m_Transform.SetPos(_pos);
	MAP2->m_Transform.SetScale(10.0f, 10.0f);

	MAP2->m_CrashCheck = false;

	m_pMap->m_Minimap_List.push_back(MAP2);

	SetParent(&(m_pMap->m_MiniMap), MAP2);

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

void cMapMgr::AddNPC_Carl(D2D1_POINT_2F _pos, FUNC _func)
{
	cMapObj *NPC = new cMapObj;

	map<wstring, ImgInfo> ImgList;

	IMG_MGR->FileFindDir_Take(L".\\Img\\Npc\\Ä®\\", ImgList);

	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"stand.0"].m_Bitmap);
	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"say.1"].m_Bitmap);
	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"stand.0"].m_Bitmap);
	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"say.1"].m_Bitmap);
	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"stand.0"].m_Bitmap);
	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"say.1"].m_Bitmap);
	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"stand.0"].m_Bitmap);
	NPC->m_Renderer.AddBitmap_Bottom(ImgList[L"say.1"].m_Bitmap);

	NPC->m_Transform.SetPos(_pos);

	NPC->m_Renderer.AddAnimation(0, 0, 7, 3.0, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2);
	NPC->m_Renderer.m_State = 0;
	NPC->m_isNPC = true;

	NPC->m_MouseDownFunc = _func;

	m_pMap->m_BackGround6_List.push_back(NPC);
	SetParent(&(m_pMap->m_LayOut6), NPC);

	cMapObj *Arrow = new cMapObj;

	Arrow->m_Renderer.AddBitmap_RightTop(IMG_MGR->GetImage(L"0.arrow"));
	Arrow->m_Transform.SetPos(5.0f, -80.0f);
	m_pMap->m_BackGround6_List.push_back(Arrow);
	SetParent(NPC, Arrow);

	cMapObj *South = new cMapObj;

	South->m_Renderer.AddBitmap_LeftTop(IMG_MGR->GetImage(L"0.s"));
	South->m_Transform.SetPos(4.5f, -80.0f);
	South->m_Transform.SetScale(2.0f, 1.0f);
	m_pMap->m_BackGround6_List.push_back(South);
	SetParent(NPC, South);

	cMapObj *SE = new cMapObj;

	SE->m_Renderer.AddBitmap_LeftTop(IMG_MGR->GetImage(L"0.se"));
	SE->m_Transform.SetPos(28.0f, -80.0f);
	m_pMap->m_BackGround6_List.push_back(SE);
	SetParent(NPC, SE);

	cMapObj *Eest = new cMapObj;

	Eest->m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"0.e"));
	Eest->m_Transform.SetPos(28.0f, -80.0f);
	Eest->m_Transform.SetScale(1.0f, 2.0f);
	m_pMap->m_BackGround6_List.push_back(Eest);
	SetParent(NPC, Eest);

	cMapObj *NE = new cMapObj;

	NE->m_Renderer.AddBitmap_LeftBottom(IMG_MGR->GetImage(L"0.ne"));
	NE->m_Transform.SetPos(28.0f, -108.0f);
	m_pMap->m_BackGround6_List.push_back(NE);
	SetParent(NPC, NE);

	cMapObj *North = new cMapObj;

	North->m_Renderer.AddBitmap_RightBottom(IMG_MGR->GetImage(L"0.n"));
	North->m_Transform.SetPos(28.5f, -108.0f);
	North->m_Transform.SetScale(4.0f, 1.0f);
	m_pMap->m_BackGround6_List.push_back(North);
	SetParent(NPC, North);

	cMapObj *NW = new cMapObj;

	NW->m_Renderer.AddBitmap_RightBottom(IMG_MGR->GetImage(L"0.nw"));
	NW->m_Transform.SetPos(-19.0f, -108.0f);
	m_pMap->m_BackGround6_List.push_back(NW);
	SetParent(NPC, NW);

	cMapObj *West = new cMapObj;

	West->m_Renderer.AddBitmap_RightTop(IMG_MGR->GetImage(L"0.w"));
	West->m_Transform.SetPos(-19.0f, -108.0f);
	West->m_Transform.SetScale(1.0f, 2.0f);
	m_pMap->m_BackGround6_List.push_back(West);
	SetParent(NPC, West);

	cMapObj *SW = new cMapObj;

	SW->m_Renderer.AddBitmap_RightTop(IMG_MGR->GetImage(L"0.sw"));
	SW->m_Transform.SetPos(-19.0f, -80.0f);
	m_pMap->m_BackGround6_List.push_back(SW);
	SetParent(NPC, SW);

	cMapObj *South2 = new cMapObj;

	South2->m_Renderer.AddBitmap_LeftTop(IMG_MGR->GetImage(L"0.s"));
	South2->m_Transform.SetPos(-19.5f, -80.0f);
	South2->m_Transform.SetScale(1.1f, 1.0f);
	m_pMap->m_BackGround6_List.push_back(South2);
	SetParent(NPC, South2);

	cMapObj *Center = new cMapObj;

	Center->m_Renderer.AddBitmap(IMG_MGR->GetImage(L"0.c"));
	Center->m_Transform.SetPos(4.5f, -94.0f);
	Center->m_Transform.SetScale(4.0f, 2.0f);
	m_pMap->m_BackGround6_List.push_back(Center);
	SetParent(NPC, Center);

}

void cMapMgr::AddCoin(D2D1_POINT_2F _pos, int _SumOfMeso)
{
	cMapObj *Coin = new cMapObj;

	Coin->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(L"coin1"));
	Coin->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(L"coin2"));
	Coin->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(L"coin3"));
	Coin->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(L"coin4"));

	Coin->m_CrashCheck = true;

	Coin->m_Renderer.AddAnimation_const(0, 0, 3, 0.2f);
	Coin->m_Renderer.m_State = 0;

	Coin->m_posY = _pos.y;

	Coin->m_Transform.SetPos(_pos);

	//Coin->m_Transform.m_isCamera = true;

	Coin->m_SumOfMoney = _SumOfMeso;

	m_pMap->m_CoinList.push_back(Coin);

	SetParent(&(m_pMap->m_LayOut6), Coin);

}

void cMapMgr::PickCoin(cMapObj * _Coin)
{
	_Coin->m_isDeleted = true;

	PLAYER_MGR->m_player->m_InvenInfo.m_Meso += _Coin->m_SumOfMoney;
	DATA_MGR->Save_Inventory();

	UI_MGR->InventoryRender(nullptr);
	SOUND_MGR->SoundResume(L"PickUpItem");
	

}

void cMapMgr::AddItem(D2D1_POINT_2F _pos, int _ItemNo)
{
	cMapObj *Item = new cMapObj;

	if (_ItemNo >= 1000)
	{
		ID2D1Bitmap* pBitmap = nullptr;

		int ItemNo = _ItemNo / 1000;
		wstring wstr = to_wstring(ItemNo);
		wstr += L".info.iconRaw";
		pBitmap = IMG_MGR->GetImage(wstr);

		Item->m_ItemNo = _ItemNo;

		Item->m_Renderer.AddBitmap_Bottom(IMG_MGR->GetImage(wstr));
	}

	Item->m_CrashCheck = true;

	D2D1_POINT_2F pos = _pos;

	pos.x += 10.0f;

	Item->m_posY = _pos.y;

	Item->m_Transform.SetPos(pos);

	m_pMap->m_ItemList.push_back(Item);

	SetParent(&(m_pMap->m_LayOut6), Item);
}

void cMapMgr::PickItem(cMapObj * _Item)
{
	_Item->m_isDeleted = true;

	if (_Item->m_ItemNo >= 1000)
	{
		int ItemNo = _Item->m_ItemNo / 1000;

		for (int i = 0; i < 28; i++)
		{
			if (ItemNo == PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[i] / 1000)
			{
				PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[i]++;
				
				break;
			}

			if (i == 27)
			{
				for (int j = 0; j < 28; j++)
				{
					if (PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[j] == 0)
					{
						PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[j] = _Item->m_ItemNo;
						PLAYER_MGR->m_player->m_InvenInfo.m_UseTem[j]++;
						break;
					}
				}
			}
		}

		UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_UseTem);

	}


	DATA_MGR->Save_Inventory();
	SOUND_MGR->SoundResume(L"PickUpItem");
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

		if (m_pMapName != nullptr)
		{
			D2D1_COLOR_F oldColor = IMG_MGR->GetBrush()->GetColor();

			IMG_MGR->GetBrush()->SetColor(ColorF(ColorF::White));

			m_pMapName->TextRender(IMG_MGR->GetpRT(), IMG_MGR->GetBrush(), 15.0f, { 80,50 }, m_pMap->m_MapName.c_str());

			IMG_MGR->GetBrush()->SetColor(oldColor);
		}
	}




}

void cMapMgr::LadderRender()
{
	if (m_pMap != nullptr)
	{
		m_pMap->LadderRender();
	}
}

void cMapMgr::PortalRender()
{
	if (m_pMap != nullptr)
	{
		m_pMap->PortalRender();
	}
}

void cMapMgr::OnMouseDown(POINT _mousePos)
{
	for (auto &i : m_pMap->m_BackGround6_List)
	{
		if (i->m_isNPC == false) continue;

		D2D1_RECT_F rect = i->m_Renderer.GetImgRT();

		float posX = i->m_Transform.m_matSRT.dx;
		float posY = i->m_Transform.m_matSRT.dy;

		rect.left += posX;
		rect.right += posX;
		rect.bottom += posY;
		rect.top += posY;

		if (UI_MGR->RayCastCheck(_mousePos, rect) == false) continue;

		i->m_MouseDownFunc();
		break;
	}
}

void cMapMgr::ChangeMap(int _MapName)
{
	m_MapName = _MapName;
	m_isChange = true;

	MOB_MGR->Destoy();

	PLAYER_MGR->m_player->m_CharacInfo.m_Map = _MapName;

	DATA_MGR->Save_Charater();

	srand(GetTickCount());

}

void cMapMgr::SetParent(cMapObj *_parent, cMapObj *_son)
{
	_son->m_Transform.m_pParent = &(_parent->m_Transform);
}

void cMapMgr::Destroy()
{
	delete m_pMap;
	delete m_pMapName;
}

