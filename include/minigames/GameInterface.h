#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <HardwareWrapper.h>
#include <Joystick.h>
#include <Keyboard.h>

class Game {
public:
  virtual ~Game() = default;

  virtual void init() = 0;

  // deltaTime on millisekuntteina viime päivityksestä
  virtual void update(uint32_t deltaTime, Keyboard &keyboard,
                      Joystick &Joystick) = 0;

  virtual void render(uint32_t deltaTime, Arduino_GFX &gfx) = 0;

  virtual void cleanup() = 0;

  virtual bool isComplete() = 0;

  virtual const char *getName() { return ""; }
};

#endif
