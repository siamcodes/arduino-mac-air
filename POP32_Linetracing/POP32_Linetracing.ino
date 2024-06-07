#include <POP32.h>
int  L, C, R;   //ตัวแปรเซนเซอร์
int RefL, RefC, RefR;  //ตัวแปรค่ากลาง
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  SlowSpeed = 40;
  Speed = 50;
  ACCSpeed = 100;
  TurnSpeed = 40;
  ShowADC();  //แสดงค่าเซนเซอร์ ADC 
  beep();
  sw_ok_press();  //รอจนกว่าจะกดปุ่ม ok
  InitialADC();   //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  //Forward(Speed, 2000);  //วิ่งเดินหน้าที่ความเร็ว Speed หน่วงเวลา 2 วินาที
  //Backward(Speed, 2000);
  //TurnLeft();
  //TurnRight();
  //Uturn();
  //TracNormalJC(Speed, 50);
  MotorStop();
}

void loop() {
  ShowADC();
 // Round1();
 // Finish();
}
