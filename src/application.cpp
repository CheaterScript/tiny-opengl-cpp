#include "rendering_engine/application.h"

#include <iostream>

void debugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
    std::cout << "Debug message: " << message << std::endl;
}

void Application::Run()
{
    while (!glfwWindowShouldClose(window_))
    {

        ProcessInput();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene_->Render();

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

Application::Application(const unsigned int width, const unsigned height, const char *title) : width_(width), height_(height), title_(title), scene_(std::make_unique<Container>())
{

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
    glfwSetFramebufferSizeCallback(window_, Application::FramebufferSizeCallback);

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debugCallback, nullptr);

    glEnable(GL_DEPTH_TEST);
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