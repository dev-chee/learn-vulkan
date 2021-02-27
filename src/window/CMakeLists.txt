set(window_WINDOW_TITLE "${PROJECT_NAME} - window" CACHE STRING "default window title")
set(window_WINDOW_WIDTH 800 CACHE STRING "default window width")
set(window_WINDOW_HEIGHT 600 CACHE STRING "default window height")

configure_file(${CMAKE_CURRENT_LIST_DIR}/config.h.txt ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(window main.cpp)
target_link_libraries(window PRIVATE glm::glm glfw)
