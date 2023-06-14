#pragma once

#include <functional>

enum class eventType
{
	none = 0,
	windowClose
};

class Event
{
public:
	friend class EventDispatcher;

public:
	virtual ~Event() = default;

	virtual eventType getEventType() const = 0;
	virtual const char* getName() const = 0;

protected:
	bool m_handle = false;
};

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;
	virtual ~WindowCloseEvent() = default;

	static inline eventType getStaticEventType() { return eventType::windowClose; }

	virtual eventType getEventType() const override { return getStaticEventType(); }
	virtual const char* getName() const override { return "windowClose"; };
};

class EventDispatcher
{
public:
	template<typename T>
	using EventFn = std::function<bool(T&)>;

public:
	EventDispatcher(Event& event)
		: m_event(event)
	{}

	template<typename T>
	bool disptach(const EventFn<T>& fn)
	{
		if (m_event.getEventType() == T::getStaticEventType())
		{
			m_event.m_handle = fn( *(T*)&m_event );
			return true;
		}
		return false;
	}

private:
	Event& m_event;
};