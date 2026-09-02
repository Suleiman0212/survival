#include "game/survival.hpp"

namespace Survival {
struct State {
  Transform3d cameraTransform;
  Camera3d camera;

  Mesh3d objectMesh;
  Transform3d objectTransform;
  Shader objectShader;
  Texture objectTexture;
  Object3d object;

  // clang-format off
  State()
        : cameraTransform(),
          camera(cameraTransform, 45.0f, 0.01f, 100.0f),
          objectMesh(CUBE),
          objectTransform(glm::vec3(0.0f, 0.0f, -1.0f)),
          objectShader(
              DEFAULT_OBJECT3D_VERTEX_SHADER_SOURCE,
              DEFAULT_OBJECT3D_FRAGMENT_SHADER_SOURCE
          ),
          objectTexture(
              "/home/suleko/Projects/survival/assets/tommy1.jpg",
              GL_LINEAR_MIPMAP_LINEAR,
              GL_LINEAR
          ),
          object(
              objectMesh,
              objectTransform,
              objectShader,
              objectTexture
          ) {}
  // clang-format on
};

std::optional<State> state;

void Init() { state.emplace(); }

void Update() {
  state->camera.transform.position.z += 0.01f;
  state->object.transform.rotation.x += 1.0f;
  state->object.transform.rotation.y += 1.0f;
}

void Render() { state->object.Draw(state->camera); }

void Finish() {}
} // namespace Survival
