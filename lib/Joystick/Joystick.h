#pragma once
#include <Arduino.h>

// TODO: muuta tän nimi vec2i16 kun saadaan joystick toimimaan.
struct Vec2i16
{
    int16_t x;
    int16_t y;
};

class Joystick
{
public:
    Joystick(uint8_t pinA, uint8_t pinB, uint8_t pinC);

    Vec2i16 getPosition(void);
    void readPosition(void);
    bool isJoystickDown();

    enum class Direction
    {
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
