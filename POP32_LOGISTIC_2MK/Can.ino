void Can() {
  Forward(SlowSpeed, 200);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 20);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 20);
  TurnRight() ;
  TracJC(SlowSpeed, 10);
  Grip();
  TracNormalBW(SlowSpeed, 50);
  TurnLeft1();
  TracTime(Speed,200);
  Put();
  TracNormalBW(Speed, 50);
  TurnLeft();
  //------------------------
  TracJC(Speed, 20);
  TurnRight();
  TracJC(SlowSpeed, 100);
  TracJC(SlowSpeed,10);
  Grip();
  TracNormalBW(Speed, 50);
  TurnLeft();
  TracJC(Speed, 100);
  TracJC(Speed, 20);
  TurnRight() ;
  TracJC(Speed, 50);
  TracJC(Speed, 0);
  TurnLeft1();
  TracTime(Speed,100);
  Put();
  
  //GripCan(); //ยกแขนลง-คีบ-ยกแขนขึ้น
  //TurnLeft();
  //PutCan();  //ยกแขนลง-คีบ-ยกแขนขึ้น

}
