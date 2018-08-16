#include "stdafx.h"
#include "cPlayerMgr.h"

cPlayerMgr::~cPlayerMgr()
{
	delete m_player;
	m_player = nullptr;

	Destroy();
}

void cPlayerMgr::CreatePlayer()
{
	m_player = new PlayerTest;

	DATA_MGR->Load_CharacterInfo(m_player->m_CharacInfo);
	DATA_MGR->Load_Inventory(m_player->m_InvenInfo);
}

void cPlayerMgr::Destroy()
{
	for (auto &i : m_PlayerList)
	{
		i = {};
		delete i;
		i = nullptr;
	}

	m_PlayerList.clear();
}
