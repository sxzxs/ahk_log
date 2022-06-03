#include "cpp2ahk_distribute.h"
#include <windows.h>
#include <string>
#include "cpp2ahk.h"
#include <tchar.h>
#include <cstdio>
#include "fstream"
using namespace std;

int cpp2ahk_GetCursorInfo(nlohmann::json &int_json,nlohmann::json &out_json)
{
	int rtn = OK;
	CURSORINFO pci;
	memset(&pci, 0x0,sizeof(CURSORINFO));
	pci.cbSize = 24;
	GetCursorInfo(&pci);
	if (pci.flags == 0)
	{
		out_json["GetCursorInfo"] = "false";
	}
	else
	{
		out_json["GetCursorInfo"] = "true";
	}
	out_json["flag"] = pci.flags;
	return rtn;
}

int spd_log_no_json(std::string log_str, int log_mode, bool is_out_file, bool is_out_console)
{
	int rtn = OK;
	if (is_out_console == 1 && is_out_file == 1)
	{
		Spd_log::instance()->out_log(log_str, log_mode);
		Spd_console::instance()->out_log(log_str, log_mode);
	}
	else if (is_out_console == 1)
	{
		Spd_console::instance()->out_log(log_str, log_mode);
	}
	else if (is_out_file == 1)
	{
		Spd_log::instance()->out_log(log_str, log_mode);
	}
	return rtn;
}
int cpp2ahk_spglog(nlohmann::json &int_json, nlohmann::json &out_json)
{
	int rtn = OK;
	//std::string log_str = to_string(int_json["str"]);
	std::string log_str;
	if (int_json["str"].type() == nlohmann::detail::value_t::string)
	{
		log_str = int_json["str"];
	}
	else
	{
		log_str = to_string(int_json["str"]);
	}
	std::string log_mode = int_json["mode"];
	int is_out_console = int_json["is_out_console"];
	int is_out_file = int_json["is_out_file"];
	if (is_out_console == 1 && is_out_file == 1)
	{
		Spd_log::instance()->out_log(log_str, log_mode);
		Spd_console::instance()->out_log(log_str, log_mode);
	}
	else if (is_out_console == 1)
	{
		Spd_console::instance()->out_log(log_str, log_mode);
	}
	else if (is_out_file == 1)
	{
		Spd_log::instance()->out_log(log_str, log_mode);
	}
	out_json["rtn"] = 0;
	out_json["rtn_msg"] = u8"success";
	return rtn;
}

int write_file(string str)
{
	int rtn = OK;
	FILE *fp = NULL;
	fstream m_fstream("g:/log.txt", ios::in  | ios::app);//创建读取追加
	//fstream m_fstream("g://", ios::in | ios::out); //不存在出错读取覆盖
	//fstream m_fstream(g, ios::in | ios::out | ios::trunc); //创建读取覆盖
	m_fstream << str;
	m_fstream.close();
	return rtn;
}
