cmake_minimum_required(VERSION 3.19)
project(LearnVulkan VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_subdirectory(dependenties)
add_subdirectory(src)

# Vulkan_GLSLC_EXECUTABLE

# if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
#     add_subdirectory(packaging)
# endif()
