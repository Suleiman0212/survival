#pragma once

template <typename T>
concept Drawable = requires(T object) { object.Draw(); };

namespace Renderer {

template <Drawable T> void Draw(T &object) { object.Draw(); }

void start(float red, float green, float blue);
void end();
} // namespace Renderer
