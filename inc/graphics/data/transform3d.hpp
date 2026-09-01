#pragma once

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
};
