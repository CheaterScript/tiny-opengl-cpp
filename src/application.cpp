#include "rendering_engine/application.h"
#include "rendering_engine/eventManager.h"
#include "rendering_engine/renderingContext.h"
#include <iostream>

#if defined(_WIN64)
#define GLFW_EXPOSE_NATIVE_WIN32
#define WIN32_LEAN_AND_MEAN
#include <GLFW/glfw3native.h>
#include <Windows.h>

#endif
void debugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
    std::cout << "Debug message: " << message << std::endl;
}

void SetWindowTransparent(GLFWwindow *window)
{
    HWND hwnd = glfwGetWin32Window(window);

    // 设置窗口样式为层叠
    LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
    SetWindowLong(hwnd, GWL_EXSTYLE, style | WS_EX_LAYERED);

    // 设置窗口背景透明
    BYTE alpha = 0; // 完全透明
    SetLayeredWindowAttributes(hwnd, 0, alpha, LWA_COLORKEY);

    // 将窗口置顶
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

#if defined(_WIN32)
    // 获取屏幕分辨率
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);

    int screenWidth = desktop.right;
    int screenHeight = desktop.bottom;

    // 计算右下角的位置
    int xPos = screenWidth - 800;
    int yPos = screenHeight - 600;

    // 设置窗口位置
    glfwSetWindowPos(window, xPos, yPos);
#endif
}

void Application::Run()
{
    while (!glfwWindowShouldClose(window_))
    {

        ProcessInput();

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Render();

        // GLenum error = glGetError();
        // if (error != GL_NO_ERROR)
        // {
        //     std::cerr << "OpenGL Error: " << error << std::endl;
        // }

        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}

Container &Application::getScene()
{
    return *scene_;
}

void Application::Render()
{
    // 创建上下文
    RenderingContext renderingContext;
    if (mainCamera_)
    {
        renderingContext.viewMatrix = mainCamera_->GetViewMatrix();
        renderingContext.projectionMatrix = mainCamera_->GetProjectionMatrix();
    }

    scene_->Render(renderingContext);
}

void Application::ShowMouseCursor(bool bIsShow)
{

    glfwSetInputMode(window_, GLFW_CURSOR, bIsShow ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
}

void Application::setMainCamera(std::shared_ptr<Camera> camera)
{
    mainCamera_ = camera;
}

std::shared_ptr<Camera> Application::getMainCamera()
{
    return mainCamera_;
}

Application::Application(const unsigned int width, const unsigned height, const char *title) : width_(width), height_(height), title_(title), scene_(std::make_shared<Container>())
{

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window_ = glfwCreateWindow(width_, height_, title, NULL, NULL);
    if (window_ == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window_);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glfwSetWindowUserPointer(window_, this);
    glfwSetFramebufferSizeCallback(window_, Application::FramebufferSizeCallback);
    glfwSetCursorPosCallback(window_, Application::MouseCallback);
    glfwSetKeyCallback(window_, Application::KeyCallback);

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debugCallback, nullptr);

    glEnable(GL_DEPTH_TEST);

#if defined(_WIN32)
    SetWindowTransparent(window_);
#endif
}

Application::~Application()
{
    glfwTerminate();
}

void Application::ProcessInput()
{
    if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window_, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void Application::FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void Application::MouseCallback(GLFWwindow *window, double xpos, double ypos)
{
    Application *app = static_cast<Application *>(glfwGetWindowUserPointer(window));
    if (app)
    {
        MouseEvent e(xpos, ypos);
        app->eventManager.DispatchEvent(EventType::MouseEvent, &e);
    }
}
void Application::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Application *app = static_cast<Application *>(glfwGetWindowUserPointer(window));
    if (app)
    {
        KeyEvent e(key, action);
        app->eventManager.DispatchEvent(EventType::KeyEvent, &e);
    }
}