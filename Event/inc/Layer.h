#pragma once

#include "eventpch.h"
#include "Event.h"

class Layer
{
public:


	Layer(const std::string& debug_name);

	virtual ~Layer() = default;

	virtual void on_attach() {};

	virtual void on_detach() {};

	virtual void on_update() {};

	virtual void on_event(Event& event) {};


private:

	std::string m_name;
};