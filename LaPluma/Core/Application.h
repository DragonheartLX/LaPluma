#pragma once

#include "Core.h"

#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>

namespace LaPluma
{
    struct AppSetting
    {
        int width = 1280;
        int height = 720;
        std::string name = "LaPluma App";
    };
    

    class LP_API Application
    { 
    public:
        Application();
        Application(int ac, char** av);
        ~Application();

        void run();
        void init();
    public:
        int argc;
        char** argv;

        AppSetting ap_setting;
        bool ap_isRunning = false;
        GLFWwindow* ap_win = nullptr;
    };
    
    void setViewport(GLFWwindow* window, int width, int height);
    void glfwErrorCallback(int error_code, const char* description);

    Application * createApplication(int argc, char** argv);
} // namespace LaPluma
