void Can() {
  Forward(Speed, 200);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 50);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 50);
  TurnRight1() ;
  TracJC(SlowSpeed, 30);
  Grip();
  TracNormalBW(Speed, 50);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 50);
  TurnRight1() ;
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(SlowSpeed, 50);
  TurnRight1();
  TracJC(Speed, 50);
  TurnLeft1();
  TracTime(SlowSpeed, 200);
  Put();
  //------------------------
  TracNormalBW(Speed, 50);
  TurnLeft1();
  TracJC(Speed, 50);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(SlowSpeed, 30);
  Grip();
  TracNormalBW(Speed, 50);
  UTurn();
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracTime(SlowSpeed, 200);
  Put();
  //GripCan(); //ยกแขนลง-คีบ-ยกแขนขึ้น
  //TurnLeft();
  //PutCan();  //ยกแขนลง-คีบ-ยกแขนขึ้น

}
