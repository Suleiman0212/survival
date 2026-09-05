#include "graphics/material/shader.hpp"
#include "graphics/material/texture.hpp"
#include "graphics/window.hpp"
#include <memory>

class Material {
public:
  virtual ~Material() = default;
  virtual void Bind(std::shared_ptr<Shader> shader) = 0;
};

class TexturedMaterial : public Material {
public:
  TexturedMaterial(std::shared_ptr<Texture> texture)
      : texture(std::move(texture)) {}

  void Bind(std::shared_ptr<Shader> shader) {
    texture->Bind(GL_TEXTURE0);
    shader->SetInt("textureZero", 0);
  }

private:
  std::shared_ptr<Texture> texture;
};
