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
  TracJC(Speed, 100);
  TracJC(Speed, 50);
  TurnLeft();
  TracJC(Speed, 100);
  TracJC(Speed, 50);
  TurnLeft();

}
