void ForwardBalance() //เดินหน้าปรับจูน
{
  int Status=0;
  Forward(SlowSpeed,1);
  //AvoidRed();
  while(Status==0)
  {
    Forward(SlowSpeed,1);
    ReadADC();
    WallDecision();
    if(in(7)==0 && in(6)==0) Status=1;
    else if(in(7)==0 && in(6)==1) //เจอดำด้านซ้าย ขาวด้านขวา
    {
      MotorStop();
      //AvoidOthers();
      motor(2,100);
      motor(1,-5);
      delay(100);
      motor(1,100);
      ConvertADC();
      while(in(6)==1) {
        ConvertADC();
      }
      //delay(50);
      Status=1;
    }
    else if(in(7)==1 && in(6)==0) //เจอขาวด้านซ้าย ดำด้านขวา
    {
      MotorStop();
      motor(1,100);
      motor(2,-5);
      delay(100);
      motor(2,100);
      ConvertADC();
      while(in(7)==1) {
        ConvertADC();
      }
      //delay(50);
      Status=1;
    }
  }
  MotorStop();
}

void SwIn(){
  if(in(7)==0){
    Backward(30,1000);
    Right();
  }
  else if(in(6)==0){
    Backward(30,1000);
    Left();
  }
}

void SwInInverted(){
  if(in(7)==0){
    Backward(30,1000);
    Left();
  }
  else if(in(6)==0){
    Backward(30,1000);
    Right();
  }
}

//void BackwardBalance() //ถอยหลังปรับจูน
//{
//  int Status=0;
//  Backward(SlowSpeed,1);
//  while(Status==0)
//  {
//    Convert5AnalogBack();
//    if((BL1==0)&&(BR1==0)) Status=1;
//    else if((BL1==0)&&(BR1==1)) //เจอดำด้านซ้าย ขาวด้านขวา
//    {
//      MotorStop();
//      //motor(1,SlowSpeed);
//      //motor(2,SlowSpeed);
//      motor(3,-SlowSpeed);
//      motor(4,-SlowSpeed);
//      while(BR1==1) {Convert5AnalogBack();}
//      delay(50);
//      Status=1;
//    }
//    else if((BL1==1)&&(BR1==0)) //เจอขาวด้านซ้าย ดำด้านขวา
//    {
//      MotorStop();
//      //motor(3,SlowSpeed);
//      //motor(4,SlowSpeed);
//      motor(1,-SlowSpeed);
//      motor(2,-SlowSpeed);
//      while(BL1==1) {Convert5AnalogBack();}
//      delay(50);
//      Status=1;
//    }
//  }
//  MotorStop();
//}
