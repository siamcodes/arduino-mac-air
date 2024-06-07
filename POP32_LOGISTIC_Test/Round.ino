void Round(){
  Forward(Speed, 300);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 50);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracTime(SlowSpeed, 1000);
}
