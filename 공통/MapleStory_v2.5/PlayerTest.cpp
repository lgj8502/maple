#include "stdafx.h"
#include "PlayerTest.h"




PlayerTest::PlayerTest()
{
}


PlayerTest::~PlayerTest()
{
}

void PlayerTest::Init()
{
	SettingBase();
	SettingHair();
	SettingFace();
	SettingCoat();
	SettingPants();
	SettingShoes();

	SetParent(PART_ORIGIN, PART_CENTER);

	m_Parts[PART_ORIGIN].m_Transform.m_gravity = false;
	m_Parts[PART_ORIGIN].m_Transform.m_isCamera = true;

	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].m_Renderer.m_State = PLAYER_IDLE;
		m_Parts[i].m_Transform.m_State = PLAYER_IDLE;
	}

	m_Parts[PART_HEAD].m_Transform.SetPos({ 1,-30 });
	m_Parts[PART_BODY].m_Transform.SetPos({ 0,0 });
	m_Parts[PART_ARM].m_Transform.SetPos({ 9,-5 });
	m_Parts[PART_COAT].m_Transform.SetPos({ 1,-5 });
	m_Parts[PART_COATARM].m_Transform.SetPos({ -1 ,-3 });
	m_Parts[PART_PANTS].m_Transform.SetPos({ 3 , 5 });
	m_Parts[PART_SHOES].m_Transform.SetPos({ 0 , 12 });
	m_Parts[PART_HAND].m_Transform.SetPos({ -5 , 5 });
	m_Parts[PART_FACE].m_Transform.SetPos({ -3,5 });
	m_Parts[PART_HAIR].m_Transform.SetPos({ 0,-9 });

	SetParent(PART_CENTER, PART_BODY);
	SetParent(PART_CENTER, PART_HEAD);
	SetParent(PART_CENTER, PART_ARM);
	SetParent(PART_HEAD, PART_FACE);
	SetParent(PART_HEAD, PART_HAIR);
	SetParent(PART_BODY, PART_COAT);
	SetParent(PART_ARM, PART_COATARM);
	SetParent(PART_CENTER, PART_PANTS);
	SetParent(PART_CENTER, PART_SHOES);
	SetParent(PART_CENTER, PART_HAND);

#pragma region IDLE

	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);

	//////////////  이동 애니메이션 /////////////////////////////////////

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 9, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 10, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 10.5f, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 10, -5 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0.9f, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ -0.5f, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -1, -3 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -1, -3 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -0.5f, -3 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -1, -3 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 5 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 1, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 1, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 1, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 1, 12 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

#pragma endregion IDLE

#pragma region WALK

	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_WALK, 1, 4, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_WALK, 0, 0, 0.8);

	//////////////  이동 애니메이션 /////////////////////////////////////

	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 1 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 1 });

	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_WALK, 0, 3, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });

	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_WALK, 0, 3, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 5, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });

	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 2, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });

	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_IDLE, 4, 7, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 0, -5 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 2, -1 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 0, -5 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -1, -4 });

	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 5, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 5, 5 });

	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 8, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 2, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 6, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 2, 12 });

	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

#pragma endregion WALK

#pragma region JUMP

	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_JUMP, 5, 5, 1);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_JUMP, 1, 1, 1);


	//////////////  이동 애니메이션 /////////////////////////////////////

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 5, -13 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_IDLE, 8, 8, 5);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 3, 0 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 3 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 0, 10 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -10, -7 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_JUMP, 0, 0, 5);



#pragma endregion JUMP


	// 사다리 임시 모션

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 50, -13 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_LADDER, 8, 8, 5);
}

void PlayerTest::Update(float _DelayTime)
{
	if (GetPos().y > MAP_MGR->m_pMap->m_LayOut6_Size.y)
	{
		D2D1_POINT_2F pos = GetPos();

		pos.y = MAP_MGR->m_pMap->m_LayOut6_Size.y - 250.0f;

		SetPos(pos);
	}

	// 포탈관련
	if (m_ChangeMap == true)
	{
		for (auto &i : MAP_MGR->m_pMap->m_Portal_List)
		{
			if (i->m_PortalID == m_PortalNum)
			{
				D2D1_POINT_2F pos =  i->GetMapPos();
				pos.y -= 100.0f;

				SetPos(pos);

				pos.x -= WIN_WIDTH / 2.0f;
				pos.y -= WIN_HEIGHT / 2.0f;

				MAP_MGR->m_CameraPos = pos;
		
				break;
			}
		}
		m_ChangeMap = false;
	}


	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].Update(_DelayTime);
	}

	if (m_Parts[0].m_Transform.m_gravity == true)
	{
		ChangeState(PLAYER_JUMP);
	}

	// Jump

	if (m_isJumping == true && m_Parts[0].m_Transform.m_gravity == false)
	{

		m_isLanding = false;

		ChangeState(PLAYER_JUMP);


		if (m_JumpStart == false)
		{
			m_Parts[0].m_Transform.m_velocityY = -m_JumpPower * m_JumpPowerRatio * 0.01f;

			m_JumpStart = true;
		}


		m_Parts[0].m_Transform.m_velocityY += 9.81f * _DelayTime * 200.0f;

		if (m_Parts[0].m_Transform.m_velocityY > 0.0f)
		{
			//m_Parts[0].m_Transform.m_gravity = true;

			LadderOff();

			m_isJumping = false;
		}
		else
		{
			m_Parts[0].m_Transform.Translate(0, m_Parts[0].m_Transform.m_velocityY * _DelayTime);
		}
	}

	// 타일맵 충돌 체크

	int countTile = 0;

	for (size_t i = 0; i < MAP_MGR->m_pMap->m_Tile_List.size(); i++)
	{
		if (CrashCheckMap(MAP_MGR->m_pMap->m_Tile_List[i]) == true)
		{
			float posY = MAP_MGR->m_pMap->m_Tile_List[i]->GetMapPos().y;

			posY += MAP_MGR->m_pMap->m_Tile_List[i]->m_Renderer.GetImgRT().top;

			if (GetPos().y < posY)
			{
				Landing(MAP_MGR->m_pMap->m_Tile_List[i]);
				countTile++;
			}

			break;
		}
	}

	if (countTile == 0 && m_Parts[0].m_Transform.m_State != PLAYER_JUMP && m_Parts[0].m_Transform.m_State != PLAYER_LADDER) m_Parts[0].m_Transform.m_gravity = true;

	// 사다리 충돌 체크

	for (size_t i = 0; i < MAP_MGR->m_pMap->m_Ladder_List.size(); i++)
	{
		if (CrashCheckMap(MAP_MGR->m_pMap->m_Ladder_List[i]) == true)
		{
			float posX = MAP_MGR->m_pMap->m_Ladder_List[i]->GetMapPos().x;

			float dx = abs(GetPos().x - posX);

			if (dx < 10.0f)
			{
				CheckLadder(MAP_MGR->m_pMap->m_Ladder_List[i]);
				//countLadder++;				
			}

			break;
		}
	}
	
	// 포탈 충돌 체크

	int PortalCount = 0;

	for (size_t i = 0; i < MAP_MGR->m_pMap->m_Portal_List.size(); i++)
	{
		if (CrashCheckMap(MAP_MGR->m_pMap->m_Portal_List[i]) == true)
		{
			float posX = MAP_MGR->m_pMap->m_Portal_List[i]->GetMapPos().x;

			float dx = abs(GetPos().x - posX);

			m_isCrashLadder = false;

			if (dx < 7.0f)
			{	
				CheckPortal(MAP_MGR->m_pMap->m_Portal_List[i]);
				PortalCount++;
			}

			break;
		}
	}

	if (PortalCount == 0) PortalOff();

	
}

void PlayerTest::Render()
{
	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].Render();
	}
}

bool PlayerTest::CrashCheckMap(cMapObj * _obj)
{
	if (_obj->m_CrashCheck == false) return false;

	float left = GetPos().x - 7.0f;
	float right = GetPos().x + 7.0f;
	float up = GetPos().y - 50.0f;
	float down = GetPos().y + 17.5f;

	D2D1_POINT_2F pos = _obj->m_Transform.GetPos();

	D2D1_RECT_F rect = _obj->m_Renderer.GetImgRT();

	rect.left += pos.x;
	rect.right += pos.x;
	rect.top += pos.y;
	rect.bottom += pos.y;

	if (right > rect.left && left < rect.right &&
		up < rect.bottom && down > rect.top)
	{
		m_CrashHeight = down - rect.top - 5.0f;		

		return true;
	}
	return false;
}

void PlayerTest::Landing(cMapObj* _pLandingTile)
{
	m_LandingTile = _pLandingTile;
	m_isLanding = true;

	if (m_Parts[0].m_Transform.m_gravity == true)
	{
		LadderOff();

		if (m_OldLandingTile != nullptr)
		{
			m_OldLandingTile->m_CrashCheck = true;
		}

		m_JumpPowerRatio = 100.0f;

		m_Parts[0].m_Transform.m_gravity = false;

		m_JumpStart = false;
		m_isJumping = false;

		m_Parts[0].m_Transform.m_velocityY = 0.0f;

		ChangeState(PLAYER_IDLE);

		m_Parts[0].m_Transform.Translate(0, -m_CrashHeight);
	}
}



void PlayerTest::BlowJumpTile()
{
	if (m_LandingTile != nullptr && m_LandingTile->m_isBaseTile == false)
	{
		m_LandingTile->m_CrashCheck = false;
	
		m_OldLandingTile = m_LandingTile;
	
		//m_Parts[0].m_Transform.m_gravity = true;
	
		m_JumpPowerRatio = 50.0f;
	
		m_isJumping = true;
	
		//LadderOff();
	
	}
}

void PlayerTest::CheckLadder(cMapObj * _Ladder)
{
	//if (m_Parts[0].m_Transform.m_State == PLAYER_LADDER) return;

	m_isCrashLadder = true;

	if (_Ladder->m_isLadderTop == true)
	{
		m_CrashedTopLadder = _Ladder;
		m_CrashedLadder = nullptr;
	}
	else
	{
		m_CrashedLadder = _Ladder;
		m_CrashedTopLadder = nullptr;
	}

	m_isLanding = false;
}

void PlayerTest::LadderOff()
{
	m_isCrashLadder = false;
	m_CrashedLadder = nullptr;
	m_CrashedTopLadder = nullptr;

	m_Parts[PART_ORIGIN].m_Transform.m_gravity = true;
}

void PlayerTest::PortalIn()
{
	if (m_isCrashPortal == false) return;

	m_PortalNum = m_CrashedPartal->m_ChangeMapPortalID;

	MAP_MGR->ChangeMap(m_CrashedPartal->m_ChangeMap);

	//m_CrashedPartal = false;

	m_ChangeMap = true;

	//for (auto &i : MAP_MGR->m_pMap->m_Portal_List)
	//{
	//	if (i->m_PortalID == PortalNum)
	//	{
	//		D2D1_POINT_2F pos =  i->GetMapPos();
	//		pos.y -= 10.0f;


	//		if (pos.x < WIN_WIDTH / 2.0f)
	//		{
	//			SetPos(pos);
	//		}

	//		break;
	//	}
	//}

}

void PlayerTest::CheckPortal(cMapObj * _Portal)
{
	m_isCrashPortal = true;
	m_CrashedPartal = _Portal;
}

void PlayerTest::PortalOff()
{
	m_isCrashPortal = false;
	m_CrashedPartal = nullptr;
}


void PlayerTest::SetParent(ePlayerParts _Parent, ePlayerParts _Son)
{
	m_Parts[_Son].m_Transform.m_pParent = &(m_Parts[_Parent].m_Transform);
}

void PlayerTest::LeftWalk(float _DelayTime)
{
	if (m_Parts[PART_ORIGIN].m_Transform.m_State == PLAYER_LADDER) return;

	if (GetPos().x < 50.0f) return;

	m_isCrashLadder = false;

	m_Parts[PART_ORIGIN].m_Transform.m_velocityX = -m_MoveSpeed * m_MoveSpeedRatio * 0.01f;

	m_Parts[PART_ORIGIN].m_Transform.VelocityTransX(_DelayTime);

	for (int i = 0; i < PART_END; i++)
	{
		if (m_Parts[i].m_Renderer.m_State != PLAYER_JUMP)
		{
			m_Parts[i].m_Renderer.m_State = PLAYER_WALK;
			m_Parts[i].m_Transform.m_State = PLAYER_WALK;
		}
	}

}

void PlayerTest::RightWalk(float _DelayTime)
{
	if (m_Parts[PART_ORIGIN].m_Transform.m_State == PLAYER_LADDER) return;

	if (GetPos().x > MAP_MGR->m_pMap->m_LayOut6_Size.x - 50.0f) return;

	m_isCrashLadder = false;

	m_Parts[PART_ORIGIN].m_Transform.m_velocityX = +m_MoveSpeed * m_MoveSpeedRatio * 0.01f;

	m_Parts[PART_ORIGIN].m_Transform.VelocityTransX(_DelayTime);

	for (int i = 0; i < PART_END; i++)
	{
		if (m_Parts[i].m_Renderer.m_State != PLAYER_JUMP)
		{
			m_Parts[i].m_Renderer.m_State = PLAYER_WALK;
			m_Parts[i].m_Transform.m_State = PLAYER_WALK;
		}
	}

}

void PlayerTest::ClimbLadder(float _DelayTime)
{
	if (m_isCrashPortal == true) return;

	if (m_CrashedTopLadder != nullptr)
	{
		if (m_CrashedTopLadder->GetMapPos().y > GetPos().y + 45.0f)
		{
			LadderOff();
			return;
		}
	}

	if (m_isCrashLadder == true)
	{
		m_isLanding = false;

		float x = 0.0f;

		if (m_CrashedLadder == nullptr)
		{
			x = m_CrashedTopLadder->GetMapPos().x;
		}
		else
		{
			x = m_CrashedLadder->m_LadderTop->GetMapPos().x;
		}

		x -= m_Parts[PART_ORIGIN].m_Transform.GetPos().x;

		m_Parts[PART_ORIGIN].m_Transform.Translate(x, -3.0f);

		m_Parts[PART_ORIGIN].m_Transform.m_gravity = false;

		ChangeState(PLAYER_LADDER);	

		//if (m_CrashedTopLadder != nullptr)
		//{
		//	if (m_CrashedTopLadder->GetMapPos().y > GetPos().y + 200.0f)
		//	{
		//		LadderOff();
		//	}
		//}
	}
}

void PlayerTest::DownLadder(float _DelayTime)
{
	//if (m_CrashedTopLadder == nullptr) return;

	if (m_isCrashLadder == true && m_isLanding == false && m_isJumping == false)
	{
		float x = 0.0f;

		if (m_CrashedLadder == nullptr)
		{
			x = m_CrashedTopLadder->GetMapPos().x;
		}
		else
		{
			x = m_CrashedLadder->m_LadderTop->GetMapPos().x;
		}

		x -= m_Parts[PART_ORIGIN].m_Transform.GetPos().x;

		m_Parts[PART_ORIGIN].m_Transform.Translate(x, +3.0f);

		m_Parts[PART_ORIGIN].m_Transform.m_gravity = false;

		ChangeState(PLAYER_LADDER);

		if (m_CrashedLadder != nullptr && CrashCheckMap(m_LandingTile) == true)
		{
			LadderOff();
		}

		//f (m_CrashedLadder != nullptr)
		//
		//	if (m_isLanding == true)
		//	{
		//		LadderOff();
		//	}
		//
	}





}

void PlayerTest::StopLadder()
{
	if (m_Parts[0].m_Transform.m_State == PLAYER_LADDER)
	{
		m_Parts[PART_ORIGIN].m_Transform.m_gravity = false;
	}
}

void PlayerTest::StopWalk()
{
	if (m_Parts[0].m_Transform.m_State == PLAYER_LADDER || m_Parts[0].m_Transform.m_State == PLAYER_JUMP) return;

	m_Parts[0].m_Transform.m_velocityX = 0.0f;

	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].m_Renderer.m_State = PLAYER_IDLE;
		m_Parts[i].m_Transform.m_State = PLAYER_IDLE;
	}
}

void PlayerTest::JumpMove()
{
	m_isJumping = true;
}

void PlayerTest::ChangeBase(size_t _itemNo)
{
	m_Base = _itemNo;

	SettingBase();
}

void PlayerTest::ChangeHair(size_t _itemNo)
{
	m_Hair = _itemNo;

	SettingHair();
}

void PlayerTest::ChangeFace(size_t _itemNo)
{
	m_Face = _itemNo;

	SettingFace();
}

void PlayerTest::ChangeCoat(size_t _itemNo)
{
	m_Coat = _itemNo;

	SettingCoat();
}

void PlayerTest::ChangePants(size_t _itemNo)
{
	m_Pants = _itemNo;

	SettingPants();
}

void PlayerTest::ChangeShoes(size_t _itemNo)
{
	m_Shoes = _itemNo;

	SettingShoes();
}

void PlayerTest::SettingBase()
{
	m_Parts[PART_HEAD].m_Renderer.ClearBitmap();
	m_Parts[PART_BODY].m_Renderer.ClearBitmap();
	m_Parts[PART_ARM].m_Renderer.ClearBitmap();
	m_Parts[PART_HAND].m_Renderer.ClearBitmap();


	LoadImg("base\\", m_Base, m_BaseList);

	m_Parts[PART_HEAD].m_Renderer.AddBitmap(m_BaseList[L"HEAD"].m_Bitmap);
	m_Parts[PART_HEAD].m_Renderer.AddBitmap(m_BaseList[L"HEAD_BACK"].m_Bitmap);

	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"Body1_IDLE"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"Body2_IDLE"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"Body3_IDLE"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"Body2_IDLE"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"walk1.0.body"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"walk1.1.body"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"walk1.2.body"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"walk1.3.body"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"Body_Jump"].m_Bitmap);

	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm1_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm2_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm3_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm2_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.0.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.1.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.2.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.3.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm_Jump"].m_Bitmap);

	m_Parts[PART_HAND].m_Renderer.AddBitmap(m_BaseList[L"Hand_hide"].m_Bitmap);
	m_Parts[PART_HAND].m_Renderer.AddBitmap(m_BaseList[L"Hand"].m_Bitmap);
}

void PlayerTest::SettingHair()
{
	m_Parts[PART_HAIR].m_Renderer.ClearBitmap();

	LoadImg("hair\\", m_Hair, m_HairList);

	m_Parts[PART_HAIR].m_Renderer.AddBitmap(m_HairList[L"stand1.0.hairOverHead"].m_Bitmap);
	m_Parts[PART_HAIR].m_Renderer.AddBitmap(m_HairList[L"backDefault.backHair"].m_Bitmap);
}

void PlayerTest::SettingFace()
{
	m_Parts[PART_FACE].m_Renderer.ClearBitmap();

	LoadImg("face\\", m_Face, m_FaceList);

	m_Parts[PART_FACE].m_Renderer.AddBitmap(m_FaceList[L"default.face"].m_Bitmap);
	m_Parts[PART_FACE].m_Renderer.AddBitmap(m_FaceList[L"blink.1.face"].m_Bitmap);
	m_Parts[PART_FACE].m_Renderer.AddBitmap(m_FaceList[L"blink.2.face"].m_Bitmap);
}

void PlayerTest::SettingCoat()
{
	m_Parts[PART_COAT].m_Renderer.ClearBitmap();
	m_Parts[PART_COATARM].m_Renderer.ClearBitmap();

	LoadImg("coat\\", m_Coat, m_CoatList);

	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"stand1.0.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"stand1.1.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"stand1.2.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"stand1.1.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"walk1.0.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"walk1.1.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"walk1.2.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"walk1.3.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"fly.0.mail"].m_Bitmap);

	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.0.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.1.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.2.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.0.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.0.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.1.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.2.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.3.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"fly.1.mailArm"].m_Bitmap);

}

void PlayerTest::SettingPants()
{
	m_Parts[PART_PANTS].m_Renderer.ClearBitmap();

	LoadImg("pants\\", m_Pants, m_PantsList);

	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"stand1.0.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"stand1.1.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"stand1.2.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"stand1.1.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"walk1.0.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"walk1.1.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"walk1.2.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"walk1.3.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"jump.0.pants"].m_Bitmap);
}

void PlayerTest::SettingShoes()
{
	m_Parts[PART_SHOES].m_Renderer.ClearBitmap();

	LoadImg("shoes\\", m_Shoes, m_ShoesList);

	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"stand1.0.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"walk1.0.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"walk1.1.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"walk1.2.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"walk1.3.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"jump.0.shoes"].m_Bitmap);
}

void PlayerTest::LoadImg(char *_path, size_t _ItemNo, map<wstring, ImgInfo> &_BotmapList)
{
	_BotmapList.clear();

	USES_CONVERSION;

	ostringstream addText;

	addText << _path << _ItemNo << "\\";

	string Str = W2A(m_ImgDir);

	Str += addText.str().c_str();

	LPCWSTR Dir = A2W(Str.c_str());

	IMG_MGR->FileFindDir_Take(Dir, _BotmapList);

	if (_BotmapList.size() == 0)
	{
		MK_LOG(" 경로 : %S , Img 로드 실패", _path);
	}
}

void PlayerTest::ChangeState(ePlayerState _state)
{
	if (m_Parts[0].m_Transform.m_State != _state)
	{
		for (int i = 0; i < PART_END; i++)
		{
			m_Parts[i].m_Renderer.m_State = _state;
			m_Parts[i].m_Transform.m_State = _state;
		}

	}

}

