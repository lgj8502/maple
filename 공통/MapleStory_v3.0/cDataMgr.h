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

class cDataMgr : public TemplateSingleton<cDataMgr>
{
	BASESET(cDataMgr);

private:

	FILE			*m_pConsoleBuffer;
	FILE			*m_pDataFile;

	CHAR			m_szSaveFile[256];
	vector<string>	DataTypeList;

public:
	~cDataMgr();

	void Init();

	void Save_UserInfo(sUserInfo _Info);

	void Load_UserInfo(sUserInfo &_Info);




};

#define DATA_MGR	cDataMgr::GetInstance()