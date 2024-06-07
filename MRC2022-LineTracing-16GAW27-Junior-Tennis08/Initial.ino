void InitialRef() {
  RefL1 = 900;
  RefR1 = 900;
}

void InitialSpeed() 
{
  //MaxSpeed = BaseSpeed;
  MaxSpeed = BaseSpeed+18;
  Ki = 0;
  Error = 0;
  PreError = 0;
  if(BaseSpeed<=40)
  {
    LeftBaseSpeed = BaseSpeed-4;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 1;
  }
  else if(BaseSpeed<=50)
  {
    LeftBaseSpeed = BaseSpeed-8;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if(BaseSpeed<=60)
  {
    LeftBaseSpeed = BaseSpeed-4;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if(BaseSpeed<=70)
  {
    LeftBaseSpeed = BaseSpeed-4;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if(BaseSpeed<=80)
  {
    LeftBaseSpeed = BaseSpeed-6;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if(BaseSpeed<=85)
  {
    LeftBaseSpeed = BaseSpeed-8;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else if(BaseSpeed<=90)
  {
    LeftBaseSpeed = BaseSpeed-8;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
  else
  {
    LeftBaseSpeed = BaseSpeed-10;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    Kp = 100;       //forward PID
    Kd = 30;
    Kt = 10;
  }
}  
