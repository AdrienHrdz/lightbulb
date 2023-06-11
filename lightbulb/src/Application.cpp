

#include "Application.h"

Application::Application(const std::string& title)
	: m_window(new Window(1920, 1080, title))
{
}

Application::~Application()
{
}

void Application::initialize()
{
	m_window->initialize();
}

void Application::shutdown()
{
	m_window->shutdown();
}

void Application::run()
{
	while(m_running)
	{
		m_window->onUpdate();
	}
}
