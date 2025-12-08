#pragma once
#include "GameInterface.h"

constexpr uint8_t MAX_OBSTACLES = 12;

struct Obstacle {
  int8_t x;
  int8_t y;
  bool active;
};

class FallingBlocks : public Game {
public:
  FallingBlocks();
  void init(Arduino_GFX &gfx) override;
  void update(Keyboard &keyboard, Joystick &joystick) override;
  void render(Arduino_GFX &gfx) override;
  void cleanup() override;
  const char *getName() override;

  static void gameTimer();

private:
  void spawnObstacle();
  void moveObstacles();
  void checkCollision();
  void handlePlayerInput(Keyboard &keyboard, Joystick &joystick);
  void adjustDifficulty();

public:
  static FallingBlocks *instance;

private:
  Obstacle obstacles[MAX_OBSTACLES];
  Obstacle obstaclesLastPos[MAX_OBSTACLES];
  uint32_t lastSpawnTime;
  uint32_t lastMoveTime;
  uint8_t playerX;
  uint8_t lastPlayerX;
  uint16_t speed;
  uint32_t spawnInterval;
  uint16_t gamesPlayed = 1;

  bool isDirty = true;
  uint32_t lastInputTime = 0;
  const uint32_t INPUT_DELAY = 100;
};
