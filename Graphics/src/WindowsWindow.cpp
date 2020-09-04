#include "graphicspch.h"
#include "WindowsWindow.h"

namespace Windowing
{

	static std::uint8_t s_GLFW_window_count = 0;

	static void ErrorCallback(int error, const char* description)
	{
		ARD_LOG_ERROR("GLFW error: {0} - {1}", error, description);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_data.Height = props.Height;
		m_data.Width = props.Width;
		m_data.Title = props.Title;

		ARD_LOG_INFO("Started creation of window: {0} - ({1}, {2})", m_data.Title, m_data.Width, m_data.Height);

		if (s_GLFW_window_count == 0)	// First GLFW window created
		{
			int success = glfwInit();
			glfwSetErrorCallback(ErrorCallback);
		}

		m_window = glfwCreateWindow((int)props.Width, (int)props.Height, m_data.Title.c_str(), nullptr, nullptr);
		++s_GLFW_window_count;

		glfwMakeContextCurrent(m_window);

		glfwSetWindowUserPointer(m_window, &m_data);
		set_vsync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
		--s_GLFW_window_count;

		if (s_GLFW_window_count == 0)
		{
			glfwTerminate();
		}
	}

	std::uint32_t WindowsWindow::get_height() const
	{
		return m_data.Height;
	}

	std::uint32_t WindowsWindow::get_width() const
	{
		return m_data.Width;
	}

	bool WindowsWindow::is_vsync() const
	{
		return m_data.VSync;
	}

	void WindowsWindow::set_vsync(bool enable)
	{
		m_data.VSync = enable;
	}

	void WindowsWindow::set_event_callback(const EventCallbackFn& callback)
	{
		m_data.EventCallback = callback;
	}

	void WindowsWindow::on_update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
}