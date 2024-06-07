#include <ATX2.h>

char Speed, SlowSpeed, ACCSpeed, BaseSpeed, LeftBaseSpeed, RightBaseSpeed, TurnSpeed, MaxSpeed, SonarSpeed, DistanceRef;
char Error, PreError, Kp, Kd, Ki, Kt, BackLeftBaseSpeed, BackRightBaseSpeed;
int RefL1, RefR1, SumError;
int L1,  R1;
long Timer, Timer2, Timer3;
char SW_OK, Error99Check = 0, digital_sw = 0;

#define SW_pin 18
#define No 0
#define Yes 1

void setup() {

  XIO();
  Speed = 40;
  DistanceRef = 8;     //0:ไม่เช็คสิ่งกีดขวาง ,>0 เช็คสิ่งกีดขวาง ปกติ = 8
  ACCSpeed = Speed;
  SlowSpeed = 50;
  BaseSpeed = Speed;
  TurnSpeed = 50;
  SonarSpeed = Speed;
  InitialSpeed();
  InitialRef();
  beep(0);
  glcdMode(2);
  glcdClear();
  setTextSize(2);
  setTextColor(GLCD_RED);
  glcd(0, 0, "Ubon TP Robot.");
  setTextColor(GLCD_WHITE);
  glcd(1, 0, "Line MRC2022");
  setTextColor(GLCD_GREEN);
  glcd(2, 0, "Junior Tennis  ");
  setTextColor(GLCD_BLUE);
  glcd(3, 0, "Speed = %d   ", Speed);
  setTextColor(GLCD_ORANGE);
  glcd(4, 0, "ACC=%d", ACCSpeed);
  setTextColor(GLCD_GRAY);
  glcd(5, 0, " OK to Start ");
  //digitalWrite(SW_pin, HIGH);
  SW_OK = No;
  while (SW_OK == No)  { // waiting "OK" button
    if (Read_sw_OK()) {
      StartTimer();
      beep(1);
      while (Read_sw_OK())  { //wait unpress OK button
        if (ReadTimer() >= 2000) {
          beep(2);
          Show2Analog();
          SW_OK = No;
        }
        else SW_OK = Yes;
      }
    }
  }
  BaseSpeed = Speed;
  glcdClear();
  setTextSize(2);
  setTextColor(GLCD_ORANGE);
  glcd(0, 0, "   Starting   ");
  StartTimer2();

  //ForwardSpeedTime(40,1500); Finish();
  //BackwardDelay(1000);
  //TracJC();
  //TurnLeft();
  //TracJC();
  //UTurnRight();
  //TurnLeft();
  //TracSonar();
  //CurveRight(60,80);
  //Finish();

}

void loop() {
  // put your main code here, to run repeatedly:
  Round1();
}
