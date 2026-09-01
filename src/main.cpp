#include "graphics/objects/mesh.hpp"
#include "graphics/renderer.hpp"
#include "graphics/texture.hpp"
#include "graphics/window.hpp"
#include <GLFW/glfw3.h>

int main() {
  Window::init(800, 600, "Survival");

  Texture texture("/home/suleko/Projects/survival/assets/cube.png",
                  GL_NEAREST_MIPMAP_NEAREST, GL_NEAREST);
  Mesh3d mesh1(CUBE, texture, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f});

  while (Window::running()) {
    Renderer::start(0.0f, 0.0f, 0.0f);

    glm::vec3 dir = {0, 0, 0};
    if (Window::keyPressed(GLFW_KEY_W)) {
      dir.x -= 1;
    }
    if (Window::keyPressed(GLFW_KEY_S)) {
      dir.x += 1;
    }
    if (Window::keyPressed(GLFW_KEY_D)) {
      dir.y += 1;
    }
    if (Window::keyPressed(GLFW_KEY_A)) {
      dir.y -= 1;
    }

    mesh1.rot += dir * 0.3f;

    Renderer::draw(mesh1);
    Renderer::end();
  }
  Window::finish();
}
