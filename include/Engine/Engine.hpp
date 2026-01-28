#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>

#include "Engine/Pipeline.hpp"

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"  
};

const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif


namespace sai {
    const std::string SHADER_PATH = "../src/Engine/shaders/";
    
    class Engine {
        public:
            Engine(GLFWwindow* window);
            ~Engine();

            Engine(const Engine&) = delete;
            Engine &operator=(const Engine&) = delete;

        private:
            struct QueueFamilyIndices {
                std::optional<uint32_t> graphicsFamily;
                std::optional<uint32_t> presentFamily;

                bool isComplete() { return graphicsFamily.has_value() && presentFamily.has_value(); }
            };

            struct SwapChainSupportDetails {
                VkSurfaceCapabilitiesKHR capabilites;
                std::vector<VkSurfaceFormatKHR> formats;
                std::vector<VkPresentModeKHR> presentModes;
            };

            void initVulkan();

            void createInstance();
            void setupDebugMessenger();
            void createSurface();
            void pickPhysicalDevice();
            void createLogicalDevice();
            void createSwapChain();
            void createImageViews();
            void createGraphicsPipeline();

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

            void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

            bool isDeviceSuitable(VkPhysicalDevice device);
            bool checkDeviceExtensionSupport(VkPhysicalDevice device);

            QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

            SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
            VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
            VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
            VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilites);

            VkShaderModule createShaderModule(const std::vector<char>& code);

            Pipeline m_pipeline;
            VkInstance m_instance;
            VkDebugUtilsMessengerEXT m_debugMessenger;
            GLFWwindow* m_window;
            VkSurfaceKHR m_surface;
            VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
            VkDevice m_device;
            VkQueue m_graphicsQueue;
            VkQueue m_presentQueue;
            VkSwapchainKHR m_swapChain;
            std::vector<VkImage> m_swapChainImages;
            std::vector<VkImageView> m_swapChainImageViews;
            VkFormat m_swapChainImageFormat;
            VkExtent2D m_swapChainExtent;
            VkPipelineLayout m_pipelineLayout;
    };
} // namespace sai