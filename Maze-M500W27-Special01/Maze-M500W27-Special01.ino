#include <ATX2.h> //เพิ่มไลบราลี 
int SonarF,SonarR1,SonarR2;
int RobotSpeed,SlowSpeed,TurnSpeed,LeftSpeed,RightSpeed;
int Error,PreError,Integral,MaxSpeed;

#define RefSonarF 25    //ระยะห่างด้านหน้าก่อนชะลอ
#define RefSonarR 20    //ระยะเช็คกำแพงด้านขวา
#define RefSonarR1PID 5 //ระยะห่างจากกำแพงวิ่ง PID
#define RefSonaWall 7
#define Kp 2
#define Kd 30
#define Ki 0

#define Mode 1    //0:วิ่งและเลี้ยวปกติ 1:PID ตามขวา


void setup() {
  // put your setup code here, to run once:
  RobotSpeed = 70;  //ความเร็ววิ่งทางตรง
  SlowSpeed = 60;   //ความเร็วชะลอ
  TurnSpeed = 70;    //ความเร็วการเลี้ยว
  XIO();  //ประกาศ IO
  beep(1);  //เสียงบี๊บ
  Show3Sonar();
  sw_ok_press();  //รอจนกว่าจะกดปุ่ม OK
  beep();
  delay(100);
  //Forward(RobotSpeed,2000);
  //Forward(SlowSpeed,2000);
  //Backward(SlowSpeed,2000);
  //TurnLeft();
  //TurnRight();
  //Forward1Block();
  //MotorStop();
}

void loop() {
  // put your main code here, to run repeatedly:
  Auto();
}
