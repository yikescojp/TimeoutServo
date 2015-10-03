#include <Arduino.h>
#include "TimeoutServo.h"

TimeoutServo::TimeoutServo() {
  _pin = -1;
  _min = MIN_PULSE_WIDTH;
  _max = MAX_PULSE_WIDTH;
  _timeout = 1000;
  _lasttime = 0;
}

uint8_t TimeoutServo::attach(int pin) {
  return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

uint8_t TimeoutServo::attach(int pin, int min, int max) {
  _pin = pin;
  _min = min;
  _max = max;
}

uint32_t TimeoutServo::setTimeout(uint32_t timeout) {
  return _timeout = timeout;
}

void TimeoutServo::write(int value) {
  Servo::attach(_pin, _min, _max);
  Servo::write(value);
  _lasttime = millis();
}

void TimeoutServo::run() {
  if (_lasttime == 0) return;
  if (millis() - _lasttime > _timeout) {
    Servo::detach();
    _lasttime = 0;
  }
}
