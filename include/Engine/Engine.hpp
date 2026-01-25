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
            std::vector<const char*> getRequiredExtensions();

            static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
                VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                void* pUserData);

            static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, 
                const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                const VkAllocationCallbacks* pAllocator,
                VkDebugUtilsMessengerEXT* pDebugMessenger);

            static void DestroyDebugUtilsMessengerEXT(VkInstance instance, 
                VkDebugUtilsMessengerEXT debugMessenger,
                const VkAllocationCallbacks* pAllocator);

            void setupDebugMessenger();

            void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

            Pipeline m_pipeline;
            VkInstance m_instance;
            VkDebugUtilsMessengerEXT m_debugMessenger;
    };
} // namespace prism