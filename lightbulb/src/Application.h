#pragma once

#include <string>
#include "Window.h"

class Application
{
public:
	Application(const std::string& title);
	~Application();

	void initialize();
	void shutdown();
	void run();

private:
	Window* m_window;

	bool m_running = true;
};