#pragma once

// The MASK macro just sets up mask bits that we will check our events against
#define MASK(x) 1 << x

enum class EventType
{
	KeyPressedEvent, KeyReleasedEvent, KeyTyped,

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

#define SET_EVENT_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

class Event
{

public:

	virtual int GetCategoryFlags() const = 0;

	bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}
};