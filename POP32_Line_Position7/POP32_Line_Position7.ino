//#include <SPI.h>
#include <POP32.h>
#define NUM_SENSORS 7
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6 };
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS], REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {195,118,117,240,165,110,144};
int MaxValue[NUM_SENSORS] = {916,766,879,956,936,859,885};
int REF[NUM_SENSORS] = {555,442,498,598,550,484,514};

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
