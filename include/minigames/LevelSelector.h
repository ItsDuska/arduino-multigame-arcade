
#pragma once
#include "GameInterface.h"

class GameManager;
class LevelSelector : public Game {
public:
  LevelSelector(GameManager *gameManager);
  void init(Arduino_GFX &gfx) override;
  void update(Keyboard &keyboard, Joystick &joystick) override;
  void render(Arduino_GFX &gfx) override;
  void cleanup() override;
  const char *getName() override;

private:
  uint8_t currentLineIndex;
  GameManager *gameManager;

  bool isDirty = true;
  uint32_t lastInputTime = 0;
  const uint32_t INPUT_DELAY = 200;
};
