void TrackPID(int MotorSpeed) //วิ่งตามลู่แบบ PID
{
  int Output,LeftOutput,RightOutput;

  TuneMotor(MotorSpeed);
  Error = SonarR1 - RefSonarR1PID;  //คำนวณ Error
  if(abs(Error)>5) Error = 0; //ลดการเหวี่ยงเวลาเจอช่อง
  MaxSpeed = MotorSpeed;
  Output = (Kp*Error)+(Ki*Integral)+Kd*(Error-PreError);
  LeftOutput = LeftSpeed+Output;
  RightOutput = RightSpeed-Output;
  if(LeftOutput>MaxSpeed) LeftOutput = MaxSpeed;
  if(RightOutput>MaxSpeed) RightOutput = MaxSpeed;
  if(LeftOutput<0) LeftOutput = 0;
  if(RightOutput<0) RightOutput = 0;
  fd2(LeftOutput,RightOutput);
  PreError = Error;
  Integral += Error;
}
