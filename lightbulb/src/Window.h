#pragma once

#include <string>
#include <functional>

#include "Event/Event.h"

struct GLFWwindow;

class Window
{
public:
	typedef std::function<void(Event&)> EventCallbackFn;

public:
	Window(uint32_t width, uint32_t height, const std::string& title);
	~Window();

	void onUpdate();

	uint32_t getWidth() const { return m_windowData.width; }
	uint32_t getHeight() const { return m_windowData.height; }

	void setEventCallbackFn(const EventCallbackFn& function) { m_windowData.callbackFunction = function; }

private:
	void initialize();
	void shutdown();

private:
	struct WindowData
	{
		uint32_t width, height;
		std::string title;
		EventCallbackFn callbackFunction;
	};

	WindowData m_windowData;

	GLFWwindow* m_window = nullptr;
};