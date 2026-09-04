#include "graphics/object/heightmap3d.hpp"
#include "graphics/mesh/mesh3d.hpp"
#include <cstdlib>
#include <ctime>
#include <glad/glad.h>

HeightMap3d::HeightMap3d(glm::vec2 size, glm::ivec2 resolution,
                         Transform3d &transform, Shader &shader,
                         Texture &texture)
    : size(size), resolution(resolution), transform(transform), shader(shader),
      texture(texture) {
  srand(time(NULL));
  std::vector<Mesh3dVertex> vertices;
  std::vector<Mesh3dIndex> indices;

  const int vertexCountX = resolution.x + 1;
  const int vertexCountZ = resolution.x + 1;

  vertices.reserve(vertexCountX * vertexCountZ);
  indices.reserve(resolution.x * resolution.y * 6);

  for (int z = 0; z < vertexCountZ; z++) {
    for (int x = 0; x < vertexCountX; x++) {
      float u = (float)x / resolution.x;
      float v = (float)z / resolution.y;
      float xpos = u * size.x;
      float zpos = v * size.y;
      float ypos = (float)rand() / RAND_MAX * 0.3f;

      vertices.push_back({{xpos, ypos, zpos}, {u, v}});
    }
  }

  for (int z = 0; z < resolution.y - 1; z++) {
    for (int x = 0; x < resolution.x - 1; x++) {
      Mesh3dIndex topLeft = (z * vertexCountX + x);
      Mesh3dIndex topRight = (z * vertexCountX + x + 1);
      Mesh3dIndex bottomLeft = ((z + 1) * vertexCountX + x);
      Mesh3dIndex bottomRight = ((z + 1) * vertexCountX + x + 1);

      indices.push_back(topLeft);
      indices.push_back(bottomLeft);
      indices.push_back(topRight);

      indices.push_back(topRight);
      indices.push_back(bottomLeft);
      indices.push_back(bottomRight);
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
