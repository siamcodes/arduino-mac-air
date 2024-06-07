void Test() {
  Put();
  Forward(Speed, 300);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 30); 
  TurnRight();
  TracJC(Speed, 100);
  TracJC(SlowSpeed, 50);
  TurnRight();
  TracJC(SlowSpeed, 30);
  Grip();
  TracNormalBW(Speed,30);
  TurnLeftBW();
  Put();
//  TurnLeftBW();
//  TurnLeft();
//  TracJC(Speed, 20);
//  TurnRight();
//  TracJC(Speed, 100);
//  TracJC(Speed, 20);
//  Grip();

  
}
