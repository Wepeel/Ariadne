#pragma once

#include <spdlog/spdlog.h>

#include <memory>
#include <string_view>


class Log
{
public:

	Log() = delete;

	static void Init();

	static void trace(std::string_view log_message);

	static void debug(std::string_view log_message);

	static void info(std::string_view log_message);

	static void warn(std::string_view log_message);

	static void error(std::string_view log_message);

	static void critical(std::string_view log_message);

	static void level_trace();

	static void level_untrace();


private:

	static std::shared_ptr<spdlog::logger> m_ard_logger;
	static std::shared_ptr<spdlog::logger> m_game_logger;
};

#define ARD_LOG_INIT() Log::Init()


#define ARD_LOG_TRACE_VISIBLE() Log::level_trace()

#define ARD_LOG_TRACE_INVISIBLE() Log::level_untrace()


#define ARD_LOG_TRACE(...) Log::trace(__VA_ARGS__)

#define ARD_LOG_DEBUG(...) Log::debug(__VA_ARGS__)

#define ARD_LOG_INFO(...) Log::info(__VA_ARGS__)

#define ARD_LOG_WARN(...) Log::warn(__VA_ARGS__)

#define ARD_LOG_ERROR(...) Log::error(__VA_ARGS__)

#define ARD_LOG_CRITICAL(...) Log::critical(__VA_ARGS__)