// lightbulb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <iostream>

#include "Application.h"

// Emedded font
#include "../assets/Roboto-Regular.embed"

int main()
{
    Application* app = new Application("LightBulb");

    app->init();

    app->run();

    app->shutdown();

    return 0;

    //GLFWwindow* window;

    ///* Initialize the library */
    //if (!glfwInit())
    //    return -1;

    ///* Create a windowed mode window and its OpenGL context */
    //window = glfwCreateWindow(1080, 720, "LightBulb", NULL, NULL);
    //if (!window)
    //{
    //    glfwTerminate();
    //    return -1;
    //}

    ///* Make the window's context current */
    //glfwMakeContextCurrent(window);

    //glewInit();

    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;        // Enable Gamepad Controls
    //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // docking
    ////io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

    //ImGui::StyleColorsDark();

    //ImGuiStyle& style = ImGui::GetStyle();
    //if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    //{
    //    style.WindowRounding = 0.0f;
    //    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    //}

    //ImGui_ImplGlfw_InitForOpenGL(window, true);
    //ImGui_ImplOpenGL3_Init("#version 430");

    //// Load default font
    //ImFontConfig fontConfig;
    //fontConfig.FontDataOwnedByAtlas = false;
    //ImFont* robotoFont = io.Fonts->AddFontFromMemoryTTF((void*)g_RobotoRegular, sizeof(g_RobotoRegular), 20.0f, &fontConfig);
    //io.FontDefault = robotoFont;

    //const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    //std::cout << "Width : " << mode->width << std::endl;
    //std::cout << "Height : " << mode->height << std::endl;

    //// Our state
    //bool show_demo_window = true;
    //bool show_another_window = false;
    //ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    ///* Loop until the user closes the window */
    //while (!glfwWindowShouldClose(window))
    //{
    //    /* Poll for and process events */
    //    glfwPollEvents();

    //    // Start the Dear ImGui frame
    //    ImGui_ImplOpenGL3_NewFrame();
    //    ImGui_ImplGlfw_NewFrame();
    //    ImGui::NewFrame();

    //    {
    //        ImGui::Begin("Viewport");

    //        ImGui::End();

    //        ImGui::Begin("Settings");

    //        ImGui::End();
    //    }


    //    // Rendering
    //    ImGui::Render();
    //    int display_w, display_h;
    //    glfwGetFramebufferSize(window, &display_w, &display_h);
    //    glViewport(0, 0, display_w, display_h);
    //    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    //    glClear(GL_COLOR_BUFFER_BIT);


    //    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    //    glfwSwapBuffers(window);
    //}// End While

    //// Cleanup
    //ImGui_ImplOpenGL3_Shutdown();
    //ImGui_ImplGlfw_Shutdown();
    //ImGui::DestroyContext();

    //glfwDestroyWindow(window);
    //glfwTerminate();

    return 0;
}