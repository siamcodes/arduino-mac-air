void SetSpeed()
{
  int SW_OK0;
  glcdClear();
  glcd(0,0,"    Set Speed   ");
  glcd(1,0,"Speed = %d",Speed);
  SW_OK0 = No;
  while(SW_OK0 == No)  
  {  // waiting "OK" button
      if(Read_sw_OK()) 
      {
        StartTimer();
        beep(0);
        sw_ok_unpress();
        if(ReadTimer() >= 2000)     //Set Speed Ok
        {
          beep(1);
          SW_OK0 = Yes;
        }
        else      //Change Speed
        {
          SW_OK0 = No;
          Speed += 5;
          if(Speed>100) Speed = 60;
          glcd(1,0,"Speed = %d  ",Speed);       
        }
       }
  }
  glcd(2,0,"ACCSpeed = %d",ACCSpeed);
  SW_OK0 = No;
  while(SW_OK0 == No)  
  {  // waiting "OK" button
      if(Read_sw_OK()) 
      {
        StartTimer();
        beep(2);
        sw_ok_unpress();
        if(ReadTimer() >= 2000)     //Set Speed Ok
        {
          beep(100);
          SW_OK0 = Yes;
        }
        else      //Change Speed
        {
          SW_OK0 = No;
          ACCSpeed += 5;
          if(ACCSpeed>100) ACCSpeed = 60;
          glcd(2,0,"ACCSpeed = %d  ",ACCSpeed);       
        }
       }
  }
  InitialSpeed();
  glcd(3,0,"Press OK to Start"); 
}
