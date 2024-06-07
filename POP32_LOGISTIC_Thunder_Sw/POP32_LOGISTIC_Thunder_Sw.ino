//#include <SPI.h>
#include <POP32.h>
#define NUM_SENSORS 7
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS],REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {110,82,86,181,95,78,97,99};
int MaxValue[NUM_SENSORS] = {934,762,831,954,929,776,834,850};
int REF[NUM_SENSORS] = {522,422,458,567,512,427,465, 450};

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
//m2();

 while(1){MotorStop();}

}
