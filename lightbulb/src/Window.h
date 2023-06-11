#pragma once

#include <string>

struct GLFWwindow;

class Window
{
public:
	Window(uint32_t width, uint32_t height, const std::string& title);

	void initialize();
	void shutdown();

	void onUpdate();
private:
	uint32_t m_width, m_height;
	std::string m_title;

	GLFWwindow* m_window = nullptr;
};