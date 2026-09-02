#pragma once

#include "graphics/camera/camera3d.hpp"
#include "graphics/data/transform3d.hpp"
#include "graphics/material/shader.hpp"
#include "graphics/material/texture.hpp"
#include "graphics/mesh/mesh3d.hpp"

static inline const char *DEFAULT_OBJECT3D_VERTEX_SHADER_SOURCE = R"(
  #version 330 core

  layout (location = 0) in vec3 position;
  layout (location = 1) in vec2 aUv;

  uniform mat4 projection;
  uniform mat4 view;
  uniform mat4 model;

  out vec2 uv;

  void main() {
    gl_Position = projection * view * model * vec4(position, 1.0f);
    uv = aUv;
  }
)";

static inline const char *DEFAULT_OBJECT3D_FRAGMENT_SHADER_SOURCE = R"(
  #version 330 core

  in vec2 uv;

  out vec4 fragColor;

  uniform sampler2D textureZero;

  void main() {
    fragColor = texture(textureZero, uv);
  }
)";

class Object3d {
public:
  Object3d(Mesh3d &mesh, Transform3d &transform, Shader &shader,
           Texture &texture)
      : mesh(mesh), transform(transform), shader(shader), texture(texture) {}

  void Draw(Camera3d camera);

  Mesh3d &mesh;
  Transform3d &transform;
  Shader &shader;
  Texture &texture;
};
