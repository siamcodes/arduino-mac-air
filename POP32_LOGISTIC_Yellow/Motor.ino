void MotorStop(){ //มอเตอร์หยุด
   ao();  //มอเตอร์หยุดทั้งหมด
   delay(200); //หน่วงเวลา 10 ms
}

void Forward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  fd2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
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
  while (L2 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(150);    //ปรับค่าให้เลี้ยวตรงเส้น
  ConvertADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnLeft1() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(150);
  ConvertADC();
  while (L1 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight1() { //เลี้ยวขวา
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
  sr(TurnSpeed); //หมุนซ้าย
  delay(300);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}
