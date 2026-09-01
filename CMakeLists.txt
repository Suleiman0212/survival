cmake_minimum_required(VERSION 3.20)

project(survival
    VERSION 0.1
    LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 REQUIRED)

add_executable(survival
    src/main.cpp

    src/graphics/window.cpp
    src/graphics/renderer.cpp
    src/graphics/texture.cpp
    src/graphics/objects/sprite.cpp
    src/graphics/objects/mesh.cpp

    src/glad/glad.c
)

target_include_directories(survival
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(survival
    PRIVATE
        glfw
)
