void MotorStop(int Time) {
  analogWrite(ML1, 0);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, 0);
  delay(Time);
}

void Forward(int SpeedLeft, int SpeedRight, int Time) {
  analogWrite(ML1, SpeedLeft);
  analogWrite(ML2, 0);
  analogWrite(MR1, SpeedRight);
  analogWrite(MR2, 0);
  delay(Time);
}

void Backward(int SpeedLeft, int SpeedRight, int Time) {
  analogWrite(ML1, 0);
  analogWrite(ML2, SpeedLeft);
  analogWrite(MR1, 0);
  analogWrite(MR2, SpeedRight);
  delay(Time);
}

void TurnLeft(int SpeedLeft, int SpeedRight, int Time) {
  analogWrite(ML1, 0);
  analogWrite(ML2, SpeedLeft);
  analogWrite(MR1, SpeedRight);
  analogWrite(MR2, 0);
  delay(Time);
}

void TurnRight(int SpeedLeft, int SpeedRight, int Time) {
  analogWrite(ML1, SpeedLeft);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, SpeedRight);
  delay(Time);
}

void UTurn(int SpeedLeft, int SpeedRight, int Time) {
  analogWrite(ML1, SpeedLeft);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, SpeedRight);
  delay(Time);
}

void CheckObstacle() {
  MotorStop(500);
  TurnRight(150, 100, 500);    //หมุนขวา
  Forward(100, 200, 800);
}
