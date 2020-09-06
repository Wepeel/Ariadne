#pragma once

#include "eventpch.h"
#include "Layer.h"

class LayerStack
{

public:

	LayerStack();

	~LayerStack();


	void push_layer(Layer* layer);

	void pop_layer(Layer* layer);

	void push_overlay(Layer* overlay);

	void pop_overlay(Layer* overlay);


	std::vector<Layer*>::iterator begin();

	std::vector<Layer*>::iterator end();

	std::vector<Layer*>::reverse_iterator rend();

	std::vector<Layer*>::reverse_iterator rbegin();


private:

	std::vector<Layer*> m_layers;
	std::vector<Layer*>::iterator m_layer_insert;
};