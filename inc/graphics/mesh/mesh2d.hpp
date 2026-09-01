#pragma once

#include <glm/glm.hpp>
#include <vector>

struct Mesh2dVertex {
  glm::vec2 pos;
  glm::vec2 uv;
};

class Mesh2d {
public:
  Mesh2d(std::vector<Mesh2dVertex> vertices);

  void Draw();

  std::vector<Mesh2dVertex> vertices;

private:
  unsigned int VBO, VAO;
};
