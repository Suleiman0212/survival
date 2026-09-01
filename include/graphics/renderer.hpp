#pragma once

template <typename T>
concept Drawable = requires(T object) { object.draw(); };

namespace Renderer {

template <Drawable T> void draw(T &object) { object.draw(); }

void start(float red, float green, float blue);
void end();
} // namespace Renderer
