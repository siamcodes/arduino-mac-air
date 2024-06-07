void MotorStop(){ //มอเตอร์หยุด
   ao();  //มอเตอร์หยุดทั้งหมด
   delay(10); //หน่วงเวลา 10 ms
}

void Forward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  fd2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeedBack(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  bk2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(130); //200
  //  ConvertADC();
  //  while (L1 == 1) { //ถ้่าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
  //    ConvertADC();
  //  }
  MotorStop();
}

void TurnLeft1() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(100); //200
  //  ConvertADC();
  //  while (L1 == 1) { //ถ้่าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
  //    ConvertADC();
  //  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  delay(130);    //ปรับค่าให้เลี้ยวตรงเส้น  //200
  // ConvertADC();
  // while (R1 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
  //   ConvertADC();
  // }
  MotorStop();
}


void TurnRight1() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  delay(100);    //ปรับค่าให้เลี้ยวตรงเส้น  //200
  // ConvertADC();
  // while (R1 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
  //   ConvertADC();
  // }
  MotorStop();
}

void UTurn() { //ขวา
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  delay(200);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ  //400
  //  ConvertADC();
  //  while (R1 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
  //    ConvertADC();
  //  }
  MotorStop();
}
