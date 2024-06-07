#include <Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo
void setup()
{
  myservo.attach(9); // กำหนดขา 9 ควบคุม Servo
  attachInterrupt(0, servo90, FALLING );
  attachInterrupt(1, servo180, FALLING );
}
void loop()
{
  myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(1000); // หน่วงเวลา 1000ms


}

void servo90() {
  myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 90
  delay(1000); // หน่วงเวลา 1000ms
}

void servo180(){
  myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 180
  delay(1000); // หน่วงเวลา 1000ms
}
