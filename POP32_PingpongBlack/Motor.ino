void MotorStop(){ //มอเตอร์หยุด
   AO();  //มอเตอร์หยุดทั้งหมด
   delay(100); //หน่วงเวลา 100 ms
}

void Forward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  FD2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  BK2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  SL(TurnSpeed); //หมุนซ้าย
  delay(250);
  ConvertADC();
  while (L2 == 1) { //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  SR(TurnSpeed); //หมุนซ้าย
  delay(250);    //ปรับค่าให้เลี้ยวตรงเส้น
  ConvertADC();
  while (R2 == 1) { //ถ้าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurnR() { //ขวา
  MotorStop();
  SR(TurnSpeed); //หมุนขวา กลับเฟส
  delay(400);    //ปรับค่าให้เลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R2 == 1) { //ถ้าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurnL() { //ซ้าย
  MotorStop();
  SL(TurnSpeed); //หมุนซ้าย
  delay(400);    //ปรับค่าให้เลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (L2 == 1) { //ถ้าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnLeftN() { //เลี้ยวซ้าย
  MotorStop();
  SL(TurnSpeed); //หมุนซ้าย
  delay(500);
  MotorStop();
}

void TurnRightN() { //เลี้ยวขวา
  MotorStop();
  SR(TurnSpeed); //หมุนซ้าย
  delay(500);    //ปรับค่าให้เลี้ยวตรงเส้น
  MotorStop();
}
