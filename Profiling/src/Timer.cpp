#include "profilingpch.h"
#include "Timer.h"
#include "TimeLogger.h"

timer::timer()
	:m_beginning(clock::now()), m_name("") {}

timer::timer(const char* name)
	: m_beginning(clock::now()), m_name(name)
{}

timer::~timer()
{
	log_elapsed();
}

void timer::log_elapsed() const
{
	time_logger::log_time(m_name, elapsed());
}

void timer::reset()
{
	m_beginning = clock::now();
}

double timer::elapsed() const
{
	return std::chrono::duration_cast<measuring_duration>(clock::now() - m_beginning).count();
}