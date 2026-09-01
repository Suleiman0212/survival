#pragma once

#include <glm/glm.hpp>

class Transform2d {
public:
  Transform2d(glm::vec2 size) : size(size) {}
  Transform2d(glm::vec2 position, glm::vec2 size)
      : position(position), size(size) {}
  Transform2d(glm::vec2 position, glm::vec2 size, float rotation)
      : position(position), size(size), rotation(rotation) {}
  Transform2d(glm::vec2 position, glm::vec2 size, float rotation,
              glm::vec2 pivot)
      : position(position), size(size), rotation(rotation), pivot(pivot) {}

  glm::vec2 position = {0.0f, 0.0f};
  glm::vec2 size;
  glm::vec2 pivot = {0.0f, 0.0f};
  float rotation = 0.0f;
};
