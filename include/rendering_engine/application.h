#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

class Application
{
private:
    unsigned int width_, height_;
    char *title_;
    GLFWwindow *window_;
    
    void ProcessInput();
    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height);

public:
    Application(const unsigned int width, const unsigned height, char *title);
    ~Application();

    void run();
};