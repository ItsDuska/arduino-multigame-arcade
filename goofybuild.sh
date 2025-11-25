g++ -g -Wall -o game \
      mock/main.cpp \
      mock/MockArduino.cpp \
      src/GameManager.cpp \
      src/minigames/GameRegistry.cpp \
      src/minigames/Game1_ButtonMash.cpp
