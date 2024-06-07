void MRC() {
  Forward(SlowSpeed, 100);

  TracJC(Speed, 30);
  TurnRight();   //1
  TracJC(Speed, 50);
  TurnRight();    //2
  TracJC(Speed, 50);
  TurnRight();    //3

  TracTime(ACCSpeed, 14000);  //โค้ง
  TracTime(SlowSpeed, 3000);  //แยก-เหลี่ยม
  TracTime(ACCSpeed, 10000);

  TracJC(SlowSpeed, 30);
  TurnLeft();//4
  TracJC(SlowSpeed, 30);
  TurnLeft();      //5
  TracJC(70, 100); //6  ข้ามแยก
  TracJC(SlowSpeed, 30);
  TurnLeft();     //7
  TracJC(SlowSpeed, 30);
  TurnLeft();    //8
  TracJC(70, 100);  //9  ข้ามแยก
  TracJC(SlowSpeed, 30);
  TurnLeft();     //10
  TracJC(SlowSpeed, 30);
  TurnLeft();    //11

  TracTime(ACCSpeed, 12000);  //โค้ง
  TracTime(SlowSpeed, 3000);  //แยก-เหลี่ยม
  TracTime(ACCSpeed, 10000);

  TracJC(SlowSpeed, 30);
  TurnLeft();    //12
  TracJC(SlowSpeed, 30);
  TurnLeft();    //13
  TracJC(SlowSpeed, 30);
  TurnLeft();    //14
  TracJC(SlowSpeed, 30);
  TurnLeft();    //15
  TracJC(SlowSpeed, 30);
  TurnLeft();    //16
  TracJC(SlowSpeed, 30);
  TurnLeft();    //17

  TracTime(ACCSpeed, 12000);  //โค้ง
  TracTime(SlowSpeed, 3000);  //แยก-เหลี่ยม
  TracTime(ACCSpeed, 10000);

  TracJC(SlowSpeed, 30);
  TurnRight();   //18
  TracJC(SlowSpeed, 30);
  TurnRight();    //19
  TracJC(SlowSpeed, 30);
  TurnRight();    //20
  TracTime(Speed, 2000);     //แทรกหน่วงเวลา
  TracTime(ACCSpeed, 20000);     //แทรกหน่วงเวลา
}
