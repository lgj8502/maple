#pragma once

#include <atlbase.h>

enum ePlayerState
{
	PLAYER_IDLE,
	PLAYER_WALK,
	PLAYER_JUMP,
	PLAYER_ATTACK,
	PLAYER_LADDER,
	PLAYER_FIGHT,

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

	// 기본 이동 속도
	float	m_MoveSpeed = 200.0f;
	float	m_JumpPower = 500.0f;

	// 지형과 충돌시 캐릭터가 땅에 박히는 현상 제거용
	float	m_CrashHeight = 0.0f;

	cMapObj *m_LandingTile = nullptr;
	cMapObj *m_OldLandingTile = nullptr;



	D2D1_POINT_2F m_MapPos = {};

	map<wstring, ImgInfo>	m_BaseList;
	map<wstring, ImgInfo>	m_HairList;
	map<wstring, ImgInfo>	m_FaceList;
	map<wstring, ImgInfo>	m_CoatList;
	map<wstring, ImgInfo>	m_PantsList;
	map<wstring, ImgInfo>	m_ShoesList;

	void SettingBase();
	void SettingHair();
	void SettingFace();
	void SettingCoat();
	void SettingPants();
	void SettingShoes();


public:

	size_t m_Base = 100;
	size_t m_Hair = 100;
	size_t m_Face = 100;
	size_t m_Coat = 100;
	size_t m_Pants = 100;
	size_t m_Shoes = 100;

	///////////////////// 스탯 //////////////////////////////////////////////////////



	// 이속률 (캐릭터가 가지는 이동 스탯)  100.0f == 1배
	float	m_MoveSpeedRatio = 100.0f;
	float	m_JumpPowerRatio = 100.0f;

	int		m_STR = 0;
	int		m_DEX = 0;
	int		m_INT = 0;
	int		m_LUK = 0;

	////////////////////////////////////////////////////////////////////////////////

public:
	PlayerTest();
	~PlayerTest();

	void Update(float _DelayTime = 0.0f);
	void Render();

	bool CrashCheckMap(cMapObj *_obj);
	void Landing(cMapObj* _pLandingTile);
	void GravityOn();
	void BlowJumpTile();


	void SetParent(ePlayerParts _Parent, ePlayerParts _Son);

	void LeftWalk(float _DelayTime);
	void RightWalk(float _DelayTime);

	void StopWalk();

	void JumpMove();

	void ChangeBase(size_t _itemNo);
	void ChangeHair(size_t _itemNo);
	void ChangeFace(size_t _itemNo);
	void ChangeCoat(size_t _itemNo);
	void ChangePants(size_t _itemNo);
	void ChangeShoes(size_t _itemNo);

	void LoadImg(char *_path, size_t _ItemNo, map<wstring, ImgInfo> &_BotmapList);



	inline D2D1_POINT_2F GetMapPos()
	{
		return m_MapPos;
	}



};

