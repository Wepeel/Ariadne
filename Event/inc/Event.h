#pragma once

#include <string>
#include <sstream>

// The MASK macro just sets up mask bits that we will check our events against
#define MASK(x) 1 << x

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	AppTick, AppUpdate, AppRender,
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory
{
	None = 0,
	EventCategoryApplication = MASK(0),
	EventCategoryInput = MASK(1),
	EventCategoryKeyboard = MASK(2),
	EventCategoryMouse = MASK(3),
	EventCategoryMouseButton = MASK(4)
};

#define SET_EVENT_TYPE(type) static EventType GetStaticType() {return EventType::type;}\
												virtual EventType GetEventType() const override { return GetStaticType();}

#define SET_EVENT_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

class Event
{

public:

	virtual ~Event() = default;

	virtual int GetCategoryFlags() const = 0;
	virtual EventType GetEventType() const = 0;

	bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}

	bool m_handled = false;
};

class EventDispatcher
{
public:
	EventDispatcher(Event& event)
		: m_Event(event)
	{
	}

	// F will be deduced by the compiler
	template<typename T, typename F>
	bool Dispatch(const F& func)
	{
		if (m_Event.GetEventType() == T::GetStaticType())
		{
			m_Event.m_handled = func(static_cast<T&>(m_Event));
			return true;
		}
		return false;
	}
private:
	Event& m_Event;
};