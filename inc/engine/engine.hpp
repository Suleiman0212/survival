#pragma once

class Engine {
public:
  void Run();

private:
  void Init();
  void Update();
  void Render();
  void Finish();
};
