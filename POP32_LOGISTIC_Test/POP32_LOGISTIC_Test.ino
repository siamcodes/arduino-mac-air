#include <POP32.h>
int L2, L1, C, R1, R2, BL, BC, BR;  //ตัวแปรเก็บค่าเซนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2, RefBL, RefBC, RefBR;  //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  Speed = 50;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 80
  SlowSpeed = 40; //ความเร็วตอนช้า 50
  TurnSpeed = 50;  //ความเร็วตอนเลี้ยว 60
  beep();
  ShowADC();

  Put();
  Grip();
  GripUp();
  GripDown();
  
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();
  
  //Forward(Speed, 2000);
  //TracNormalJC(Speed,50);
  //TurnLeft();
  //MotorStop();
  ResetTimer1();  //เปิดใช้งานคู่กับ Finish()
}

void loop() {
  Round();
  Finish();
}
