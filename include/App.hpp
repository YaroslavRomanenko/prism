#pragma once

#include "Core/Window.hpp"
#include "Engine/Engine.hpp"

class App {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        App();
        ~App();

        void run();

    private:
        void mainLoop();

        winry::Window m_window;
        sai::Engine m_engine;
};