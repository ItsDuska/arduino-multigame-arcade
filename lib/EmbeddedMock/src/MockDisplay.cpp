#include "MockDisplay.h"

Arduino_GFX::Arduino_GFX(int w, int h) : _width(w), _height(h) {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Embedded Sim", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, w * 2, h * 2,
                            SDL_WINDOW_SHOWN); // *2 zoomaus
  renderer = SDL_CreateRenderer(window, -1, 0);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STREAMING, w, h);
  pixels = new uint32_t[w * h];
}

void Arduino_GFX::drawPixel(int16_t x, int16_t y, uint16_t color) {
  if (x < 0 || x >= _width || y < 0 || y >= _height)
    return;
  pixels[y * _width + x] = color565to8888(color);
}

void Arduino_GFX::renderSDL() {
  SDL_UpdateTexture(texture, NULL, pixels, _width * sizeof(uint32_t));
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

uint32_t Arduino_GFX::color565to8888(uint16_t color) {
  uint8_t r = (color >> 11) << 3;
  uint8_t g = ((color >> 5) & 0x3F) << 2;
  uint8_t b = (color & 0x1F) << 3;
  return (0xFF000000 | (r << 16) | (g << 8) | b);
}

void Arduino_GFX::fillScreen(uint16_t color) {
  // Muunnetaan 16-bit väri 32-bit SDL-väriksi
  uint32_t argb = color565to8888(color);

  // Täytetään koko puskuri tällä värillä
  for (int i = 0; i < _width * _height; i++) {
    pixels[i] = argb;
  }
}
