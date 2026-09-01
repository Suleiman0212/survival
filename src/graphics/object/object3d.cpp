#include "graphics/object/object3d.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "graphics/window.hpp"
#include <glm/glm.hpp>

void Object3d::Draw() {
  glm::mat4 view = glm::mat4(1.0f);
  view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

  glm::mat4 projection = glm::perspective(
      glm::radians(45.0f), (float)Window::width / (float)Window::heigth, 0.1f,
      100.0f);

  glm::mat4 model(1.0f);
  model = glm::translate(model, transform.position);
  model = glm::translate(model, transform.pivot);
  model = glm::rotate(model, glm::radians(transform.rotation.x),
                      glm::vec3(1.0f, 0.0f, 0.0f));
  model = glm::rotate(model, glm::radians(transform.position.y),
                      glm::vec3(0.0f, 1.0f, 0.0f));
  model = glm::rotate(model, glm::radians(transform.rotation.z),
                      glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, -transform.pivot);
  model = glm::scale(model, transform.size);

  shader.Bind();
  shader.SetMat4("view", view);
  shader.SetMat4("projection", projection);
  shader.SetMat4("model", model);

  texture.Bind(GL_TEXTURE0);
  shader.SetInt("textureZero", 0);
  mesh.Draw();
}
