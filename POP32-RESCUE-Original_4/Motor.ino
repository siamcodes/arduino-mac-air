void MotorStop() { //มอเตอร์หยุด
  ao();         //มอเตอร์หยุดทั้งหมด
  delay(10);   //หน่วงเวลา 10 ms
}

void Forward(int MotorSpeed, int Time) { //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);     //กำหนดความเร็วมอเตอร์
  fd2(LeftSpeed, RightSpeed);   //เดินไปข้างหน้า
  delay(Time);
}

void ForwardCheck(int MotorSpeed) { //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);     //กำหนดความเร็วมอเตอร์
  AvoidOthers();
  ReadADC();
  CheckWallBalance();
  beep();
  fd2(LeftSpeed, RightSpeed);   //เดินไปข้างหน้า
}

void Backward(int MotorSpeed, int Time) { //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);     //กำหนดความเร็วมอเตอร์
  bk2(LeftSpeed, RightSpeed);   //เดินถอยหลัง
  delay(Time);
}


void TurnLeft() {     //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(300);
  ConvertADC();
  while (L1 == 1) {   //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void Left() {     //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed);      //หมุนซ้าย
  delay(250);
  MotorStop();
}

void TurnRight() {    //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed);      //หมุน
  delay(300);
  //delay(9000 / TurnSpeed);
  //sr(TurnSpeed / 2);
  ConvertADC();
  while (R1 == 1) {   //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void Right() {     //เลี้ยวซ้าย
  MotorStop();
  sr(TurnSpeed);      //หมุนซ้าย
  delay(250);
  MotorStop();
}

void UTurn() {        //ขวา
  MotorStop();
  sr(TurnSpeed);      //หมุนซ้าย
  delay(600);         //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R1 == 1) {   //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTL() {        //ขวา
  MotorStop();
  sl(TurnSpeed);      //หมุนซ้าย
  delay(500);         //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  MotorStop();
}

void UTR() {        //ขวา
  MotorStop();
  sr(TurnSpeed);      //หมุนซ้าย
  delay(500);         //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  MotorStop();
}

void UTurnSlow() {        //ขวา
  MotorStop();
  sr(50);      //หมุนซ้าย
  delay(500);         //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R2 == 1) {   //ถ้่าเจอขาวอยูู่่ วนอ่านค่าสีไไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void rescue() {
  CalError();
  while (Error == 103) {
    AvoidRed();
    tl(30);
    delay(100);
    tr(30);
    if (in(8) == 0) {
      beep();
      bk(10);
      delay(50);
      if (C == 0) {

        delay(100);
      }
      bk(25);
      delay(500);
      sr(25);
      delay(500);
      bk(25);
      delay(500);
      sr(20);
      delay(1000);
      ao();
    }
    //    else if (in(6) == 1 && in(7) == 0) {
    //      beep();
    //      bk(25);
    //      delay(500);
    //      sl(25);
    //      delay(500);
    //      ao();
    //    }
  }
}
