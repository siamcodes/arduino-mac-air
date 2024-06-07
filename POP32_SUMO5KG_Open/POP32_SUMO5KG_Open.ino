#include <POP32.h>
int L1, C, R1, BC; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL1, RefC, RefR1, RefBC; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID


void setup() {
  Speed = 70;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 50; //ความเร็วตอนช้า 50
  TurnSpeed = 80;  //ความเร็วตอนเลี้ยว 50

  pinMode(PB0,INPUT_PULLUP);  

  beep();        //เสียงบัซเซอร์ 0-3
  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  ConvertADC();
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  delay(2000);
  beep(3);        //เสียงบัซเซอร์ 0-3

  //Forward(Speed, 1000);
  //Backward(Speed, 200);
  //TurnRight();
  //TurnLeft();
  //UTurn();
  //MotorStop();
  ResetTimer1();
  attachInterrupt(PB0, CheckLine, FALLING);
}

void loop() {
  //TracTime(Speed, 10);
  //Forward(Speed, 1);

    ConvertADC();
    if(BC==0){  //PA7
      CheckLine();
      ConvertADC();
    }else{
      //TracTime(Speed,1);
      Forward(Speed, 1);
    }
}
