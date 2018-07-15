#include "stdafx.h"
#include "cPlayerMgr.h"

cPlayerMgr::~cPlayerMgr()
{
	delete m_player;
	m_player = nullptr;
}

void cPlayerMgr::CreatePlayer()
{
	m_player = new PlayerTest;
}
