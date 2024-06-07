
void CN1()     //สนามที่บ้าน
{
  Forward(SlowSpeed, 100);       //เดินจากจุดเริ่มต้น 200
  TracNormalJC(Speed, 30);   //แทรกเดินเตรีียมเลี้ยว
  TurnRight();                   //เลี้ยว
  TracNormalJC(ACCSpeed, 30);      //ข้ามแยก
  TracNormalJC(Speed, 30);
  TurnRight();                   //เลี้ยว
  TracNormalJC(Speed, 30);    //แทรกเดินเตรีียมเลี้ยว
  TurnRight();                   //เลี้ยว
  TracNormalJC(SlowSpeed, 60);    //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracNormalJC(Speed, 30);      //เตรียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracNormalTime(ACCSpeed, 500); //แทรกหน่วงเวลา
}


void CN2()  //สนาม WRG
{
  Forward(Speed, 100);          //เดินจากจุดเริ่มต้น 200
  for (int i = 1; i <= 5; i++) {
    TracNormalJC(Speed, 20);      //แทรกเดินเตรีียมเลี้ยว 1-5
    TurnLeft();                   //เลี้ยวซ้าย
  }

  for (int i = 1; i <= 2; i++) {
    TracNormalJC(Speed, 20);      //แทรกเดินเตรีียมเลี้ยว 6-7
    TurnRight();                   //เลี้ยวขวา
  }
  TracNormalJC(ACCSpeed, 30);      //แทรกเดินตรง 8
  TracNormalJC(Speed, 30);      //แทรกเดินเตรีียมเลี้ยว 9
  TurnRight();                  //เลี้ยว

  for (int i = 1; i <= 3; i++) {
    TracNormalJC(Speed, 30);      //แทรกเดินตรง 10-12
  }

  TracNormalJC(Speed, 30);      //แทรกเดินเตรีียมเลี้ยว 13
  TurnLeft();                  //เลี้ยว
  TracNormalJC(ACCSpeed, 50);      //แทรกเดินตรง 14
  TracNormalTime(ACCSpeed, 3000); //แทรกหน่วงเวลา 15
}


void MoveCan() {
  Forward(SlowSpeed, 100);       //เดินจากจุดเริ่มต้น
  GripDown();     //ยกแขนลง
  for (int i = 1; i <= 3; i++) {
    TracNormalJC(Speed, 40);      //แทรกเดินเตรียมเลี้ยว A
    GripCan();
    TracNormalBW(ACCSpeed, 30);
    TurnRight();
    TracNormalJC(Speed, 50);      //แทรกเดินเตรียมเลี้ยว B
    PutCan();
    TracNormalBW(ACCSpeed, 3);
    TurnRight();
    TracNormalJC(Speed, 40);      //แทรกเดินเตรียมเลี้ยว C
    GripCan();
    TracNormalBW(ACCSpeed, 30);
    TurnRight();
    TracNormalJC(Speed, 50);      //แทรกเดินเตรียมเลี้ยว D
    PutCan();
    TracNormalBW(ACCSpeed, 30);
    UTurn();
    TracNormalJC(Speed, 40);      //แทรกเดินเตรียมเลี้ยว B
    GripCan();
    TracNormalBW(ACCSpeed, 30);
    TurnRight();
    TracNormalJC(Speed, 50);      //แทรกเดินเตรียมเลี้ยว C
    PutCan();
    TracNormalBW(ACCSpeed, 40);
    TurnRight();
    TracNormalJC(Speed, 40);      //แทรกเดินเตรียมเลี้ยว D
    GripCan();
    TracNormalBW(ACCSpeed, 40);
    TurnRight();
    TracNormalJC(Speed, 50);      //แทรกเดินเตรียมเลี้ยว A
    PutCan();
    TracNormalBW(ACCSpeed, 40);
    ao();
    delay(200);
  }

  TracNormalTime(ACCSpeed, 100); //แทรกหน่วงเวลา
}
