#pragma once

#include "TemplateSingleton.h"

enum eDataType
{
	DTT_USERINFO,
	DTT_CHARACTER,
	DTT_INVENTORY,


	DTT_END
};

struct sUserInfo
{
	string m_ID = "";
	string m_PassWard = "";
};

#define CHAR_INFO_COUNT 24

struct sCharacter
{
	string m_Name = "";
	int m_Level = 0;
	int m_Exp = 0;
	float m_ExpMax = 0;
	int m_Ability = 0;

	size_t m_Base = 0;
	size_t m_Hair = 0;
	size_t m_Face = 0;
	size_t m_Cap = 0;
	size_t m_Coat = 0;
	size_t m_Pants = 0;
	size_t m_Shoes = 0;
	size_t m_Weapon = 0;

	float m_X = 0.0f;
	float m_Y = 0.0f;

	int m_Map = MNAME_NONE;

	int m_HPmax = 0;
	int m_HP = 0;
	int m_MPmax = 0;
	int m_MP = 0;

	int m_STR = 0;
	int m_DEX = 0;
	int m_INT = 0;
	int m_LUK = 0;


};

struct sInvenInfo
{
	int m_Meso = 0;

	int m_Equip[28] = {};
	int m_UseTem[28] = {};
	int m_Etc[28] = {};
	int m_Install[28] = {};
	int m_Cash[28] = {};
};

//struct sSkillInfo
//{
//	int m_FirstSkill[10] = {};
//	int m_SecondSkill[10] = {};
//};


class cDataMgr : public TemplateSingleton<cDataMgr>
{
	BASESET(cDataMgr);

private:

	FILE			*m_pDataFile;
	CHAR			m_szSaveFile[256];
	vector<string>	DataTypeList;

public:

	string			m_ID = "";
	string			m_CharacterName = "";

public:
	~cDataMgr();

	void Init();

	// ID 생성
	bool Create_UserInfo(sUserInfo _Info);
	// ID 생성시 같은 ID 가 있는지 확인
	bool Check_ID(string _ID);
	// 로그인시 ID와 비번 일치하는지 확인
	bool Check_UserInfo(sUserInfo _Info);

	// 캐릭터 생성
	bool Create_Character(sCharacter _Info);
	bool Load_CharacterInfo(sCharacter &_Info);
	bool Save_Charater();

	bool Load_CharacterList(vector<sCharacter> &_list);

	// 인벤토리 관련
	bool Create_Inventory(sInvenInfo _Info);
	bool Load_Inventory(sInvenInfo &_Info);
	bool Save_Inventory();

	D2D1_POINT_2F Lerp(D2D1_POINT_2F _start, D2D1_POINT_2F _end, float _rate);

	int AddPower(int _Weapon);
	int AddDefence(int _Armor);

	// 게임 종료시 모든 매니저 delete
	void AllMgrDestroy();

	void UseItem(int _ItemNo);

private:


	// 테스트용
	bool TestWrite();
};

#define DATA_MGR	cDataMgr::GetInstance()