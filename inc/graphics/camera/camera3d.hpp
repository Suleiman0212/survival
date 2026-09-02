#pragma once

#include "graphics/data/transform3d.hpp"

class Camera3d {
public:
  Camera3d(Transform3d &transform, float fov, float near, float far);

  glm::vec3 Forward() const;

  glm::vec3 Right() const;

  glm::vec3 Up() const;

  glm::mat4 View() const;

  glm::mat4 Projection() const;

  Transform3d &transform;
  float yFov, zNear, zFar;
};
