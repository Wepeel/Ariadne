#include "profilingpch.h"
#include "TimeLogger.h"

void time_logger::log_time(const char* name, double value)
{
	std::printf("%s: %f milliseconds\n", name, value);
}