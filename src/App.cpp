#include "App.hpp"

#include <stdexcept>
#include <iostream>

namespace prism {
    App::App() : m_window(WIDTH, HEIGHT, "Prism"), m_engine() {}

    App::~App() {}

    void App::run() {
        mainLoop();
    }

    void App::mainLoop() {
        while (!m_window.shouldClose()) {
            glfwPollEvents();
        }
    }
    
} // namespace prism