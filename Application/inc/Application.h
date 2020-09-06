#pragma once

#include "apppch.h"

class Application
{

public:

	Application();

	virtual ~Application();

	void run();

	void on_event(Event& e);

	bool on_window_close(WindowCloseEvent wce);

	void push_layer(Layer* layer);

	void push_overlay(Layer* overlay);

private:

	std::unique_ptr<Windowing::Window> m_window = nullptr;

	bool m_running = false;

	LayerStack m_layer_stack;
};