void Finish() {
  long int RunningTime;
  RunningTime = ReadTimer2(); 
  ao();
  beep(200);
  glcdClear();
  glcd(0,0,"   Finish.   ");
  setTextColor(GLCD_GREEN);
  glcd(2,0,"Running Time.");
  setTextColor(GLCD_RED);
  glcd(4,0,"%l.%l seconds", RunningTime/1000, RunningTime%1000);
  while(1){};
}
