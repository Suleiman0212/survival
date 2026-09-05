#include "game/survival.hpp"
#include "graphics/mesh/mesh3d.hpp"
#include "graphics/mesh/primitives.hpp"
#include "graphics/object/object3d.hpp"

namespace Survival {
// clang-format off
struct State {
  Transform3d cameraTransform;
  Camera3d camera;
  std::shared_ptr<Shader> objectShader;
  std::shared_ptr<TexturedMaterial> objectMaterial;
  Object3d object;

  State()
    : cameraTransform(),
      camera(cameraTransform, 45.0f, 0.01f, 100.0f),
      objectShader(std::make_shared<Shader>(
          DEFAULT_OBJECT3D_VERTEX_SHADER_SOURCE,
          DEFAULT_OBJECT3D_FRAGMENT_SHADER_SOURCE)),
      objectMaterial(std::make_shared<TexturedMaterial>(
          std::make_shared<Texture>(
              "/home/suleko/Projects/survival/assets/cube.png",
              GL_NEAREST_MIPMAP_NEAREST, GL_NEAREST))),
      object(
          MakeMesh(CUBE_VERTICES, CUBE_INDICES),   // временный -> move напрямую
          Transform3d(glm::vec3(0.0f, 0.0f, -1.0f)),
          objectShader,
          objectMaterial) {}
}; // clang-format on

std::optional<State> state;

void Init() {
  state.emplace();
  glDisable(GL_CULL_FACE);
}

void Update() {
  state->camera.transform.position.z += 0.01f;
  state->object.transform.rotation.x += 0.1f;
  state->object.transform.rotation.z += 0.1f;
}

void Render() { state->object.Draw(state->camera); }

void Finish() {}
} // namespace Survival
