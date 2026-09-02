#include "graphics/material/shader.hpp"
#include "help/utils.hpp"
#include <cstddef>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <print>

void shader_compile_status(unsigned int handle, bool is_vertex) {
  int success;
  char infoLog[512];
  glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(handle, 512, NULL, infoLog);

    if (is_vertex)
      std::print("VERTEX_SHADER_COMPILATION_ERROR: {}", infoLog);
    else
      std::print("FRAGMENT_SHADER_COMPILATION_ERROR: {}", infoLog);
    Utils::quit();
  }
}

void program_link_status(unsigned int handle) {
  int success;
  char infoLog[512];
  glGetProgramiv(handle, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(handle, 512, NULL, infoLog);

    std::print("SHADER_PROGRAM_LINK_ERROR: {}", infoLog);
    Utils::quit();
  }
}

Shader::Shader(const char *vertexSource, const char *fragmentSource) {
  vertexHandle = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexHandle, 1, &vertexSource, NULL);
  glCompileShader(vertexHandle);
  shader_compile_status(vertexHandle, true);

  fragmentHandle = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentHandle, 1, &fragmentSource, NULL);
  glCompileShader(fragmentHandle);
  shader_compile_status(fragmentHandle, false);

  programHandle = glCreateProgram();
  glAttachShader(programHandle, vertexHandle);
  glAttachShader(programHandle, fragmentHandle);
  glLinkProgram(programHandle);
  program_link_status(programHandle);

  glDeleteShader(vertexHandle);
  glDeleteShader(fragmentHandle);
}

Shader::~Shader() { glDeleteProgram(programHandle); }

void Shader::Bind() { glUseProgram(programHandle); }

void Shader::SetMat4(const char *name, glm::mat4 val) {
  glUniformMatrix4fv(glGetUniformLocation(programHandle, name), 1, GL_FALSE,
                     glm::value_ptr(val));
}

void Shader::SetInt(const char *name, int val) {
  glUniform1i(glGetUniformLocation(programHandle, name), val);
}
