void setup() {
  pinMode(16,OUTPUT);

}

void loop() {
  digitalWrite(16, HIGH);
  delay(100);
  digitalWrite(16,LOW);
  delay(100);
}
