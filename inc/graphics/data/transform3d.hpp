#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include <glm/glm.hpp>

class Transform3d {
public:
  Transform3d() {}
  Transform3d(glm::vec3 position) : position(position) {}
  Transform3d(glm::vec3 position, glm::vec3 size)
      : position(position), size(size) {}
  Transform3d(glm::vec3 position, glm::vec3 size, glm::vec3 rotation)
      : position(position), size(size), rotation(rotation) {}
  Transform3d(glm::vec3 position, glm::vec3 size, glm::vec3 rotation,
              glm::vec3 pivot)
      : position(position), size(size), rotation(rotation), pivot(pivot) {}

  glm::vec3 position = {0.0f, 0.0f, 0.0f};
  glm::vec3 size = {1.0f, 1.0f, 1.0f};
  glm::vec3 pivot = {0.0f, 0.0f, 0.0f};
  glm::vec3 rotation = {0.0f, 0.0f, 0.0f};

  glm::mat4 Model() {
    glm::mat4 model(1.0f);
    model = glm::translate(model, position);
    model = glm::translate(model, pivot);
    model = glm::rotate(model, glm::radians(rotation.x),
                        glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(position.y),
                        glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z),
                        glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, -pivot);
    model = glm::scale(model, size);
    return model;
  }
};
