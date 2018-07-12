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
	SettingWeapon();

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
	m_Parts[PART_WEAPON].m_Transform.SetPos({ -18,14 });

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
	SetParent(PART_BODY, PART_WEAPON);

#pragma region IDLE

	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	//
	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	//
	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_IDLE, 0, 0, 2);

	//////////////  이동 애니메이션 /////////////////////////////////////
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });

	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);


	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1,-30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1,-30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1,-30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1,-30 });
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0.9f, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ -0.5f, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 9, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 10, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 10.5f, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 10, -5 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);
	//	PART_FACE,
	//PART_HAIR,
	//PART_HAND
	//m_Parts[PART_HAND].m_Transform.SetPos({ -5 , 5 });
	//m_Parts[PART_FACE].m_Transform.SetPos({ -3,5 });
	//m_Parts[PART_HAIR].m_Transform.SetPos({ 0,-9 });

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

	// 100 번대
	//m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -18,14 });
	//m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 0, 2);

	//101
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -9,12 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -9,12 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -9,12 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -9,12 });
	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_IDLE, 0, 3, 0.5, 0.5, 0.5, 0.5);

#pragma endregion IDLE

#pragma region WALK

	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_WALK, 0, 0, 2);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_WALK, 0, 0, 0.8);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_WALK, 0, 0, 0.8);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_WALK, 0, 0, 0.8);

	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_WALK, 1, 4, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_WALK, 0, 0, 0.8);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_WALK, 1, 4, 0.2, 0.2, 0.2, 0.2);
	//////////////  이동 애니메이션 /////////////////////////////////////

	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 1 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 1 });

	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });

	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 2, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });

	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 5, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });

	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);



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

	//100번대
	//m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -20,5 });
	//m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -20,-2 });
	//m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -20,5 });
	//m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -18,14 });

	//101
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -9,7 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -13,-2 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -9,7 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -6, 10 });

	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

#pragma endregion WALK

#pragma region JUMP

	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_JUMP, 0, 0, 2);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);

	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_JUMP, 0, 0, 1);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_JUMP, 0, 0, 1);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_JUMP, 1, 1, 1);

	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_JUMP, 8, 8, 1);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_JUMP, 5, 5, 1);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_JUMP, 5, 5, 1);

	//////////////  이동 애니메이션 /////////////////////////////////////

	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 1 });
	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1,-30 });
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 5, -13 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -10, -7 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);


	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 3, 0 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 4 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 0, 10 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);

	//m_Parts[PART_HAND].m_Transform.AddAniPos({ -10, -7});
	//m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_JUMP, 0, 0, 5);

	//m_Parts[PART_WEAPON].m_Transform.AddAniPos({ 5, -17 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ 6, -35 });
	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_JUMP, 8, 8, 5);



#pragma endregion JUMP

#pragma region ATTACK
	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_ATTACK, 0, 0, 0.9);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_ATTACK, 0, 0, 0.9);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_ATTACK, 0, 0, 0.9);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_ATTACK, 0, 0, 0.9);

	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_ATTACK, 6, 8, 0.3, 0.3, 0.3);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_ATTACK, 6, 8, 0.3, 0.3, 0.3);


	//////////////  이동 애니메이션 /////////////////////////////////////
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 1 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 1 });
	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);


	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ -5, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ -18, -30 });
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ -11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ -3, -16 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 5, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 1, 0 }); // 6, 0
	m_Parts[PART_BODY].m_Transform.AddAniPos({ -9, 0 }); // 14
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ 0, -7 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ -1, -7 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ -6, -5 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -12, -2 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 2, -5 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -5, 3 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 2, 1 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ -1, 1 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ -9, 2 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 4, 10 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 0, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ -8, 11 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);

	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ 15,5 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ 3,10 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ 28, -36 });
	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_ATTACK, 9, 11, 0.3, 0.3, 0.3);
#pragma endregion ATTACK

#pragma region PRONE
	///////// 비트맵 교체 애니메이션 //////////////
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_PRONE, 0, 0, 2);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_PRONE, 12, 12, 2);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_ATTACK, 0, 0, 2);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_ATTACK, 0, 0, 2);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_ATTACK, 0, 0, 2);

	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_PRONE, 12, 12, 2);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_PRONE, 12, 12, 2);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_PRONE, 12, 12, 2);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_PRONE, 9, 9, 2);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_PRONE, 10, 10, 2);

	//////////////  이동 애니메이션 /////////////////////////////////////
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 8 });
	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_HEAD].m_Transform.AddAniPos({ -14, -20 });
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ -8, 3 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ -4, 0 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 5, 0 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 15, 0 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 25, 5 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -26, -2 });
	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_PRONE, 12, 12, 2);

#pragma endregion PRONE

	//proneStab
#pragma region PRONESTEB
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 0, 0, 0.9);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 12, 12, 0.9);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 12, 13, 0.4, 0.5);

	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 0, 0, 0.9);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 0, 0, 0.9);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 0, 0, 0.9);

	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 10, 11, 0.4, 0.5);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_PRONESTEB, 10, 11, 0.4, 0.5);

	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 8 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 8 });
	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_HEAD].m_Transform.AddAniPos({ -14, -20 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ -14, -20 });
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ -8, 3 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ -13, 3 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_PRONE, 13, 14, 0.4, 0.5);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-9 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_PRONE, 13, 14, 0.4, 0.5);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_PRONE, 13, 14, 0.4, 0.5);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ -4, 0 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ -4, 0 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 5, 0 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 5, 0 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 15, 0 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 15, 0 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 25, 5 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 25, 5 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);

	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -26, -2 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -35, -1 });
	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_PRONESTEB, 13, 14, 0.4, 0.5);
#pragma endregion PRONESTEB



#pragma endregion JUMP

#pragma region LADDER
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_LADDER, 1, 1, 0.8);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_LADDER, 13, 13, 0.8);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_LADDER, 14, 14, 0.8);

	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_LADDER, 3, 3, 0.8);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_LADDER, 1, 1, 0.8);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_LADDER, 0, 0, 0.8);

	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_LADDER, 15, 15, 0.8);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_LADDER, 15, 15, 0.8);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_LADDER, 15, 15, 0.8);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_LADDER, 12, 12, 0.8);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_LADDER, 12, 12, 0.8);
	//==========
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 0, -26 });
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ -13, 3 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-5 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ 0, -4 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 5, 0 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 0, 8 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 0, 16 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -35, -6 });
	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_LADDER, 15, 15, 0.8);

#pragma endregion LADDER

#pragma region LADDERMOVE
	m_Parts[PART_HEAD].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 1, 1, 0.8);
	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 13, 14, 0.4, 0.4);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 14, 14, 0.8);

	m_Parts[PART_FACE].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 3, 3, 0.8);
	m_Parts[PART_HAIR].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 1, 1, 0.8);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 0, 0, 0.8);

	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 15, 16, 0.4, 0.4);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 15, 15, 0.8);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 15, 16, 0.4, 0.4);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 12, 13, 0.4, 0.4);
	m_Parts[PART_WEAPON].m_Renderer.AddAnimation(PLAYER_LADDERMOVE, 12, 12, 0.8);



	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_CENTER].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 0, -26 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 0, -26 });
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_ARM].m_Transform.AddAniPos({ -13, 3 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ -13, 3 });
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddAniPos({ -3,5 });
	m_Parts[PART_FACE].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-5 });
	m_Parts[PART_HAIR].m_Transform.AddAniPos({ 0,-5 });
	m_Parts[PART_HAIR].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddAniPos({ -5 , 5 });
	m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_COAT].m_Transform.AddAniPos({ 0, -4 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 0, -4 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 5, 0 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 5, 0 });
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 0, 8 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 0, 8 });
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 0, 16 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 0, 16 });
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -35, -6 });
	m_Parts[PART_WEAPON].m_Transform.AddAniPos({ -35, -6 });
	m_Parts[PART_WEAPON].m_Transform.AddTransAnimation(PLAYER_LADDERMOVE, 16, 17, 0.4, 0.4);

#pragma endregion LADDERMOVE

#pragma endregion LADDERMOVE


	//// 사다리 임시 모션
	//
	//m_Parts[PART_ARM].m_Transform.AddAniPos({ 50, -13 });
	//m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_LADDER, 8, 8, 5);
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

	//Attack
	if (m_isAttack == true && m_isProne == false)
	{
		ChangeState(PLAYER_ATTACK);
		m_AttackSpeed -= _DelayTime;
		if (m_AttackSpeed <= 0)
		{
			m_AttackStart = false;
			m_isAttack = false;
			m_AttackSpeed = 0.9f;
		}

		if (m_isAttack == false)
		{
			ChangeState(PLAYER_IDLE);
		}


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

	if (MAP_MGR->m_isPlaying == true)
	{
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

		if (countTile == 0 && m_Parts[0].m_Transform.m_State != PLAYER_JUMP && m_Parts[0].m_Transform.m_State != PLAYER_LADDER && m_Parts[0].m_Transform.m_State != PLAYER_LADDERMOVE) m_Parts[0].m_Transform.m_gravity = true;
	}



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

	//Prone
	if (m_isProne == true)
	{
		if (PlayerState() != PLAYER_JUMP)
		{
			ChangeState(PLAYER_PRONE);
		}

		if (m_isProneSteb == true)
		{
			ChangeState(PLAYER_PRONESTEB);
			m_AttackSpeed -= _DelayTime;
			if (m_AttackSpeed <= 0)
			{
				m_isProneSteb = false;
				m_AttackSpeed = 0.9f;
			}
		}
	}

}

void PlayerTest::Render()
{
	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].Render();
	}

	if (m_Parts[0].m_Renderer.m_State == PLAYER_LADDER || m_Parts[0].m_Renderer.m_State == PLAYER_LADDERMOVE)
	{
		m_Parts[PART_HEAD].Render();
		m_Parts[PART_HAIR].Render();
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
	if (m_CrashedLadder != nullptr || m_CrashedTopLadder != nullptr) return;

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

	MAP_MGR->m_isPlaying = false;

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
	if (PlayerState() == PLAYER_LADDER || PlayerState() == PLAYER_LADDERMOVE || m_isAttack == true) return;
	

	if (GetPos().x < 50.0f) return;

	m_isCrashLadder = false;
	m_CrashedLadder = nullptr;
	m_CrashedTopLadder = nullptr;

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
	if (PlayerState() == PLAYER_LADDER || PlayerState() == PLAYER_LADDERMOVE || m_isAttack == true) return;

	if (GetPos().x > MAP_MGR->m_pMap->m_LayOut6_Size.x - 50.0f) return;

	m_isCrashLadder = false;
	m_CrashedLadder = nullptr;
	m_CrashedTopLadder = nullptr;

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
	if (m_isCrashPortal == true || m_isAttack == true) return;

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

		x -= m_Parts[PART_ORIGIN].m_Transform.GetPos().x + 5.0f;

		m_Parts[PART_ORIGIN].m_Transform.Translate(x, -3.0f);

		m_Parts[PART_ORIGIN].m_Transform.m_gravity = false;

		ChangeState(PLAYER_LADDERMOVE);	

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
	if (m_isAttack == true) return;

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

		x -= m_Parts[PART_ORIGIN].m_Transform.GetPos().x + 5.0f;

		m_Parts[PART_ORIGIN].m_Transform.Translate(x, +3.0f);

		m_Parts[PART_ORIGIN].m_Transform.m_gravity = false;

		ChangeState(PLAYER_LADDERMOVE);

		if (m_CrashedLadder != nullptr && ( CrashCheckMap(m_LandingTile) == true || CrashCheckMap(m_CrashedLadder) == false))
		{
			LadderOff();
		}

	}
}

void PlayerTest::StopLadder()
{
	if (m_Parts[0].m_Transform.m_State == PLAYER_LADDER || m_Parts[PART_ORIGIN].m_Transform.m_State == PLAYER_LADDERMOVE)
	{
		m_Parts[PART_ORIGIN].m_Transform.m_gravity = false;

		ChangeState(PLAYER_LADDER);
	}
}

void PlayerTest::Prone()
{
	if (m_isAttack == true) return;

	if (PlayerState() == PLAYER_IDLE)
	{
		m_isProne = true;
	}

	
}

void PlayerTest::NotProne()
{
	m_isProne = false;

	if (PlayerState() == PLAYER_PRONE)
	{
		ChangeState(PLAYER_IDLE);
	}

}

void PlayerTest::ProneSteb()
{
	m_isProneSteb = true;
}

void PlayerTest::Attack()
{
	if (PlayerState() == PLAYER_JUMP || PlayerState() == PLAYER_PRONE || PlayerState() == PLAYER_PRONESTEB) return;

	if (m_isAttack == false)
	{
		D2D1_POINT_2F pos = GetPos();

		if (m_Parts[0].m_Transform.GetScale().x > 0)
		{
			pos.x -= 40.0f;

			EFF_MGR->EffectSingle(L"0.swingO1.2.0", pos, true, 0.6f, 0.3f);
		}
		else
		{
			pos.x += 40.0f;

			EFF_MGR->EffectSingle(L"0.swingO1.2.0", pos, false, 0.6f, 0.3f);

		}


		m_isAttack = true;
	}	
}

void PlayerTest::NotAttack()
{
	m_isAttack = false;
}

void PlayerTest::StopWalk()
{
	if (m_Parts[0].m_Transform.m_State == PLAYER_LADDER || m_Parts[PART_ORIGIN].m_Transform.m_State == PLAYER_LADDERMOVE || m_Parts[0].m_Transform.m_State == PLAYER_JUMP) return;

	m_Parts[0].m_Transform.m_velocityX = 0.0f;

	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].m_Renderer.m_State = PLAYER_IDLE;
		m_Parts[i].m_Transform.m_State = PLAYER_IDLE;
	}
}

void PlayerTest::JumpMove()
{	
	if (m_isAttack == true) return;

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

	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO1.0.body"].m_Bitmap); //9
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO1.1.body"].m_Bitmap);
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO1.2.body"].m_Bitmap); // 11

																					 //PRONE
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"proneStab.0.body"].m_Bitmap); // 12
																						   //Ladder
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"ladder.0.body"].m_Bitmap); // 13
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"ladder.1.body"].m_Bitmap); // 14
																					//Attack2
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO2.0.body"].m_Bitmap); // 15
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO2.1.body"].m_Bitmap); // 16
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO2.2.body"].m_Bitmap); // 17
																					 //Attack3
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO3.0.body"].m_Bitmap); // 18
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO3.1.body"].m_Bitmap); // 19
	m_Parts[PART_BODY].m_Renderer.AddBitmap(m_BaseList[L"swingO3.2.body"].m_Bitmap); // 20

	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm1_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm2_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm3_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm2_IDLE"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.0.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.1.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.2.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"walk1.3.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm_Jump"].m_Bitmap);

	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO1.0.arm"].m_Bitmap); //9
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO1.1.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO1.2.arm"].m_Bitmap); //11

																				   //PRONE
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"proneStab.0.arm"].m_Bitmap); //12
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"proneStab.1.arm"].m_Bitmap); // 13

	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"Arm_hide"].m_Bitmap); //14
																			  //Attack2
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO2.0.arm"].m_Bitmap); //15
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO2.1.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO2.2.arm"].m_Bitmap); //17
																				   //Attack3
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO3.0.arm"].m_Bitmap); //18
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO3.1.arm"].m_Bitmap);
	m_Parts[PART_ARM].m_Renderer.AddBitmap(m_BaseList[L"swingO3.2.arm"].m_Bitmap); //20

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
	m_Parts[PART_FACE].m_Renderer.AddBitmap(m_FaceList[L"hide.face"].m_Bitmap); //3
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

	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO1.0.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO1.1.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO1.2.mail"].m_Bitmap); //11

																					 //PRONE prone.0.mail
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"prone.0.mail"].m_Bitmap); //12
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"proneStab.0.mail"].m_Bitmap); //13
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"proneStab.1.mail"].m_Bitmap); //14

																					   //ladder
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"ladder.0.mail"].m_Bitmap); //15
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"ladder.1.mail"].m_Bitmap); //16
																					//Attack2
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO2.0.mail"].m_Bitmap);//17
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO2.1.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO2.2.mail"].m_Bitmap);//19
																					//Attack3
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO3.0.mail"].m_Bitmap);//20
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO3.1.mail"].m_Bitmap);
	m_Parts[PART_COAT].m_Renderer.AddBitmap(m_CoatList[L"swingO3.2.mail"].m_Bitmap);//22

	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.0.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.1.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.2.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"stand1.0.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.0.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.1.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.2.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"walk1.3.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"fly.1.mailArm"].m_Bitmap);

	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO1.0.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO1.1.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO1.2.mailArm"].m_Bitmap); //11
																							   //PRONE
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"prone.0.mailArm"].m_Bitmap); // 12
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"proneStab.0.mailArm"].m_Bitmap); //13
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"proneStab.1.mailArm"].m_Bitmap); //14
																							 //hide.coatArm
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"hide.coatArm"].m_Bitmap); //15
																					  //Attack2
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO2.0.mailArm"].m_Bitmap);//16
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO2.1.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO2.2.mailArm"].m_Bitmap);//18
																						  //Attack3
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO3.0.mailArm"].m_Bitmap);//19
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO3.1.mailArm"].m_Bitmap);
	m_Parts[PART_COATARM].m_Renderer.AddBitmap(m_CoatList[L"swingO3.2.mailArm"].m_Bitmap);//21
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

	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO1.0.pants"].m_Bitmap); //9
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO1.1.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO1.2.pants"].m_Bitmap); //11
																						//prone
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"prone.0.pants"].m_Bitmap); //12
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"proneStab.0.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"proneStab.1.pants"].m_Bitmap); //14
																						  //ladder
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"ladder.0.pants"].m_Bitmap); //15
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"ladder.1.pants"].m_Bitmap); //16
																					   //Atttack2
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO2.0.pants"].m_Bitmap); //17
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO2.1.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO2.2.pants"].m_Bitmap);//19
																					   //Atttack3
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO3.0.pants"].m_Bitmap); //20
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO3.1.pants"].m_Bitmap);
	m_Parts[PART_PANTS].m_Renderer.AddBitmap(m_PantsList[L"swingO3.2.pants"].m_Bitmap);//22
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

	//	Attack
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO1.0.shoes"].m_Bitmap);//6
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO1.1.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO1.2.shoes"].m_Bitmap);//8
																					   //	//prone
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"prone.0.shoes"].m_Bitmap);//9
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"proneStab.0.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"proneStab.1.shoes"].m_Bitmap);//11
																						 // ladder
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"ladder.0.shoes"].m_Bitmap); //12
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"ladder.1.shoes"].m_Bitmap);//13
																					  //	Attack2
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO2.0.shoes"].m_Bitmap);//14
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO2.1.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO2.2.shoes"].m_Bitmap);//16
																					   //	Attack3
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO3.0.shoes"].m_Bitmap);//17
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO3.1.shoes"].m_Bitmap);
	m_Parts[PART_SHOES].m_Renderer.AddBitmap(m_ShoesList[L"swingO3.2.shoes"].m_Bitmap);//19
}

void PlayerTest::SettingWeapon()
{
	m_Parts[PART_WEAPON].m_Renderer.ClearBitmap();
	m_Weapon = 101;
	LoadImg("weapon\\", m_Weapon, m_WeaponList);

	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"walk1.3.weapon"].m_Bitmap);

	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"walk1.0.weapon"].m_Bitmap);
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"walk1.1.weapon"].m_Bitmap);
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"walk1.2.weapon"].m_Bitmap);
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"walk1.3.weapon"].m_Bitmap); //4

																						 //m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"fly.0.weapon"].m_Bitmap);
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"fly.1.weapon"].m_Bitmap); //6 // 5

	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO1.0.weapon"].m_Bitmap);  //6
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO1.1.weapon"].m_Bitmap);
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO1.2.weapon"].m_Bitmap); //8


	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingOF.0.weapon"].m_Bitmap); //9

	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"prone.0.weapon"].m_Bitmap); //10
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"proneStab.0.weapon"].m_Bitmap); //11
																							 //hide.weapon
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"hide.weapon"].m_Bitmap); //12
																					  //Attack2
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO2.0.weapon"].m_Bitmap);//13
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO2.1.weapon"].m_Bitmap);
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO2.2.weapon"].m_Bitmap);//15
																						  //Attack3
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO3.0.weapon"].m_Bitmap);//16
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO3.1.weapon"].m_Bitmap);
	m_Parts[PART_WEAPON].m_Renderer.AddBitmap(m_WeaponList[L"swingO3.2.weapon"].m_Bitmap);//18




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

