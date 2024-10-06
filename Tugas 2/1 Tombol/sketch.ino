int status_tombol;

void setup() {
  // put your setup code here, to run once:

pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  status_tombol = digitalRead(7);

  if(status_tombol == HIGH) {
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
  }

}
