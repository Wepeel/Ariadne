#include "graphicspch.h"
#include "Window.h"
#include "WindowsWindow.h"

namespace Windowing
{
	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}
}