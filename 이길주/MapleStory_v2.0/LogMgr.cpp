#include "stdafx.h"
#include "LogMgr.h"

#include <time.h>
#include <fstream>

void LogMgr::CurrentDateTIme()
{
	time_t now = time(0);

	struct tm tstruct;

	localtime_s(&tstruct, &now);

	strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
}

LogMgr::~LogMgr()
{
}

void LogMgr::LogOutput(string _str)
{

	saveFile.open("LogList.txt", ios::app);

	ostringstream Temp;

	CurrentDateTIme();

	Temp << buf << " " << _str.c_str() << endl;	

	saveFile.write(Temp.str().c_str(), Temp.str().size());

	saveFile.close();

	
}

