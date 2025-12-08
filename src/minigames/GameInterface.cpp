#include "minigames/GameInterface.h"

void Game::enableTimer(uint32_t durationMs, bool winOnExpire) {
  timerDuration = millis() + durationMs;
  winOnTimeout = winOnExpire;
  useTimer = true;
}

void Game::checkTimer() {
  if (!useTimer) {
    return;
  }

  if (millis() >= timerDuration) {
    gameComplete = true;
    hasWon = winOnTimeout;
  }
}
