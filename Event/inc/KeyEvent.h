#pragma once
#include "Event.h"
#include "KeyCode.h"

class KeyEvent : public Event
{

public:

	KeyCode GetKeyCode() const { return m_keycode; }

	SET_EVENT_CATEGORY(EventCategoryInput | EventCategoryKeyboard)


protected:

	KeyEvent(KeyCode keycode)
		:m_keycode(keycode) {}

	KeyCode m_keycode;
};


class KeyPressedEvent : public KeyEvent
{

};