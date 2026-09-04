#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

namespace Window {
extern GLFWwindow *window;
extern int width, height;

void Init(int width, int heigth, const char *title);
void StartFrame(float red, float green, float blue);
void EndFrame();
bool Running();
void Finish();
} // namespace Window
