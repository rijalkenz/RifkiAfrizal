#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   
 
void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(8, OUTPUT);
  
  lcd.begin();
}
void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "04 2F 37 32 94 6C 80") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Boleh mauk");
    Serial.println();
    digitalWrite(8, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("Boleh mauk");
    delay(3000);
  }
 
 else   {
    Serial.println("Gabole ya");
    Serial.println();
    lcd.setCursor(0, 0);
    lcd.print("Gabole ya");

    for(int i = 0; i < 10; i++){

      digitalWrite(8, HIGH);
      delay(150);
      digitalWrite(8, LOW);
      delay(150);
    }
  }
      digitalWrite(8, LOW);

    lcd.clear();


} 