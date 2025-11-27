#pragma once
#include <SDL2/SDL.h>
#include <stdint.h>

// Määritellään vakiot, joita Adafruit Keypad käyttää.
// Keyboard.cpp vertaa näihin (e.bit.EVENT == KEY_JUST_PRESSED)
#define KEY_JUST_PRESSED 1
#define KEY_JUST_RELEASED 2

// Matkii Adafruit Keypadin palautusarvoa oikealla rakenteella
struct keypadEvent {
  // Luodaan sisäinen struct nimeltä 'bit'
  struct {
    char KEY;
    uint8_t EVENT;
  } bit;
};

class Adafruit_Keypad {
public:
  // Konstruktori joka ei tee mitään
  Adafruit_Keypad(void *userKeymap, const void *rowPins, const void *colPins,
                  int r, int c) {}

  void begin() {}

  void tick() {
    // PC-simulaatiossa tämä on tyhjä, koska main loop hoitaa SDL-tapahtumat
    // ja kutsuu simulateKeyPress-funktiota.
  }

  bool available() { return _hasEvent; }

  keypadEvent read() {
    _hasEvent = false;
    return _lastEvent;
  }

  // Tätä kutsutaan SDL main loopista (tai Keyboard.cpp:n PC-haarasta)
  void simulateKeyPress(char key) {
    _lastEvent.bit.KEY = key;
    _lastEvent.bit.EVENT = KEY_JUST_PRESSED;
    _hasEvent = true;
  }

private:
  bool _hasEvent = false;
  keypadEvent _lastEvent;
};
