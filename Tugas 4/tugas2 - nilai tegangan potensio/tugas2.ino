void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(A0);
  float voltage = (analogValue / 1023.0) * 5.0;

  Serial.println(voltage);
  
}
