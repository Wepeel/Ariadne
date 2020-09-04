#pragma once

#include "Window.h"

class Application
{

public:

	Application();

	~Application();

private:

	std::unique_ptr<Windowing::Window> m_window = nullptr;
};