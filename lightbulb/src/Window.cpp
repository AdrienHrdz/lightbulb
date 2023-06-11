#include "Window.h"

#include <iostream>

#include <GLFW/glfw3.h>

Window::Window(uint32_t width, uint32_t height, const std::string& title)
	: m_width(width)
	, m_height(height)
	, m_title(title)
{}

void Window::initialize()
{
	if(!glfwInit())
		return;

	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	if (!m_window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(m_window);
}

void Window::shutdown()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::onUpdate()
{
<<<<<<< HEAD
=======
	glfwPollEvents();
	glfwSwapBuffers(m_window);

>>>>>>> 2c899aff754a4f2363b8873928a8cc38749dcddd
	std::cout << "on window update" << std::endl;
}