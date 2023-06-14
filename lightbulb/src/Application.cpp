#include "Application.h"

#include <iostream>

#include <imgui.h>

// singleton instance
Application* Application::s_instance = nullptr;

Application::Application(const std::string& title)
	: m_window(std::make_unique<Window>(1280, 720, title))
{
	s_instance = this;

	m_window->setEventCallbackFn(std::bind(&Application::onEvent, this, std::placeholders::_1));

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

void Application::onEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.disptach<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
}

bool Application::onWindowClose(WindowCloseEvent& e)
{
	std::cout << "On close event (from Application class)" << std::endl;
	m_running = false;
	return true;
}

void Application::run()
{
	while(m_running)
	{
		m_window->onUpdate();
	}
}
