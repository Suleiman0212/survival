#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

namespace Window {
extern GLFWwindow *window;
extern int width, heigth;

void Init(int width, int heigth, const char *title);
bool Running();
void Finish();
bool KeyPressed(int key);
} // namespace Window
