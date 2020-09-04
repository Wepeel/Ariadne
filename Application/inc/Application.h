#pragma once

#include "Window.h"

class Application
{

public:

	Application();

	virtual ~Application();

	void run();

	void on_event(Event& e);

private:

	std::unique_ptr<Windowing::Window> m_window = nullptr;

	bool m_running = false;
};