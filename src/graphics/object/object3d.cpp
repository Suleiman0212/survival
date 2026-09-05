#include "graphics/object/object3d.hpp"
#include <glm/glm.hpp>

void Object3d::Draw(Camera3d &camera) {

  glm::mat4 view = camera.View();
  glm::mat4 projection = camera.Projection();
  glm::mat4 model = transform.Model();

  shader->Bind();
  shader->SetMat4("view", view);
  shader->SetMat4("projection", projection);
  shader->SetMat4("model", model);

  material->Bind(shader);
  mesh.Draw();
}
