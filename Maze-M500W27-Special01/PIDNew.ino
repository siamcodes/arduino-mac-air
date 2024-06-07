void CalError()
{
  Read3Sonar(); 
  if(SonarF<=RefSonaWall) Error = -100;
  else Error = SonarR1 - RefSonarR1PID;  //คำนวณ Error
  if(Error>18) Error = 18;
  if(PreError == -100) delay(25);
}
void TrackPIDNew(int MotorSpeed) //วิ่งตามลู่แบบ PID
{
  int Output,LeftOutput,RightOutput;

  TuneMotor(MotorSpeed);
  CalError();
  MaxSpeed = MotorSpeed+10;
  Output = (Kp*Error)+(Ki*Integral)+Kd*(Error-PreError);
  LeftOutput = LeftSpeed+Output;
  RightOutput = RightSpeed-Output;
  if(LeftOutput>MaxSpeed) LeftOutput = MaxSpeed;
  if(RightOutput>MaxSpeed) RightOutput = MaxSpeed;
  if(LeftOutput<-MaxSpeed) LeftOutput = -MaxSpeed;
  //if(RightOutput<-MaxSpeed) RightOutput = -MaxSpeed;
  if(RightOutput<0) RightOutput = 0;
  motor(1,LeftOutput);
  motor(2,RightOutput);
  PreError = Error;
  Integral += Error;
}
