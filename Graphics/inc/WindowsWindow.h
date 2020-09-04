#pragma once

#include "graphicspch.h"
#include "Window.h"

namespace Windowing
{

	class WindowsWindow : public Window
	{
	public:

		WindowsWindow(const WindowProperties& props);

		virtual ~WindowsWindow();


		std::uint32_t get_width() const override;

		std::uint32_t get_height() const override;

		bool is_vsync() const override;

		void set_vsync(bool enable) override;

		void set_event_callback(const EventCallbackFn& callback) override;

		void on_update() override;

		virtual void* get_native_window() const { return m_window; }

	private:

		virtual void Init(const WindowProperties& props);

		virtual void Shutdown();

	private:

		GLFWwindow* m_window;

		struct WindowsData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowsData m_data;
	};
}