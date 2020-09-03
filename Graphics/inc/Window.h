#pragma once

#include "graphicspch.h"

struct WindowProperties
{
	std::string title;
	std::uint32_t width;
	std::uint32_t height;
};

class Window
{

public:

	virtual ~Window() = default;

	virtual std::uint32_t get_width() const = 0;

	virtual std::uint32_t get_height() const = 0;


	static Window* Create(const WindowProperties& props = WindowProperties());

};