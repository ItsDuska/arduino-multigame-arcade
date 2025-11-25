

//#define NO_BOARD

#include "src/GameManager.h"

GameManager gameManager;

void setup()
{
  Serial.begin(9600);
  gameManager.init();
}

void loop() {
  gameManager.update();
}
