#include "App.hpp"

#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main() {
    App app;

    try {
        app.run();
    } catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}