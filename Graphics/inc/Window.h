#pragma once

#include "graphicspch.h"

namespace Windowing
{

	struct WindowProperties
	{
		std::string Title;
		std::uint32_t Width;
		std::uint32_t Height;

		WindowProperties(const std::string& title = "Ariadne",
			uint32_t width = 1280,
			uint32_t height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
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

		virtual void on_update() = 0;


		static Window* Create(const WindowProperties& props = WindowProperties());

	};
}