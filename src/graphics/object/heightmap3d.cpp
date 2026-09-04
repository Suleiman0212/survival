#include "graphics/object/heightmap3d.hpp"
#include "graphics/mesh/mesh3d.hpp"
#include <cmath>
#include <glad/glad.h>

float GetY(float x, float z) {
  return sin(x * 1.0f) * 1.0f + cos(z * 0.5f) * 0.5f;
}

HeightMap3d::HeightMap3d(glm::vec2 size, float scale, Transform3d &transform,
                         Shader &shader, Texture &texture)
    : size(size), scale(scale), transform(transform), shader(shader),
      texture(texture) {
  std::vector<Mesh3dVertex> vertices;
  std::vector<Mesh3dIndex> indices;

  for (int z = 0; z < size.y; z++) {
    for (int x = 0; x < size.x; x++) {
      float x0 = x * scale;
      float x1 = (x + 1) * scale;
      float z0 = z * scale;
      float z1 = (z + 1) * scale;

      float u0 = (float)x / (size.x - 1);
      float u1 = (float)(x + 1) / (size.x - 1);
      float v0 = (float)z / (size.y - 1);
      float v1 = (float)(z + 1) / (size.y - 1);
      vertices.push_back({{x0, GetY(x0, z0), z0}, {u0, v0}});
      vertices.push_back({{x1, GetY(x1, z0), z0}, {u1, v0}});
      vertices.push_back({{x0, GetY(x0, z1), z1}, {u0, v1}});
      vertices.push_back({{x1, GetY(x1, z1), z1}, {u1, v1}});

      int i = (z * size.x + x) * 4;
      indices.push_back(i);
      indices.push_back(i + 1);
      indices.push_back(i + 2);
      indices.push_back(i + 1);
      indices.push_back(i + 2);
      indices.push_back(i + 3);
    }
  }

  mesh.emplace(vertices, indices);
}

void HeightMap3d::Draw(Camera3d &camera) {

  glm::mat4 view = camera.View();
  glm::mat4 projection = camera.Projection();
  glm::mat4 model = transform.Model();

  shader.Bind();
  shader.SetMat4("view", view);
  shader.SetMat4("projection", projection);
  shader.SetMat4("model", model);

  texture.Bind(GL_TEXTURE0);
  shader.SetInt("textureZero", 0);
  mesh->Draw();
}
