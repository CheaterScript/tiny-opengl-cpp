#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

class Application
{
private:
    unsigned int width_, height_;
    const char *title_;
    GLFWwindow *window_;
    
    void ProcessInput();
    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height);

public:
    Application(const unsigned int width, const unsigned height, const char *title);
    ~Application();

    void run();
};