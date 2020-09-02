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
public:

	SET_EVENT_TYPE(KeyPressed)

		KeyPressedEvent(const KeyCode keycode, const std::uint16_t repeatCount)
		:KeyEvent(keycode), m_repeat_count(repeatCount) {}

	std::uint16_t GetRepeatCount() const { return m_repeat_count; }

private:

	std::uint16_t m_repeat_count;
};

class KeyReleasedEvent : public KeyEvent
{
public:

	SET_EVENT_TYPE(KeyReleased)

		KeyReleasedEvent(const KeyCode keycode)
		:KeyEvent(keycode) {}
};

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(const KeyCode keycode)
		: KeyEvent(keycode) {}

	SET_EVENT_TYPE(KeyTyped)
};