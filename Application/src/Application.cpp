#include "apppch.h"
#include "Application.h"

Application::Application()
{
	ARD_LOG_INIT();

	m_window = std::unique_ptr<Windowing::Window>(Windowing::Window::Create());
	m_window->set_event_callback(std::bind(&Application::on_event, this, std::placeholders::_1));
}

Application::~Application()
{

}

void Application::run()
{
	m_running = true;
	ARD_LOG_INFO("Begun running");

	while (m_running)
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_window->on_update();
	}
}

void Application::on_event(Event& e)
{
	ARD_LOG_INFO("{0}", e.GetEventType());
}