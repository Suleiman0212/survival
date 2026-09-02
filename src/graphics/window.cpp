#include "graphics/window.hpp"
#include "help/utils.hpp"
#include <GLFW/glfw3.h>

namespace Window {
GLFWwindow *window = NULL;
int width, heigth;

void SizeCallback(GLFWwindow *window, int width, int height) {
  Window::width = width;
  Window::heigth = height;
  glViewport(0, 0, width, height);
}

void Init(int _width, int _heigth, const char *title) {
  width = _width;
  heigth = _heigth;

  glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_SAMPLES, 4);

  Window::window = glfwCreateWindow(width, heigth, title, NULL, NULL);
  if (window == NULL) {
    glfwTerminate();
    Utils::panic("failed to create GLFW window");
  }
  glfwMakeContextCurrent(window);
  Debug::info("GLFW window created");

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    Utils::panic("failed to initialize GLAD");
  }
  Debug::info("GLAD initialized");

  glViewport(0, 0, width, heigth);
  glfwSetFramebufferSizeCallback(window, SizeCallback);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);
  // glEnable(GL_BLEND);
  // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void StartFrame(float red, float green, float blue) {
  glClearColor(red, green, blue, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void EndFrame() { glfwSwapBuffers(window); }

bool Running() { return !glfwWindowShouldClose(window); }

void Finish() {
  glfwTerminate();
  Debug::info("window closed");
}

} // namespace Window
