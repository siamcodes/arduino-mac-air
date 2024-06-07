int ENA = 2;
int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
int ENB = 7;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  forward();
  delay(2000);
  MotorStop();
  delay(1000);
  backward();
  delay(2000);
  MotorStop();
  delay(1000);
}

void forward() {
  digitalWrite(ENA, HIGH);
  analogWrite(IN1, 250);
  analogWrite(IN2, 0);
  digitalWrite(ENB, HIGH);
  analogWrite(IN3, 250);
  analogWrite(IN4, 0); 
}

void backward() {
  digitalWrite(ENA, HIGH);
  analogWrite(IN1, 0);
  analogWrite(IN2, 250);
  digitalWrite(ENB, HIGH);
  analogWrite(IN3, 0);
  analogWrite(IN4, 250);
}

void MotorStop() {
  digitalWrite(ENA, HIGH);
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  digitalWrite(ENB, HIGH);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
