#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION

#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#include "utils.hpp"

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif


class App
{
private:
    GLFWwindow* window;

public:
    windowProperties windowProps;

public:
    App(windowProperties windowProps);
    ~App();

    void update();
    void render();
    bool shouldClose();

    virtual void loop(){

        ImGui::Begin("Please implement loop function", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);
        ImGui::Text("Please implement loop function");
        ImGui::End();
    };
    virtual void startUp(){
        perror("Please implement startUp function");
    };

private:
    
    static void glfw_error_callback(int error, const char* description)
    {
        fprintf(stderr, "GLFW Error %d: %s\n", error, description);
    }

    void setup();
    void cleanup();


};


