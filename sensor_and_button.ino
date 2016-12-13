#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
unsigned long now;
int pos = 90;
int increment = 1;
int boto = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);
  myservo3.attach(10);
  myservo4.attach(3);

  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT);

  myservo1.write(2);
  myservo2.write(10);
  myservo3.write(53);
  myservo4.write(pos);

}




void loop() {

  // put your main code here, to run repeatedly:

  int a = digitalRead(7);
  //  Serial.println(a);

  int b = myservo1.read();
  //Serial.println(now);
  int c = myservo3.read();

  int d = digitalRead(8);

  if (d == 0 && boto == 0) {
    myservo1.write(2);
    myservo2.write(10);
    myservo3.write(53);
    myservo4.write(pos);
    d = 1;
    boto = 1;
    delay(500);
  }


  if (d == 0 && boto == 1) {

    boto = 0;

    if (millis() % 100 == 0) {
      myservo4.write(pos);
      pos = pos + increment;
      if (pos > 170) {
        increment = -increment;
      }
      if (pos < 10) {
        increment = -increment;
      }
    }


    if (b == 2 && c == 53) {
      myservo1.write(100);
      myservo3.write(155);
      delay(2000);
      myservo3.write(53);
      delay(1000);
      now = millis();
    }


    if (millis() - now > 30000 ) {
      // ok. 7 seconds elapsed
      myservo1.write(5);
      delay(5000);
    }



    if (b > 95 &&   a == 0   && c == 53) {
      //    myservo4.write(random(10, 170));
      //    delay(1000);
      myservo2.write(90);
      delay(2000);
      myservo1.write(2);               ///
      delay(1000);
      myservo2.write(10);
      delay(1000);///

    }

  }
}
