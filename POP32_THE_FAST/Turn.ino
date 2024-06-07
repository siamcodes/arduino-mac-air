void TurnLeft() {
  MotorStop();
  sl(TurnSpeed);
  delay(6000 / TurnSpeed);
  sl(TurnSpeed / 2);
  ConvertADC();
  while (L1 == 1) {
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() {
  MotorStop();
  sr(TurnSpeed);
  delay(6000 / TurnSpeed);
  sr(TurnSpeed / 2);
  ConvertADC();
  while (R1 == 1) {
    ConvertADC();
  }
  MotorStop();
}

void UTurnLeft() {
  MotorStop();
  sl(TurnSpeed);
  delay(18000 / TurnSpeed);
  ConvertADC();
  while (L1 == 1) {
    ConvertADC();
  }
  MotorStop();
}

void UTurnRight() {
  MotorStop();
  sr(TurnSpeed);
  delay(18000 / TurnSpeed);
  ConvertADC();
  while (R1 == 1) {
    ConvertADC();
  }
  MotorStop();
}

void Left(int Speed , int Time) {
  sl(Speed);
  delay(Time);
  ao();
}

void Right(int Speed , int Time) {
  sr(Speed);
  delay(Time);
  ao();
}

void TurnLeftDelay(int Speed , int Time) {
  tl(Speed);
  delay(Time);
}

void TurnRightDelay(int Speed , int Time) {
  tr(Speed);
  delay(Time);
}

void CurveRight(int MotorSpeed, int Time) //โค้างทางขวาอ้อมสิ่งกีดขวาง
{
  MotorStop();
  Right(MotorSpeed, 125);
  fd2(37, MotorSpeed);
  delay(300);
  ConvertADC();
  while (L1 == 1) {
    ConvertADC();
  }
  //ForwardSpeedTime(MotorSpeed,Time);
  delay(Time);
  TurnRight();
}

void CurveLeft(int MotorSpeed, int Time) //โค้างทางขวาอ้อมสิ่งกีดขวาง
{
  MotorStop();
  delay(100);
  Left(MotorSpeed, 125);
  fd2(MotorSpeed, 37);
  delay(100);
  ConvertADC();
  while (L1 == 1) {
    ConvertADC();
  }
  //ForwardSpeedTime(MotorSpeed,Time);
  delay(Time);
  TurnLeft();
}
