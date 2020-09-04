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
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//TODO: Assertion

		glfwSetWindowUserPointer(m_window, &m_data);
		set_vsync(true);


		// Set Callbacks
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
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
		if (enable)
		{
			glfwSwapInterval(1);
		}

		else
		{
			glfwSwapInterval(0);
		}

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