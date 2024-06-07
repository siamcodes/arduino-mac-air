void Auto() //เลือกโหมดการวิ่ง
{
  if(Mode==0) AutoNormal(); //วิ่งตามช่องอัตโนมัติปกติ
  else AutoRight(); //วิ่งตามช่อง PID ขวา
}
void Forward1Block()  //เดินหน้า 1 ช่อง
{
  Forward(SlowSpeed,680);
}
void AutoNormal() //วิ่งตามช่องอัตโนมัติปกติ
{
  Forward1Block();
  while(1)  //วนทำตลอดไป
  {
    Read3Sonar();
    if(SonarF<RefSonarF)  //เจอทางตันให้ชะลอ
    {
      Read3Sonar();
      if(SonarF<RefSonarF)  //เจอทางตันให้ชะลอ
      {
        Forward(SlowSpeed,1000);  //เดินช้าๆจูนกำแพง
        MotorStop();
        Backward(SlowSpeed,150);  //ถอยหลังให้ห่างจากกำแพง
        MotorStop();
        Read3Sonar();
        if(SonarR1<RefSonarR) //เช็คด้านขวาตัน
        {
          TurnLeft(); 
          Backward(SlowSpeed,500);  //ถอยหลังจูน
          MotorStop();
        }
        else //ด้านเป็นช่องต้องเลี้ยวขวา
        {
          TurnRight(); 
          Forward1Block(); //เดินหน้าไปอีก 1 ช่อง
        }
      }
    }
    else if(SonarR1>RefSonarR)  //ด้านขวาเจอช่องว่าง
    {
      Read3Sonar();
      if(SonarR1>RefSonarR)  //ด้านขวาเจอช่องว่าง
      {
        MotorStop();  //เบรคก่อนเช็คท้าย
        Forward(SlowSpeed,1);  //เดินให้ท้ายพ้นกำแพง
        while(SonarR2<RefSonarR) {Read3Sonar();}  //วนรอให้ท้ายพ้นกำแพง
        MotorStop();
        TurnRight();
        Forward1Block();  //เดินไปอีกหนึ่งช่อง
      }
    }
   else //ไม่เจอทางตันไม่เจอช่องด้านขวาให้หุ่นยนต์เดินตรง
   {
      Forward(RobotSpeed,1);
      //TrackPID(RobotSpeed);
   }
  }
}
