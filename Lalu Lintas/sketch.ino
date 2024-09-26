void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lampu(2, 3, 7, 10);
  lampu(5, 6, 4, 10);
  lampu(8, 9, 4, 7);
}

void lampu(int hijau, int kuning, int merah1, int merah2){
  digitalWrite(hijau, HIGH);
  digitalWrite(merah1, HIGH);
  digitalWrite(merah2, HIGH);
  delay(3000);
  
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, HIGH);
  delay(1000);

  digitalWrite(kuning, LOW);
  digitalWrite(merah1, LOW);
  digitalWrite(merah2, LOW);
}