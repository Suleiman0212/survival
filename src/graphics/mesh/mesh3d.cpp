#include "graphics/mesh/mesh3d.hpp"
#include <glad/glad.h>

Mesh3d::Mesh3d(std::vector<Mesh3dVertex> vertices) {
  this->vertices = vertices;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Mesh3dVertex),
               vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh3dVertex),
                        (void *)0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Mesh3dVertex),
                        (void *)offsetof(Mesh3dVertex, uv));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

void Mesh3d::Draw() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
