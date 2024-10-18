#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pinSuhu = A0;
int pinLED = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  lcd.begin();
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

  lcd.setCursor(0, 0);
  lcd.print("Suhu = ");
  lcd.print(nilaiSuhu);


  if(nilaiSuhu > 29){
    digitalWrite(pinLED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("PANAS BANGET");
  } else {
    digitalWrite(pinLED, LOW);
    lcd.setCursor(0, 1);
    lcd.print("DINGINN BANGET");
  }
  
  delay(1000);
}