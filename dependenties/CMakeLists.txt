include(FetchContent)

#
# Find GLM library
#
find_package(glm CONFIG QUIET)
if(NOT glm_FOUND)
    unset(glm_DIR CACHE)

    FetchContent_Declare(glm
        GIT_REPOSITORY  https://github.com/g-truc/glm.git
        GIT_TAG         0.9.9.8)
    
    FetchContent_MakeAvailable(glm)
endif()

include(FindVulkan)
find_package(Vulkan QUIET REQUIRED)

find_package(glfw CONFIG QUIET)
if(NOT glfw_FOUND)
    unset(glfw_DIR CACHE)

    FetchContent_Declare(glfw
        GIT_REPOSITORY  https://github.com/glfw/glfw.git
        GIT_TAG         3.3.3)

    set(GLFW_USE_HYBRID_HPG OFF CACHE INTERNAL "Force use of high-performance GPU on hybrid systems")
    set(GLFW_VULKAN_STATIC OFF CACHE INTERNAL "Assume the Vulkan loader is linked with the application")
    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    FetchContent_MakeAvailable(glfw)
endif()

target_include_directories(glfw PUBLIC ${Vulkan_INCLUDE_DIR})
target_link_libraries(glfw PUBLIC ${Vulkan_LIBRARY})
