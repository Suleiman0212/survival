#include "graphics/camera/camera3d.hpp"
#include "graphics/window.hpp"

Camera3d::Camera3d(Transform3d &transform, float fov, float near, float far)
    : transform(transform), yFov(fov), zNear(near), zFar(far) {}

glm::vec3 Camera3d::Forward() const {
  float pitch = transform.rotation.x;
  float yaw = transform.rotation.y;

  return glm::normalize(
      glm::vec3(cos(pitch) * sin(yaw), sin(pitch), -cos(pitch) * cos(yaw)));
}

glm::vec3 Camera3d::Right() const {
  return glm::normalize(glm::cross(Forward(), glm::vec3(0, 1, 0)));
}

glm::vec3 Camera3d::Up() const {
  return glm::normalize(glm::cross(Right(), Forward()));
}

glm::mat4 Camera3d::View() const {
  return glm::lookAt(transform.position, transform.position + Forward(), Up());
}

glm::mat4 Camera3d::Projection() const {
  return glm::perspective(glm::radians(yFov),
                          (float)Window::width / (float)Window::height, zNear,
                          zFar);
}
