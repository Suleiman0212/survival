#include "engine/input.hpp"
#include "graphics/window.hpp"

struct KeyState {
  bool pressed = false;
  bool justPressed = false;
};

namespace Input {
KeyState keys[GLFW_KEY_LAST + 1];

void KeyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mods) {
  if (action == GLFW_PRESS) {
    keys[key].pressed = true;
    keys[key].justPressed = true;
  } else {
    keys[key].pressed = false;
  }
}

void Init() { glfwSetKeyCallback(Window::window, KeyCallback); }

bool KeyPressed(int key) { return keys[key].pressed; }

bool KeyJustPressed(int key) { return keys[key].justPressed; }

void StartFrame() { glfwPollEvents(); }

void EndFrame() {
  for (auto &key : keys) {
    key.justPressed = false;
  }
}
} // namespace Input
