#define CPP_DEBUG
#include "../src/GameManager.h"


GameManager gameManager;

void setup()
{
  Serial.begin(9600);
  gameManager.init();

}

void loop()
{
  gameManager.update();
}

int main()
{
  std::cout << "=== Arduino Multi-Game Arcade - Desktop Test ===\n";

  setup();

  for (int i = 0; i < 1000; i++)
  {
    loop();

    delay(100);
  }

  std::cout << std::endl << "Test complete!\n";
  return 0;
}
