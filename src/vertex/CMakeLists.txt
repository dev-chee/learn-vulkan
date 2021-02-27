set(vertex_WINDOW_TITLE "${PROJECT_NAME} - vertex buffer" CACHE STRING "default window title")
set(vertex_WINDOW_WIDTH 800 CACHE STRING "default window width")
set(vertex_WINDOW_HEIGHT 600 CACHE STRING "default window height")
set(vertex_FRAMES_IN_FLIGHT 2 CACHE STRING "default frames in flight")

configure_file(${CMAKE_CURRENT_LIST_DIR}/config.h.txt ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(vertex main.cpp application.h application.cpp)
target_link_libraries(vertex PRIVATE glm::glm glfw ${Vulkan_LIBRARY})

add_custom_command(
  TARGET vertex POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/shaders
  COMMAND glslc ${CMAKE_CURRENT_LIST_DIR}/shaders/shader.vert -o ${CMAKE_CURRENT_BINARY_DIR}/shaders/vert.spv
  COMMAND glslc ${CMAKE_CURRENT_LIST_DIR}/shaders/shader.frag -o ${CMAKE_CURRENT_BINARY_DIR}/shaders/frag.spv)
