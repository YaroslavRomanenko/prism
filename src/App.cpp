#include "App.hpp"

#include <stdexcept>
#include <iostream>

App::App() : m_window(WIDTH, HEIGHT, "Prism"), m_engine(m_window.getGLFWwindowPtr()) {}

App::~App() {}

void App::run() {
    mainLoop();
}

void App::mainLoop() {
    while (!m_window.shouldClose()) {
        glfwPollEvents();
    }
}