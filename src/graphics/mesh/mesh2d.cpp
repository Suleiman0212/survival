#include "graphics/mesh/mesh2d.hpp"
#include <glad/glad.h>

Mesh2d::Mesh2d(std::vector<Mesh2dVertex> vertices) {
  this->vertices = vertices;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Mesh2dVertex),
               vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Mesh2dVertex),
                        (void *)0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Mesh2dVertex),
                        (void *)offsetof(Mesh2dVertex, uv));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

void Mesh2d::Draw() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
