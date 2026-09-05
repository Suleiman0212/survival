#include "graphics/mesh/mesh3d.hpp"

Mesh3d::Mesh3d(const void *vertices, size_t vertexCount, size_t vertexSize,
               const std::optional<std::vector<Mesh3dIndex>> indices,
               const VertexLayout &layout)
    : vertexCount(vertexCount),
      indexCount(indices.has_value() ? indices->size() : 0) {
  indicesEnabled = indices.has_value();

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  if (indicesEnabled) {
    glGenBuffers(1, &EBO);
  }
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertexCount * vertexSize, vertices,
               GL_STATIC_DRAW);

  if (indicesEnabled) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.value().size() * sizeof(Mesh3dIndex),
                 indices.value().data(), GL_STATIC_DRAW);
  }

  for (auto attribute : layout.attributes) {
    glVertexAttribPointer(attribute.location, attribute.componentCount,
                          attribute.type, attribute.normalized, layout.stride,
                          (void *)attribute.offset);
    glEnableVertexAttribArray(attribute.location);
  }
}

Mesh3d::~Mesh3d() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  if (indicesEnabled)
    glDeleteBuffers(1, &EBO);
}

void Mesh3d::Draw() {
  glBindVertexArray(VAO);
  if (indicesEnabled)
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
  else {
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
  }
}

Mesh3d::Mesh3d(Mesh3d &&other) noexcept
    : VBO(other.VBO), VAO(other.VAO), EBO(other.EBO),
      indicesEnabled(other.indicesEnabled), vertexCount(other.vertexCount),
      indexCount(other.indexCount) {
  other.VAO = 0;
  other.VBO = 0;
  other.EBO = 0;
  other.indicesEnabled = false;
}

Mesh3d &Mesh3d::operator=(Mesh3d &&other) noexcept {
  if (this != &other) {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    if (indicesEnabled)
      glDeleteBuffers(1, &EBO);

    VAO = other.VAO;
    VBO = other.VBO;
    EBO = other.EBO;
    indicesEnabled = other.indicesEnabled;
    vertexCount = other.vertexCount;
    indicesEnabled = other.indicesEnabled;

    other.VAO = 0;
    other.VBO = 0;
    other.EBO = 0;
    other.indicesEnabled = 0;
  }
  return *this;
}
