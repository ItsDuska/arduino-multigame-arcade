#include "GameRegistry.h"

Game* createGame(uint8_t gameIndex)
{
	switch (gameIndex)
  {
    case 0: return new ButtonMashGame();
    case 1: return new ReactionTimeGame();
    case 2: return new JoystickSpinGame();
    case 3: return new FallingBlocks();
    
    default: return nullptr;
  }
}
