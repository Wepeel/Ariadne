#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>


std::shared_ptr<spdlog::logger> Log::m_ard_logger;
std::shared_ptr<spdlog::logger> Log::m_game_logger;


void Log::Init()
{
	spdlog::set_pattern("%^[%T] %n:\t%l: %v%$");

	m_ard_logger = spdlog::stdout_color_mt("ARIADNE");
	m_game_logger = spdlog::stdout_color_mt("GAME");

	spdlog::set_level(spdlog::level::debug);
}

void Log::level_trace()
{
	m_ard_logger->set_level(spdlog::level::trace);
}

void Log::level_untrace()
{
	m_ard_logger->set_level(spdlog::level::debug);
}