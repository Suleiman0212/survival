#include "graphics/objects/sprite.hpp"
#include "graphics/shader.hpp"
#include "graphics/window.hpp"
#include <cstddef>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct SpriteVertex {
  glm::vec2 pos;
  glm::vec2 uv;
};

// clang-format off
SpriteVertex vertices[] = {
    // pos              // uv
    {{0.0f, 0.0f},      {0.0f, 0.0f}},
    {{1.0f, 0.0f},      {1.0f, 0.0f}},
    {{1.0f, 1.0f},      {1.0f, 1.0f}},

    {{1.0f, 1.0f},      {1.0f, 1.0f}},
    {{0.0f, 1.0f},      {0.0f, 1.0f}},
    {{0.0f, 0.0f},      {0.0f, 0.0f}}
};

const char *spriteVertexSource =
"#version 330 core\n"

"layout (location = 0) in vec2 pos;\n"
"layout (location = 1) in vec2 uv;\n"

"uniform mat4 projection;\n"
"uniform mat4 model;\n"
"out vec2 tcord;\n"

"void main() {\n"
" gl_Position = projection * model * vec4(pos, 0.0f, 1.0f);\n"
" tcord = uv;\n"
"}\n";

const char *spriteFragmentSource =
"#version 330 core\n"

"in vec2 tcord;\n"
"out vec4 fragColor;\n"
"uniform sampler2D inTexture;\n"

"void main() {\n"
" fragColor = texture(inTexture, tcord);\n"
"}\n";
// clang-format on

Shader *spriteShader = nullptr;
unsigned int VBO, VAO;
bool spriteReady = false;

void initialize_quad() {
  spriteShader = new Shader(spriteVertexSource, spriteFragmentSource);
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(SpriteVertex),
                        (void *)0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(SpriteVertex),
                        (void *)offsetof(SpriteVertex, uv));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

Sprite::Sprite(Texture &texture, glm::vec2 pos, glm::vec2 size)
    : texture(texture) {
  this->pos = pos;
  this->size = size;
  // this->origin = size / 2.0f;
  if (!spriteReady) {
    initialize_quad();
    spriteReady = true;
  }
}

void Sprite::draw() {
  if (!spriteReady)
    return;
  spriteShader->bind();

  glm::mat4 projection =
      glm::ortho(0.0f, (float)Window::width, (float)Window::heigth, 0.0f);
  spriteShader->setMat4("projection", projection);

  glm::mat4 model(1.0f);
  model = glm::translate(model, glm::vec3(pos + privot, 0.0f));
  model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, glm::vec3(-privot, 0.0f));
  model = glm::scale(model, glm::vec3(size, 1.0f));
  spriteShader->setMat4("model", model);

  texture.bind(GL_TEXTURE0);
  spriteShader->setInt("inTexture", 0);

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}
