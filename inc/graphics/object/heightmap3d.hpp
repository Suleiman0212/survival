#pragma once

#include "graphics/camera/camera3d.hpp"
#include "graphics/data/transform3d.hpp"
#include "graphics/material/shader.hpp"
#include "graphics/material/texture.hpp"
#include "graphics/mesh/mesh3d.hpp"
#include <optional>

class HeightMap3d {
public:
  HeightMap3d(glm::vec2 size, glm::ivec2 resolution, Transform3d &transform,
              Shader &shader, Texture &texture);

  void Draw(Camera3d &camera);

  Transform3d &transform;

private:
  std::optional<Mesh3d> mesh;
  glm::vec2 size;
  glm::ivec2 resolution;
  Shader &shader;
  Texture &texture;
};
