void RobotStart() 
{
  ForwardSpeedTime(60,200);
}

void Forward() {
  fd2(LeftBaseSpeed, RightBaseSpeed);
}

void ForwardDelay(int Time) {
  Forward();
  delay(Time);
}

void ForwardSpeedDelay(int Time) {
  BaseSpeed = ACCSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}

void ForwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}

void Backward() {
  bk2(BackLeftBaseSpeed, BackRightBaseSpeed);
}

void BackwardDelay(int Time) {
  Backward();
  delay(Time);
}

void BackwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Backward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}

void MotorStop() {
  ao();
  delay(10);
}
