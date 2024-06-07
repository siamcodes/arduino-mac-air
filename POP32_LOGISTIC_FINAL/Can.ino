void Can() {
  Forward(Speed, 200);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 50);
  TurnRight1();
  TracJC(Speed, 100);
  TracJC(Speed, 50);
  TurnRight1() ;
  Put();
  TracJC(SlowSpeed, 100);
  Grip();
  TracJCback(Speed, 150);
  TurnLeftBW();
  TracTime(Speed, 200);
  Put();
  //-----------------------
  TracJCback(Speed, 100);
  TurnLeft1();
  TracJC(Speed, 50);
  TurnLeft1();
  TracJC(Speed, 25);
  TracJC(Speed, 0);
  //----------------------------------------
  //GripCan(); //ยกแขนลง-คีบ-ยกแขนขึ้น
  //TurnLeft();
  //PutCan();  //ยกแขนลง-คีบ-ยกแขนขึ้น

}
