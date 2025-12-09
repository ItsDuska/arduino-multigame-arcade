#include "minigames/GameInterface.h"

Game *Game::instance = nullptr;

void interuptGameOver() {
  if (Game::instance) {
    Game::instance->handleGameOver();
  }
}

void Game::setupInterupt() {
  pinMode(GAME_OVER_INTERUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(GAME_OVER_INTERUPT_PIN),
                  interuptGameOver, FALLING);
  instance = this;
}
void Game::handleGameOver() {
  gameComplete = true;
  hasWon = overrideWinOrLoss;
}

void Game::enableTimer(uint32_t durationMs, bool winOnExpire) {
  timerDuration = millis() + durationMs;
  overrideWinOrLoss = winOnExpire;
  useTimer = true;
}

void Game::checkTimer() {
  if (!useTimer) {
    return;
  }

  if (millis() >= timerDuration) {
    digitalWrite(GAME_OVER_INTERUPT_PIN, LOW);
  }
}
