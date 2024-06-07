#include <POP32.h> //เพิ่มไลบราลี
int L1, C, R1; //ประกาศตัวแปรเซ็นเซอร์หน้า 7 ตัว
int BL1, BR1; //ประกาศตัวแปรเซ็นเซอร์หลัง 5 ตัว
int RefL1 = 700, RefC = 700, RefR1 = 700;
int RefBL1 = 700, RefBR1 = 700;
int RobotSpeed = 50, SlowSpeed = 40, AccSpeed = 100, TurnSpeed = 50;
int LeftSpeed, RightSpeed, LeftSpeedBack, RightSpeedBack;
int Kp = 10, Ki = 0, Kd = 30, Error, PreError, Integral;
long BaseTimer0, Timer0;
void setup() {
  beep(0);  //เสียงบี๊บ
  KickFront();
  KickBack();
  ShowADC(); //แสดงค่าเซ็นเซอร์
  sw_ok_press();  //รอจนกว่าจะมีการกดปุ่ม sw ok
  beep(0);
  delay(100);

  Forward(RobotSpeed,1000);
  Backward(RobotSpeed,1000);
  TurnLeft();
  //ForwardBalance();
  //TrackJCBalance(RobotSpeed,100);
  //BackwardBalance();
  //Box1();
  //TrackSpeedTimer(AccSpeed,500);
  MotorStop();
}

void loop() {


}
