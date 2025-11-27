#pragma once
#include <cstring> // memcpy
#include <stdint.h>
#include <vector>

class MockEEPROMClass {
public:
  MockEEPROMClass() {
    // Arduino Megassa on 4KB (4096 tavua) EEPROMia
    // Alustetaan se nollilla
    memory.resize(4096, 0);
  }

  uint8_t read(int idx) {
    if (idx >= 0 && idx < (int)memory.size()) {
      return memory[idx];
    }
    return 0;
  }

  void write(int idx, uint8_t val) {
    if (idx >= 0 && idx < (int)memory.size()) {
      memory[idx] = val;
    }
  }

  void update(int idx, uint8_t val) {
    if (read(idx) != val) {
      write(idx, val);
    }
  }

  // --- Template-funktiot structeille (tärkeä!) ---

  template <typename T> T &get(int idx, T &t) {
    if (idx + sizeof(T) <= memory.size()) {
      std::memcpy(&t, &memory[idx], sizeof(T));
    }
    return t;
  }

  template <typename T> const T &put(int idx, const T &t) {
    if (idx + sizeof(T) <= memory.size()) {
      const uint8_t *ptr = (const uint8_t *)&t;
      for (size_t i = 0; i < sizeof(T); i++) {
        memory[idx + i] = ptr[i];
      }
    }
    return t;
  }

  uint16_t length() { return memory.size(); }

private:
  std::vector<uint8_t> memory;
};

extern MockEEPROMClass EEPROM;
