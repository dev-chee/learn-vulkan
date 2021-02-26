set(WINDOW_TITLE "Vulkan - window" CACHE STRING "Default window title")
set(WINDOW_WIDTH 800 CACHE STRING "Default window width")
set(WINDOW_HEIGHT 600 CACHE STRING "Default window height")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.txt ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

add_executable(window main.cpp)
target_include_directories(window PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(window PRIVATE glm glfw)
