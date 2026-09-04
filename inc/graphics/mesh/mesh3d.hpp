#pragma once

#include <glm/glm.hpp>
#include <optional>
#include <vector>

struct Mesh3dVertex {
  glm::vec3 pos;
  glm::vec2 uv;
};

typedef unsigned int Mesh3dIndex;

class Mesh3d {
public:
  Mesh3d(std::vector<Mesh3dVertex> vertices,
         std::optional<std::vector<Mesh3dIndex>> indices);

  void Draw();

  std::vector<Mesh3dVertex> vertices;
  std::optional<std::vector<Mesh3dIndex>> indices;

private:
  unsigned int VBO, VAO;
  std::optional<Mesh3dIndex> EBO;
};
