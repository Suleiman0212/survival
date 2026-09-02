// 2D
// #include "graphics/mesh/primitives.hpp"
// #include "graphics/object/object2d.hpp"
// #include "graphics/renderer.hpp"
// #include "graphics/window.hpp"
//
// int main() {
//   Window::Init(1280, 720, "Survival");
//
//   Mesh2d mesh(QUAD);
//   Transform2d transform({100.0f, 100.0f});
//   Shader shader(DEFAULT_OBJECT2D_VERTEX_SHADER_SOURCE,
//                 DEFAULT_OBJECT2D_FRAGMENT_SHADER_SOURCE);
//   Texture texture("/home/suleko/Projects/survival/assets/tommy1.jpg",
//                   GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
//   Object2d object(mesh, transform, shader, texture);
//
//   while (Window::Running()) {
//     Renderer::Start(0.0f, 0.0f, 0.0f);
//
//     object.Draw();
//
//     Renderer::End();
//   }
//
//   Window::Finish();
// }

// 3D
#include "graphics/mesh/primitives.hpp"
#include "graphics/object/object3d.hpp"
#include "graphics/renderer.hpp"
#include "graphics/window.hpp"

int main() {
  Window::Init(1280, 720, "Survival");

  Transform3d cameraTransform;
  Camera3d camera(cameraTransform, 45.0f, 0.01f, 100.0f);

  Mesh3d objectMesh(CUBE);
  Transform3d objectTransform;
  Shader objectShader(DEFAULT_OBJECT3D_VERTEX_SHADER_SOURCE,
                      DEFAULT_OBJECT3D_FRAGMENT_SHADER_SOURCE);
  Texture objectTexture("/home/suleko/Projects/survival/assets/tommy1.jpg",
                        GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
  Object3d object(objectMesh, objectTransform, objectShader, objectTexture);

  while (Window::Running()) {
    Renderer::Start(0.0f, 0.0f, 0.0f);

    camera.transform.position.z += 0.01f;
    object.Draw(camera);

    Renderer::End();
  }

  Window::Finish();
}
