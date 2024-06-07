void Can() {
  Forward(SlowSpeed, 300);       //เดินจากจุดเริ่มต้น
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(Speed, 50);
  TurnRight();
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(SlowSpeed, 50);
  TurnLeft();
  TracJC(SlowSpeed, 50);
  TurnLeft();
  TracJC(SlowSpeed, 50);
  TurnLeft();
  TracJC(SlowSpeed, 50);
  TurnRight();
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  TracJC(SlowSpeed, 50);
  TurnLeft();
  TracJC(ACCSpeed, 100);
  TracJC(ACCSpeed, 100);
  //TracJC(SlowSpeed, 10);
  //GripCan(); //ยกแขนลง-คีบ-ยกแขนขึ้น
  //TurnLeft();
  //PutCan();  //ยกแขนลง-คีบ-ยกแขนขึ้น

}
