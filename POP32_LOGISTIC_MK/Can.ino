void MoveCan() {
  Forward(SlowSpeed, 100);       //เดินจากจุดเริ่มต้น
  //GripDown();     //ยกแขนลง
  for (int i = 1; i <= 4; i++) {
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว A
    GripCan();
    TracNormalBW(ACCSpeed, 15);
    TurnRight();
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว B
    PutCan();
    TracNormalBW(ACCSpeed, 15);
    TurnRight();
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว C
    GripCan();
    TracNormalBW(ACCSpeed, 15);
    TurnRight();
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว D
    PutCan();
    TracNormalBW(ACCSpeed, 15);
    UTurn();
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว B
    GripCan();
    TracNormalBW(ACCSpeed, 15);
    TurnRight();
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว C
    PutCan();
    TracNormalBW(ACCSpeed, 15);
    TurnRight();
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว D
    GripCan();
    TracNormalBW(ACCSpeed, 15);
    TurnRight();
    TracNormalJC(Speed, 0);      //แทรกเดินเตรียมเลี้ยว A
    PutCan();
    TracNormalBW(Speed, 150);
    ao();
    delay(10);
  }
  TracNormalTime(Speed, 300); //แทรกหน่วงเวลา
}

void Logistic() {
  Forward(SlowSpeed, 200);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 50);
  TurnRight();
  TracJC(Speed, 50);
  TracJC(Speed, 35);
  TurnRight();
  TracJC(Speed, 20);
  Grip();   //chekpoint1
}

void Test() {
  Forward(SlowSpeed, 300);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 20);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 20);
  TurnLeft();
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 30);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 30);
  Put();
  TracJC(Speed, 25);
  Grip();
  //---------------------
  TracJCback(Speed, 100);
  TracJCback(Speed, 100);
  TracJCback(Speed, 100);
  TracJCback(Speed, 100);
  TracJCback(Speed, 100);
  TracJCback(Speed, 50);
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  TracJC(Speed, 100);
  Put();
}

void Test2() {
  Forward(Speed, 300);       //เดินจากจุดเริ่มต้น
  TracJC(Speed, 20); 
  Put();
  TurnRight();
  TracJC(Speed, 100);
  TracJC(Speed, 20);
  TurnRight();
  TracJC(Speed, 20);
  Grip();
  UTurn();
//  TracJC(Speed, 100);
//  TracJC(Speed, 30);
//  TurnRight();
//  TracJC(Speed, 100);
//  TracJC(Speed, 100);
//  Put();
//  UTurn();
  
}
