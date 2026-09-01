#include "graphics/renderer.hpp"
#include "graphics/window.hpp"

namespace Renderer {
void Start(float red, float green, float blue) {
  glClearColor(red, green, blue, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void End() {
  glfwSwapBuffers(Window::window);
  glfwPollEvents();
}
} // namespace Renderer
