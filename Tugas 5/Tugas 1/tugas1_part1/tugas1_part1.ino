
int pinSuhu = A0;

void setup() {
  Serial.begin(9600);
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
  
  delay(1000);
}