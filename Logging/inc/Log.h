#pragma once

#include <spdlog/spdlog.h>

#include <memory>
#include <string_view>


class Log
{
public:

	Log() = delete;

	static void Init();

	static void level_trace();

	static void level_untrace();

	static std::shared_ptr<spdlog::logger> get_core_logger() { return m_ard_logger; };

	static std::shared_ptr<spdlog::logger> get_game_logger() { return m_game_logger; };


private:

	static std::shared_ptr<spdlog::logger> m_ard_logger;
	static std::shared_ptr<spdlog::logger> m_game_logger;
};

#define ARD_LOG_INIT() Log::Init()


#define ARD_LOG_TRACE_VISIBLE() Log::level_trace()

#define ARD_LOG_TRACE_INVISIBLE() Log::level_untrace()


#define ARD_LOG_TRACE(...) Log::get_core_logger()->trace(__VA_ARGS__)

#define ARD_LOG_DEBUG(...) Log::get_core_logger()->debug(__VA_ARGS__)

#define ARD_LOG_INFO(...) Log::get_core_logger()->info(__VA_ARGS__)

#define ARD_LOG_WARN(...) Log::get_core_logger()->warn(__VA_ARGS__)

#define ARD_LOG_ERROR(...) Log::get_core_logger()->error(__VA_ARGS__)

#define ARD_LOG_CRITICAL(...) Log::get_core_logger()->critical(__VA_ARGS__)