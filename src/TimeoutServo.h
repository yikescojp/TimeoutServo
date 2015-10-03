#ifndef TimeoutServo_h
#define TimeoutServo_h

#include <Servo.h>

class TimeoutServo : public Servo {
public:
  TimeoutServo();
  uint8_t attach(int pin);
  uint8_t attach(int pin, int min, int max);
  uint32_t setTimeout(uint32_t timeout);
  void write(int value);
  void run();
private:
  int _pin;
  int _min;
  int _max;
  uint32_t _timeout;
  unsigned long _lasttime;
};

#endif
