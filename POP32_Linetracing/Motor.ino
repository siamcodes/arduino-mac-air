void MotorStop() {
  ao();
  delay(10);
}

void Forward(int MotorSpeed, int Time) {
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  fd2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time) { //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  bk2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(200);
  ConvertADC();
  while (L == 1) { //ถ้าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed);    //หมุนขวา
  delay(200);       //ปรับค่าให้เลี้ยวตรงเส้น
  ConvertADC();
  while (R == 1) {  //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurn() {      //ยูเทินขวา
  MotorStop();
  sr(TurnSpeed);    //หมุนขวา
  delay(400);       //ปรับค่าให้เลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R == 1) { //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}
