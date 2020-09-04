#pragma once

#include "Window.h"

class Application
{

public:

	Application();

	virtual ~Application();

	void run();

private:

	std::unique_ptr<Windowing::Window> m_window = nullptr;

	bool m_running = false;
};