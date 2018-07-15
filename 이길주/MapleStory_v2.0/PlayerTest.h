#pragma once

#include <atlbase.h>

enum ePlayerState
{
	PLAYER_IDLE,
	PLAYER_WALK,
	PLAYER_JUMP,
	PLAYER_ATTACK,
	PLAYER_ATTACK2,
	PLAYER_ATTACK3,
	PLAYER_LADDER,
	PLAYER_LADDERMOVE,
	PLAYER_FIGHT,
	PLAYER_PRONE,
	PLAYER_PRONESTEB,
	PLAYER_HIT,
	PLAYER_DIE,
};

enum ePlayerParts
{
	PART_ORIGIN,
	PART_CENTER,
	//////////////
	PART_BACKSHIELD,
	PART_BODY,
	PART_HEAD,
	PART_FACE,
	PART_HAIR,
	PART_PANTS,
	PART_COAT,
	PART_FRONTSHIELD,
	PART_WEAPON,
	PART_ARM,

	PART_CAP,
	PART_COATARM,
	PART_SHOES,
	PART_HAND,

	PART_END,
};

class PlayerTest
{

	LPCWSTR m_ImgDir = L".\\Img\\Character\\";

private:

	Object2D m_Parts[PART_END];


	bool   m_isJumping = false;
	bool   m_JumpStart = false;

	bool   m_isLanding = false;

	// 기본 이동 속도
	float	m_MoveSpeed = 200.0f;
	float	m_JumpPower = 500.0f;
	float   m_AttackSpeed = 0.9f;


	// 지형과 충돌시 캐릭터가 땅에 박히는 현상 제거용
	float	m_CrashHeight = 0.0f;

	cMapObj *m_LandingTile = nullptr;
	cMapObj *m_OldLandingTile = nullptr;

	bool m_isCrashLadder = false;
	cMapObj *m_CrashedLadder = nullptr;
	cMapObj *m_CrashedTopLadder = nullptr;

	cMapObj *m_CrashedPartal = nullptr;
	bool m_isCrashPortal = false;
	bool m_ChangeMap = false;
	int m_PortalNum = 0;


	bool		m_isProne = false;
	bool		m_isProneSteb = false;

	bool		m_isAttack = false;
	bool	    m_AttackStart = false;
	D2D1_POINT_2F m_AttackEffectPos = {};

	bool		m_isHitted = false;
	float		m_HitTime = 0.5f;
	bool		m_isAlpha = false;
	float		m_AlphaTime = 1.5f;
	float		m_IntervalTime = 0.02f;
	bool		m_isProtected = false;

	bool		m_isDead = false;
	float		m_DeadTime = 2.0f;

	//D2D1_POINT_2F m_MapPos = {};

	map<wstring, ImgInfo>	m_BaseList;
	map<wstring, ImgInfo>	m_HairList;
	map<wstring, ImgInfo>	m_FaceList;
	map<wstring, ImgInfo>	m_CoatList;
	map<wstring, ImgInfo>	m_PantsList;
	map<wstring, ImgInfo>	m_ShoesList;
	map<wstring, ImgInfo>	m_WeaponList;

	void SettingBase();
	void SettingHair();
	void SettingFace();
	void SettingCoat();
	void SettingPants();
	void SettingShoes();

	void SettingWeapon();

	void ChangeState(ePlayerState _state);


public:

	D2D1_POINT_2F m_startPos = {};

	size_t m_Base = 100;
	size_t m_Hair = 100;
	size_t m_Face = 100;
	size_t m_Coat = 100;
	size_t m_Pants = 101;
	size_t m_Shoes = 101;
	size_t m_Weapon = 101;

	///////////////////// 스탯 //////////////////////////////////////////////////////

	int		m_HP = 0;
	int		m_MP = 0;
	int		m_HPmax = 0;
	int		m_MPmax = 0;

	// 이속률 (캐릭터가 가지는 이동 스탯)  100.0f == 1배
	float	m_MoveSpeedRatio = 100.0f;
	float	m_JumpPowerRatio = 100.0f;

	int		m_STR = 0;
	int		m_DEX = 0;
	int		m_INT = 0;
	int		m_LUK = 0;

	int		m_AttackPower = 50;

	////////////////////////////////////////////////////////////////////////////////

public:
	PlayerTest();
	~PlayerTest();


	void Init();
	void Update(float _DelayTime = 0.0f);
	void Render();

	bool CrashCheckMap(cMapObj *_obj);
	bool CrashCheckMob(cMob *_obj, D2D1_POINT_2F _pos);
	void Landing(cMapObj* _pLandingTile);
	void BlowJumpTile();

	void CheckLadder(cMapObj* _Ladder);
	void LadderOff();

	void PortalIn();
	void CheckPortal(cMapObj* _Portal);
	void PortalOff();

	void SetParent(ePlayerParts _Parent, ePlayerParts _Son);

	void LeftWalk(float _DelayTime);
	void RightWalk(float _DelayTime);
	void ClimbLadder(float _DelayTime);
	void DownLadder(float _DelayTime);
	void StopLadder();

	void Prone();
	void NotProne();
	void ProneSteb();

	void Attack();
	void NotAttack();

	void StopWalk();

	void JumpMove();

	void ChangeBase(size_t _itemNo);
	void ChangeHair(size_t _itemNo);
	void ChangeFace(size_t _itemNo);
	void ChangeCoat(size_t _itemNo);
	void ChangePants(size_t _itemNo);
	void ChangeShoes(size_t _itemNo);

	void LoadImg(char *_path, size_t _ItemNo, map<wstring, ImgInfo> &_BotmapList);


	inline void SetPos(D2D1_POINT_2F _pos)
	{
		m_Parts[0].m_Transform.SetPos(_pos);
	}

	inline D2D1_POINT_2F GetPos()
	{
		return m_Parts[0].m_Transform.GetPos();
	}


	inline ePlayerState PlayerState()
	{
		return (ePlayerState)(m_Parts[0].m_Transform.m_State);
	}


};

