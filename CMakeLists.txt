cmake_minimum_required(VERSION 3.10)
project(Engine VERSION 1.0)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Engine src/main.cxx)

add_subdirectory(src/math)
add_subdirectory(tests)
target_link_libraries(Engine PUBLIC 3D-Math)

configure_file(src/config.h.in src/config.h)

target_include_directories(Engine PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/math"
                          )

set_target_properties(Engine 3D-Math tests
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)