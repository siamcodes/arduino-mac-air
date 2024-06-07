int LED[] = {9, 10, 11};

void setup() {
  attachInterrupt(0, onALL, FALLING);
  Serial.begin(9600);
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED[i], HIGH);
    delay(500);
    digitalWrite(LED[i], LOW);
    delay(500);
  }
}

void onALL() {
  digitalWrite(LED[0], HIGH);
  digitalWrite(LED[1], HIGH);
  digitalWrite(LED[2], HIGH);
  delay(4000);
}
