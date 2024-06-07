void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (C == 0) Forward(MotorSpeed, 1);
  else if (L == 0) tl(60);
  else if (R == 0) tr(60);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, Time);
  ConvertADC();
  while (L == 1 || R == 1) { //ยังไม่เจอแยก
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
