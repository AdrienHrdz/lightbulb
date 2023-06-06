// lightbulb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <iostream>

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewInit();

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410");




    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();


        ImGuiIO& io = ImGui::GetIO();

        int n = 20;
        printf("NewFrame() %d\n", n);
        io.DisplaySize = ImVec2(1920, 1080);
        io.DeltaTime = 1.0f / 60.0f;
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static float f = 0.0f;
        ImGui::Text("Hello, world!");
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        ImGui::ShowDemoWindow(nullptr);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());



    }
    ImGui::DestroyContext();

    glfwTerminate();

    //// Build atlas
    //unsigned char* tex_pixels = nullptr;
    //int tex_w, tex_h;
    //io.Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);

    //while (true)
    //{
    //    int n = 20;
    //    printf("NewFrame() %d\n", n);
    //    io.DisplaySize = ImVec2(1920, 1080);
    //    io.DeltaTime = 1.0f / 60.0f;
    //    ImGui::NewFrame();

    //    static float f = 0.0f;
    //    ImGui::Text("Hello, world!");
    //    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    //    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    //    ImGui::ShowDemoWindow(nullptr);

    //    ImGui::Render();
    //}

    //printf("DestroyContext()\n");
    return 0;
}