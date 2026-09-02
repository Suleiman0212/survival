#include "engine/engine.hpp"
#include "engine/input.hpp"
#include "game/survival.hpp"
#include "graphics/gui.hpp"
#include "graphics/window.hpp"

void Engine::Run() {
  Init();

  while (Window::Running()) {
    Update();
    Render();

    Input::EndFrame();
    Window::EndFrame();
    Gui::EndFrame();
  }
}

void Engine::Init() {
  Window::Init(1280, 720, "Survival");
  Gui::Init();
  Input::Init();
  Survival::Init();
}

void Engine::Update() {
  Input::StartFrame();
  Survival::Update();
}

void Engine::Render() {
  Window::StartFrame(0.0f, 0.0f, 0.0f);
  Gui::StartFrame();
  Survival::Render();
}

void Engine::Finish() {
  Window::Finish();
  Gui::Finish();
}
