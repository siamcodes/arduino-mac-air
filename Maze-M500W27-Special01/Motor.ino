void MotorStop()  //มอเตอร์หยุดหมุน
{
  ao(); //มอเตอร์หยุด 2 ล้อ
  delay(100);
}
void TuneMotor(int MotorSpeed)  //ปรับจูนมอเตอร์
{
  if(MotorSpeed<=60)  //น้อยกว่าหรือเท่ากับ 50
  {
    LeftSpeed = MotorSpeed-3;   //เอียงขวา
    RightSpeed = MotorSpeed-0;   //เอียงซ้าย
  }
  else   //มากกว่า 50
  {
    LeftSpeed = MotorSpeed-2;   //เอียงขวา
    RightSpeed = MotorSpeed-0;   //เอียงซ้าย
  }
}
void Forward(int MotorSpeed,int Time) //เดินหน้า
{
  TuneMotor(MotorSpeed);
  fd2(LeftSpeed,RightSpeed);
  delay(Time);
}
void Backward(int MotorSpeed,int Time) //ถอยหลัง
{
  TuneMotor(MotorSpeed);
  bk2(LeftSpeed-0,RightSpeed-0);
  delay(Time);
}
void TurnLeft() //เลี้ยวซ้าย
{
  MotorStop();
  sl(TurnSpeed);
  delay(250);
  MotorStop();
}
void TurnRight() //เลี้ยวขวา
{
  MotorStop();
  sr(TurnSpeed);
  delay(230);
  MotorStop();
}
