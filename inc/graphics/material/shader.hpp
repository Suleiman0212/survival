#pragma once

#include <glm/glm.hpp>

class Shader {
public:
  Shader(const char *vertexSource, const char *fragmentSource);
  ~Shader();

  void Bind();

  void SetMat4(const char *name, glm::mat4 val);

  void SetInt(const char *name, int val);

private:
  unsigned int vertexHandle, fragmentHandle;
  unsigned int programHandle;
};
