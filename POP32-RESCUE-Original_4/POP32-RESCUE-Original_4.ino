/*                                                         ___            __           __   __        __
                                                   |__| |__  |    |    /  \    |  | /  \ |__) |    |  \
                                                   |  | |___ |___ |___ \__/    |/\| \__/ |  \ |___ |__/

      __    ___ ___  ___          __         ___      __   __                    ___               __                __
  |  | |__) |  |   |  |__  |\ |    |__) \ /     |      /__` /  \  |\/| |__/ |  /\   |      /\  |\ | |  \     /\  |\ | |  \  /\   |\/|  /\  |\ |
  |/\| |  \ |  |   |  |___ | \|    |__)  |      |  .   .__/ \__/  |  | |  \ | /~~\  |     /~~\ | \| |__/    /~~\ | \| |__/ /~~\  |  | /~~\ | \|


  ---READ ME!---
    โค้ดนี้ถูกเขียนขึ้นเพื่อการแข่งขันหุ่นยนต์กู้ภัยในรายการ สพฐ.
    หากเห็นสัญญลักษณ์ '*****' คั่นระหว่างคอมเมนต์ หมายความว่าห้ามแก้/เปลี่ยนข้อมูลใน Function หรือบรรทัด นั้นๆ
    เว็บไซต์ต่างๆที่ปรากฎขึ้นสามารถนำไปเซิร์ชได้ เป็น Hardware ที่ใช้ในการทำภารกิจ จากเว็ปไซต์ INEX
    หากมีปัญหาติดขัด สอบถาม อ.สมเกียรติ
*/

#include <POP32_Pixy2.h>  //กล้อง Pixy
#include <POP32.h>        //POP32

int L2, L1, C, R1, R2, Dist, Wall; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2, RefWall; //ตัวแปรเก็บค่าเฉลี่ยเซนเซอร์
int Speed, ACCSpeed, SlowSpeed, SlowerSpeed, TurnSpeed, LeftSpeed, RightSpeed, TracposSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID แทรกเส้น
int TourTime = 100;
int Count = 23;
bool greenfound = false;
bool bluefound = false;
bool yellowfound = false;
bool wayout = false;

//ตัวแปรเกี่ยวกับ PID กล้อง (ปรับทิศทาง)
#define head_Kp 5
#define head_Ki 0.0
#define head_Kd 20
float head_sp = 200; float head_error, hI, hD, hPrevError, head_spd;
//--------------------------------------------------------------------

//ตัวแปรเกี่ยวกับ PID กล้อง (ปรับระยะ)
#define dis_Kp 5
#define dis_Ki 0.0
#define dis_Kd 15
float dis_sp = 180; float dis_error, dI, dD, dPrevError, dis_spd;

float dis_sp2 = 150;
float head_sp2 = 150;
//---------------------------------------------------------------

//ตัวแปรค่าคงที่ความคลาดเคลื่อนของตำแหน่งแกน x และ y ของกล้อง
const int h_gap = 7;
const int d_gap = 7;

const int h_gapfinal = 4;
const int d_gapfinal = 4;

const int h_gapWalk = 30;
const int d_gapWalk = 30;

POP32_Pixy2 pixy;     //กำหนดตัวแปรกล้อง pixy

void setup() {
  pixy.init();        //เริ่มต้นกล้อง pixy
  Speed = 50;         //ความเร็วปกติ 60
  ACCSpeed = 70;     //ความเร็วตอนเร่ง 70
  SlowSpeed = 40;     //ความเร็วตอนช้า 50
  SlowerSpeed = 25;   //ความเร็วช้าพิเศษ 25
  TurnSpeed = 60;     //ความเร็วตอนเลี้ยว 70
  TracposSpeed = 0;   //ความเร็วตอนเดินตามลูกบอล 0

  beep();            //เสียงบัซเซอร์
  pixy.setLamp(0, 0);

  //Grip();           //คีบ

  //GripDown();         //ยกแขนลง
  //Put();              //ปล่อย
  //ShowLCD();        //แสดงค่าเริ่มต้น OLED ตอนเปิดเครื่อง

  //GripUp();         //ยกแขนขึ้น

  //Put();            //ปล่อย
  //Grip();           //คีบ
  //delay(500);       //หน่วงเวลา
  //  oled.text(0, 0, "Press A to continue");  //ทดสอบ
  //  oled.text(2, 0, "Press B to Skip");
  //  oled.show();
  //  if (SW_A) {                            //การวัดค่า
  //    SensorCal();
  //  }
  // else {                                  //เซนเซอร์
  ShowADC();          //แสดงค่าที่อ่านจากเซนเซอร์  (Function มาจากแท็ป ShowADC)
  InitialADC();       //***** ใส่ค่าเฉลี่ยของเซนเซอร์สี *****    (Function มาจากแท็ป InitialADC)
  waitAnykey();       //รอจนกว่าจะกดปุ่มใดๆ
  beep();             //เสียงบัซเซอร์

  //---------ทดสอบ Hardware ล้อ / มอเตอร์ / เซ็นเซอร์---------

  // Forward(Speed, 1000);         //เดินหน้าหน่วงเวลา วิ่งที่ความเร็ว Speed = 70 เป็นเวลา 3 วินาที           (Function มาจากแท็ป Motor)
  // TracNormalJC(Speed, 60);      //เดินตามเส้นธรรมดาแบบไม่มีการควบคุมแบบ PID ด้วยความเร็ว Speed = 70 หน่วงเวลา 60 ms เพื่อให้เลี้ยวที่แยกตัว T ได้(Function มาจากแท็ป TracNormal)

  /* TIP 'Trac'  = เดินตามเส้น
         'Normal = ธรรมดาแบบไม่มี PID
         'JC'    = ทำตามภารกิจต่อมรแท็ป 'Can'
  */
  TracJC(Speed, 50);
  TurnLeft();                   //เลี้ยวซ้าย    (Function มาจากแท็ป Motor)
  TracJC(Speed, 50);
  TurnLeft();
  TracJC(Speed, 50);
  TurnLeft();
  TracJC(Speed, 50);
  TurnLeft();
  TracJC(Speed, 50);
  UTurn();

  // TracJC(Speed, 60);
  // TurnRight();                 //เลี้ยวขวา    (Function มาจากแท็ป Motor)
  //UTurn();                     //ยูเทิร์น     (Function มาจากแท็ป Motor)
  //TracNormalJC(Speed, 50);     //เดินตามเส้นธรรมดาแบบไม่มีการควบคุมแบบ PID ด้วยความเร็ว Speed = 70 หน่วงเวลา 50 ms (Function มาจากแท็ป TracNormal)
  //TracNormalTime(Speed,1000);  //เดินตามเส้นแบบหน่วงเวลา ด้วยความเร็ว Speed = 70 หน่วงเวลาที่ 1000 ms (Function มาจากแท็ป TracNormal)
  //MotorStop();                  //หยุดมอเตอร์     (Function มาจากแท็ป Motor)
  //TracPos();                    //เดินตามลูกบอลจากกล้อง pixy
  //box();
  //AvoidRed();
  //BallPosition();
  //Walkout();
  ResetTimer1();                  //***** ล้างค่า timer *****
  Finish();
}

void loop() { //นำคำสั่งมาใส่เพื่อทำการวนซ้ำไปเรื่อยๆ
  // Forward(30, 3000);
  //  TracPosGreen();
  //  box();
  //  Walkback();
  //  TracPosGreen();
  //  box();
  //  Walkback();
  //  TracPosBlue();
  //  box();
  //  Walkback();
  //  TracPosYellow();
  //  box();
  //  Walkback();
  //  TracPosYellow();
  //  box();
  //  Walkout();
  //
  //  Can1();
  //rescue();
  // Finish();
}
