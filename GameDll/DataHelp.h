/************************************************************************/
/* 自动更新基址类                                                                     */
/************************************************************************/
#pragma once
class DataHelp
{
public:
	DataHelp(void);
	~DataHelp(void);
public:
	DWORD ScanAddress(const char *markCode, DWORD distinct = 1, DWORD findMode = 1, LPDWORD offset = NULL);
	DWORD ScanCall(const char *markCode, DWORD distinct = 1, DWORD findMode = 1);
	void UpdateGameData();
};

