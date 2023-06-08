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
    window = glfwCreateWindow(640, 480, "LightBulb", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewInit();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");


    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();

        ///* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);

        ///* Swap front and back buffers */
        //glfwSwapBuffers(window);

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }


        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);

        //ImGuiIO& io = ImGui::GetIO();

        //int n = 20;
        //printf("NewFrame() %d\n", n);
        //io.DisplaySize = ImVec2(1920, 1080);
        //io.DeltaTime = 1.0f / 60.0f;
        //ImGui_ImplOpenGL3_NewFrame();
        //ImGui::NewFrame();


        ////ImGui::Begin("fenetre");
        //static float f = 0.0f;
        //ImGui::Text("Hello, world!");
        //ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
        //ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        //ImGui::ShowDemoWindow(nullptr);

        //ImGui::Render();
        //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        //ImGui::End();
    }
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
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