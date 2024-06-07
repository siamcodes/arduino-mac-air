void MotorStop() {
  ao();
  delay(10);
}

void Forward(int MotorSpeed, int Time) {
  InitialSpeed(MotorSpeed);   
  fd2(LeftSpeed, RightSpeed);
  delay(Time);
}

void Backward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  bk2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(150);
  ConvertADC();
  while (L2 == 1) { //ถ้าเจอขาวอยู่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(150);    //ปรับค่าให้เลี้ยวตรงเส้น
  ConvertADC();
  while (R1 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}


void UTurn() { //ขวา
  MotorStop();
  tr(TurnSpeed); //หมุนซ้าย
  delay(300);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R1 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}
