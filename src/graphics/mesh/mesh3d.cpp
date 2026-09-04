#include "graphics/mesh/mesh3d.hpp"
#include <glad/glad.h>

Mesh3d::Mesh3d(std::vector<Mesh3dVertex> vertices,
               std::optional<std::vector<Mesh3dIndex>> indices)
    : vertices(vertices), indices(indices) {

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  if (indices.has_value()) {
    EBO.emplace();
    glGenBuffers(1, &EBO.value());
  }
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Mesh3dVertex),
               vertices.data(), GL_STATIC_DRAW);

  if (indices.has_value()) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO.value());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.value().size() * sizeof(Mesh3dIndex),
                 indices.value().data(), GL_STATIC_DRAW);
  }
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh3dVertex),
                        (void *)0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Mesh3dVertex),
                        (void *)offsetof(Mesh3dVertex, uv));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

void Mesh3d::Draw() {
  glBindVertexArray(VAO);
  if (!indices.has_value())
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
  else {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO.value());
    glDrawElements(GL_TRIANGLES, indices->size(), GL_UNSIGNED_INT, 0);
  }
}
