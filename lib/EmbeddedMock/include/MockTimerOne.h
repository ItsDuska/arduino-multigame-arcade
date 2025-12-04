#pragma once
#include <stddef.h>
#include <stdint.h>

class MockTimerOne {
public:
  MockTimerOne();

  // --- TimerOne API ---
  void initialize(unsigned long microseconds = 1000000);
  void setPeriod(unsigned long microseconds);
  void attachInterrupt(void (*isr)());
  void detachInterrupt();
  void start();
  void stop();
  void restart();

  // Tätä kutsutaan main loopissa simuloidaksemme ajan kulumista
  void tick();

  // PWM komennot (ei implementoitu)
  void pwm(uint8_t pin, uint16_t duty);
  void setPwmDuty(uint8_t pin, uint16_t duty);
  void disablePwm(uint8_t pin);

private:
  unsigned long _period;      // Mikrosekunteina
  unsigned long _lastRunTime; // Milloin viimeksi ajettiin
  void (*_callback)();        // Tallennettu funktio
  bool _running;
};

extern MockTimerOne Timer1;
