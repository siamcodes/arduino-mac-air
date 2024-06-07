void Track1BlockRGB(int TracSpeed,int Time) //เดินตามช่อง 1 ช่อง 
{
  int Status=0;
  StartTimer0();
  Forward(TracSpeed,1);
  while(Status==0)
  {
    Status=TracBalance();
    if((ReadTimer0()>Time)&&(Status==0))    //เดินตามช่องไปจนหมดเวลาครบ 1 ช่อง
    {
      Status = 1;
    }
  }
}
