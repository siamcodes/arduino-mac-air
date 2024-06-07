void Finish() {
  long int RunningTime;
  RunningTime = ReadTimer2(); 
  ao();
  beep(200);
  oled.clear();
  oled.text(0,0,"   Finish.   ");
  oled.text(2,0,"Running Time.");
  oled.text(4,0,"%l.%l seconds", RunningTime/1000, RunningTime%1000);
  oled.show();
  while(1){};
}
