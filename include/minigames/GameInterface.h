#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <HardwareWrapper.h>
#include <Joystick.h>
#include <Keyboard.h>

constexpr uint8_t GAME_OVER_INTERUPT_PIN = 2;

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

  void handleGameOver(); // interuptia varten

public:
  static Game *instance;

protected:
  void enableTimer(uint32_t durationMs, bool winOnExpire);
  void checkTimer();

  void setupInterupt();

protected:
  bool hasWon = false;
  bool gameComplete = false;
  bool useTimer = false;
  uint32_t timerDuration = 0;
  // tällä voidaan overridea että tullaanko voittaan vai ei esim jos
  // pelaaja osuu esteeseen. Vähän likainen tapa mutta interuptien takia se on
  // näin.
  bool overrideWinOrLoss = false;
};

#endif
