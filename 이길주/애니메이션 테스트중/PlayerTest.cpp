#include "stdafx.h"
#include "PlayerTest.h"




PlayerTest::PlayerTest()
{

	GetBaseBitmap();
	GetHairBitmap();
	GetFaceBitmap();
	GetCoatBitmap();
	GetPantsBitmap();
	GetShoesBitmap();

	SetParent(PART_ORIGIN, PART_BODY);

	m_Parts[PART_ORIGIN].m_Transform.SetPos({ 300,500});
	m_Parts[PART_ORIGIN].m_Transform.m_gravity = true;


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

	SetParent(PART_ORIGIN, PART_BODY);
	SetParent(PART_ORIGIN, PART_HEAD);
	SetParent(PART_ORIGIN, PART_ARM);
	SetParent(PART_HEAD, PART_FACE);
	SetParent(PART_HEAD, PART_HAIR);
	SetParent(PART_BODY, PART_COAT);
	SetParent(PART_ARM, PART_COATARM);
	SetParent(PART_ORIGIN, PART_PANTS);
	SetParent(PART_ORIGIN, PART_SHOES);
	SetParent(PART_ORIGIN, PART_HAND);
	SetParent(PART_HEAD, PART_FACE);
	SetParent(PART_HEAD, PART_HAIR);

	///////// 비트맵 교체 애니메이션 //////////////

#pragma region IDLE

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
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
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
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -1, -3 });
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

	m_Parts[PART_BODY].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_ARM].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_COAT].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_COATARM].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_PANTS].m_Renderer.AddAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_SHOES].m_Renderer.AddAnimation(PLAYER_WALK, 1, 4, 0.2, 0.2, 0.2, 0.2);
	m_Parts[PART_HAND].m_Renderer.AddAnimation(PLAYER_WALK, 0, 0, 0.8);	
	
	//////////////  이동 애니메이션 /////////////////////////////////////
	
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -29 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -30 });
	m_Parts[PART_HEAD].m_Transform.AddAniPos({ 1, -29 });
	
	m_Parts[PART_HEAD].m_Transform.AddTransAnimation(PLAYER_WALK, 0, 3, 0.2, 0.2, 0.2, 0.2);
	
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 5, -4 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -5 });
	m_Parts[PART_ARM].m_Transform.AddAniPos({ 11, -4 });
	
	m_Parts[PART_ARM].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 2, 1 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 0 });
	m_Parts[PART_BODY].m_Transform.AddAniPos({ 0, 1 });
	
	m_Parts[PART_BODY].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -4 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -5 });
	m_Parts[PART_COAT].m_Transform.AddAniPos({ 1, -4 });
	m_Parts[PART_COAT].m_Transform.AddTransAnimation(PLAYER_IDLE, 4, 7, 0.5, 0.5, 0.5, 0.5);
	
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 0, -5 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 2, -1 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ 0, -5 });
	m_Parts[PART_COATARM].m_Transform.AddAniPos({ -1, -4 });
	
	m_Parts[PART_COATARM].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 3, 6 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 5, 5 });
	m_Parts[PART_PANTS].m_Transform.AddAniPos({ 5, 6 });
	
	m_Parts[PART_PANTS].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);
	
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 8, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 2, 13 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 6, 12 });
	m_Parts[PART_SHOES].m_Transform.AddAniPos({ 2, 13 });
	
	m_Parts[PART_SHOES].m_Transform.AddTransAnimation(PLAYER_WALK, 4, 7, 0.2, 0.2, 0.2, 0.2);

#pragma endregion WALK

#pragma region JUMP

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

m_Parts[PART_HAND].m_Transform.AddAniPos({ -10, -7});
m_Parts[PART_HAND].m_Transform.AddTransAnimation(PLAYER_JUMP, 0, 0, 5);



#pragma endregion JUMP

}


PlayerTest::~PlayerTest()
{
}

void PlayerTest::Update(float _DelayTime)
{
	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].Update(_DelayTime);
	}

	// 충돌판정 구현 후 삭제 예정
	if (m_Parts[0].m_Transform.GetPos().y > 700.0f)
	{
		m_Parts[0].m_Transform.m_gravity = false;

		m_JumpStart = false;

		m_Parts[0].m_Transform.m_velocityY = 0.0f;

		for (int i = 0; i < PART_END; i++)
		{
			m_Parts[i].m_Renderer.m_State = PLAYER_IDLE;
			m_Parts[i].m_Transform.m_State = PLAYER_IDLE;
		}

		m_Parts[0].m_Transform.Translate(0, -2);

	}
	//

	if (m_Parts[PART_ORIGIN].m_Transform.m_velocityX == 0 && m_Parts[PART_ORIGIN].m_Transform.m_velocityY == 0)
	{
		for (int i = 0; i < PART_END; i++)
		{
			m_Parts[i].m_Renderer.m_State = PLAYER_IDLE;
			m_Parts[i].m_Transform.m_State = PLAYER_IDLE;
		}
	}

	if (m_isJumping == true && m_Parts[0].m_Transform.m_gravity == false)
	{

		for (int i = 0; i < PART_END; i++)
		{
			m_Parts[i].m_Renderer.m_State = PLAYER_JUMP;
			m_Parts[i].m_Transform.m_State = PLAYER_JUMP;
		}


		if (m_JumpStart == false)
		{
			m_Parts[0].m_Transform.m_velocityY = -m_JumpPower * m_JumpPowerRatio * 0.01f;

			m_JumpStart = true;
		}

		m_Parts[0].m_Transform.m_velocityY += 9.81f * _DelayTime * 200.0f;

		if (m_Parts[0].m_Transform.m_velocityY > 0.0f)
		{
			m_Parts[0].m_Transform.m_gravity = true;

			m_isJumping = false;
		}
		else
		{
			m_Parts[0].m_Transform.Translate(0, m_Parts[0].m_Transform.m_velocityY * _DelayTime);
		}
	}
}

void PlayerTest::Render()
{
	for (int i = 0; i < PART_END; i++)
	{
		m_Parts[i].Render();
	}
}

void PlayerTest::SetParent(ePlayerParts _Parent, ePlayerParts _Son)
{
	m_Parts[_Son].m_Transform.m_pParent = &(m_Parts[_Parent].m_Transform);
}

void PlayerTest::LeftWalk(float _DelayTime)
{
	m_Parts[PART_ORIGIN].m_Transform.m_velocityX = -m_MoveSpeed * m_MoveSpeedRatio * 0.01f;
	
	m_Parts[PART_ORIGIN].m_Transform.VelocityTrans(_DelayTime);

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

	m_Parts[PART_ORIGIN].m_Transform.m_velocityX = +m_MoveSpeed * m_MoveSpeedRatio * 0.01f;

	m_Parts[PART_ORIGIN].m_Transform.VelocityTrans(_DelayTime);

	for (int i = 0; i < PART_END; i++)
	{
		if (m_Parts[i].m_Renderer.m_State != PLAYER_JUMP)
		{
			m_Parts[i].m_Renderer.m_State = PLAYER_WALK;
			m_Parts[i].m_Transform.m_State = PLAYER_WALK;

		}
	}
}

void PlayerTest::StopWalk()
{
	m_Parts[0].m_Transform.m_velocityX = 0.0f;
}

void PlayerTest::JumpMove()
{
	m_isJumping = true;
}

void PlayerTest::ChangeCoat(wstring _num)
{

}

void PlayerTest::GetBaseBitmap()
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

void PlayerTest::GetHairBitmap()
{
	m_Parts[PART_HAIR].m_Renderer.ClearBitmap();

	LoadImg("hair\\", m_Hair, m_HairList);

	m_Parts[PART_HAIR].m_Renderer.AddBitmap(m_HairList[L"stand1.0.hairOverHead"].m_Bitmap);
	m_Parts[PART_HAIR].m_Renderer.AddBitmap(m_HairList[L"backDefault.backHair"].m_Bitmap);
}

void PlayerTest::GetFaceBitmap()
{
	m_Parts[PART_FACE].m_Renderer.ClearBitmap();

	LoadImg("face\\", m_Face, m_FaceList);

	m_Parts[PART_FACE].m_Renderer.AddBitmap(m_FaceList[L"default.face"].m_Bitmap);
	m_Parts[PART_FACE].m_Renderer.AddBitmap(m_FaceList[L"blink.1.face"].m_Bitmap);
	m_Parts[PART_FACE].m_Renderer.AddBitmap(m_FaceList[L"blink.2.face"].m_Bitmap);
}

void PlayerTest::GetCoatBitmap()
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

void PlayerTest::GetPantsBitmap()
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

void PlayerTest::GetShoesBitmap()
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
	USES_CONVERSION;

	ostringstream addText;

	addText << _path << _ItemNo << "\\";

	string Str = W2A(m_ImgDir);

	Str += addText.str().c_str();

	LPCWSTR Dir = A2W(Str.c_str());

	IMG_MGR->FileFindDir_Take(Dir, _BotmapList);
}
