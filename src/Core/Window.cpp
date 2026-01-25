#include "Core/Window.hpp"

namespace prism {
    Window::Window(int width, int height, const std::string& title) : m_width(width), m_height(height), m_title(title) {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    }

    Window::~Window() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
} // namespace prism