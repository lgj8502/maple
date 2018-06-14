#pragma once

#include "TemplateSingleton.h"
#include <fstream>

class LogMgr : public TemplateSingleton<LogMgr>
{
	BASESET(LogMgr);

private :

	char buf[30] = "";		

	void CurrentDateTIme();	

public:

	~LogMgr();

	ofstream saveFile;

	void LogOutput(string _str);	

};

#define Log_MGR(x)	LogMgr::GetInstance()->LogOutput(x)