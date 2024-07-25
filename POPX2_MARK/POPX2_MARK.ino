///#include <SPI.h>
#include <popx2.h>
//#include "SoftwareSerial.h"
#include <MCP3XXX.h>
MCP3008 adc;
#define CS_PIN PA0    //PC15      //ss 8
#define MOSI_PIN PA1  //PC14      //di 7
#define MISO_PIN PA2  //PA15      //do 6
#define CLOCK_PIN PA3 //PB11      //clk 5
#define L 111
#define R 112
#define ALL 113
#define N 114
#define NUM_SENSORS 8
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6,7};
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS],REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {377,120,120,306,147,264,287};
int MaxValue[NUM_SENSORS] = {909,811,803,851,807,837,846};
int REF[NUM_SENSORS] = {643,465,461,578,477,550,566};
///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  adc.begin(CS_PIN, MOSI_PIN, MISO_PIN, CLOCK_PIN);  // adc.begin(SS, MOSI, MISO, SCK);  //CS, DI,DO,CLK
  //AutoRef();
   beep();
  //beep();
  sw_OK_press(); // Wait For Press SW
    sound(1500, 100);
  sound(3000, 100);
  delay(500);
  
  ShowCalibrate(); //Calibrate Light of Sensor
  //SerialF(); //Serial Sensor
  //Program1();
  
}

void loop() {
//  FF(40, 0.03, 0.05, 'p', 0, 100, -10);
//  SpinL();
//Motor(20,20);delay(1000); 
//stdPID(0, 0.03, 0.03, 100, -10) ;
//m1();
//SpinL();

while(1){MotorStop();}

}
