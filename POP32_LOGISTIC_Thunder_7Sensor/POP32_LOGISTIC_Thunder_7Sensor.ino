//#include <SPI.h>
#include <POP32.h>
#define NUM_SENSORS 7
uint8_t F_PIN[NUM_SENSORS] = { 6, 5, 4, 3, 2, 1, 0 }; //ซ้าย->ขวา  สีเขียวค่าน้อย สีขาวค่ามาก
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS], REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {139, 494, 166, 195, 204, 225, 229};
int MaxValue[NUM_SENSORS] = {958, 984, 966, 970, 975, 977, 976};
int REF[NUM_SENSORS] = {548, 739, 566, 582, 589, 601, 602};

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
  stdPID(0, 0.03, 0.05, 100, -10); //ใส่ baseSpeed เป็น 0 ก่อนเพื่อเทสหุ่นต้องนิ่งเกาะเส้น ถ้าไม่เกาะเส้นให้ไปแก้ที่ฟังก์ชัน readCalibrate()
  //m1();
  //Motor(20,20);delay(1000);


  //while (1) {MotorStop(); } //เมื่อใช้งานให้เอาออก


}
