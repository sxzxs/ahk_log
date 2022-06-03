// cpp2ahk.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <windows.h>
#include "json.hpp"
#include "cpp2ahk.h"
#include "cpp2ahk_distribute.h"
#include <map>
#include <tchar.h>
#include <codecvt>
#include "cpp2ahk_support.h"
#include <windows.h>

using namespace std;

typedef int (*func)(nlohmann::json &int_json,nlohmann::json &out_json);
std::map<string, func> ALL_DISTRUBUTE_FUNC = 
{
	{"GetCursorInfo", cpp2ahk_GetCursorInfo},
	{"spglog", cpp2ahk_spglog}
};
//mode
//	1 info, 2 warn, 3 err, 4 critcal
extern "C" _declspec(dllexport) int log_simple(char log_str[4000], int log_mode, bool is_out_file, bool is_out_console)
{
	int rtn = OK;
	spd_log_no_json(log_str, log_mode, is_out_file, is_out_console);
	return rtn;
}
//test

extern "C" _declspec(dllexport) int log_simple_test(int *a)
{
	return 1;
}

extern "C" _declspec(dllexport) int cpp2ahk(char in_str[4000], char out_str[4000])
{
	int rtn = OK;
	setlocale(LC_CTYPE, "");
	//string utf8_str = ANSIToUTF8(in_str);
	nlohmann::json in_json = nlohmann::json::parse(in_str);
	nlohmann::json out_json;
	string out_json_str = "";
	if (in_json.is_discarded())
	{
		rtn = -1;
	}
	if (ALL_DISTRUBUTE_FUNC.find(in_json["func"]) != ALL_DISTRUBUTE_FUNC.end())
	{
		rtn = ALL_DISTRUBUTE_FUNC[in_json["func"]](in_json, out_json);
	}
	else
	{
		rtn = -1;
	}

	if (rtn == OK)
	{
		out_json_str = out_json.dump();
		strcpy(out_str, out_json_str.data());
	}
	return rtn;
}
