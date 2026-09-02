#include <print>
#define STB_IMAGE_IMPLEMENTATION
#include "graphics/material/texture.hpp"
#include "help/utils.hpp"
#include <glad/glad.h>
#include <stb_image/stb_image.h>

Texture::Texture(const char *path, int min_filter, int mag_filter) {
  int width, heith, channels;
  unsigned char *data = stbi_load(path, &width, &heith, &channels, 0);
  if (!data) {
    std::print("ERROR: failed to load texture \"{}\"", path);
    Utils::quit();
  }

  glGenTextures(1, &handle);
  glBindTexture(GL_TEXTURE_2D, handle);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, heith, 0, GL_RGB,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(data);
}

Texture::~Texture() { glDeleteTextures(1, &handle); }

void Texture::Bind(unsigned int id) {
  glActiveTexture(id);
  glBindTexture(GL_TEXTURE_2D, handle);
}
