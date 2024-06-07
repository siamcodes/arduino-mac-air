void Show2Analog() {
  glcdClear();
  glcdFillScreen(GLCD_BLUE);
  setTextSize(1);
  setTextColor(GLCD_BLACK);
  glcd(0,1,"Black");
  sw_ok_unpress();
  sw_ok_press();
  StartTimer();
  beep(1);
  sw_ok_unpress();
  if(ReadTimer()>3000) SetSpeed();
  else{
  Read2Analog();
  RefL1 = L1;
  RefR1 = R1;
  glcd(2,0,"L1 = %d",L1);
  glcd(3,0,"R1 = %d",R1);
  setTextColor(GLCD_WHITE);
  glcd(0,10,"White");
  sw_ok_unpress();
  sw_ok_press();
  beep(2);
  Read2Analog();
  glcd(2,9,"L1 = %d",L1);
  glcd(3,9,"R1 = %d",R1);
  setTextColor(GLCD_RED);
  glcd(5,0,"Average");
  sw_ok_unpress();
  sw_ok_press();
  beep(3);
  RefL1 = (RefL1+L1)/2;
  RefR1 = (RefR1+R1)/2;
  glcd(6,0,"L1= %d",RefL1);
  glcd(7,0,"R1= %d",RefR1);
  sw_ok_unpress();
  sw_ok_press();
  beep(2);
  ShowSonar();
  sw_ok_unpress();
  }
}
