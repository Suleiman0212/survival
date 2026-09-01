#pragma once

class Texture {
public:
  Texture(const char *path, int min_filter, int mag_filter);
  void bind(unsigned int id);

private:
  unsigned int handle;
};
