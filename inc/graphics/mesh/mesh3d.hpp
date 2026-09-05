#pragma once

#include <cstddef>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <optional>
#include <vector>

struct VertexAttribute {
  unsigned int location;
  int componentCount;
  int type;
  int normalized;
  size_t offset;
};

struct VertexLayout {
  std::vector<VertexAttribute> attributes;
  size_t stride;
};

struct Mesh3dVertex {
  glm::vec3 pos;
  glm::vec2 uv;

  static VertexLayout GetLayout() {
    return {
        {
            {0, 3, GL_FLOAT, GL_FALSE, offsetof(Mesh3dVertex, pos)},
            {1, 2, GL_FLOAT, GL_FALSE, offsetof(Mesh3dVertex, uv)},
        },
        sizeof(Mesh3dVertex),
    };
  }
};

typedef unsigned int Mesh3dIndex;

class Mesh3d {
public:
  Mesh3d(const void *vertices, size_t vertexCount, size_t vertexSize,
         const std::optional<std::vector<Mesh3dIndex>> indices,
         const VertexLayout &layout);
  Mesh3d(Mesh3d &&) noexcept;
  Mesh3d &operator=(Mesh3d &&) noexcept;
  Mesh3d(const Mesh3d &) = delete;
  Mesh3d &operator=(const Mesh3d &) = delete;
  ~Mesh3d();

  void Draw();

private:
  unsigned int VBO, VAO;
  unsigned int EBO;
  bool indicesEnabled;
  size_t vertexCount;
  size_t indexCount;
};

template <typename Vertex>
Mesh3d MakeMesh(const std::vector<Vertex> &vertices,
                const std::optional<std::vector<Mesh3dIndex>> &indices) {
  return Mesh3d(vertices.data(), vertices.size(), sizeof(Vertex), indices,
                Vertex::GetLayout());
}
