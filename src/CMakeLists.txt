configure_file(${CMAKE_CURRENT_LIST_DIR}/version.h.txt ${CMAKE_CURRENT_BINARY_DIR}/version.h @ONLY)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(window)
# add_subdirectory(triangle)