#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;  //

#define dir1A 2  //
#define dir2A 3  //
#define pwmA 5   //
#define dir1B 4  //
#define dir2B 7  //
#define pwmB 6   //
#define numsensor 8
int last_value = 0;
int Max[numsensor] = { 586, 561, 612, 613, 579, 646, 536, 500 };
int Min[numsensor] = { 136, 135, 134, 133, 133, 134, 134, 135 };
unsigned long F[numsensor];
float leftmotor, rightmotor, powermotor, error, lasterror;
void setup() {
  Serial.begin(9600);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(pwmB, OUTPUT);
  adc.begin(A0, A1, A2, A3);
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

  // t(50,0.007,0.1);  //YR kd 0.1
  // l();
  while (digitalRead(8) == 1);  //start switch
  delay(500);
  tt(50, 0.009, 0.22, 150);
  tt(100, 0.016, 0.22, 200);
  t(50, 0.01, 0.07);
  t(45, 0.012, 0.05);  //s_cycle
  ty(50, 0.007, 0.07);
  Move(50,50,30);
  r();
  tt(50,0.009,0.22,250);
  tt(100,0.016,0.18,850);
  // // t(50,0.007,0.07);  //YR kd 0.1
  trr(50,0.01,0.07);
  tll(40, 0.012, 0.05);   //s_cycle
  
  tt(50, 0.009, 0.22, 350);
  tt(100, 0.016, 0.22, 350);

  t(50, 0.01, 0.1);
  t(45, 0.012, 0.05);  //s_cycle
  tt(50, 0.009, 0.22, 300);
  trr(50, 0.007, 0.1);
  l();
  tt(90,0.016,0.18,200); 
  tll(45,0.009,0.15);
  l();
  tt(60, 0.009, 0.12, 150);
  // t(60,0.007,0.07);
  // t(65,0.012,0.11);   //m_cycle
  // tt(65,0.012,0.11,850); 
  // // t(65,0.012,0.11);   //m_cycle
  tt(60,0.01,0.13,1800); 
  tt(50,0.007,0.07,150);
  tt(100,0.016,.18,900);
  tt(60,0.01,0.13,1800); 
  // t(50,0.007,0.07);
  // t(65,0.012,0.11);   //m_cycle
  // t(40,0.007,0.07); 
  // t(70,0.012,0.11);   //m_cycle
  tll(50,0.01,0.07);
  r();
  tt(55,0.01,0.1,200);
  trr(50,0.01,0.07);
  r();
  tt(55,0.01,0.07,80);
  tt(80,0.013,0.16,300);
  t(50,0.01,0.07);
  tt(80,0.013,0.15,300);
  t(50,0.01,0.07);      //X
  l();
  tt(90,0.018,0.2,250);  //B_cycle
  tll(50,0.01,0.12);
  r();
  tt(55,0.01,0.07,150);
  tll(55,0.009,0.13);
  l();
  Move(50,50,30);
  r();
  tll(60,0.009,0.12);
  Move(50,50,30);
  r();
  Move(50,50,20);
  l();
  tt(55,0.01,0.07,150);
  tt(90,0.018,0.2,500);  //B_cycle
  trr(50,0.007,0.07);
  l();
  tt(60,0.018,0.2,280);
  t(50,0.007,0.07);
  t(45,0.012,0.05);   //s_cycle
  tt(50,0.007,0.07,350);
  tt(100,0.016,0.18,350);

  // tt(50,0.01,0.07,150);
  // tl(50,0.007,0.07);
  // l();
  // tt(50,0.015,0.20,150);
  // t(40,0.007,0.07);
  // r();
  // tt(40,0.007,0.07,100);
  // r();
  // tt(40,0.015,0.20,250);
  // tt(100,0.016,.18,900);
  // t(40,0.007,0.07);
  // r();
  // tt(40,0.007,0.07,50);
  // r();
  // t(40,0.007,0.07);
  // r();
  // tt(55,0.01,0.07,150);
  // tr(55,0.007,0.07);
  // tt(55,0.01,0.07,150);
  // tr(55,0.007,0.07);
  // tt(55,0.01,0.07,150);
  // tr(55,0.007,0.07);
  // tt(55,0.01,0.07,200);
  // tr(50,0.01,0.07);
  // r();
  // tt(50,0.01,0.07,150);
  // t(50,0.01,0.12);
  // l();
  // tt(50,0.009,0.22,350);
  // tt(80,0.016,0.22,400);

  // t(45,0.012,0.07);
  // l();
  // Move(50,50,100);
  // last_value = 0;

  // tt(50,0.012,0.07,50);
  // t(50,0.012,0.07);
  // r();
  // tt(50,0.01,0.07,80);
  // tr(50,0.007,0.07);
  // r();
  // tt(65,0.008,0.15,1050);  //_/-/


  // t(50,0.007,0.07);
  // l();
  // tt(40,0.01,0.07,50);
  // tl(40,0.007,0.07);
  // l();
  // tt(40,0.007,0.07,100);
  // t(50,0.007,0.07);
  // l();
  // tt(40,0.007,0.07,100);
  // t(45,0.009,0.078);  //U
  // l();
  // tt(40,0.007,0.07,100);
  // t(50,0.007,0.07);
  // r();
  // tt(40,0.007,.07,50);
  // tr(50,0.007,.07);
  // r();
  // tt(40,0.007,.07,100);
  // tll(50,0.007,.07);
  // l();
  // tt(50,0.009,0.22,350);
  // tt(80,0.016,0.22,400);
  // t(50,0.007,0.07);
  // t(70,0.015,0.15);  //.018 0.1
  // tt(50,0.009,0.09,250);
  // tt(90,0.018,0.2,550);
  // t(50,0.007,0.07);
  // tt(65,0.01,0.15,1050);
  // t(80,0.01,0.18);
  // tt(60,0.01,0.13,1800); 
  motor(0, 0);
}

void loop() {
  Serial.println(digitalRead(8));
}

void Move(int spl, int spr, int Timer) {
  motor(spl, spr);
  delay(Timer);
}

void motor(int motorl, int motorr) {
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
  while (true) {
    for (int i = 0; i < 8; i++) {
      Serial.print(adc.readADC(i));
      Serial.print(",\t");
    }
    Serial.println("");
  }
}
void Read() {
  int x = 0;
  for (int i = 0; i < numsensor; i++) {
    x = map(adc.readADC(i), Min[i], Max[i], 0, 1000);
    if (x >= 1000) x = 1000;
    if (x <= 0) x = 0;
    F[i] = x;
  }
}
void viewRead() {
  while (true) {
    Read();
    for (int i = 0; i < 8; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println("");
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

void viewReadLine() {
  while (true) {
    for (int i = 0; i < 8; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println(ReadLine());
  }
}