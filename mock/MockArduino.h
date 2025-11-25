#ifndef MOCK_ARDUINO_H
#define MOCK_ARDUINO_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdint>
#include <cstdlib>


#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

#define LOW 0
#define HIGH 1
#define A0 0


#define F(string_literal) (string_literal)


static auto programStartTime = std::chrono::steady_clock::now();


class MockSerial
{
public:
  void begin(long baud)
  {
    std::cout << "[Serial] Initialized at " << baud << " baud" << std::endl;
  }

  void print(const char* str)
  {
    std::cout << str;
  }

  void print(const std::string& str)
  {
    std::cout << str;
  }

  void print(int val)
  {
    std::cout << val;
  }

  void print(unsigned int val)
  {
    std::cout << val;
  }

  void print(long val)
  {
    std::cout << val;
  }

  void print(unsigned long val)
  {
    std::cout << val;
  }

  void println(const char* str)
  {
    std::cout << str << std::endl;
  }

  void println(const std::string& str)
  {
    std::cout << str << std::endl;
  }

  void println(int val)
  {
    std::cout << val << std::endl;
  }

  void println(unsigned int val)
  {
    std::cout << val << std::endl;
  }

  void println(long val)
  {
    std::cout << val << std::endl;
  }

  void println(unsigned long val)
  {
    std::cout << val << std::endl;
  }
};

extern MockSerial Serial;

inline unsigned long millis()
{
  auto now = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - programStartTime);
  return static_cast<unsigned long>(duration.count());
}

inline unsigned long micros()
{
  auto now = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(now - programStartTime);
  return static_cast<unsigned long>(duration.count());
}

inline void delay(unsigned long ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

inline void delayMicroseconds(unsigned int us)
{
  std::this_thread::sleep_for(std::chrono::microseconds(us));
}

inline void pinMode(uint8_t pin, uint8_t mode)
{
}

inline void digitalWrite(uint8_t pin, uint8_t value)
{
  std::cout << "[PIN " << (int)pin << "] digitalWrite: " << (value ? "HIGH" : "LOW") << std::endl;
}

inline int digitalRead(uint8_t pin)
{
  return HIGH;
}

inline int analogRead(uint8_t pin)
{
  return rand() % 1024;
}

inline void analogWrite(uint8_t pin, int value)
{
  std::cout << "[PIN " << (int)pin << "] analogWrite: " << value << std::endl;
}

inline long random(long min, long max)
{
  return min + (rand() % (max - min));
}

inline void randomSeed(unsigned long seed)
{
  srand(seed);
}

#endif
