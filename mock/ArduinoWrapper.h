#ifndef ARDUINO_WRAPPER_H
#define ARDUINO_WRAPPER_H

//#define CPP_DEBUG

#ifdef CPP_DEBUG
#include "MockArduino.h"
#else
#include <Arduino.h>
#endif

#endif
