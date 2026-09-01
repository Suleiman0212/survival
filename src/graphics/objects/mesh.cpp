#include "graphics/objects/mesh.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "graphics/shader.hpp"
#include "graphics/window.hpp"

// clang-format off
const char *meshVertexSource =
"#version 330 core\n"

"layout (location = 0) in vec3 pos;\n"
"layout (location = 1) in vec2 uv;\n"

"uniform mat4 projection;\n"
"uniform mat4 view;\n"
"uniform mat4 model;\n"
"out vec2 tcord;\n"

"void main() {\n"
" gl_Position = projection * view * model * vec4(pos, 1.0f);\n"
" tcord = uv;\n"
"}\n";

const char *meshFragmentSource =
"#version 330 core\n"

"in vec2 tcord;\n"
"out vec4 fragColor;\n"
"uniform sampler2D inTexture;\n"

"void main() {\n"
" fragColor = texture(inTexture, tcord);\n"
"}\n";
// clang-format on

Shader *meshShader = nullptr;
bool meshReady = false;

Mesh3d::Mesh3d(std::vector<MeshVertex> vertices, Texture &texture,
               glm::vec3 pos, glm::vec3 size)
    : texture(texture) {
  this->vertices = vertices;
  this->pos = pos;
  this->size = size;

  if (!meshReady) {
    meshShader = new Shader(meshVertexSource, meshFragmentSource);
    meshReady = true;
  }

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(MeshVertex),
               vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex),
                        (void *)0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex),
                        (void *)offsetof(MeshVertex, uv));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

void Mesh3d::draw() {
  if (!meshReady)
    return;
  meshShader->bind();

  glm::mat4 view = glm::mat4(1.0f);
  view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
  meshShader->setMat4("view", view);

  glm::mat4 projection = glm::perspective(
      glm::radians(45.0f), (float)Window::width / (float)Window::heigth, 0.1f,
      100.0f);
  meshShader->setMat4("projection", projection);

  glm::mat4 model(1.0f);
  model = glm::translate(model, pos);
  model = glm::translate(model, pivot);
  model = glm::rotate(model, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
  model = glm::rotate(model, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
  model = glm::rotate(model, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, -pivot);
  model = glm::scale(model, size);
  meshShader->setMat4("model", model);

  texture.bind(GL_TEXTURE0);
  meshShader->setInt("inTexture", 0);

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
