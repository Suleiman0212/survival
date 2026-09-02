#include "graphics/object/object2d.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "graphics/window.hpp"
#include <glm/glm.hpp>

void Object2d::Draw() {
  glm::mat4 projection =
      glm::ortho(0.0f, (float)Window::width, (float)Window::heigth, 0.0f);

  glm::mat4 model = transform.Model();

  shader.Bind();
  shader.SetMat4("projection", projection);
  shader.SetMat4("model", model);

  texture.Bind(GL_TEXTURE0);
  shader.SetInt("textureZero", 0);
  mesh.Draw();
}
