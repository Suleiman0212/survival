#pragma once

#include "graphics/mesh/mesh3d.hpp"
#include <glm/glm.hpp>

extern inline int edgeTable[256];
extern inline int triTable[256][16];

std::vector<Mesh3dVertex>
MarchingCubesGenerateMesh3dVertices(glm::ivec3 resolution, float cellSize,
                                    float isolevel);
