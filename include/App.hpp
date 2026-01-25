#pragma once

#include "Core/Window.hpp"
#include "Engine/Engine.hpp"

namespace prism {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            App();
            ~App();

            void run();

        private:
            void mainLoop();

            Window m_window;
            Engine m_engine;
    };
} // namespace prism