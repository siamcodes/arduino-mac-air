#include <POP32.h>

int L, C, R;

int Speed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed, MaxSpeed; //ตัวแแปรความเร็วมอเตอร์
float paramGap1 = 50;  // กำแพงด้านหน้าอยู่ห่างแน่ๆ
float paramGap2 = 5;   // ไกลกำแพงเกินไป ระยะห่างทางซ้ายต่ำสุด
float paramGap3 = 15;  // ใกล้กำแพงเกินไป ระยะห่างทางซ้ายสูงสุด

int Ref = 10;


void setup()
{
  Serial.begin(9600);
  Speed = 50;  //ความเร็วปกติ 50
  SlowSpeed = 30;  //ความเร็วปกติ 50
  TurnSpeed = 30;  //ความเร็วตอนเลี้ยว 70
  sw_OK_press(); beep();
  //  forward(Speed,1000);
  //  left();
  //  right();
  //  UTurn();
  //  MotorStop();

}

void loop()
{
  //ShowADC();
  Can();
 // mission();

}
