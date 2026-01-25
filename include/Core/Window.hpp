#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace prism {
    class Window {
        public:
            Window(int width, int height, const std::string& title);

            Window(const Window&) = delete;
            Window &operator=(const Window&) = delete;

            bool shouldClose() { return glfwWindowShouldClose(m_window); }

            ~Window();
        private:
            GLFWwindow* m_window;
            std::string m_title;
            
            int m_width;
            int m_height;
    };
} // namespace prism