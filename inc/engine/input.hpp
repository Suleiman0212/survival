#pragma once

namespace Input {
void Init();
void StartFrame();
void EndFrame();
bool KeyPressed(int key);
bool KeyJustPressed(int key);
} // namespace Input
