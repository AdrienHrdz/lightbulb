#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "Window.h"

class Application
{

public:
	Application();
	~Application();
	void init();
	void shutdown();
	void run();

public:
	Window* m_Window;
};