#include <POP32.h>
int L1,L2, C, R1,R2, BC; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL1,RefL2, RefC, RefR1,RefR2, RefBC; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  Speed = 58;  //ความเร็วปกติ 57
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 50; //ความเร็วตอนช้า 50
  TurnSpeed = 70;  //ความเร็วตอนเลี้ยว 60

  beep(1);        //เสียงบัซเซอร์ 0-3
  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  ConvertADC();
  CalError();
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  delay(5000);
  beep(3); 
  //Forward(Speed, 2000);  //65
 //Backward(70, 180);
  //TurnRight();
  //TurnLeft();
  //UTurn();
  //TracTime(Speed,2000);
  //TracJC(Speed, 1000);
  //MotorStop();
  //ResetTimer1();
  //attachInterrupt(PA8, Line, FALLING);
}

void loop() {
  //TracTime(Speed,1000);
  WRG();

}
