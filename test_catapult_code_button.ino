#include <Servo.h>
Servo myservo1;
Servo myservo2;
int boto = 0;


void setup() {

  Serial.begin(9600);

  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);

  pinMode (12, INPUT_PULLUP);

  myservo1.write(2);
  myservo2.write(10);
}

void loop() {

  int b1 = digitalRead(12);
  Serial.println(b1);


  if (b1 == 0 && boto == 0) {
    myservo1.write(120);
    b1 = 1;
    boto = 1;
    delay(500);

  }


  if (b1 == 0 && boto == 1) {
    myservo2.write(90);
    boto = 0;
    delay(2000);
    myservo1.write(2);               ///
    delay(2000);
    myservo2.write(10);               ///
  }


}
