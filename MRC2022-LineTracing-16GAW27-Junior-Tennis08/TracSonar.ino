void TracSonar() {

  BaseSpeed = SonarSpeed;
  InitialSpeed();
   while(Sonar()>DistanceRef)
  {
    TracPID();
    StartTimer();
    while((ReadTimer()<Kt)&&(Sonar()>DistanceRef))  
    {
      CalError();
    }
  }
  ao();
  BaseSpeed = Speed;
  InitialSpeed();
}

void TracSonarGo() 
{
  InitialSpeed();
  while(1)
  {
    if(Sonar()>DistanceRef)   //วิ่งปกติ
    {
      StartTimer3();
      while((ReadTimer3()<100))  
      {
        CalError();
        TracPID();
        StartTimer();
        while((ReadTimer()<Kt)) {}
      }
    }
    else        //เจอสิ่งกีดขวาง
    {
      ao(); beep(0); delay(1000);    
    }
  }
}
