#pragma once

#include "rendering_engine/container.h"
#include "rendering_engine/eventManager.h"
#include "rendering_engine/camera.h"
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
    std::shared_ptr<Camera> mainCamera_;

    void ProcessInput();
    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height);
    static void MouseCallback(GLFWwindow *window, double xpos, double ypos);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:
    Application(const unsigned int width, const unsigned height, const char *title);
    ~Application();

    EventManager eventManager;

    void Run();
    Container &getScene();
    void Render();
    void ShowMouseCursor(bool bIsShow);
    void setMainCamera(std::shared_ptr<Camera> camera);
    std::shared_ptr<Camera> getMainCamera();
};