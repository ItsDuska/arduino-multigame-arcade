#include "MockTimerOne.h"
#include "MockArduino.h" // Tarvitaan micros()

// Globaali instanssi
MockTimerOne Timer1;

MockTimerOne::MockTimerOne()
    : _period(1000000), _lastRunTime(0), _callback(NULL), _running(false) {}

void MockTimerOne::initialize(unsigned long microseconds) {
  _period = microseconds;
  _lastRunTime = micros();
  _running = true;
  _callback = NULL;
}

void MockTimerOne::setPeriod(unsigned long microseconds) {
  _period = microseconds;
}

void MockTimerOne::attachInterrupt(void (*isr)()) {
  _callback = isr;
  _lastRunTime = micros(); // Nollataan laskuri ettei laukea heti ryppäänä
  _running = true;
}

void MockTimerOne::detachInterrupt() { _callback = NULL; }

void MockTimerOne::start() {
  _running = true;
  _lastRunTime = micros();
}

void MockTimerOne::stop() { _running = false; }

void MockTimerOne::restart() { start(); }

void MockTimerOne::tick() {
  if (!_running || _callback == NULL)
    return;

  unsigned long currentMicros = micros();
  if (currentMicros - _lastRunTime >= _period) {
    _lastRunTime = currentMicros;
    _callback();
  }
}

// Stubit PWM:lle - eivät tee simulaattorissa mitään
void MockTimerOne::pwm(uint8_t pin, uint16_t duty) {}
void MockTimerOne::setPwmDuty(uint8_t pin, uint16_t duty) {}
void MockTimerOne::disablePwm(uint8_t pin) {}
