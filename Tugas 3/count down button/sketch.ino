byte pinD1 = 1;
byte pinD2 = 2;

byte pinA = 4;
byte pinB = 5;
byte pinC = 6;
byte pinD = 7;
byte pinE = 8;
byte pinF = 9;
byte pinG = 10;

byte pinBtn = 13;

bool jalan = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinD1, OUTPUT);
  pinMode(pinD2, OUTPUT);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

  pinMode(pinBtn, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(jalan == true){
    timer();
    jalan = false;
  } else {
    
    for (int n = 0; n < 500; n++){
      digit2();
      angka2();
      clear();
      digit1();
      angka0();
      clear();

      if(jalan == false) {
        jalan = digitalRead(pinBtn);
      }
    }
  }
}

void timer(){
  // 19
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka9();
    clear();
  }
  // 18
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka8();
    clear();
  }
  // 17
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka7();
    clear();
  }
  // 16
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka6();
    clear();
  }
  // 15
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka5();
    clear();
  }
  // 14
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka4();
    clear();
  }
  // 13
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka3();
    clear();
  }
  // 12
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka2();
    clear();
  }
  // 11
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka1();
    clear();
  }

  // 10
  for (int n = 0; n < 500; n++){
    digit2();
    angka1();
    clear();
    digit1();
    angka0();
    clear();
  }
  // 09
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka9();
    clear();
  }
  // 08
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka8();
    clear();
  }
  // 07
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka7();
    clear();
  }
  // 06
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka6();
    clear();
  }
  
  // 05
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka5();
    clear();
  }
  // 04
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka4();
    clear();
  }
  // 03
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka3();
    clear();
  }
  // 02
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka2();
    clear();
  }
  // 01
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka1();
    clear();
  }

  // 00
  for (int n = 0; n < 500; n++){
    digit2();
    angka0();
    clear();
    digit1();
    angka0();
    clear();
  }
}

void digit1(){
  digitalWrite(pinD1, HIGH);
  digitalWrite(pinD2, LOW);
}
void digit2(){
  digitalWrite(pinD1, LOW);
  digitalWrite(pinD2, HIGH);
}

void angka0(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}
void angka1(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
void angka2(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}
void angka3(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}
void angka4(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void angka5(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void angka6(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void angka7(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
void angka8(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
void angka9(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void clear(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  delay(1);
}
