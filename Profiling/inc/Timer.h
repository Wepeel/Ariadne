#pragma once

#include "profilingpch.h"


class timer
{

public:

	timer();

	timer(const char* name);

	~timer();

	void log_elapsed() const;

	void reset();

	double elapsed() const;


private:

	using clock = std::chrono::high_resolution_clock;
	using measuring_duration = std::chrono::milliseconds;

	std::chrono::time_point<clock> m_beginning;

	const char* m_name;
};