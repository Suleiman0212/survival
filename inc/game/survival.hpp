#pragma once

#include "graphics/camera/camera3d.hpp"
#include "graphics/data/transform3d.hpp"
#include "graphics/material/shader.hpp"
#include "graphics/mesh/mesh3d.hpp"
#include "graphics/mesh/primitives.hpp"
#include "graphics/object/object3d.hpp"
#include "graphics/window.hpp"
#include "help/debug.hpp"
#include <optional>

namespace Survival {
void Init();
void Update();
void Render();
void Finish();
}; // namespace Survival
