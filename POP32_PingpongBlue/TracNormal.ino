void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if ( C == 0 ) Forward(MotorSpeed, 1);
  else if (L2 == 0) tl(70);
  else if (L1 == 0) tl(45);
  else if (R2 == 0) tr(70);
  else if (R1 == 0) tr(45);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, 1);
  ConvertADC();
  while (L2 == 1 || R2 == 1) {  //ยังไม่เจอแยก
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}

void TracNormalTime(int MotorSpeed, int Time) { //แทรกเส้นธรรมดา แบบหน่วงเวลา
  ResetTimer0();
  Forward(MotorSpeed, 1);
  while (Timer0 < Time) {
    Trac(MotorSpeed);
    ReadTimer0();
  }
}

void TracBW(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (BL1 == 1 && BR1 == 1) Backward(MotorSpeed, 1);  //ถ้าเซนเซฮร์ BL1 และ BR1 ยังไม่เจอเส้นขาว
  else if (BL2 == 0) tl(70);
  else if (BL1 == 0) tl(45);
  else if (BR2 == 0) tr(70);
  else if (BR1 == 0) tr(45);
}

void TracNormalBW(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Backward(MotorSpeed, 1);
  ConvertADC();
  while (BL1 == 1 || BR1 == 1) {  //ยังไม่เจอแยก
    TracBW(MotorSpeed);
  }
  Backward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}
