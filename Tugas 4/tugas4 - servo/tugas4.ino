#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(3);
}c:\Users\aspire 5\Documents\_potensio\tugas3\tugas3.ino

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(A0);
  int angle = map(analogValue, 0, 1023, 0, 180);

  Serial.println(angle);
  myServo.write(angle);
  delay(100);
}
