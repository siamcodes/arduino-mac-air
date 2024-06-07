void ConvertADC()
{
  Read2Analog();
  if(L1<RefL1) L1 = 0;else L1 = 1;  //0:ดำ 1:ขาว
  if(R1<RefR1) R1 = 0;else R1 = 1;
}

void CalError() {
  ConvertADC();
  if((L1==1)&&(R1==0)) Error = 1;  
  else if((L1==1)&&(R1==1)) Error = 0; 
  else if((L1==0)&&(R1==1)) Error = -1; 
  else if((L1==0)&&(R1==0)) Error = 100; 

}

void TracPID()  {
  int Output, LeftSpeed, RightSpeed;
  Output = (Kp*Error) + (Ki*SumError) + (Kd*(Error-PreError));
  LeftSpeed = LeftBaseSpeed + Output;
  RightSpeed = RightBaseSpeed - Output;
  if(LeftSpeed>MaxSpeed) LeftSpeed = MaxSpeed;
  else if(LeftSpeed<-MaxSpeed) LeftSpeed = -MaxSpeed;
  //else if(LeftSpeed<0) LeftSpeed = 0;//new pid
  
  if(RightSpeed>MaxSpeed) RightSpeed = MaxSpeed;
  else if(RightSpeed<-MaxSpeed) RightSpeed = -MaxSpeed;
  //else if(RightSpeed<0) RightSpeed = 0;//new pid
  motor(1,LeftSpeed); 
  motor(2,RightSpeed);
  PreError = Error;
  SumError += Error;
}
