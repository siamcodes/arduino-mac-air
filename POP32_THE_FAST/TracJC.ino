void TracJCStop() 
{  
  InitialSpeed();
  //TracSpeedTime(BaseSpeed,5000/BaseSpeed);
  CalError();
  while(Error<99)
  {
    if(DistanceRef>0)   //เช็คสิ่งกีดขวาง
    {
      if(Sonar()>DistanceRef)   //วิ่งปกติ
      {
          CalError();
          TracPID();
          StartTimer();
          while((ReadTimer()<Kt)&&(Error<100))
          {
            CalError();
          }
      }
      else  //เจอสิ่งกีดขวาง
      { 
        if(Sonar()<=DistanceRef) CurveLeft(60,70);    
      }
    }
    else    //ไม่เช็คสิ่งกีดขวาง
    {
      TracPID();
      StartTimer();
      while((ReadTimer()<Kt)&&(Error<100))
      {
        CalError();
      }
    }
  }
}

void TracJC() 
{
  TracJCStop();
  Forward();
  //if(BaseSpeed<=50) delay(3000/BaseSpeed);
  if(BaseSpeed<=50) delay(800/BaseSpeed);
  else if(BaseSpeed<=60) delay(1000/BaseSpeed); 
  else if(BaseSpeed<=70) delay(1000/BaseSpeed); 
}

void TracJCStraight() 
{
  TracJC();
  ForwardDelay(5000/BaseSpeed);
}

void TracJCSlowStop() 
{
  BaseSpeed = SlowSpeed;
  TracJCStop();
  BaseSpeed = Speed;
  InitialSpeed();
}

void TracJCSlow() {
  TracJCSlowStop();
  Forward();
  while(Error>=100)
  {
    CalError();
  }
}

void TracJCSpeedTime(int MotorSpeed, int TimeDelay) {
  BaseSpeed = MotorSpeed;
  TracJCStop();
  Forward();
  delay(TimeDelay);
  BaseSpeed = Speed;
  InitialSpeed();
}

void TracJCSpeed() 
{
  BaseSpeed = ACCSpeed;
  TracJCStop();
  Forward();
  while(Error>=100)
  {
    CalError();
  }
  delay(1000/BaseSpeed);
  BaseSpeed = Speed;
  InitialSpeed();
}

void TracSpeedTime(int TracSpeed, int TracTime) {
  BaseSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalError();
  while(ReadTimer()<TracTime)
  {
    TracPID();
    delay(Kt);
    CalError();
  }
  BaseSpeed = Speed;
  InitialSpeed();
}

void TracJCSpeedStop() 
{
  BaseSpeed = ACCSpeed;
  TracJCStop();
  BaseSpeed = Speed;
  InitialSpeed();
}

void TracJCSpeedStop99() 
{
  BaseSpeed = ACCSpeed;
  InitialSpeed();
  CalError();
  while(Error<99)
  {
    TracPID();
    StartTimer();
    while((ReadTimer()<Kt)&&(Error<99))
    {
      Error99Check = 1;
      CalError();
    }
  }
  BaseSpeed = Speed;
  InitialSpeed();
}
