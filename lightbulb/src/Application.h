#pragma once

#include <string>
#include <memory>

#include "Window.h"
//#include "Gui.h"

class Application
{
public:
	Application(const std::string& title);
	~Application();

	static Application& get() { return *s_instance; }
	const std::shared_ptr<Window> getWindow() const { return m_window; }

	void run();

private:
	void initialize();
	void shutdown();

private:
	std::shared_ptr<Window> m_window;

	bool m_running = true;

	static Application* s_instance;
};