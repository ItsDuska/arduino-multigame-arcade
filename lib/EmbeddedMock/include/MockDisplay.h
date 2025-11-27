#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class Arduino_GFX {
public:
  Arduino_GFX(int w, int h);
  ~Arduino_GFX() {}

  bool begin(int speed = 0) { return true; }

  // Grafiikka
  void fillScreen(uint16_t color);
  void drawPixel(int16_t x, int16_t y, uint16_t color);
  void setCursor(int16_t x, int16_t y) {}
  void setTextColor(uint16_t c) {}
  void setTextColor(uint16_t c, uint16_t bg) {}
  void setTextSize(uint8_t s) {}
  void setTextSize(uint8_t sx, uint8_t sy, uint8_t pixel_margin) {}

  // Print-funktiot (Ohjataan konsoliin debuggausta varten)
  void print(const char *text) { std::cout << "[TFT] " << text; }
  void println(const char *text) { std::cout << "[TFT] " << text << std::endl; }

  // Muut
  void setRotation(uint8_t r) {}
  int16_t width() { return _width; }
  int16_t height() { return _height; }

  void renderSDL();

private:
  int _width, _height;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  uint32_t *pixels;

  uint32_t color565to8888(uint16_t color);
};
