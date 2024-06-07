//#include <SPI.h>
#include <POP32.h>
#define NUM_SENSORS 8
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS], REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {491,396,915,423,378,486,474,705};
int MaxValue[NUM_SENSORS] = {3743,3296,3833,3633,3683,3776,3752,3825};
int REF[NUM_SENSORS] = {2117,1846,2374,2028,2030,2131,2113,2265};


///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  //AutoRef();
  beep();
  sw_OK_press(); // Wait For Press SW
  delay(500);
  //ShowCalibrate(); //Calibrate Light of Sensor
  //SerialF(); //Serial Sensor
  //Program1();

}

void loop() {
  m1();
  //Motor(20,20);delay(1000);

  while (1) {
    MotorStop();
  }

}
