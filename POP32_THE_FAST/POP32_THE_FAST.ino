#include <POP32.h>

char Speed, SlowSpeed, ACCSpeed, BaseSpeed, LeftBaseSpeed, RightBaseSpeed, TurnSpeed, MaxSpeed, SonarSpeed, DistanceRef;
char Error, PreError, Kp, Kd, Ki, Kt, BackLeftBaseSpeed, BackRightBaseSpeed;
int  RefL3, RefL2, RefL1, RefC, RefR1, RefR2, RefR3, SumError;
int L3, L2, L1, C, R1, R2, R3;
long Timer, Timer2, Timer3;
char SW_OK1, Error99Check = 0, digital_sw = 0;

#define SW_pin 18
#define No 0
#define Yes 1

void setup() {

  Speed = 50;
  DistanceRef = 8;     //0:ไม่เช็คสิ่งกีดขวาง ,>0 เช็คสิ่งกีดขวาง ปกติ = 8
  ACCSpeed = Speed;
  SlowSpeed = 50;
  BaseSpeed = Speed;
  TurnSpeed = 50;
  SonarSpeed = Speed;
  InitialSpeed();
  InitialRef();
  beep(0);
  oled.text(3, 0, "Speed = %d   ", Speed);
  oled.text(4, 0, "ACC=%d", ACCSpeed);
  oled.text(5, 0, " OK to Start ");
  oled.show();
  sw_ok_press();
  /*
  //digitalWrite(SW_pin, HIGH);
  SW_OK1 = No;
  while (SW_OK1 == No)  { // waiting "OK" button
    if (Read_sw_OK()) {
      StartTimer();
      beep(1);
      while (Read_sw_OK())  { //wait unpress OK button
        if (ReadTimer() >= 2000) {
          beep(2);
          ShowADC();
          SW_OK1 = No;
        }
        else SW_OK1 = Yes;
      }
    }
  }
  BaseSpeed = Speed;

  oled.text(0, 0, "   Starting   ");
  oled.show();
  */
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
