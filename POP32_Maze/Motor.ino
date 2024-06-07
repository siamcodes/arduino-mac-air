void MotorStop(){ //มอเตอร์หยุด
   ao();  //มอเตอร์หยุดทั้งหมด
   delay(10); //หน่วงเวลา 10 ms
}

void forward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  FD2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  BK2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void left() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(450);
  ConvertADC();
//  while (L == 0) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
//    ConvertADC();
//  }
  MotorStop();
}

void right() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(450);    //ปรับค่าให้เลี้ยวตรงเส้น
//  ConvertADC();
//  while (R == 0) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
//    ConvertADC();
//  }
  MotorStop();
}


void UTurn() { //ขวา
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  delay(900);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
//  ConvertADC();
//  while (R == 0) { //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
//    ConvertADC();
//  }
  MotorStop();
}
