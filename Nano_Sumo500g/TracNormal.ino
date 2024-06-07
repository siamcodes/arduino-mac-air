//void Trac() { //เดินตามเส้นธรรมดา
//  ConvertADC();
//  if (C == 0) MotorStop(10);  //Forward(250, 200, 1);
//  else  if (L == 0) TurnLeft(250, 200, 1);
//  else  if (R == 0) TurnRight(250, 200, 1);
//}
//
//void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
//  Forward(140, 100, 1);
//  ConvertADC();
//  while (C == 1) { //ยังไม่เจอแยก
//  //CheckObstacle();            //เช็คสิ่งกีดขวาง
//    Trac();
//  }
//  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
//}
