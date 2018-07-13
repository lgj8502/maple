#pragma once
#include "TemplateSingleton.h"
#include "PlayerTest.h"

class cPlayerMgr : public TemplateSingleton<cPlayerMgr>
{
	BASESET(cPlayerMgr);

public:

	~cPlayerMgr();

	PlayerTest *m_player = nullptr;

	void CreatePlayer();

};

#define PLAYER_MGR	cPlayerMgr::GetInstance()