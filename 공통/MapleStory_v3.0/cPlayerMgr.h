#pragma once
#include "TemplateSingleton.h"
#include "PlayerTest.h"

class cPlayerMgr : public TemplateSingleton<cPlayerMgr>
{
	BASESET(cPlayerMgr);

public:

	~cPlayerMgr();

	int m_PlayerIndex = -1;

	PlayerTest *m_player = nullptr;

	vector<PlayerTest*> m_PlayerList;

	void CreatePlayer();

	void Destroy();

};

#define PLAYER_MGR	cPlayerMgr::GetInstance()