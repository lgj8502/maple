#include "stdafx.h"
#include "cDataMgr.h"

#include <Dbghelp.h>
#pragma comment( lib, "Dbghelp.lib" )

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

	for (int i = 0; i < DTT_END; i++)
	{
		//	저장할 파일명 만들기		
		//sprintf_s(m_szSaveFile, 256, "Save/UserIDList.txt");

		//	버퍼 열기
		m_pDataFile = _fsopen(DataTypeList[i].c_str(), "a", SH_DENYNO);

		//printf_s(m_pLogFile, "");

		fclose(m_pDataFile);
		m_pDataFile = NULL;
	}


}

void cDataMgr::Save_UserInfo(sUserInfo _Info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_USERINFO].c_str(), "a", SH_DENYNO);

	char a[256] = "";
	char b[256] = "";
	strcpy_s(a, _Info.m_ID.c_str());
	strcpy_s(b, _Info.m_PassWard.c_str());

	if (m_pDataFile != NULL)
	{
		fprintf_s(m_pDataFile, "%s, %s\n", a, b);

		fclose(m_pDataFile);
		m_pDataFile = NULL;
	}
}

void cDataMgr::Load_UserInfo(sUserInfo & _Info)
{
	m_pDataFile = _fsopen(DataTypeList[DTT_USERINFO].c_str(), "r", SH_DENYNO);

	if (m_pDataFile != NULL)
	{
		char buf[256] = "";
		
		fread_s(buf , 6, 3, 2, m_pDataFile);

		

		fclose(m_pDataFile);
		m_pDataFile = NULL;
	}
}
