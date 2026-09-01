#pragma once

#include "graphics/texture.hpp"
#include <glm/glm.hpp>

class Sprite {
public:
  Sprite(Texture &texture, glm::vec2 pos, glm::vec2 size);

  void draw();

  Texture &texture;
  glm::vec2 pos;
  float rot = 0.0f;
  glm::vec2 size;
  glm::vec2 privot = glm::vec2(0, 0);
};
