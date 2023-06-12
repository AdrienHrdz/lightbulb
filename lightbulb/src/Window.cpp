#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include "../assets/Roboto-Regular.embed"
#include <iostream>

Window::Window(uint32_t width, uint32_t height, const std::string& title)
	: m_width(width)
	, m_height(height)
	, m_title(title)
{
	initialize();
}

Window::~Window()
{
	shutdown();
}

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

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
	{
		std::cout << "on close event" << std::endl;
	});
	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double pos_x, double pos_y)
	{
		std::cout << "Mouse move : [" << pos_x << ", " << pos_y << "]" << std::endl;
	});
	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int keyCode, int scancode, int action, int mods)
	{
		switch (action)
		{
		case GLFW_PRESS : 
			std::cout << "Key pressed : " << keyCode << std::endl;
			break;
		case GLFW_RELEASE:
			std::cout << "Key released : " << keyCode << std::endl;
			break;
		case GLFW_REPEAT:
			std::cout << "Key repeated : " << keyCode << std::endl;
			break;
		}
	});

	/*****************************************
					IMGUI
	*****************************************/
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;        // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // docking

	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
	    style.WindowRounding = 0.0f;
	    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	ImGui_ImplOpenGL3_Init("#version 430");

	// Load default font
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	float fontSize;
	if (mode->width > 2000)
		fontSize = 35.0F;
	else
		fontSize = 20.0f;
	ImFontConfig fontConfig;
	fontConfig.FontDataOwnedByAtlas = false;
	ImFont* robotoFont = io.Fonts->AddFontFromMemoryTTF((void*)g_RobotoRegular, sizeof(g_RobotoRegular), fontSize, &fontConfig);
	io.FontDefault = robotoFont;
}

void Window::shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::onUpdate()
{
	glfwPollEvents();

	ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

	ImGui::ShowDemoWindow();

	int display_w, display_h;
    glfwGetFramebufferSize(m_window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(m_window);
}
