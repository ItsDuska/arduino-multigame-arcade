#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <HardwareWrapper.h>
#include <Joystick.h>
#include <Keyboard.h>

class Game {
public:
  virtual ~Game() = default;

  virtual void init(Arduino_GFX &gfx) = 0;

  virtual void update(Keyboard &keyboard, Joystick &Joystick) = 0;

  virtual void render(Arduino_GFX &gfx) = 0;

  virtual void cleanup() = 0;

  bool isComplete() const { return gameComplete; }

  bool getGameStatus() const { return hasWon; }

  virtual const char *getName() { return ""; }

protected:
  void enableTimer(uint32_t durationMs, bool winOnExpire);
  void checkTimer();

protected:
  bool hasWon = false;
  bool gameComplete = false;
  bool useTimer = false;
  uint32_t timerDuration = 0;
  bool winOnTimeout = false;
};

#endif
