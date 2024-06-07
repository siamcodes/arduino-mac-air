void InitialSpeed(int MotorSpeed) { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  MaxSpeed = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed <= 50)
  {
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 70)
  {
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 100)
  {
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }

}
