#include "apppch.h"
#include "Application.h"

Application::Application()
{
	ARD_PROFILE_FUNCTION();

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

		for (Layer* layer : m_layer_stack)
		{
			layer->on_update();
		}

		m_window->on_update();
	}

	ARD_LOG_INFO("Ended run");
}

void Application::on_event(Event& e)
{
	EventDispatcher disp(e);

	disp.Dispatch<WindowCloseEvent>(std::bind(&Application::on_window_close, this, std::placeholders::_1));

	for (auto it = m_layer_stack.rbegin(); it != m_layer_stack.rend(); ++it)
	{
		(*it)->on_event(e);
		if (e.m_handled)
		{
			break;
		}
	}
}

bool Application::on_window_close(WindowCloseEvent wce)
{
	m_running = false;
	return true;
}

void Application::push_layer(Layer* layer)
{
	m_layer_stack.push_layer(layer);
}

void Application::push_overlay(Layer* overlay)
{
	m_layer_stack.pop_overlay(overlay);
}