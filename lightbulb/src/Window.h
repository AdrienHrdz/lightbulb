#pragma once
#include "glhelper.h"

#include <string>

struct GLFWwindow;

class Window
{
public:
	Window(uint32_t width, uint32_t height, const std::string& title);
	~Window();

	void onUpdate();

	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }

private:
	void initialize();
	void shutdown();

private:
	uint32_t m_width, m_height;
	std::string m_title;

	GLFWwindow* m_window = nullptr;

	unsigned int m_gpuProgramID;
};