#include "Application.h"
#include "Log/Log.h"

namespace LaPluma
{
    Application::Application(): argc(0), argv(nullptr)
    {
        
    };

    Application::Application(int ac, char **av): argc(ac), argv(av)
    {
        
    };

    Application::~Application()
    {

    };

    void Application::init()
    {
        // Init log
        Log::init();
        // GLFW window
        glfwSetErrorCallback(glfwErrorCallback);
        if (!glfwInit())
        {
            LoggerError("GLFW initialize failed.");
            return;
        };

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        ap_win = glfwCreateWindow(ap_setting.width, ap_setting.height, ap_setting.name.c_str(), NULL, NULL);
        if (ap_win == nullptr)
        {
            LoggerError("GLFW windows create failed.");
            glfwTerminate();
            return;
        };
        glfwMakeContextCurrent(ap_win);
        glfwSetFramebufferSizeCallback(ap_win, setViewport);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LoggerError("GLAD load failed.");
            return;
        };
    };

    void Application::run()
    {
        while (!glfwWindowShouldClose(ap_win))
        {
            //processInput(window);

            // render

            glfwSwapBuffers(ap_win);
            glfwPollEvents();
        }

        glfwTerminate();
    };

    void setViewport(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    };

    void glfwErrorCallback(int error_code, const char* description)
    {
        LoggerWarn("GLFW error code: {0:d}. {1}", error_code, description);
    };
} // namespace LaPluma
