#pragma once
#include "Event.h"
#include "MouseCodes.h"

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const float x, const float y)
		: m_mouseX(x), m_mouseY(y) {}

	float GetX() const { return m_mouseX; }
	float GetY() const { return m_mouseY; }

	SET_EVENT_TYPE(MouseMoved)
		SET_EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
private:
	float m_mouseX, m_mouseY;
};

class MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(const float xOffset, const float yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset) {}

	float GetXOffset() const { return m_XOffset; }
	float GetYOffset() const { return m_YOffset; }

	SET_EVENT_TYPE(MouseScrolled)
		SET_EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
private:
	float m_XOffset, m_YOffset;
};

class MouseButtonEvent : public Event
{
public:
	MouseCode GetMouseButton() const { return m_button; }

	SET_EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
protected:
	MouseButtonEvent(const MouseCode button)
		: m_button(button) {}

	MouseCode m_button;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(const MouseCode button)
		: MouseButtonEvent(button) {}

	SET_EVENT_TYPE(MouseButtonPressed)
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(const MouseCode button)
		: MouseButtonEvent(button) {}

	SET_EVENT_TYPE(MouseButtonReleased)
};