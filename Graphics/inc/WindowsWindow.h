#pragma once

#include "graphicspch.h"
#include "Window.h"

class WindowsWindow : public Window
{
public:

	WindowsWindow();

	virtual ~WindowsWindow();


	std::uint32_t get_width() const override;

	std::uint32_t get_height() const override;

private:

};