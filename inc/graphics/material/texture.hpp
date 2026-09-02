#pragma once

class Texture {
public:
  Texture(const char *path, int min_filter, int mag_filter);
  ~Texture();

  void Bind(unsigned int id);

private:
  unsigned int handle;
};
