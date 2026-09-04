#include "game/survival.hpp"
#include "graphics/object/heightmap3d.hpp"

namespace Survival {
struct State {
  Transform3d cameraTransform;
  Camera3d camera;

  Mesh3d objectMesh;
  Transform3d objectTransform;
  Shader objectShader;
  Texture objectTexture;
  Object3d object;

  Transform3d heightmapTransform;
  Shader heightmapShader;
  Texture heightmapTexture;
  HeightMap3d heightmap;

  // clang-format off
  State()
        : cameraTransform(),
          camera(cameraTransform, 45.0f, 0.01f, 100.0f),
          objectMesh(CUBE_VERTICES, CUBE_INDICES),
          objectTransform(glm::vec3(10.0f, 0.0f, -55.0f)),
          objectShader(
              DEFAULT_OBJECT3D_VERTEX_SHADER_SOURCE,
              DEFAULT_OBJECT3D_FRAGMENT_SHADER_SOURCE
          ),
          objectTexture(
              "/home/suleko/Projects/survival/assets/cubet.png",
              GL_NEAREST_MIPMAP_NEAREST,
              GL_NEAREST
          ),
          object(
              objectMesh,
              objectTransform,
              objectShader,
              objectTexture
          ),
          heightmapTransform(glm::vec3(0.0f, -7.0f, -55.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(35.0f, 0.0f, 0.0f)),
          heightmapShader(
              DEFAULT_OBJECT3D_VERTEX_SHADER_SOURCE,
              DEFAULT_OBJECT3D_FRAGMENT_SHADER_SOURCE
          ),
          heightmapTexture(
              "/home/suleko/Projects/survival/assets/tommy1.jpg",
              GL_LINEAR_MIPMAP_LINEAR,
              GL_LINEAR
          ),
          heightmap(
              glm::vec2(100, 100),
              0.2f,
              heightmapTransform,
              heightmapShader,
              heightmapTexture
          ) {}
  // clang-format on
};

std::optional<State> state;

void Init() { state.emplace(); }

void Update() {
  // state->camera.transform.position.z += 0.01f;
  state->object.transform.rotation.x += 1.0f;
  state->object.transform.rotation.y += 1.0f;
}

void Render() {
  state->object.Draw(state->camera);
  state->heightmap.Draw(state->camera);
}

void Finish() {}
} // namespace Survival
