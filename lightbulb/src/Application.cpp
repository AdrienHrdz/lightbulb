#include "Application.h"

#include <imgui.h>

// singleton instance
Application* Application::s_instance = nullptr;

Application::Application(const std::string& title)
	: m_window(new Window(1280, 720, title))
{
	s_instance = this;

	initialize();
}

Application::~Application()
{
	shutdown();
}

void Application::initialize()
{
}

void Application::shutdown()
{
}

void Application::run()
{
	while(m_running)
	{
		m_window->onUpdate();
	}
}
