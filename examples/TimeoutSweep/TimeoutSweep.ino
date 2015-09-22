#include <Servo.h> 
#include <TimeoutServo.h>

TimeoutServo servo;

int pin = 10;
int timeout = 1000;

void setup()
{ 
  servo.attach(pin);
  servo.setTimeout(timeout);
}

int count = 0;
int pos = 0;
void loop() 
{
  count = millis() % 10000;
  if (count < 1800) {
    pos = (int) (count / 10);
    servo.write(pos);
  }
  servo.run();
} 
