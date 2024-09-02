#pragma once

#include "rendering_engine/container.h"
#include "rendering_engine/eventManager.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <memory>

class Application
{
private:
    unsigned int width_, height_;
    const char *title_;
    GLFWwindow *window_;
    std::shared_ptr<Container> scene_;

    void ProcessInput();
    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height);

public:
    Application(const unsigned int width, const unsigned height, const char *title);
    ~Application();

    EventManager eventManager;

    void Run();
    Container & getScene();
    void ShowMouseCursor(bool bIsShow);
};