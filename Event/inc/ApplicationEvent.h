#pragma once

#include "Event.h"

class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(unsigned int width, unsigned int height)
		: m_width(width), m_height(height) {}

	unsigned int GetWidth() const { return m_width; }
	unsigned int GetHeight() const { return m_height; }

	SET_EVENT_TYPE(WindowResize)
		SET_EVENT_CATEGORY(EventCategoryApplication)
private:
	unsigned int m_width, m_height;
};

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	SET_EVENT_TYPE(WindowClose)
		SET_EVENT_CATEGORY(EventCategoryApplication)
};

class AppTickEvent : public Event
{
public:
	AppTickEvent() = default;

	SET_EVENT_TYPE(AppTick)
		SET_EVENT_CATEGORY(EventCategoryApplication)
};

class AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() = default;

	SET_EVENT_TYPE(AppUpdate)
		SET_EVENT_CATEGORY(EventCategoryApplication)
};

class AppRenderEvent : public Event
{
public:
	AppRenderEvent() = default;

	SET_EVENT_TYPE(AppRender)
		SET_EVENT_CATEGORY(EventCategoryApplication)
};