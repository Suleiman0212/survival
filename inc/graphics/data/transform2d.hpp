#pragma once

#include "glm/gtc/matrix_transform.hpp"
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

  glm::mat4 Model() {
    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(position + pivot, 0.0f));
    model =
        glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-pivot, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));
    return model;
  }
};
