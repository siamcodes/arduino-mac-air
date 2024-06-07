//#include <SPI.h>
#include <POP32.h>
#define NUM_SENSORS 7
uint8_t F_PIN[NUM_SENSORS] = { 6, 5, 4, 3, 2, 1, 0 }; //ซ้าย->ขวา  สีเขียวค่าน้อย สีขาวค่ามาก
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS], REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {143,513,167,203,218,226,234};
int MaxValue[NUM_SENSORS] = {958,984,966,970,975,976,975};
int REF[NUM_SENSORS] = {550,748,566,586,596,601,604};
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
   stdPID(30,2.05,0.01,50,-10);
  // stdPID(40,0.05,1.50,50,-10);
  // m1();
  // Motor(20,20);delay(1000);


 // while (1) {
 //   MotorStop(); //เมื่อใช้งานให้เอาออก
 // }

}
