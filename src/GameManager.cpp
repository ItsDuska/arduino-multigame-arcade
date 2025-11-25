#include "GameManager.h"


#define PIN_RD A7
#define PIN_WR A6
#define PIN_RS A5
#define PIN_CS A4
#define PIN_RST A3

#define JOYSTICK_PIN_A 0
#define JOYSTICK_PIN_B 1
#define JOYSTICK_PIN_C 2

GameManager::GameManager() :
  currentState(STATE_MENU),
  currentGameIndex(0),
  totalGames(GAME_COUNT),
  activeGame(nullptr),
  lastUpdateTime(0),
  Joystick(JOYSTICK_PIN_A, JOYSTICK_PIN_B, JOYSTICK_PIN_C)
{
}

void GameManager::init()
{
	bus = new Arduino_SWPAR8(PIN_RS, PIN_CS, PIN_WR, PIN_RD, A9, A8, A15, A14, A13, A12, A11, A10);
	gfx = new Arduino_R61529(bus, PIN_RST, 0, false);

  Serial.println("=== Multi-Game Arcade ===");
  Serial.print("Total games: ");
  Serial.println(totalGames);
  currentState = STATE_GAME_INIT;
}


void GameManager::update()
{
  uint32_t currentTime = millis();
  uint32_t deltaTime = currentTime - lastUpdateTime;
  lastUpdateTime = currentTime;

  switch (currentState)
  {
    case STATE_MENU:
    	// add main menu here
      currentState = STATE_GAME_INIT;
      break;

    case STATE_GAME_INIT:
      initNextGame();
      break;

    case STATE_GAME_RUNNING:
      if (activeGame)
      {
        activeGame->update(deltaTime, keyboard, Joystick);

        if (activeGame->isComplete())
        {
          currentState = STATE_GAME_OVER;
        }
      }
      break;

    case STATE_GAME_OVER:
      cleanupCurrentGame();
      currentGameIndex++;

      if (currentGameIndex >= totalGames)
      {
        currentState = STATE_ALL_COMPLETE;
      }
      else
      {
        currentState = STATE_GAME_INIT;
      }
      break;

    case STATE_ALL_COMPLETE:

      currentGameIndex = 0;
      currentState = STATE_GAME_INIT;
      break;
  }
}


void GameManager::initNextGame()
{
  Serial.print("Loading game ");
  Serial.print(currentGameIndex + 1);
  Serial.print("/");
  Serial.println(totalGames);

  activeGame = createGame(currentGameIndex);

  if (activeGame)
  {
    activeGame->init();
    currentState = STATE_GAME_RUNNING;
  }
  else
  {
    Serial.println("ERROR: Failed to create game");
    currentState = STATE_ALL_COMPLETE;
  }
}

void GameManager::cleanupCurrentGame()
{
  if (activeGame)
  {
    activeGame->cleanup();
    delete activeGame;
    activeGame = nullptr;
  }
}
