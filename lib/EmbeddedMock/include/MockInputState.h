#pragma once
#ifdef TARGET_PC
// Tämä on yksinkertainen "jaettu muisti" SDL:n (main.cpp) ja Mock-luokkien
// välillä
struct MockInputState {
  static int joyX;    // -100-100
  static int joyY;    // -100-100
  static bool joyBtn; // true/false

  // Keypadin tilaa varten (yksinkertaistettu puskuri)
  static char lastKeyPressed;
  static bool newKeyAvailable;
};
#endif
