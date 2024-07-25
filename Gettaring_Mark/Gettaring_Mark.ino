//#include <SPI.h>
#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;  //

//#include <Servo.h>
#include <Servo.h>
Servo myservo[3];
#define dir1A 2  //
#define dir2A 3  //
#define pwmA 5   //
#define dir1B 4  //
#define dir2B 7  //
#define pwmB 6   //
//#include "SoftwareSerial.h"
#define NUM_SENSORS 8
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS], REFmax[NUM_SENSORS];
int last_value = 0, LastError, SumError;

///////////////////////////////////////////////////////////////////////////
int MinValueF[NUM_SENSORS] = {290,243,263,280,274,273,254,253};
int MaxValueF[NUM_SENSORS] = {946,929,960,965,925,929,932,932};
//int MinValueB[NUM_SENSORS] = {90,43,63,80,74,73,54,53};
//int MaxValueB[NUM_SENSORS] = {746,429,660,765,725,729,732,732};
int REF[NUM_SENSORS] = {418,536,561,522,599,501,593,592};
///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(pwmB, OUTPUT);
    delay(500);
     while (analogRead(A6) > 500)
     delay(200);
   //  m1();
  //ShowCalibrate(); //Calibrate Light of Sensor
  //SerialF(); //Serial Sensor
  //Program1();
  motor(0, 0);
}

void loop() {
    Serial.println(digitalRead(8));        //หยุดวิ่งตลอดไป
}