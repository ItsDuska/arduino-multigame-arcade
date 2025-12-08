#pragma once
#include "GameInterface.h"

class JoystickSpinGame : public Game {
public:
  JoystickSpinGame();

  void init(Arduino_GFX &gfx) override;
  void update(Keyboard &keyboard, Joystick &joystick) override;
  void render(Arduino_GFX &gfx) override;
  void cleanup() override;

  const char *getName() override;

private:
  enum class Stage : uint8_t { UP, RIGHT, DOWN, LEFT };

  uint32_t startTime;
  int score;
  bool gameComplete;

  Stage currentStage;
  static constexpr uint32_t GAME_DURATION = 10000; // 10s time
};
