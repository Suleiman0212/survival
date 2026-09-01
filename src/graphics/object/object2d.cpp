#include "graphics/object/object2d.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "graphics/window.hpp"
#include <glm/glm.hpp>

void Object2d::Draw() {
  glm::mat4 projection =
      glm::ortho(0.0f, (float)Window::width, (float)Window::heigth, 0.0f);

  glm::mat4 model(1.0f);
  model = glm::translate(model,
                         glm::vec3(transform.position + transform.pivot, 0.0f));
  model = glm::rotate(model, glm::radians(transform.rotation),
                      glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, glm::vec3(-transform.pivot, 0.0f));
  model = glm::scale(model, glm::vec3(transform.size, 1.0f));

  shader.Bind();
  shader.SetMat4("projection", projection);
  shader.SetMat4("model", model);

  texture.Bind(GL_TEXTURE0);
  shader.SetInt("textureZero", 0);
  mesh.Draw();
}
