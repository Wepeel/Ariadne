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

	using EventCallbackFn = std::function<void(Event&)>;

	virtual ~Window() = default;

	virtual std::uint32_t get_width() const = 0;

	virtual std::uint32_t get_height() const = 0;

	virtual bool is_vsync() const = 0;

	virtual void set_vsync(bool enable) = 0;

	virtual void set_event_callback(const EventCallbackFn& callback) = 0;


	static Window* Create(const WindowProperties& props = WindowProperties());

};