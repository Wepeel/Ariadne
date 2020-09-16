#pragma once

#include "profilingpch.h"

class time_logger
{
public:
	static void log_time(const char* path, double value);
};