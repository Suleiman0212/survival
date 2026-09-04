#pragma once

#include "graphics/data/transform2d.hpp"
#include "graphics/material/shader.hpp"
#include "graphics/material/texture.hpp"
#include "graphics/mesh/mesh2d.hpp"

static inline const char *DEFAULT_OBJECT2D_VERTEX_SHADER_SOURCE = R"(
  #version 330 core

  layout (location = 0) in vec2 position;
  layout (location = 1) in vec2 aUv;

  uniform mat4 projection;
  uniform mat4 view;
  uniform mat4 model;

  out vec2 uv;

  void main() {
    gl_Position = projection * model * vec4(position, 0.0f, 1.0f);
    uv = aUv;
  }
)";

static inline const char *DEFAULT_OBJECT2D_FRAGMENT_SHADER_SOURCE = R"(
  #version 330 core

  in vec2 uv;

  out vec4 fragColor;

  uniform sampler2D textureZero;

  void main() {
    fragColor = texture(textureZero, uv);
  }
)";

class Object2d {
public:
  Object2d(Mesh2d &mesh, Transform2d &transform, Shader &shader,
           Texture &texture)
      : mesh(mesh), transform(transform), shader(shader), texture(texture) {}

  void Draw();

  Transform2d &transform;

private:
  Mesh2d &mesh;
  Shader &shader;
  Texture &texture;
};
