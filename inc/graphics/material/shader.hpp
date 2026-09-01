#pragma once

#include <glm/glm.hpp>

class Shader {
public:
  Shader(const char *vertexSource, const char *fragmentSource);

  void bind();

  void setMat4(const char *name, glm::mat4 val);

  void setInt(const char *name, int val);

  ~Shader();

private:
  unsigned int vertexHandle, fragmentHandle;
  unsigned int programHandle;
};
