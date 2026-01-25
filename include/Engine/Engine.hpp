#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Engine/Pipeline.hpp"

const std::vector<const char*> validationLayers = {
  "VK_LAYER_KHRONOS_validation"  
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

namespace prism {
    class Engine {
        public:
            Engine();
            ~Engine();

            Engine(const Engine&) = delete;
            Engine &operator=(const Engine&) = delete;

        private:
            void initVulkan();
            void createInstance();

            bool checkValidationLayerSupport();

            Pipeline m_pipeline;
            VkInstance m_instance;
    };
} // namespace prism