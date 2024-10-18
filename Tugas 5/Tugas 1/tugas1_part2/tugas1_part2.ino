int pinSuhu = A0;
int pinLED = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  int nilaiAnalog;
  float nilaiSuhu;
  nilaiAnalog = analogRead(pinSuhu);	
  nilaiSuhu = (nilaiAnalog * 4.88);	
  nilaiSuhu = (nilaiSuhu/10);
  Serial.print("Suhu = ");
  Serial.print(nilaiSuhu);
  Serial.print(" Celsius\n");  

  if(nilaiSuhu > 29){
    digitalWrite(pinLED, HIGH);
  } else {
    digitalWrite(pinLED, LOW);
  }  

  delay(1000);
}