#pragma once

#include "TemplateSingleton.h"

enum eDataType
{
	DTT_USERINFO,
	DTT_CHARACTER,


	DTT_END
};

struct sUserInfo
{
	string m_ID = "";
	string m_PassWard = "";
};

#define CHAR_INFO_COUNT 21

struct sCharacter
{
	string m_Name = "";
	int m_Level = 0;
	float m_Exp = 0.0f;

	size_t m_Base = 0;
	size_t m_Hair = 0;
	size_t m_Face = 0;
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

	// ID ����
	bool Create_UserInfo(sUserInfo _Info);
	// ID ������ ���� ID �� �ִ��� Ȯ��
	bool Check_ID(string _ID);
	// �α��ν� ID�� ��� ��ġ�ϴ��� Ȯ��
	bool Check_UserInfo(sUserInfo _Info);

	// ĳ���� ����
	bool Create_Character(sCharacter _Info);
	bool Load_CharacterInfo(sCharacter &_Info);
	bool Save_Charater(sCharacter _Info);

	bool Load_CharacterList(vector<sCharacter> &_list);

	void AllMgrDestroy();

private:


	// �׽�Ʈ��
	bool TestWrite();
};

#define DATA_MGR	cDataMgr::GetInstance()