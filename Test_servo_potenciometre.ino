#include <Servo.h>
Servo myservo3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo3.attach(10);
  pinMode(A1, INPUT);
  myservo3.write(70);
}

void loop() {
  // put your main code here, to run repeatedly:
  int r = analogRead(A1);
  int a = map(r, 0, 1023, 10, 170);
  Serial.println(a);
  myservo3.write(a);
}
