#include "stdafx.h"
#include "cDataMgr.h"

#include <Dbghelp.h>
#pragma comment( lib, "Dbghelp.lib" )

#include <io.h>

cDataMgr::~cDataMgr()
{
	
}

void cDataMgr::Init()
{
	GetCurrentDirectoryA(_MAX_FNAME, m_szSaveFile);

	//	경로에 Log 경로 설정
	strcat_s(m_szSaveFile, _MAX_FNAME, "\\Save\\");

	//	폴더 생성하기
	MakeSureDirectoryPathExists(m_szSaveFile);

	DataTypeList.push_back("Save/UserIDList.txt");
	DataTypeList.push_back("Save/Character.txt");
	DataTypeList.push_back("Save/Inventory.txt");

	for (int i = 0; i < DTT_END; i++)
	{
		//	저장할 파일명 만들기		
		//sprintf_s(m_szSaveFile, 256, "Save/UserIDList.txt");

		//	버퍼 열기
		m_pDataFile = _fsopen(DataTypeList[i].c_str(), "a", SH_DENYNO);

		//printf_s(m_pLogFile, "");

		::fclose(m_pDataFile);
		m_pDataFile = NULL;
	}


}

bool cDataMgr::Create_UserInfo(sUserInfo _Info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_USERINFO].c_str(), "a", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	fprintf_s(m_pDataFile, "ID %s\n", _Info.m_ID.c_str());
	fprintf_s(m_pDataFile, "PW %s\n", _Info.m_PassWard.c_str());

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return true;

}

bool cDataMgr::Check_ID(string _ID)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_USERINFO].c_str(), "r", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;


	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);

		if (buf[0] == 'I'&& buf[1] == 'D')
		{
			char* Data;
			strtok_s(buf, " ", &Data);

			ID = Data;

			if (ID == _ID + "\n")
			{
				::fclose(m_pDataFile);
				m_pDataFile = NULL;

				return true;
			}
		}


	}

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return false;
}

bool cDataMgr::Check_UserInfo(sUserInfo _Info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_USERINFO].c_str(), "r", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;
	string PW;

	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);


		if (buf[0] == 'I'&& buf[1] == 'D')
		{
			char* Data;
			strtok_s(buf," ", &Data);

			ID = Data;

			if (ID == _Info.m_ID + "\n")
			{
				fgets(buf, sizeof(buf), m_pDataFile);

				if (buf[0] == 'P'&& buf[1] == 'W')
				{
					char* Data;
					strtok_s(buf, " ", &Data);

					PW = Data;

					::fclose(m_pDataFile);
					m_pDataFile = NULL;

					if (PW == _Info.m_PassWard + "\n") return true;

					return false;					
				}
			}
		}
	}	

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return false;

}

bool cDataMgr::Create_Character(sCharacter _info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_CHARACTER].c_str(), "a", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}


	fprintf_s(m_pDataFile, "ID %s\n", m_ID.c_str());
	fprintf_s(m_pDataFile, "Name %s\n", _info.m_Name.c_str());
	fprintf_s(m_pDataFile, "LEVEL %d\n", _info.m_Level);
	fprintf_s(m_pDataFile, "EXP %d\n", _info.m_Exp);
	fprintf_s(m_pDataFile, "EXPMAX %d\n", (int)_info.m_ExpMax);
	fprintf_s(m_pDataFile, "ABILITY %d\n", _info.m_Ability);
	fprintf_s(m_pDataFile, "POSX %f\n", _info.m_X);
	fprintf_s(m_pDataFile, "POSY %f\n", _info.m_Y);
	fprintf_s(m_pDataFile, "MAP %d\n", _info.m_Map);
	fprintf_s(m_pDataFile, "BASE %d\n", _info.m_Base);
	fprintf_s(m_pDataFile, "HAIR %d\n", _info.m_Hair);
	fprintf_s(m_pDataFile, "FACE %d\n", _info.m_Face);
	fprintf_s(m_pDataFile, "CAP %d\n", _info.m_Cap);
	fprintf_s(m_pDataFile, "COAT %d\n", _info.m_Coat);
	fprintf_s(m_pDataFile, "PANTS %d\n", _info.m_Pants);
	fprintf_s(m_pDataFile, "SHOES %d\n", _info.m_Shoes);
	fprintf_s(m_pDataFile, "WEAPON %d\n", _info.m_Weapon);
	fprintf_s(m_pDataFile, "HPMAX %d\n", _info.m_HPmax);
	fprintf_s(m_pDataFile, "HP %d\n", _info.m_HP);
	fprintf_s(m_pDataFile, "MPMAX %d\n", _info.m_MPmax);
	fprintf_s(m_pDataFile, "MP %d\n", _info.m_MP);
	fprintf_s(m_pDataFile, "STR %d\n", _info.m_STR);
	fprintf_s(m_pDataFile, "DEX %d\n", _info.m_DEX);
	fprintf_s(m_pDataFile, "INT %d\n", _info.m_INT);
	fprintf_s(m_pDataFile, "LUK %d\n", _info.m_LUK);

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return true;
}

bool cDataMgr::Load_CharacterInfo(sCharacter & _Info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_CHARACTER].c_str(), "r", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;
	string NAME;

	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);

		if (buf[0] == 'I'&& buf[1] == 'D')
		{
			char* Data;
			strtok_s(buf, " ", &Data);

			ID = Data;

			if (ID == m_ID + '\n' || ID == m_ID + '\0' + '\n')
			{
				fgets(buf, sizeof(buf), m_pDataFile);

				if (buf[0] == 'N'&& buf[1] == 'a' && buf[2] == 'm' && buf[3] == 'e')
				{
					char* Data;
					strtok_s(buf, " ", &Data);

					NAME = Data;					

					for (size_t i = 0; i < NAME.size(); i++)
					{
						if (NAME[i] == '\n')
						{
							NAME[i] = '\0';
						}
					}

					if (NAME != m_CharacterName) continue;

					_Info.m_Name = m_CharacterName;

					vector<string> DataList;

					for (int i = 0; i < CHAR_INFO_COUNT - 1; i++)
					{
						char* load;

						string a = "";

						fgets(buf, sizeof(buf), m_pDataFile);
						strtok_s(buf, " ", &load);

						a = load;

						for (size_t i = 0; i < a.size(); i++)
						{
							if (a[i] == '\n')
							{
								a[i] = '\0';
							}
						}
						
						DataList.push_back(a);
					}

					_Info.m_Level		= stoi(DataList[0]);
					_Info.m_Exp			= stoi(DataList[1]);
					_Info.m_ExpMax		= (float)stoi(DataList[2]);
					_Info.m_Ability		= stoi(DataList[3]);
					_Info.m_X			= stof(DataList[4]);
					_Info.m_Y			= stof(DataList[5]);
					_Info.m_Map			= stoi(DataList[6]);
					_Info.m_Base		= stoi(DataList[7]);
					_Info.m_Hair		= stoi(DataList[8]);
					_Info.m_Face		= stoi(DataList[9]);
					_Info.m_Cap			= stoi(DataList[10]);
					_Info.m_Coat		= stoi(DataList[11]);
					_Info.m_Pants		= stoi(DataList[12]);
					_Info.m_Shoes		= stoi(DataList[13]);
					_Info.m_Weapon		= stoi(DataList[14]);
					_Info.m_HPmax		= stoi(DataList[15]);
					_Info.m_HP			= stoi(DataList[16]);
					_Info.m_MPmax		= stoi(DataList[17]);
					_Info.m_MP			= stoi(DataList[18]);
					_Info.m_STR			= stoi(DataList[19]);
					_Info.m_DEX			= stoi(DataList[20]);
					_Info.m_INT			= stoi(DataList[21]);
					_Info.m_LUK			= stoi(DataList[22]);

					break;
				}
			}
		}


	}

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return false;
}

bool cDataMgr::Save_Charater()
{
	m_pDataFile = _fsopen(DataTypeList[DTT_CHARACTER].c_str(), "r+t", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;
	string NAME;

	long seek;
	long start;


	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);
		seek = ftell(m_pDataFile);

		if (buf[0] == 'I'&& buf[1] == 'D')
		{
			int count = 0;

			for (int i = 0; i < 256; i++)
			{
				count++;

				if (buf[i] == '\0')
				{
					break;
				}
				

			}

			start = seek - count;

			char* Data;
			strtok_s(buf, " ", &Data);

			ID = Data;

			if (ID == m_ID + '\n' || ID == m_ID + '\0' + '\n')
			{
				fgets(buf, sizeof(buf), m_pDataFile);				

				if (buf[0] == 'N'&& buf[1] == 'a' && buf[2] == 'm' && buf[3] == 'e')
				{
					char* Data;
					strtok_s(buf, " ", &Data);

					NAME = Data;

					for (size_t i = 0; i < NAME.size(); i++)
					{
						if (NAME[i] == '\n')
						{
							NAME[i] = '\0';
						}
					}

					if (NAME != m_CharacterName) continue;

					while (true)
					{
						fgets(buf, sizeof(buf), m_pDataFile);

						if (buf[0] == 'L' && buf[1] == 'U' && buf[2] == 'K')
						{
							break;
						}
					}					

					long len = _filelength(_fileno(m_pDataFile)) - ftell(m_pDataFile);

					long a = ftell(m_pDataFile);

					char *tmp = (char*)malloc(len);

					len = fread_s(tmp, len, 1, len, m_pDataFile);

					fseek(m_pDataFile, start, SEEK_SET);

					fwrite(tmp, 1, len, m_pDataFile);

					fflush(m_pDataFile);

					free(tmp);

					_chsize(_fileno(m_pDataFile), ftell(m_pDataFile));					

					break;

				}
			}
		}
	}

	::fclose(m_pDataFile);	

	Create_Character(PLAYER_MGR->m_player->m_CharacInfo);

	return true;


}

bool cDataMgr::Load_CharacterList(vector<sCharacter>& _list)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_CHARACTER].c_str(), "r", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;
	string NAME;

	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);

		if (buf[0] == 'I'&& buf[1] == 'D')
		{
			char* Data;
			strtok_s(buf, " ", &Data);

			ID = Data;

			if (ID == m_ID + "\n")
			{
				fgets(buf, sizeof(buf), m_pDataFile);

				if (buf[0] == 'N'&& buf[1] == 'a' && buf[2] == 'm' && buf[3] == 'e')
				{
					char* Data;
					strtok_s(buf, " ", &Data);

					NAME = Data;

					for (int i = 0; i < 256; i++)
					{
						if (NAME[i] == '\n')
						{
							NAME[i] = '\0';
							break;
						}
					}

					sCharacter Info;

					Info.m_Name = NAME;

					vector<string> DataList;

					for (int i = 0; i < CHAR_INFO_COUNT - 1; i++)
					{
						char* load;

						string a = "";

						fgets(buf, sizeof(buf), m_pDataFile);
						strtok_s(buf, " ", &load);

						a = load;

						for (size_t i = 0; i < a.size(); i++)
						{
							if (a[i] == '\n')
							{
								a[i] = '\0';
							}
						}

						DataList.push_back(a);
					}

					Info.m_Level = stoi(DataList[0]);
					Info.m_Exp = stoi(DataList[1]);
					Info.m_ExpMax = (float)stoi(DataList[2]);
					Info.m_Ability = stoi(DataList[3]);
					Info.m_X = stof(DataList[4]);
					Info.m_Y = stof(DataList[5]);
					Info.m_Map = stoi(DataList[6]);
					Info.m_Base = stoi(DataList[7]);
					Info.m_Hair = stoi(DataList[8]);
					Info.m_Face = stoi(DataList[9]);
					Info.m_Cap = stoi(DataList[10]);
					Info.m_Coat = stoi(DataList[11]);
					Info.m_Pants = stoi(DataList[12]);
					Info.m_Shoes = stoi(DataList[13]);
					Info.m_Weapon = stoi(DataList[14]);
					Info.m_HPmax = stoi(DataList[15]);
					Info.m_HP = stoi(DataList[16]);
					Info.m_MPmax = stoi(DataList[17]);
					Info.m_MP = stoi(DataList[18]);
					Info.m_STR = stoi(DataList[19]);
					Info.m_DEX = stoi(DataList[20]);
					Info.m_INT = stoi(DataList[21]);
					Info.m_LUK = stoi(DataList[22]);

					_list.push_back(Info);					
				}
			}
		}


	}

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return false;
}

bool cDataMgr::Create_Inventory(sInvenInfo _Info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_INVENTORY].c_str(), "a", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	fprintf_s(m_pDataFile, "ID %s\n", m_ID.c_str());
	fprintf_s(m_pDataFile, "Name %s\n", m_CharacterName.c_str());
	fprintf_s(m_pDataFile, "MESO %d\n", _Info.m_Meso);

	for (int i = 0; i < 28; i++)
	{
		fprintf_s(m_pDataFile, "EQUIP%d %d\n", i, _Info.m_Equip[i]);
	}
	for (int i = 0; i < 28; i++)
	{
		fprintf_s(m_pDataFile, "USE%d %d\n", i, _Info.m_UseTem[i]);
	}

	fprintf_s(m_pDataFile, "END\n");

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return true;
}

bool cDataMgr::Load_Inventory(sInvenInfo & _Info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_INVENTORY].c_str(), "r", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;
	string NAME;

	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);

		if (buf[0] == 'I'&& buf[1] == 'D')
		{
			char* Data;
			strtok_s(buf, " ", &Data);

			ID = Data;

			if (ID == m_ID + '\n' || ID == m_ID + '\0' + '\n')
			{
				fgets(buf, sizeof(buf), m_pDataFile);

				if (buf[0] == 'N'&& buf[1] == 'a' && buf[2] == 'm' && buf[3] == 'e')
				{
					char* Data;
					strtok_s(buf, " ", &Data);

					NAME = Data;

					for (size_t i = 0; i < NAME.size(); i++)
					{
						if (NAME[i] == '\n')
						{
							NAME[i] = '\0';
						}
					}

					if (NAME != m_CharacterName) continue;

					//_Info.m_Name = m_CharacterName;

					vector<string> DataList;

					for (int i = 0; i < 28 + 28 + 1; i++)
					{
						char* load;

						string a = "";

						fgets(buf, sizeof(buf), m_pDataFile);
						strtok_s(buf, " ", &load);

						a = load;
						
						for (size_t i = 0; i < a.size(); i++)
						{
							if (a[i] == '\n')
							{
								a[i] = '\0';
							}
						}

						DataList.push_back(a);
					}

					_Info.m_Meso = stoi(DataList[0]);

					for (int i = 0; i < 28; i++)
					{
						_Info.m_Equip[i] = stoi(DataList[i + 1]);
					}
					for (int i = 0; i < 28; i++)
					{
						_Info.m_UseTem[i] = stoi(DataList[i + 29]);	
					}

					break;
				}
			}
		}


	}

	::fclose(m_pDataFile);
	m_pDataFile = NULL;

	return false;
}

bool cDataMgr::Save_Inventory()
{
	m_pDataFile = _fsopen(DataTypeList[DTT_INVENTORY].c_str(), "r+t", SH_DENYNO);

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;
	string NAME;

	long seek;
	long start;


	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);
		seek = ftell(m_pDataFile);

		if (buf[0] == 'I'&& buf[1] == 'D')
		{
			int count = 0;

			for (int i = 0; i < 256; i++)
			{
				count++;

				if (buf[i] == '\0')
				{
					break;
				}


			}

			start = seek - count;

			char* Data;
			strtok_s(buf, " ", &Data);

			ID = Data;

			if (ID == m_ID + '\n' || ID == m_ID + '\0' + '\n')
			{
				fgets(buf, sizeof(buf), m_pDataFile);

				if (buf[0] == 'N'&& buf[1] == 'a' && buf[2] == 'm' && buf[3] == 'e')
				{
					char* Data;
					strtok_s(buf, " ", &Data);

					NAME = Data;

					for (size_t i = 0; i < NAME.size(); i++)
					{
						if (NAME[i] == '\n')
						{
							NAME[i] = '\0';
						}
					}

					if (NAME != m_CharacterName) continue;

					while (true)
					{
						fgets(buf, sizeof(buf), m_pDataFile);

						if (buf[0] == 'E' && buf[1] == 'N' && buf[2] == 'D')
						{
							break;
						}
					}

					long len = _filelength(_fileno(m_pDataFile)) - ftell(m_pDataFile);

					long a = ftell(m_pDataFile);

					char *tmp = (char*)malloc(len);

					len = fread_s(tmp, len, 1, len, m_pDataFile);

					fseek(m_pDataFile, start, SEEK_SET);

					fwrite(tmp, 1, len, m_pDataFile);

					fflush(m_pDataFile);

					free(tmp);

					_chsize(_fileno(m_pDataFile), ftell(m_pDataFile));

					break;

				}
			}
		}
	}

	::fclose(m_pDataFile);

	Create_Inventory(PLAYER_MGR->m_player->m_InvenInfo);

	return true;
}

D2D1_POINT_2F cDataMgr::Lerp(D2D1_POINT_2F _start, D2D1_POINT_2F _end, float _rate)
{
	D2D1_POINT_2F result = {};

	result.x = _start.x * (1 - _rate) + _end.x * _rate;
	result.y = _start.y * (1 - _rate) + _end.y * _rate;

	return result;
}

int cDataMgr::AddPower(int _Weapon)
{
	switch (_Weapon)
	{
	case 603: return 359;
	case 604: return 1275;
	case 605: return 2357;

	default: return 0;

	}
}

int cDataMgr::AddDefence(int _Armor)
{
	switch (_Armor)
	{
	case 100: return 154;
	case 101: return 154;
	case 102: return 347;
	case 203: return 687;
	case 300: return 35;
	case 301: return 157;
	case 400: return 32;
	case 401: return 102;
	case 402: return 152;

	default: return 0;

	}
}

void cDataMgr::AllMgrDestroy()
{
	if (SCENE_MGR->m_pScene->m_SceneName == "Ingame")
	{
		DATA_MGR->Save_Charater();
		PLAYER_MGR->Destroy();

		EFF_MGR->Destoy();

		MOB_MGR->Destoy();
		MAP_MGR->Destroy();	
	}
	cLogMgr::GetInstance()->Release();
	
	
	UI_MGR->Destroy();



	SCENE_MGR->Destroy();



}

void cDataMgr::UseItem(int _ItemNo)
{
	switch (_ItemNo)
	{
	case 1: 
	{
		PLAYER_MGR->m_player->m_CharacInfo.m_HP += 50;

		if (PLAYER_MGR->m_player->m_CharacInfo.m_HP > PLAYER_MGR->m_player->m_CharacInfo.m_HPmax)
		{
			PLAYER_MGR->m_player->m_CharacInfo.m_HP = PLAYER_MGR->m_player->m_CharacInfo.m_HPmax;
		}
	}break;
	case 2:
	{
		PLAYER_MGR->m_player->m_CharacInfo.m_HP += 300;

		if (PLAYER_MGR->m_player->m_CharacInfo.m_HP > PLAYER_MGR->m_player->m_CharacInfo.m_HPmax)
		{
			PLAYER_MGR->m_player->m_CharacInfo.m_HP = PLAYER_MGR->m_player->m_CharacInfo.m_HPmax;
		}
	}break;
	case 3:
	{
		PLAYER_MGR->m_player->m_CharacInfo.m_HP += 600;

		if (PLAYER_MGR->m_player->m_CharacInfo.m_HP > PLAYER_MGR->m_player->m_CharacInfo.m_HPmax)
		{
			PLAYER_MGR->m_player->m_CharacInfo.m_HP = PLAYER_MGR->m_player->m_CharacInfo.m_HPmax;
		}
	}break;
	case 4:
	{
		PLAYER_MGR->m_player->m_CharacInfo.m_MP += 100;

		if (PLAYER_MGR->m_player->m_CharacInfo.m_MP > PLAYER_MGR->m_player->m_CharacInfo.m_MPmax)
		{
			PLAYER_MGR->m_player->m_CharacInfo.m_MP = PLAYER_MGR->m_player->m_CharacInfo.m_MPmax;
		}
	}break;


	default:
		break;
	}

	SOUND_MGR->SoundResume(L"Usetem");
}

bool cDataMgr::TestWrite()
{
	fopen_s(&m_pDataFile, DataTypeList[DTT_USERINFO].c_str(), "r+t");

	if (m_pDataFile == NULL)
	{
		MK_LOG("데이타 파일 불러오기 실패");
		return false;
	}

	char buf[256];

	string ID;

	long seek;
	long start;


	while (feof(m_pDataFile) == false)
	{
		fgets(buf, sizeof(buf), m_pDataFile);

		seek = ftell(m_pDataFile);

		if (buf[0] == 'P'&& buf[1] == 'W') start = seek;

		if (buf[0] == 'O'&& buf[1] == 'D')
		{

			long len = _filelength(_fileno(m_pDataFile)) - ftell(m_pDataFile) + 6 /* "test" 길이*/;

			char *tmp = (char*)malloc(len);

			len = fread_s(tmp, len, 1, len, m_pDataFile);

			fseek(m_pDataFile, start + 3, SEEK_SET);

			fprintf_s(m_pDataFile, "test\n");

			seek = ftell(m_pDataFile);

			fseek(m_pDataFile, seek, SEEK_SET);

			fwrite(tmp, 1, len, m_pDataFile);

			fflush(m_pDataFile);

			free(tmp);

			_chsize(_fileno(m_pDataFile), ftell(m_pDataFile));

			break;
		
		}
	}	



	
	

	//fprintf_s(m_pDataFile, "Test");





	::fclose(m_pDataFile);

	return false;
}
