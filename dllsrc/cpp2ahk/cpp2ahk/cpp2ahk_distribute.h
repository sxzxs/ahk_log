#pragma once
#include <iostream>
#include "json.hpp"
#include <string>
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h" // support for loading levels from the environment variable
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/async.h"
#include "spdlog/async_logger.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Spd_console
{
public:
	void out_log(std::string str, std::string log_mode = "info")
	{
		if (log_mode == "info")
		{
			m_console_logger->info(str);
		}
		else if (log_mode == "error")
		{
			m_console_logger->error(str);
		}
		else if (log_mode == "war")
		{
			m_console_logger->warn(str);
		}
		else if (log_mode == "critical")
		{
			m_console_logger->critical(str);
		}
		else
		{
			m_console_logger->info(str);
		}
	}
	void out_log(std::string str, int log_mode)
	{
		if (log_mode == 1)
		{
			m_console_logger->info(str);
		}
		else if (log_mode == 2)
		{
			m_console_logger->warn(str);
		}
		else if (log_mode == 3)
		{
			m_console_logger->error(str);
		}
		else if (log_mode == 4)
		{
			m_console_logger->critical(str);
		}
		else
		{
			m_console_logger->info(str);
		}
	}
	static Spd_console *instance()
	{
		static Spd_console obj;
		return &obj;
	}
private:
	Spd_console()
	{
		::ShowWindow(::GetConsoleWindow(), SW_SHOW);
		spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%F] [pid %P] [thread %t] %^[%l]%$ %v (%ius)");
		spdlog::cfg::load_env_levels();
		//当遇到info消息级别以上的立刻刷新到日志，也可设置为遇到warning级别及其以上的立刻刷新
		m_console_logger = spdlog::stdout_color_mt("console");   
		m_console_logger->flush_on(spdlog::level::info);
	}
	~Spd_console()
	{
		spdlog::flush_every(std::chrono::seconds(3));
		spdlog::shutdown();
	}
	std::shared_ptr<spdlog::logger> m_console_logger;
};
class Spd_log
{
public:
	void out_log(std::string str, std::string log_mode = "info")
	{
		if (log_mode == "info")
		{
			m_daily_logger->info(str);
		}
		else if (log_mode == "error")
		{
			m_daily_logger->error(str);
		}
		else if (log_mode == "war")
		{
			m_daily_logger->warn(str);
		}
		else if (log_mode == "critical")
		{
			m_daily_logger->critical(str);
		}
		else
		{
			m_daily_logger->info(str);
		}
	}
	void out_log(std::string str, int log_mode)
	{
		if (log_mode == 1)
		{
			m_daily_logger->info(str);
		}
		else if (log_mode == 2)
		{
			m_daily_logger->warn(str);
		}
		else if (log_mode == 3)
		{
			m_daily_logger->error(str);
		}
		else if (log_mode == 4)
		{
			m_daily_logger->critical(str);
		}
		else
		{
			m_daily_logger->info(str);
		}
	}
	static Spd_log *instance()
	{
		static Spd_log obj;
		return &obj;
	}
private:
	Spd_log()
	{
		spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%F] [pid %P] [thread %t] %^[%l]%$ %v (%ius)");
		spdlog::cfg::load_env_levels();
		//当遇到info消息级别以上的立刻刷新到日志，也可设置为遇到warning级别及其以上的立刻刷新
		m_daily_logger = spdlog::daily_logger_mt<spdlog::async_factory>("daily", "logs/daily.txt", 2, 30);
		m_daily_logger->flush_on(spdlog::level::info);
	}
	~Spd_log()
	{
		spdlog::flush_every(std::chrono::seconds(3));
		spdlog::shutdown();
	}
	std::shared_ptr<spdlog::logger> m_daily_logger;
};
int cpp2ahk_GetCursorInfo(nlohmann::json &int_json, nlohmann::json &out_json);
int cpp2ahk_spglog(nlohmann::json &int_json, nlohmann::json &out_json);
int spd_log_no_json(std::string log_str, int log_mode, bool is_out_file, bool is_out_console);
int write_file(std::string str);

//int cpp2ahk_GetCursorInfo(nlohmann::json &out_json);

