#include <Adafruit_MCP3008.h>
#include <POP32.h>
//Adafruit_MCP3008 adc;  //
#include "SoftwareSerial.h"
#define dir1A 2  //
#define dir2A 3  //
#define pwmA 5   //
#define dir1B 4  //
#define dir2B 7  //
#define pwmB 6   //
#define numsensor 8
#include <MCP3XXX.h>
MCP3008 adc;
int last_value = 0;
int Max[numsensor] = { 586, 561, 612, 613, 579, 646, 536, 500 };
int Min[numsensor] = { 136, 135, 134, 133, 133, 134, 134, 135 };
unsigned long F[numsensor];
float leftmotor, rightmotor, powermotor, error, lasterror;
void setup() {
  //Serial.begin(9600);
  Serial.begin(9600);
  beep();
  oled.text(4, 0, "SW_OK => RUN");
  oled.show();
  waitSW_OK();  //รอจนกว่าจพกดปุ่ม ok
  beep();
  delay(500);
  //Move(20,20,1000); while(1) stop(0);
  //view();
  // view();
  // viewRead();
  // viewReadLine();
  // t(50,0.007,0.1);  //YR kd 0.1
  // t(80,0.01,0.18);   //_/-/
  // t(45,0.009,0.078);  //U
  //SENSOR 0.8 c.m.

  //  t(50,0.007,0.1);
  // t(45,0.012,0.05);   //s_cycle
  // tt(50,0.007,0.07,550);

  // t(50,0.007,0.07);
  // t(70,0.015,0.15);   //m_cycle
  // tt(50,0.007,0.07,550);

  // t(50,0.009,0.09,250);
  // tt(90,0.018,0.2,550);  //B_cycle
  // t(50,0.007,0.07);

  // t(50,0.001,0.1);  //YR kd 0.1
  // l();
  //while (digitalRead(8) == 1);  //start switch
  delay(500);
    Move( 50, 50, 1000);
    Motor(0, 0);
}

void loop() {

  //Serial.println(digitalRead(8));
    Move( 50, 50, 1000);
  Motor(0, 0);
}

void Move(int spl, int spr, int Timer) {
  Motor(spl, spr);
  delay(Timer);
}

void Motor(int motorl, int motorr) {
  motorl = (motorl * 255) / 100;
  motorr = (motorr * 255) / 100;
  if (motorl == 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, 0);
  } else if (motorl > 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(pwmA, motorl);
  } else if (motorl < 0) {
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, -motorl);
  }
  if (motorr == 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, 0);
  } else if (motorr > 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
    analogWrite(pwmB, motorr);
  } else if (motorr < 0) {
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, -motorr);
  }
}

void view() {
  while (1) {
    oled.text(0, 0, "%d  ", analog10(0));
    oled.text(1, 0, "%d  ", analog10(1));
    oled.text(2, 0, "%d  ", analog10(2));
    oled.text(3, 0, "%d  ", analog10(3));
    oled.show();
    Serial.print(analog10(0));
    Serial.print("\t,");
    Serial.print(analog10(1));
    Serial.print("\t,");
    Serial.print(analog10(2));
    Serial.print("\t,");
    Serial.println(analog10(3));
  }
}
//วนอ่านค่าเซนเซอร์ 10 bit---------------
void Read() {
  for (int i = 0; i < numsensor; i++) {
    int x = map(analog10(i), Min[i], Max[i], 0, 1000);  // อ่านค่าเซ้นเซอร์ ถ้าไม่เกาะเส้นให้เปลี่ยน  1000, 0
    if (x > 1000) x = 1000;
    if (x < 0) x = 0;
    F[i] = x;
  }
}




int ReadLine() {
  unsigned long avg = 0;
  unsigned long sum = 0;
  int on_line = 0;
  Read();
  for (int i = 0; i < numsensor; i++) {
    if (F[i] > 200) on_line = 1;
    if (F[i] > 50) {
      avg = avg + (F[i] * (i * 1000));
      sum = sum + F[i];
    }
  }
  if (on_line == 0) {
    if (last_value > 3500) return 7000;
    else return 0;
  } else {
    last_value = avg / sum;
  }
  return last_value;
}

