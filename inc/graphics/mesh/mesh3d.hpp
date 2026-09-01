#pragma once

#include <glm/glm.hpp>
#include <vector>

struct Mesh3dVertex {
  glm::vec3 pos;
  glm::vec2 uv;
};

class Mesh3d {
public:
  Mesh3d(std::vector<Mesh3dVertex> vertices);

  void Draw();

  std::vector<Mesh3dVertex> vertices;

private:
  unsigned int VBO, VAO;
};
