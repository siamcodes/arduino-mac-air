#include <POP32.h>
int L2, L1, C, R1, R2, BL, BC, BR;  //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2, RefBL, RefBC, RefBR;  //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed;   //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;    //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed;  //ตัวแปรแกี่ยวกับ PID
int ErrorB, PreErrorB, IntegralB, MaxSpeedB;  //ตัวแปรแกี่ยวกับ PID

void setup() {
  Speed = 90;  //ความเร็วปกติ 50
  ACCSpeed = 80;  //ความเร็วตอนเร่ง 80
  SlowSpeed = 45; //ความเร็วตอนช้า 50
  TurnSpeed = 70;  //ความเร็วตอนเลี้ยว 60
  beep(1);        //เสียงบัซเซอร์ 0-3
  
  GripUp();       //ยกแขนขึ้น 
  GripDown();     //ยกแขนลง
  Put();          //ปล่อย  
  Grip();         //คีบ
 
  //ShowLCD();      //แสดงค่าเริ่มต้น LCD ตอนเปิดเครื่อง
  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  
  Forward(Speed, 2000); //เดินหน้าหน่วงเวลา
  //Backward(Speed,2000);
  //TracNormalBW(Speed,50);
  TracJC(Speed,100);
  TracJC(Speed,100);
   TracJC(Speed,100);
  //TurnLeft();
  //TurnRight();
  //UTurn();
  MotorStop();
  ResetTimer1();  //เปิดใช้งานคู่กับ Finish()
}

void loop() {
  //Can();
  //Finish();
}
