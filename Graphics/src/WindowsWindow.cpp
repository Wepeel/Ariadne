#include "graphicspch.h"
#include "WindowsWindow.h"

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
	m_data.Height = props.height;
	m_data.Width = props.width;
	m_data.Title = props.title;

	ARD_LOG_INFO("Started creation of window: {0} - ({1}, {2})", m_data.Title, m_data.Width, m_data.Height);


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