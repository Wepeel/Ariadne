#pragma once
#include "Event.h"
#include "KeyCode.h"

class KeyEvent : public Event
{

public:

	int


protected:

	KeyEvent(int keycode)
		:m_keycode(keycode) {}

	KeyCode m_keycode;
};