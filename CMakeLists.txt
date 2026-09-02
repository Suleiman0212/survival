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

    src/input.cpp
    src/graphics/window.cpp
    src/graphics/renderer.cpp
    src/graphics/gui.cpp
    src/graphics/material/texture.cpp
    src/graphics/material/shader.cpp
    src/graphics/camera/camera3d.cpp
    src/graphics/mesh/mesh2d.cpp
    src/graphics/mesh/mesh3d.cpp
    src/graphics/object/object2d.cpp
    src/graphics/object/object3d.cpp

    lib/glad/glad.c

    lib/imgui/imgui.cpp
    lib/imgui/imgui_demo.cpp
    lib/imgui/imgui_draw.cpp
    lib/imgui/imgui_tables.cpp
    lib/imgui/imgui_widgets.cpp
    lib/imgui/imgui_impl_glfw.cpp
    lib/imgui/imgui_impl_opengl3.cpp

)

target_include_directories(survival
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

target_link_libraries(survival
    PRIVATE
        glfw
)
