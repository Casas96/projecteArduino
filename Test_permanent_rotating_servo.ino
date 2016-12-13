#include <Servo.h>
Servo myservo;
int increment = 1;
int pos = 90;

void setup() {
  myservo.attach(3);
  myservo.write(pos);
}

void loop() {
  if (millis() % 100 == 0) {
    myservo.write(pos);
    pos = pos + increment;
    if (pos > 170) {
      increment = -increment;
    }
    if (pos < 10) {
      increment = -increment;
    }
  }
}
