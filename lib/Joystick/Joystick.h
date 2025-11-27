#pragma once

#ifdef TARGET_PC
// Simulaattorissa käytämme Mock-versiota
#include <MockArduino.h>
#else
// Oikealla raudalla käytämme oikeaa Arduino-kirjastoa
#include <Arduino.h>
#endif

struct Vec2i16 {
  int16_t x;
  int16_t y;
};

class Joystick {
public:
  Joystick(uint8_t pinA, uint8_t pinB, uint8_t pinC);

  Vec2i16 getPosition(void);
  void update(void);
  bool isJoystickDown();

  enum class Direction {
    UP,
    UP_RIGHT,
    RIGHT,
    RIGHT_DOWN,
    DOWN,
    DOWN_LEFT,
    LEFT,
    LEFT_UP,
    IDLE
  };

  Direction convertPositionToDirection();

private:
  uint8_t pinA;
  uint8_t pinB;
  uint8_t pinC;

  bool buttonDown;
  Vec2i16 position;
};
