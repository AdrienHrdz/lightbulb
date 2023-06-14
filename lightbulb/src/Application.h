#pragma once

#include <string>
#include <memory>

#include "Window.h"
#include "Event/Event.h"

class Application
{
public:
	Application(const std::string& title);
	~Application();

	static Application& get() { return *s_instance; }
	const std::unique_ptr<Window>& getWindow() const { return m_window; }

	void run();

private:
	void initialize();
	void shutdown();

	void onEvent(Event& e);
	bool onWindowClose(WindowCloseEvent& e);

private:
	std::unique_ptr<Window> m_window;

	bool m_running = true;

	static Application* s_instance;
};