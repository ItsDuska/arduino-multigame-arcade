#pragma once
#include <HardwareWrapper.h>

#include "minigames/GameInterface.h"
#include "minigames/GameRegistry.h"

#include <Joystick.h>
#include <Keyboard.h>

enum class GameState : char {
  STATE_MENU,
  STATE_GAME_INIT,
  STATE_GAME_RUNNING,
  STATE_GAME_OVER,
  STATE_ALL_COMPLETE
};

class GameManager {

public:
  GameManager();
  ~GameManager();

  void init();
  void update();

private:
  void initNextGame();
  void cleanupCurrentGame();

private:
  GameState currentState;
  uint8_t currentGameIndex;
  uint8_t totalGames;

  // Varmista että tämä vastaa luokan nimeä GameInterface.h tiedostossa
  Game *activeGame;

  uint32_t lastUpdateTime;

  // Nämä tyypit tulevat nyt HardwareWrapper.h:n kautta
  // (Joko oikeina tai Mock-versioina)
  Arduino_DataBus *bus;
  Arduino_GFX *gfx;

  Keyboard keyboard;
  Joystick joystick;
};
